from serial import Serial
from time import sleep
import matplotlib.pyplot as plt
import numpy as np

print("Waiting Arduino for rebooting...")
sleep(1)
print("Ready.")

arduino = Serial(port='COM4', baudrate=9600)
xvett = []
yvett = []
def read():
    data = arduino.readline().decode().strip().split(",")
    return data[0], data[1]

while True:
    with plt.ion():
        y, x = read()
        xvett.append(x)
        yvett.append(y)
        #print(x + "aaaa" + y)
        fig, ax = plt.subplots()
        ax.plot(xvett, yvett)
        plt.show()

# https://pygal.org/en/stable/
# https://matplotlib.org/
# https://seaborn.pydata.org/
# https://bokeh.org/