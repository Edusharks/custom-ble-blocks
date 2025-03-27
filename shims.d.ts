// Auto-generated. Do not edit.
declare namespace customBLE {
    /**
     * Starts the custom BLE service
     */
    //% shim=customBLE::startCustomBLEService
    function startCustomBLEService(): void;

    /**
     * Sends data via custom characteristic
     * @param data The data to send
     */
    //% shim=customBLE::sendCustomData
    function sendCustomData(data: string): void;

    /**
     * Registers handler for received data
     */
    //% shim=customBLE::onCustomDataReceived
    function onCustomDataReceived(handler: (data: string) => void): void;
}