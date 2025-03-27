#include "ble-service.h"
#include "MicroBit.h"

CustomBLEService::CustomBLEService(BLEDevice &_ble) : 
    ble(_ble)
{
    // Create the service
    customService = new BLEService(CUSTOM_SERVICE_UUID);

    // Create the TX characteristic (notify)
    txCharacteristic = new BLECharacteristic(
        CUSTOM_CHARACTERISTIC_UUID,
        BLERead | BLENotify,
        20,  // Max value size
        true // variable length
    );

    // Create the RX characteristic (write)
    rxCharacteristic = new BLECharacteristic(
        CUSTOM_CHARACTERISTIC_UUID,
        BLEWrite,
        20,  // Max value size
        true // variable length
    );

    // Add characteristics to service
    customService->addCharacteristic(*txCharacteristic);
    customService->addCharacteristic(*rxCharacteristic);

    // Add service to BLE stack
    ble.addService(*customService);

    // Register event handlers
    ble.onDataWritten(this, &CustomBLEService::onDataWritten);
    EventModel::defaultEventBus->listen(
        MICROBIT_ID_BLE, 
        MICROBIT_BLE_EVT_CONNECTED, 
        this, 
        &CustomBLEService::onBLEEvent
    );
}

void CustomBLEService::sendData(const char *data)
{
    if (ble.getGapState().connected) {
        txCharacteristic->setValue((uint8_t *)data, strlen(data));
        ble.updateCharacteristicValue(
            txCharacteristic->getValueHandle(),
            (uint8_t *)data,
            strlen(data)
        );
    }
}

void CustomBLEService::onDataReceived(const char *data)
{
    // This will be implemented in the TypeScript part
}

void CustomBLEService::onBLEEvent(MicroBitEvent e)
{
    if (e.value == MICROBIT_BLE_EVT_CONNECTED) {
        // Handle connection
    }
    else if (e.value == MICROBIT_BLE_EVT_DISCONNECTED) {
        // Handle disconnection
    }
}

void CustomBLEService::onDataWritten(const GattWriteCallbackParams *params)
{
    if (params->handle == rxCharacteristic->getValueHandle()) {
        char data[20];
        memcpy(data, params->data, params->len);
        data[params->len] = '\0';
        onDataReceived(data);
    }
}
