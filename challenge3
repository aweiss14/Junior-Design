// Challenge 3: Novel Behavior
// The swarmbot must show novel functionality to enhance the behavior of the  bot, or swarmbot community.
// Novel behavior: The swarmbot communicates among itself and the need  for human understanding of the bot must
// be performed with audio or visual indicators. 
// This allows for the vehicles to act like vehicles that humans are used to using for  transportation.
// Your team must ideate, conceptualize, design, build, test, and demonstrate  functionality to enhance
//  the human interaction behavior of the bot, and swarmbot  community.
// You will be graded on the practicality of your idea, its implementation, the  least number of
// electronic parts and software required to implement.
// The expectation is  set for an average team to successfully implement three functional subsystems.
// The  number of novel subsystems cannot exceed five.


int counter = 0;
int headlight_pin = 2;
int brakelight_pin = 1;
int rightturn_pin = 4;
int leftturn_pin = 0;




bool headlight = false;
bool brakelight = false;
bool rightturn = false;
bool leftturn = false;
bool ambient = false;
bool colorsensor = false;
bool collisiondetect = false;




int LED_ON = 3;
int readSensor = A0;
int sensor_Avg = 0;




int color(int sensorValue);
int both_colors();








void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(headlight_pin, OUTPUT);
pinMode(brakelight_pin, OUTPUT);
pinMode(rightturn_pin, OUTPUT);
pinMode(leftturn_pin, OUTPUT);
pinMode(LED_ON, OUTPUT);
pinMode(readSensor, INPUT);
}




void loop() {
// put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
// TEST 1: BEEP WHEN TURN ON
  beep();
  digitalWrite(9, LOW);
  delay(450);
  beep();
  digitalWrite(9, LOW);
  delay(450);




delay(1000);




// TEST 2: HEADLIGHTS ON
headlight = true;
// if car is moving:
if (headlight == true) {
  digitalWrite(headlight_pin, HIGH);
  delay(2000);
  digitalWrite(headlight_pin, LOW);
}
headlight = false;
delay(1000);




// TEST 3: BRAKELIGHTS ON
// if car is not moving, set headlight to false OR set brakelight to true
brakelight = true;
if ((headlight == false) or (brakelight == true)) {
  digitalWrite(brakelight_pin, HIGH);
  delay(2000);
  digitalWrite(brakelight_pin, LOW);
}
brakelight = false;
delay(1000);




// TEST 4: RIGHT TURN ON
rightturn = true;
if (rightturn == true) {
  digitalWrite(rightturn_pin, HIGH);
  delay(2000);
  digitalWrite(rightturn_pin, LOW);
}
rightturn = false;
delay(1000);




// TEST 5: LEFT TURN ON
leftturn = true;
if (leftturn == true) {
  digitalWrite(leftturn_pin, HIGH);
  delay(2000);
  digitalWrite(leftturn_pin, LOW);
}
leftturn = false;
delay(1000);




delay(10000);
}


void beep() {


 for (int i = 0; i < 200; i++){
   digitalWrite(9, HIGH);
   delayMicroseconds(500);
   digitalWrite(9, LOW);
   delayMicroseconds(500);
 }


}

