#ifndef MICROBIT_CUSTOM_BLE_SERVICE_H
#define MICROBIT_CUSTOM_BLE_SERVICE_H

#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitComponent.h"

// UUIDs for our service and characteristic
static const uint8_t  CUSTOM_SERVICE_UUID[] = {
    0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
    0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0
};

static const uint8_t  CUSTOM_CHARACTERISTIC_UUID[] = {
    0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf0,
    0x12,0x34,0x56,0x78,0x9a,0xbc,0xde,0xf1
};

class CustomBLEService : public MicroBitComponent
{
    public:
        /**
         * Constructor.
         * @param _ble The instance of a BLE device that we're running on.
         */
        CustomBLEService(BLEDevice &_ble);

        /**
         * Sends data via the custom characteristic
         * @param data The string data to send
         */
        void sendData(const char *data);

        /**
         * Callback when data is received
         */
        void onDataReceived(const char *data);

    private:
        // BLE instance
        BLEDevice &ble;

        // BLE service
        BLEService *customService;

        // BLE characteristic for receiving data
        BLECharacteristic *rxCharacteristic;

        // BLE characteristic for sending data
        BLECharacteristic *txCharacteristic;

        // Handle BLE events
        void onBLEEvent(MicroBitEvent e);

        // Handle data writes
        void onDataWritten(const GattWriteCallbackParams *params);
};

#endif
