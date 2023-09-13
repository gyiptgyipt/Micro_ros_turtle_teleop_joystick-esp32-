#include <Arduino.h>
// The micro_ros_platformio library provides the functions to communicate with ROS2
#include <micro_ros_arduino.h>

// These are core ROS2 libraries for creating nodes, publishers, and executors
#include <stdio.h>
#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <geometry_msgs/msg/twist.h>


// geometry_msgs::msg::Twist twist;


#if !defined(ESP32) && !defined(TARGET_PORTENTA_H7_M7) && !defined(ARDUINO_NANO_RP2040_CONNECT) && !defined(ARDUINO_WIO_TERMINAL)
#error This example is only avaible for Arduino Portenta, Arduino Nano RP2040 Connect, ESP32 Dev module and Wio Terminal
#endif

rcl_publisher_t publisher;
geometry_msgs__msg__Twist twist;
rclc_support_t support;
rcl_allocator_t allocator;
rcl_node_t node;

#define LED_PIN 13

#define RCCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){error_loop();}}
#define RCSOFTCHECK(fn) { rcl_ret_t temp_rc = fn; if((temp_rc != RCL_RET_OK)){}}



const int linear_x_pin = 35;// The pins where joystick are attached
const int angular_z_pin = 34;

int mapped_linear;
int mapped_angular;

void error_loop(){
  while(1){
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
  }
}


void setup() {
  Serial.begin(115200);
  set_microros_wifi_transports("Zyme", "lolspaw7", "192.168.215.102", 8888);

  pinMode(LED_PIN, OUTPUT);

  pinMode(linear_x_pin,INPUT); //setup X joystick
  pinMode(angular_z_pin,INPUT); //setup Y joystick

  delay(2000);

  allocator = rcl_get_default_allocator();

  //create init_options
  RCCHECK(rclc_support_init(&support, 0, NULL, &allocator));

  // create node
  RCCHECK(rclc_node_init_default(&node, "micro_ros_arduino_wifi_node_with_joystick", "", &support));

  // create publisher
  RCCHECK(rclc_publisher_init_default(
    &publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist),
    "/turtle1/cmd_vel"));
  
  twist.linear.x = 0;
  twist.angular.y = 0;
}

void loop() {

  double Linear_Value = analogRead(linear_x_pin) >> 4;   //adjust to 3.3V to 5V values
  double Angular_Value = analogRead(angular_z_pin) >> 4;
   

   mapped_linear = map (Linear_Value, 0, 255, -100, 100)/100;  //mapped -1 to 1
   mapped_angular= map (Angular_Value, 0, 255, -100, 100)/100;
  //  Serial.println(mapped_linear);

    RCSOFTCHECK(rcl_publish(&publisher, &twist, NULL));
    twist.linear.x=mapped_linear;
    twist.angular.z=mapped_angular;

    // twist.linear.x=Linear_Value; // for testing
    // twist.angular.z=Angular_Value;
}