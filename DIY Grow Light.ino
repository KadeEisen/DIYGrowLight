#include "DS3231.h" //Using DS3231 library for real time clock
DS3231 rtc(SDA, SCL); //initialize rtc object
int ledPin = 13; //pin that tells relay to turn light on/off
#define BUTTON_PIN1 12 //8 hour timer
#define BUTTON_PIN2 8 //12 hour timer
#define BUTTON_PIN3 7 //16 hour timer
int clockReset1; //acts as a timer reset check
int clockReset2; //acts as a timer reset check
int clockReset3; //acts as a timer reset check
int currentHour; //current time (hour)
int currentMin; //current time (minute)
int currentSec; //current time (second)
int newHour; //timer end (hour)
int newMin; //timer end (minute)
int newSec; //timer end (second)

void setup()
{
  Serial.begin(9600); //tells program to print to serial 9600
  pinMode(ledPin, OUTPUT); //light bulb is output
  pinMode(BUTTON_PIN1, INPUT_PULLUP); //button input
  pinMode(BUTTON_PIN2, INPUT_PULLUP); //button input
  pinMode(BUTTON_PIN3, INPUT_PULLUP); //button input
  rtc.begin(); //initialize rtc variable
  //rtc.setTime(14, 10, 20); // Uncomment to set the time to hour, min, sec (24hr format)
}

void loop()
{
  clockReset1 = 0; //timers can be set again
  clockReset2 = 0; 
  clockReset3 = 0; 
  int buttonState1 = digitalRead(BUTTON_PIN1); //read if buttons are on or off
  int buttonState2 = digitalRead(BUTTON_PIN2); 
  int buttonState3 = digitalRead(BUTTON_PIN3);

  while (buttonState1 == 0) {
    buttonState1 = 0;
    //Serial.println("Timer Start!"); //SANITY CHECK - did the Arduino register the button being pushed?
    if(clockReset1 == 0) { //time setting loop
      currentHour = rtc.getTime().hour; //gets the hour of current time 
      currentMin = rtc.getTime().min; //gets the minute of current time 
      currentSec = rtc.getTime().sec; //gets the second of current time 
      newHour = currentHour + 8; //set end timer hour
      newMin = currentMin; //set end timer minute
      newSec = currentSec; //set end timer second
      //Serial.println("Time check!"); //SANITY CHECK - shows what the start and end times are when button is pressed
      //Serial.println(rtc.getTime().sec);
      //Serial.println(newSec);
    }
    clockReset1 = 1; //prevents time from being reset while buttonState1 = 0
    digitalWrite(ledPin, HIGH); //turn on grow light
    if ((rtc.getTime().hour == newHour) && (rtc.getTime().min == newMin) && (rtc.getTime().sec == newSec)){ //if the hours, minutes, and seconds of original and end timer time are equal
      digitalWrite(ledPin, LOW); //turn off light
      //Serial.print("Timer End"); //SANITY CHECK - did the Arduino see original time = end timer time?
      buttonState1 = 1; //time can now be reset
   }
  }

  while (buttonState2 == 0) {
    buttonState2 = 0;
    //Serial.println("Timer Start!"); //SANITY CHECK - did the Arduino register the button being pushed?
    if(clockReset2 == 0) { //time setting loop
      currentHour = rtc.getTime().hour; //gets the hour of current time 
      currentMin = rtc.getTime().min; //gets the minute of current time 
      currentSec = rtc.getTime().sec; //gets the second of current time 
      newHour = currentHour + 12; //set end timer hour
      newMin = currentMin; //set end timer minute
      newSec = currentSec; //set end timer second
      // Serial.println("Time check!"); //SANITY CHECK - shows what the start and end times are when button is pressed
      // Serial.println(rtc.getTime().sec);
      // Serial.println(newSec);
    }
    clockReset2 = 1; //prevents time from being reset while buttonState1 = 0
    digitalWrite(ledPin, HIGH); //turn on grow light
    if ((rtc.getTime().hour == newHour) && (rtc.getTime().min == newMin) && (rtc.getTime().sec == newSec)){ //if the hours, minutes, and seconds of original and end timer time are equal
      digitalWrite(ledPin, LOW); //turn off light
      //Serial.print("Timer End"); //SANITY CHECK - did the Arduino see original time = end timer time?
      buttonState2 = 1; //time can now be reset
   }
  }

  while (buttonState3 == 0) {
    buttonState3 = 0;
    //Serial.println("Timer Start!"); //SANITY CHECK - did the Arduino register the button being pushed?
    if(clockReset3 == 0) { //time setting loop
      currentHour = rtc.getTime().hour; //gets the hour of current time 
      currentMin = rtc.getTime().min; //gets the minute of current time 
      currentSec = rtc.getTime().sec; //gets the second of current time 
      newHour = currentHour + 16; //set end timer hour
      newMin = currentMin; //set end timer minute
      newSec = currentSec; //set end timer second
      // Serial.println("Time check!"); //SANITY CHECK - shows what the start and end times are when button is pressed
      // Serial.println(rtc.getTime().sec);
      // Serial.println(newSec);
    }
    clockReset3 = 1; //prevents time from being reset while buttonState1 = 0
    digitalWrite(ledPin, HIGH); //turn on grow light
    if ((rtc.getTime().hour == newHour) && (rtc.getTime().min == newMin) && (rtc.getTime().sec == newSec)){ //if the hours, minutes, and seconds of original and end timer time are equal
      digitalWrite(ledPin, LOW); //turn off light
      //Serial.print("Timer End"); //SANITY CHECK - did the Arduino see original time = end timer time?
      buttonState3 = 1; //time can now be reset
   }
  }
}
