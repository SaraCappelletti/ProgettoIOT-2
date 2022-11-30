from serial import Serial
from time import sleep
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.widgets import Slider, CheckButtons

READ_MIN = 1.0

def update():
    x, y, light, state = read()
    
    if y != -1:
        xvett.append(x)
        yvett.append(READ_MIN - y)
        ax.clear()
        ax.plot(xvett, yvett, 'b')
        plt.ylabel('water level')
        fig.suptitle(state, fontsize=14, fontweight='bold')
        ax.set_title(light)
        plt.pause(0.00001)

def on_slider(value):
    global prev
    if check.get_status()[0]:
        prev = value
        return prev

def read():
    data = arduino.readline().decode().strip().split(',')
    try:
        f1, f2, s1, s2 = float(data[0]), float(data[1]), str(data[2]), str(data[3])
    except:
        f1, f2, s1, s2 = -1, -1, '', ''
    return f1, f2, s1, s2

def send(slider_value):
    arduino.write(bytes([slider_value]))


print("Waiting Arduino for rebooting...")
sleep(1)
print("Ready.")

arduino = Serial(port='COM4', baudrate=9600)
xvett = []
yvett = []
prev = 0

plt.ion()
fig, ax = plt.subplots()

fig.subplots_adjust(top=0.8, bottom=0.3)

axman = fig.add_axes([0.25, 0.05, 0.65, 0.03])
manual_slider = Slider(
    ax=axman,
    label='Degrees ',
    valmin=0,
    valmax=180,
    valstep=1,
)

manual_slider.on_changed(on_slider)

rax = plt.axes([0.1, 0.1, 0.15, 0.2], frameon=False)
check = CheckButtons(rax, ['Take control of the valve'], [False])

plt.show()

while plt.get_fignums():
    update()  
    if check.get_status()[0]:
        send(prev)
    if(len(xvett) >= 100):
        xvett = xvett[1:]
        yvett = yvett[1:]
