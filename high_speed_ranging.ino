#include "Seeed_vl53l0x.h"
#include "Arduino.h"
#include <ArduinoBLE.h>

Seeed_vl53l0x VL53L0X;

#define BLE_DEVICE_NAME               "Arduino Nano 33 BLE Sense"
#define BLE_LOCAL_NAME                "TOF BLE"
#ifdef ARDUINO_SAMD_VARIANT_COMPLIANCE
    #define SERIAL SerialUSB
#else
    #define SERIAL Serial
#endif

BLEService BLETOF("590d65c7-3a0a-4023-a05a-6aaf2f22441c");
BLECharacteristic timeofFlightXBLE("0004", BLERead | BLENotify | BLEBroadcast, 40);

char ble_dat_send[30]="";
char TOF[5] = "TOF;";
char TOF_output[5];
void setup() {
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    SERIAL.begin(115200);
    if (!BLE.begin())
    {
        while (1);    
    }
    else{
      BLE.setDeviceName(BLE_DEVICE_NAME);
      BLE.setLocalName(BLE_LOCAL_NAME);
        BLE.setAdvertisedService(BLETOF);
        /* A seperate characteristic is used for each X, Y, and Z axis. */
        BLETOF.addCharacteristic(timeofFlightXBLE);
//        accelerometerXBLE.setValue( ble_dat_send, 24);
        BLE.addService(BLETOF);
        BLE.advertise();

    Status = VL53L0X.VL53L0X_common_init();
    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }

    VL53L0X.VL53L0X_high_speed_ranging_init();

    if (VL53L0X_ERROR_NONE != Status) {
        SERIAL.println("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while (1);
    }
    }
    
}


void loop() {
    BLEDevice central = BLE.central();
    VL53L0X_RangingMeasurementData_t RangingMeasurementData;
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;

    memset(&RangingMeasurementData, 0, sizeof(VL53L0X_RangingMeasurementData_t));
    Status = VL53L0X.PerformSingleRangingMeasurement(&RangingMeasurementData);
    if (VL53L0X_ERROR_NONE == Status) {
        if (RangingMeasurementData.RangeMilliMeter >= 2000) {
//            SERIAL.println("out of range!!");
        } else {
//            SERIAL.print("Measured distance:");
//            SERIAL.print(RangingMeasurementData.RangeMilliMeter);
//            SERIAL.println(" mm");
        }
    } else {
//        SERIAL.print("mesurement failed !! Status code =");
//        SERIAL.println(Status);
    }
//    dtostrf(RangingMeasurementData.RangeMilliMeter,3,1,TOF_output)
    itoa(RangingMeasurementData.RangeMilliMeter,TOF_output,10);
//    TOF_output = RangingMeasurementData.RangeMilliMeter;
    strcpy(ble_dat_send,TOF);
    strcat(ble_dat_send,TOF_output);
    SERIAL.print(ble_dat_send);
    SERIAL.println();
    
    
//    if(central)
//    {
//      while(central.connected())
//      {
//        timeofFlightXBLE.setValue(ble_dat_send);
//        delay(1000);
//        Serial.print(ble_dat_send);
//        Serial.println();
//      }
//    }

    delay(300);
}
