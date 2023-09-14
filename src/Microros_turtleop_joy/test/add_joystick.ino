

const int linear_x_pin = 25;// The pins where joystick are attached
const int angular_z_pin = 26;

int mapped_linear;
int mapped_angular;

void setup() 
    {
    Serial.begin(115200);

 // Sensor(s)
    pinMode(linear_x_pin,INPUT);
    pinMode(angular_z_pin,INPUT);

    }
 
void loop() 
   {
  //Speed reading and mapping
  int Linear_Value = analogRead(linear_x_pin) >> 4;   //adjust to 3.3V to 5V values
  int Angular_Value = analogRead(angular_z_pin) >> 4;
   
  //  Serial.print(Linear_Value );
  //  Serial.print(",");
  //  Serial.println(Angular_Value);
  
   mapped_linear = map (Linear_Value, 0, 255, -100, 100)/100;  //mapped -1,1
   mapped_angular= map (Angular_Value, 0, 255, -100, 100)/100;

  
  // Serial.print(" Linear X :");
  // Serial.print(mapped_linear);
  // Serial.print(" Angular Z :");
  // Serial.println(mapped_angular);

  // delay (500);

  //Direction reading and mapping
   }