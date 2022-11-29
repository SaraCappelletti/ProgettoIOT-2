from serial import Serial
from time import sleep
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.widgets import Slider, CheckButtons

print("Waiting Arduino for rebooting...")
sleep(1)
print("Ready.")

arduino = Serial(port='COM4', baudrate=9600)
xvett = []
yvett = []
#slider_value = 0
prev = 0

def read():
    data = arduino.readline().decode().strip().split(',')
    if not data:
        return 0, 0
    #data = arduino.readline().decode().strip().split(',')
    #return [float(x) for x in data.split(',')]
    return float(data[0]), float(data[1])   

def send(slider_value):
    arduino.write(bytes([slider_value]))

plt.ion()
fig, ax = plt.subplots()

fig.subplots_adjust(bottom=0.3)
axman = fig.add_axes([0.25, 0.05, 0.65, 0.03])
manual_slider = Slider(
    ax=axman,
    label='Degrees ',
    valmin=0,
    valmax=180,
    valstep=1,
)

def on_slider(value):
    global prev
    if check.get_status()[0]:
        prev = value
        return prev


manual_slider.on_changed(on_slider)

rax = plt.axes([0.1, 0.1, 0.15, 0.2], frameon=False)
check = CheckButtons(rax, ['Take control of the valve'], [False])


def update():
    x, y = read()
    if y != 0 :
        print(x, y)
        xvett.append(x)
        yvett.append(y)
        ax.plot(xvett, yvett, 'b')
        plt.pause(0.01)

    
plt.show()

while plt.get_fignums():
    update()  
    if check.get_status()[0]:
        send(prev)
    if(len(xvett) > 100) :
        xvett = xvett[1:]
        yvett = yvett[1:]


'''while True:
    y, x = read()
    xvett.append(x)
    yvett.append(y)
    #print(x + "aaaa" + y)
    #fig, ax = plt.subplots()
    plt.clf()
    plt.plot(xvett, yvett)
    plt.draw()
    plt.pause(0.01)
    if(len(xvett) > 100) :
        xvett = xvett[1:]
        yvett = yvett[1:]
    myplot()

input()

# https://pygal.org/en/stable/
# https://matplotlib.org/
# https://seaborn.pydata.org/
# https://bokeh.org/'''