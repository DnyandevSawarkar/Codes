import serial

ser = serial.Serial("COM9", 115200)
while True:
    data = ser.readline().decode().rstrip()
    print(data)
