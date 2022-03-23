
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import time
import binascii
import struct, os
from bluepy.btle import UUID,Peripheral,DefaultDelegate
from concurrent import futures
from subprocess import check_output

#scope to upload data to GG Cloud 
scope = ['https://spreadsheets.google.com/feeds','https://www.googleapis.com/auth/drive']

global creds
global addr_var
global delegate_global
global perif_global

#Read accessed keys of GG Cloud 
creds = ServiceAccountCredentials.from_json_keyfile_name('client_secret.json', scope)
#Mac Address of Arduino devices
addr_var = ['74:5c:a1:94:7b:6a','b4:ae:ef:4f:3b:b4']
#Sheet of Excel Files
sensor_name = ['Sheet1','Sheet2']

#Start of BLE
class MyDelegate(DefaultDelegate):
    def __init__(self):
        DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        global addr_var
        global delegate_global
        
        for ii in range (len(addr_var)):
            if delegate_global[ii] == self:
                try:
                    update_Gsheet(sensor_name[ii],data)
                except:
                    return

#Function to upload sensor data to GG Cloud Sheets
def update_Gsheet(sensor_name,data):
    global creads
    #buffer to store sensor data
    data_packet = []
    #Split received data using ';'
    data_split = data.split(b";")
    #add splitted data to buffer data_packet
    data_packet = data_packet + data_split
    #Connect to GG Sheet and open IoT_testing_1 sheet
    client = gspread.authorize(creds)
    sheet = client.open("IoT_testing_1").worksheets()
    #Uploading systime to get current time
    curr_time = time.localtime()
    time_str = time.strftime("%m/%d/%Y %H:%M:%S",curr_time)
    data_packet = [time_str]+data_packet
    #send data to GG sheet in seperated column
    for ii in sheet:
        if ii.title == sensor_name:
            ii.append_row(data_packet)
            print("Successful !")
            return
        else:
            print("looking for workbook...")
            continue
            
#Run the program every 100ms
def perif_loop(perif,indx):
    while True:
        try:
            if perif.waitForNotifications(100.0):
                continue
        except:
            try:
                #disconnect devices
                perif.unpair
                perif.disconnect()
                print("disconnecting from: "+perif.addr)
                return
            except:
                return
            
delegate_global = []
perif_global = []
[delegate_global.append(0) for ii in range (len(addr_var))]
[perif_global.append(0) for ii in range (len(addr_var))]

#establish BLE connection between Raspberry Pi And Arduinos
def establish_connection(addr):
    global delegate_global
    global perif_global
    global addr_var
    
    while True:
        try:
            for jj in range(len(addr_var)):
                if addr_var[jj]==addr:
                    print("Attempting to connect with "+addr+" at index:" +str(jj))
                    p = Peripheral(addr)
                    perif_global[jj] = p
                    p.setDelegate(MyDelegate())
                    #Service Characteristic of Arduino: 0x0004
                    ch = p.getCharacteristics(uuid=UUID(0x0004))[0]
                    setup_data = b"\x01\00"
                    p.writeCharacteristic(ch.valHandle+1, setup_data)
                    p_delegate = MyDelegate()
                    delegate_global[jj] = p_delegate
                    p.withDelegate(p_delegate)
                    print("Connected to " +addr+" at index: "+str(jj))
                    perif_loop(p,jj)
        except:
            #reset BLE protocol of Raspberry Pi
            check_output("sudo hciconfig hci0 down",shell=True).decode()
            check_output("sudo hciconfig hci0 up",shell=True).decode()
            print("Failed to connect to "+addr)
            
            
#Using max thread to run 
ex = futures.ProcessPoolExecutor(max_workers = os.cpu_count())
results = ex.map(establish_connection,addr_var)
