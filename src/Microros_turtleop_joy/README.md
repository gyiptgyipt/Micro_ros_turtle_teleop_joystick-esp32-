# This project is micro-ros with ESP32 for teleoperation_joy

### First : try to flash firmware to ESP32 

there is three ways that I tried to update

1.Using the micro_ros package 

the step are in below link:
'''
https://github.com/micro-ROS/micro_ros_setup
'''

if you want to use espidf ,
'''
https://github.com/micro-ROS/micro_ros_espidf_component
'''

2.Using pio tools:
There is mrcro_ros_platformio library to use wiht platformio. Install PlatformIO extension in vs code and find in library: 
'''
https://github.com/micro-ROS/micro_ros_platformio
'''
and
'''
https://github.com/kaiaai/micro_ros_arduino_kaia?utm_source=platformio&utm_medium=piohome
'''

3.Using arduinoIDE.
In this case I use ArduinoIDE2 and find for micro_ros_arduino. 
I use this library for that project in platformio.
'''
https://github.com/kaiaai/micro_ros_arduino_kaia?utm_source=platformio&utm_medium=piohome
'''
and this for ArduinoIDE2

'''https://github.com/micro-ROS/micro_ros_arduino'''

#In this project I used platformio to build project and used micro_ros_arduino library.
That mean you can also use with arduinoide2.
just copy the main code and just upload with arduinoide2.
With platformio there is the library list and version in platformio.init file.(You don't need to install and add manually)


### Second step : Install micro_ros_agent package: 

# Install micro_ros_agent 
'''
https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwiM_7TW-KmBAxX_zjgGHT3RAvkQFnoECBEQAQ&url=https%3A%2F%2Fmicro.ros.org%2Fdocs%2Ftutorials%2Fcore%2Ffirst_application_linux%2F&usg=AOvVaw2JYKgRAihkJH-UZgYwhdhV&opi=89978449
'''

in that link you can use to upload firmware with that packages but there is a little probem with my machine, so I used above methods.
And build and source declear that project in your ros2 workspace.

### Third step : Listen to micro_controller with micro_ros_agent :

In this project, I use wifi udp4 to get the data from micro_controller.
### warning : Don't forget to change the wifi SSID,PASSOWRD and host computer ip address and don't use 24,25 pins for joystick module in esp32 (That used by wifi).

run that in your host pc:
```
ros2 run micro_ros_agent micro_ros_agent udp4 --port 8888
```

## check node list and topic list:

### Future -> adding launch file turtlesim_node 
