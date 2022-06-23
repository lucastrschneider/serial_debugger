#!/usr/bin/env python3

import serial
import argparse
import time

DEFAULT_SERIAL_PORT = "/dev/ttyACM0"
DEFAULT_BAUDRATE = 115200

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-s", "--port-name",
                        help="Serial port", type=str,
                        default=DEFAULT_SERIAL_PORT)
    parser.add_argument("-b", "--baudrate",
                        help="Baudrate for serial communication", type=int,
                        default=DEFAULT_BAUDRATE)

    args = parser.parse_args()

    port_name = args.port_name
    baudrate = args.baudrate

    try:
        with serial.Serial(port_name, baudrate) as serial_port:
            # Precisa do delay e do flush input para limpar de verdade
            time.sleep(0.5)
            serial_port.flushInput()
            serial_port.flushOutput()

            while True:
                payload = serial_port.read_all()
                if (len(payload) > 0):
                    # print(len(payload))
                    print(payload)
    except serial.serialutil.SerialException:
        print(f"Erro no serial! {port_name} {baudrate}")
