//% weight=100 color=#0066ff icon="\uf294" block="Custom BLE"
namespace customBLE {
    /**
     * Starts the custom BLE service
     */
    //% block="start custom BLE service"
    //% weight=90
    export function startService(): void {
        control.inBackground(() => {
            startCustomBLEService();
        });
    }

    /**
     * Sends data via custom characteristic
     * @param data The data to send, eg: "Hello"
     */
    //% block="send data %data"
    //% weight=80
    export function sendData(data: string): void {
        sendCustomData(data);
    }

    /**
     * Registers code to run when data is received
     * @param handler Code to run when data is received
     */
    //% block="on data received"
    //% weight=70
    export function onDataReceived(handler: (data: string) => void) {
        onCustomDataReceived(handler);
    }
}