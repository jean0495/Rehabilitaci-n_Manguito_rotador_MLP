# scripts/bridge.py
import serial
import serial.tools.list_ports
import time

BAUDRATE = 9600

def listar_puertos():
    puertos = serial.tools.list_ports.comports()
    for i, p in enumerate(puertos):
        print(f"[{i}] {p.device} — {p.description}")
    return puertos

print("Puertos disponibles:")
puertos = listar_puertos()

nano_port = input("Ingresa el número del puerto del Nano: ")
uno_port  = input("Ingresa el número del puerto del UNO: ")

nano = serial.Serial(puertos[int(nano_port)].device, BAUDRATE, timeout=1)
uno  = serial.Serial(puertos[int(uno_port)].device,  BAUDRATE, timeout=1)

time.sleep(2)  # espera que los arduinos inicien
print("Bridge activo. Ctrl+C para detener.\n")

try:
    while True:
        if nano.in_waiting > 0:
            linea = nano.readline().decode('utf-8').strip()
            if linea.isdigit():
                classId = int(linea)
                print(f"[Nano → UNO] classId: {classId}")
                uno.write(f"{classId}\n".encode('utf-8'))
except KeyboardInterrupt:
    print("Bridge detenido.")
    nano.close()
    uno.close()