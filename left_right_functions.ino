#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

const uint8_t motorSpeed = 400;

void setup() {
  lcd.clear();
  lcd.gotoXY(0, 0);
  lcd.print("Press A");
}


void loop() {
  bool buttonPress = buttonA.getSingleDebouncedPress();

  if (buttonPress) {
    delay(1000);

    for(double i = 0; i < 360*2; i+= 90){
      turnLeft(i);

      delay(50);
      motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
      delay(50);
      
      turnRight(i);
  
      delay(50);
      motors.setRightSpeed(0);
      motors.setLeftSpeed(0);
      delay(50);
    }
  }

}

void turnLeft(double n){
  for (double speed = 0; speed <= (n/360)*510; speed++)
    {
      motors.setRightSpeed(speed);
      motors.setLeftSpeed(-speed);
      delay(2);
    }
}

void turnRight(double n){
  for (double speed = 0; speed <= (n/360)*520; speed++)
    {
      motors.setRightSpeed(-speed);
      motors.setLeftSpeed(speed);
      delay(2);
    }
}
