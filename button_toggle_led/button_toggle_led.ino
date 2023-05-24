/*
  Buttons & LEDs

  Pressing S1 (pin 33) toggles the RGB LED colors in ascending order.
  Pressing S2 (pin 32) toggles the RGB LED colors in descending order.
*/

// constants won't change. They're used here to set pin numbers:
const int buttonOne = 33;
const int buttonTwo = 32;
const int ledBlue =  37;
const int ledGreen = 38;
const int ledRed = 39;
const int ledRGB = 3;           // number of colors of the RGB LED

// variables will change:
int buttonOneState = 0;         // variable for reading the pushbutton #1 status
int buttonTwoState = 0;         // variable for reading the pushbutton #2 status
int currentRGB = 2;             // the sequence is {Red, Green, Blue} = {0, 1, 2};

void setup() {
  // initialize the LED pins as output:
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
}

/*
   Toggles the color sequence RGB
*/
void toggleLED() {
     switch(currentRGB) {
          case 0:
               digitalWrite(ledRed, HIGH);
               digitalWrite(ledGreen, LOW);
               digitalWrite(ledBlue, LOW);
               break;
          case 1:
               digitalWrite(ledRed, LOW);
               digitalWrite(ledGreen, HIGH);
               digitalWrite(ledBlue, LOW);
               break;
          case 2:
               digitalWrite(ledRed, LOW);
               digitalWrite(ledGreen, LOW);
               digitalWrite(ledBlue, HIGH);
     }
}

void loop(){
  /*
    Read the state of the buttons,
    it follows negative logic since
    it is configured as a pullup
  */
  buttonOneState = digitalRead(buttonOne);
  buttonTwoState = digitalRead(buttonTwo);

  /*
    Check if S1 is pressed and if so,
    increment to the next color.
  */
  if (buttonOneState == LOW) {
     currentRGB++;
     currentRGB %= ledRGB;
     delay(300);  // Add delay to debounce button press
  }

  /*
    Check if S2 is pressed and if so,
    decrement to the next color.
  */
  if (buttonTwoState == LOW) {
     currentRGB+= ledRGB;
     currentRGB--;
     currentRGB %= ledRGB;
     delay(300);  // Add delay to debounce button press
  }  

  toggleLED();
}
