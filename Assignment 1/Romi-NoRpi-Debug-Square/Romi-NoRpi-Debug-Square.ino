//Esteban Tuquero
//CPE 476
//Assignment 1b

/*Using the code supplied in https://github.com/venki666/CpE476_demos/tree/master/Arduino/Romi-NoRpi-Debug
 *b) Develop the code to move the Romi Robot in a square/rectangle (you can use your own parameters) 
 */

#include <Romi32U4.h>
#include <PololuRPiSlave.h>

Romi32U4Motors motors;
Romi32U4Encoders encoders;
Romi32U4ButtonA buttonA;

void setup() {
  Serial.begin(57600);


  ledYellow(false);
  ledGreen(true);
  ledRed(false);
}

float _debug_linear_ms = 0.25;
float _debug_angle_rs = 0.00;
void _DEBUG_PID_CONTROL() {
  static float _linear_ms_change = 0.1;
  set_twist_target(_debug_linear_ms, _debug_angle_rs);
}



void loop() {

  _DEBUG_PID_CONTROL();
  
  //set motor speed to move robot forward for 2 seconds
  motors.setSpeeds(-100,-100);
  delay(500);

  //set motor speed to 0 to stop robot for 2 seconds
  motors.setSpeeds(0,0);
  delay(500);

  //wheels rotate to turn the robot
  motors.setSpeeds(200,-200);
  delay(210);  

  //stop for 2 seconds before moving again
  motors.setSpeeds(0,0);
  delay(500);
      
  if (everyNmillisec(10)) {
    // ODOMETRY
    calculateOdom();
    doPID();
  }

}
