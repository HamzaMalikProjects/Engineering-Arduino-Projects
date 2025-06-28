/*
  Project 3 - Fortune Teller

  Parts required:
  - 220 ohm resistor
  - 10 kilohm resistor
  - 10 kilohm potentiometer
  - 16x2 LCD screen
  - tilt switch

  https://store.arduino.cc/genuino-starter-kit

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// set up a constant for the tilt switch pin
const int switchPin = 6;

// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);

  // set up the switch pin as an input
  pinMode(switchPin, INPUT);

  // Print a message to the LCD.
  lcd.print("Personally I");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Wouldn't Let That Silde");
}

void loop() {
  // check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState != prevSwitchState) {
    // if the state has changed from HIGH to LOW you know that the ball has been
    // tilted from one direction to the other
    if (switchState == LOW) {
      // randomly choose a reply
      reply = random(8);
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 0
      lcd.setCursor(0, 0);
      // print some text
      lcd.print("ChatGPT Says:");
      // move the cursor to the second line
      lcd.setCursor(0, 1);

      // choose a saying to print based on the value in reply
      switch (reply) {
        case 0:
          lcd.print("Say No More");
          break;

        case 1:
          lcd.print("Keeping It Halal");
          break;

        case 2:
          lcd.print("Yes ");
          break;

        case 3:
          lcd.print("Dammm Son");
          break;

        case 4:
          lcd.print("Definitely");
          break;

        case 5:
          lcd.print("Bro code");
          break;

        case 6:
          lcd.print("No");
          break;

        case 7:
          lcd.print("No Bitches");
          break;
      }
    }
  }
  // save the current switch state as the last state
  prevSwitchState = switchState;
}