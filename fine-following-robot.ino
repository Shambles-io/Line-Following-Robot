//Define Pin Mappings
const int leftLedPin = 8;
const int leftSensorPin = A1;
const int rightLedPin = 9;
const int rightSensorPin = A0;

//Defining Button Mapping
 #define START_BUTTON 2
int lightThreshold = 375; //Assigned light threshold we used
int counter = 0; //When counter==1, the program will start. Pressing the button will start the loop.

//Defining Butter Mapping
#define BUZZER 4

void setup(){ 
  //Set Baud Rate, Required to use Serial Monitor
  Serial.begin(9600);
  pinMode(START_BUTTON, INPUT); //The Button is assigned as an input
  pinMode(leftLedPin, OUTPUT); //The Left LED, and motor are assigned as outputs
  pinMode(leftSensorPin, INPUT); //The Left photocell readings are assigned as inputs
  pinMode(rightLedPin, OUTPUT); //The Right LED, and motor are assigned as outputs
  pinMode(rightSensorPin, INPUT); //The Right photocell readings are assigned as inputs
  pinMode(BUZZER, OUTPUT); //The Buzzer is assigned as an output
 }
 
//Function is a Loop, therefore will continue cycling through the functions
void loop(){
  int buttonPressed = digitalRead(START_BUTTON); //Variable created to detect when the button is pressed
  
  //We don’t care about detecting the button’s rising versus falling edge, so we just set it to LOW.
  if(buttonPressed == LOW){
    counter ++; //When buttonPressed==LOW, counter==1, which begins our statements to begin reading photocell values
  }
  //Read Sensor Values
  int leftLightLevel = analogRead(leftSensorPin); //Reading the light level coming through the left sensor
  int rightLightLevel = analogRead(rightSensorPin); //Reading the light level coming through the right sensor
  
  //If left light sensor is greater than threshold then turn left LED on, else turn left LED off
  if (leftLightLevel > lightThreshold && counter > 0){ // If left light sensor is greater than threshold, AND counter is greater than 0, the left DC motor will turn the wheel
    digitalWrite(leftLedPin, HIGH);
  }  
  //When the left light sensor is less than the light threshold, the motor will not turn, AND our buzzer will sound  
  else{
    digitalWrite(leftLedPin, LOW);
    tone(BUZZER, 1000, 150); //This is the command to play the buzzer when the car turns to the right. It will play at 1000 Hz and for .15 seconds
  }
  //If right light sensor is greater than threshold, AND counter is greater than 0, the rightDC motor will turn the wheel
  if (rightLightLevel > lightThreshold && counter > 0) 
    digitalWrite(rightLedPin, HIGH);
 
  //When the right light sensor is less than the light threshold, the motor will not turn, AND our buzzer will sound
  else{
    digitalWrite(rightLedPin, LOW);
    tone(BUZZER, 2000, 150); //This is the command to play the buzzer when the car turns to the left. It will play at 2000 Hz and for .15 seconds
  }
  } //End bracket for out Loop function
