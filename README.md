# This project is micro-ros with ESP32 for teleoperation_joy

### First step:

Download the repo to your workspace 

```https://github.com/Htet-Wai-Yan-HWY/Micro_ros_turtle_teleop_joystick-esp32-.git
```

### Second step:

 - Go to your_workspace//src/Microros_turtleop_joy

 - Follow the instruction to flash firmware to your micro-controller and upload the code .../Microros_turtleop_joy/src/main.cpp

### Third step:

 - GO to your workspace and build the project

```colcon build --symklink--install 
``` 

### Fourth step:

 - source the project 
 
 ```source install.setup.bash
 ```



### Fifth step:

 -launch the launch fikle in ros2_turtlesim_launch package.

```ros2 launch ros2_turtlesim_launch launch.launch.py
```
 - check the output from the launch file that will show about node,topic and communication details.

## Now you are controlling turtle in the turtlesim_node with joy_stick in your esp32 over wifi.