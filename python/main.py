from serial import Serial
from time import sleep

print("Waiting Arduino for rebooting...")
sleep(10)
print("Ready.")

arduino = Serial(port='COM4', baudrate=9600)

def read():
    data = arduino.readline()
    return data.decode().strip()

while True:
    value = read()
    print(value)

# https://pygal.org/en/stable/
# https://matplotlib.org/
# https://seaborn.pydata.org/
# https://bokeh.org/