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
    return float(data[0]), float(data[1])

plt.ion()
plt.plot([], [])
for _ in range(1000):
    y, x = read()
    xvett.append(x)
    yvett.append(y)
    #print(x + "aaaa" + y)
    #fig, ax = plt.subplots()
    plt.clf()
    plt.plot(xvett, yvett)
    plt.draw()
    plt.pause(0.01)
    if(len(xvett) > 150) :
        xvett = xvett[1:]
        yvett = yvett[1:]

input()

# https://pygal.org/en/stable/
# https://matplotlib.org/
# https://seaborn.pydata.org/
# https://bokeh.org/