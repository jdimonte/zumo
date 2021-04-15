#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

const uint8_t motorSpeed = 300;

void setup() {
  lcd.clear();
  lcd.gotoXY(0, 0);
  lcd.print("Press A");
}

void loop() {
  bool buttonPress = buttonA.getSingleDebouncedPress();

if(buttonPress) {
  delay(1000);

  motors.setSpeeds(motorSpeed, motorSpeed);
  delay(2000);

  motors.setSpeeds(0, 0);
  delay(500);

  motors.setSpeeds(-motorSpeed, -motorSpeed);
  delay(2000);

  motors.setSpeeds(0, 0);
}

}
