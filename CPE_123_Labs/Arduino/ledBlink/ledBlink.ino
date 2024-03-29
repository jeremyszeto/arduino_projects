#include <CPutil.h>

// Define your pins

const int redLedPin = 7;
const int redLedPin1 = 8;

// Create your hardware

Led redLed(redLedPin);
Led redLed1(redLedPin1);

void setup() 
{
  
  // Set up serial monitor and print out program info
  Serial.begin(9600);
  setupMessage(__FILE__, "Blinks an LED");
  delay(500);
  
  // Initialize your hardware
  redLed.off();
  redLed1.off();

}

void loop() 
{
  // put your main code here, to run repeatedly:

   blinkLed();
 
}

void blinkLed()
{
  static MSTimer ledTimer;
  static int ledOnFlag = false;

  if (ledTimer.done() == true)
  {
    // reset the timer to 1 second
    ledTimer.set(1000);

    // turn on/off the led
    if (ledOnFlag == false)
    {
      redLed.on();
      redLed1.on();
      ledOnFlag = true;
    }
    else
    {
      redLed.off();
      redLed1.off();
      ledOnFlag = false;
    }
  }
   
}
