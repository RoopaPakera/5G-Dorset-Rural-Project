#include "Arduino.h"
#include <ArduinoBLE.h>
#include <Arduino_LSM9DS1.h>
#define BLE_DEVICE_NAME               "Arduino Nano 33 BLE Sense"
#define BLE_LOCAL_NAME                "Accelerometer BLE"

BLEService BLEAccelerometer("590d65c7-3a0a-4023-a05a-6aaf2f22441c");
BLECharacteristic accelerometerXBLE("0004", BLERead | BLENotify | BLEBroadcast, 40);

char ble_dat_send[30]="alo;ahihi;ahoho";

void setup()
{
    Serial.begin(115200);
    if (!BLE.begin())
    {
        while (1);    
    }
    else
    {
        BLE.setDeviceName(BLE_DEVICE_NAME);
        BLE.setLocalName(BLE_LOCAL_NAME);
        BLE.setAdvertisedService(BLEAccelerometer);
        /* A seperate characteristic is used for each X, Y, and Z axis. */
        BLEAccelerometer.addCharacteristic(accelerometerXBLE);
//        accelerometerXBLE.setValue( ble_dat_send, 24);
        BLE.addService(BLEAccelerometer);
        BLE.advertise();

    }
}
void loop()
{
  float x,y,z;
    BLEDevice central = BLE.central();
    if(central)
    {
        int writeLength;
        while(central.connected())
        {            

                accelerometerXBLE.setValue(ble_dat_send);
                delay(1000);
                Serial.print(ble_dat_send);
                Serial.println();
        }
    }
}
