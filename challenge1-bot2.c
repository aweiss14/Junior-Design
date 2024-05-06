// CHAL 1 BOT 2


int motor_2_forward = 11; // motor 1 backward
int motor_1_backward = 10;
int motor_2_backward = 5;
int motor_1_forward = 6;


int green_led = 13;
int yellow_led = 12;
int blue_led = 7;
int red_led = 8;


int headlight_pin = 2;
int brakelight_pin = 1;
int rightturn_pin = 4;
int leftturn_pin = 0;
int beeper_pin = 3;


bool collision = false;
int color = 0;
bool turndir = true;
int counter = 0;


void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor_1_backward, OUTPUT);
pinMode(motor_1_forward, OUTPUT);
pinMode(motor_2_backward, OUTPUT);
pinMode(motor_2_forward, OUTPUT);




pinMode(green_led, OUTPUT);
pinMode(yellow_led, OUTPUT);
pinMode(blue_led, OUTPUT);
pinMode(red_led, OUTPUT);




pinMode(headlight_pin, OUTPUT);
pinMode(brakelight_pin, OUTPUT);
pinMode(rightturn_pin, OUTPUT);
pinMode(leftturn_pin, OUTPUT);


}




void loop() {
//DIAGNOSTIC
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(blue_led, HIGH);
digitalWrite(red_led, LOW);
delay(250);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);


//FIRST WALL COLLISION
while(collision == false){
forward();
detectCollision();
}


while(collision == true){
stop();

delay(1000);
pivot();
delay(1800);
forward();
delay(2000);
while(color != 2) {
forward();
delay(100);
both_colors();
if (color == 2) {
stop();
digitalWrite(blue_led, HIGH);
delay(100);
forward();
delay(900);
pivotright();
delay(500);
collision = false;
}
}
}
// HITS blue PATH
stop();
//Send Server Message
digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, HIGH);
beep();
delay(250);
digitalWrite(headlight_pin, LOW);
digitalWrite(brakelight_pin, LOW);
delay(250);
digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, HIGH);
beep();
delay(250);
digitalWrite(headlight_pin, LOW);
digitalWrite(brakelight_pin, LOW);


// both_colors();
// // DETECT blue
// if (color == 2 ) {
// leftpivot();
// delay(120);
// detectCollision();
// }
// //DETECT BLACK
// else if (color == 3) {
// pivotright();
// detectCollision();
// delay(35);
// }


while (collision == false) {
both_colors();
// DETECT blue
if (color == 2 ) {
leftpivot();
delay(120);
detectCollision();
}
//DETECT BLACK
else if (color == 3) {
pivotright();
detectCollision();
delay(35);
}
}


//AFTER SECOND WALL Collision
stop();
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
delay(250);
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
delay(250);


//Send Server Message
//Recieve Message


digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
delay(250);
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
delay(250);
digitalWrite(blue_led, HIGH);
delay(250);
digitalWrite(blue_led, LOW);
delay(250);




digitalWrite(green_led, HIGH);
backward();
delay(250);


pivotright();
delay(950);
collision = false;




while (collision == false){
forward();
both_colors();
// IF COLOR IS yellow
if(color == 2){
beep();
delay(200);
beep();
digitalWrite(green_led, LOW);
digitalWrite(yellow_led, HIGH);
forward();
delay(900);
pivotright();
delay(1000);
collision = true;
}
}
collision = false;


while (collision == false) {
both_colors();
// DETECT blue
if (color == 4 ) {
leftpivot();
delay(100);
detectCollision();
}
// DETECT BLACK
else if (color == 3) {
pivotright();
detectCollision();
delay(35);
}
}


// LAST WALL DETECTION
while(collision == true){
//Server to BOT 2 to Continue
stop();
delay(1000);
pivotright();
delay(1000);
forward();
delay(1500);
stop();
delay(10000000000);
collision = false;
}
//WAIT FOR POST FROM BOT 2






}




void stop() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);


digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);

digitalWrite(headlight_pin, LOW); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(brakelight_pin, HIGH);
digitalWrite(rightturn_pin, LOW);
digitalWrite(leftturn_pin, LOW);

}




void forward() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low //Right MOTOR
analogWrite(motor_2_backward, 190);

digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW //LEFT MOTOR
analogWrite(motor_1_backward, 180);


digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, LOW);
digitalWrite(rightturn_pin, LOW);
digitalWrite(leftturn_pin, LOW);

}




void detectCollision() {
int sensorValue = analogRead(A4);
Serial.println(sensorValue);
if (sensorValue > 386) {
Serial.println("Collision Detected");
collision = true;
}
}




int colors(int sensorValue){




//int color;



if((sensorValue > 65) && (sensorValue < 90)){
    //red
    color = 1;
  } else if((sensorValue > 35) && (sensorValue < 60)){
    //blue
    color = 2;
  } else if((sensorValue > 10) && (sensorValue < 33)){
    //black
    color = 3;
  } else if((sensorValue > 90) && (sensorValue < 150)){
    //yellow
    color = 4;
  }
// 35/36 red
// 6/7 black
// 17/18 blue
// 47/47 yellow




// red = 13/14
// yellow = 29
// blue = 7/8/9
// black = 1/2








if(color == 1){
Serial.println("red");
} else if(color == 2){
Serial.println("blue");
} else if(color == 3){
Serial.println("black");
} else if(color == 4){
Serial.println("yellow");
}




Serial.println(sensorValue);




return color;
}








int both_colors(){




int sensorValue = analogRead(A1);
int color_value;
//digitalWrite(red_led, HIGH);
//digitalWrite(blue_led,HIGH);
color_value = colors(sensorValue);




return color_value;




}










void pivot() {
digitalWrite(motor_2_forward, HIGH);
analogWrite(motor_2_backward, 120);


analogWrite(motor_1_forward, 120); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);

digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, LOW);
digitalWrite(rightturn_pin, LOW);
digitalWrite(leftturn_pin, LOW);

}




void leftpivot(){
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);
analogWrite(motor_2_backward, 130);

digitalWrite(leftturn_pin, HIGH);
digitalWrite(rightturn_pin, LOW);

digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, LOW);

}




void pivotright(){
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);


digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
analogWrite(motor_1_backward, 110);

digitalWrite(rightturn_pin, HIGH);
digitalWrite(leftturn_pin, LOW);

digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, LOW);

}








void turning(){
if (turndir == false){
leftpivot();
turndir = true;
}
else{
pivotright();
turndir = false;
}
}




void beep() {


for (int i = 0; i < 200; i++){
digitalWrite(beeper_pin, HIGH);
delayMicroseconds(500);
digitalWrite(beeper_pin, LOW);
delayMicroseconds(500);
}


}


void backward() {
digitalWrite(motor_2_forward, LOW); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);


digitalWrite(motor_1_forward, LOW); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);


digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, HIGH);
digitalWrite(rightturn_pin, LOW);
digitalWrite(leftturn_pin, LOW);

}

