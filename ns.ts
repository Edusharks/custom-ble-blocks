namespace customBLE {
    let _onDataReceived: (data: string) => void = null;
    let _service: CustomBLEService = null;

    //% whenUsed
    export function notifyDataReceived(data: string) {
        if (_onDataReceived) {
            _onDataReceived(data);
        }
    }

    //% whenUsed
    export function startCustomBLEService(): void {
        if (!_service) {
            _service = new CustomBLEService(bluetooth);
            bluetooth.onBluetoothConnected(() => {
                // Handle connection
            });
            bluetooth.onBluetoothDisconnected(() => {
                // Handle disconnection
            });
        }
    }

    //% whenUsed
    export function sendCustomData(data: string): void {
        if (_service) {
            _service.sendData(data);
        }
    }

    //% whenUsed
    export function onCustomDataReceived(handler: (data: string) => void): void {
        _onDataReceived = handler;
    }
}