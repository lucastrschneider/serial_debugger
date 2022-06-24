#!/usr/bin/env python3

import serial
import argparse
import time

DEFAULT_SERIAL_PORT = "/dev/ttyACM0"
DEFAULT_BAUDRATE = 115200

def parse_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-p", "--port-name",
                        help="Serial port", type=str,
                        default=DEFAULT_SERIAL_PORT)
    parser.add_argument("-b", "--baudrate",
                        help="Baudrate for serial communication", type=int,
                        default=DEFAULT_BAUDRATE)

    args = parser.parse_args()

    return args.port_name, args.baudrate

def main():
    port_name, baudrate = parse_arguments()

    try:
        with serial.Serial(port_name, baudrate) as serial_port:
            # Precisa do delay e do flush input para limpar de verdade
            time.sleep(0.1)
            serial_port.reset_input_buffer()
            serial_port.reset_output_buffer()

            while True:
                payload = serial_port.read_all()
                if (len(payload) > 0):
                    print(payload.decode("ascii"), end="")
    except OSError:
        print("Dispositivo desconectado")
    except serial.serialutil.SerialException:
        print(f"Erro na porta serial: {port_name} {baudrate}")
    except KeyboardInterrupt:
        pass

if __name__ == "__main__":
    main()
