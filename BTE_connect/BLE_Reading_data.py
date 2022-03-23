#from bluepy import btle
import time
import binascii
import struct
from bluepy.btle import UUID,Peripheral,DefaultDelegate

p = Peripheral("74:5c:a1:94:7b:6a")
svc = p.getServiceByUUID("590d65c7-3a0a-4023-a05a-6aaf2f22441c");
ch = p.getCharacteristics(uuid=UUID(0x0004))[0]

class MyDelegate(DefaultDelegate):
    def __init__(self):
        DefaultDelegate.__init__(self)

    def handleNotification(self, cHandle, data):
        print(data)


p.setDelegate(MyDelegate())
p.writeCharacteristic(ch.valHandle+1, struct.pack("b",55))


while True:
    if p.waitForNotifications(100.0):
        continue
    print("waiting...")
    
    