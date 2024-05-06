// Challenge 4: Night Conditions
// The swarmbot must perform in simulated night conditions (dark classroom or other space) without a collision.
// The swarmbot must drive at night (dim room lighting conditions) using only headlights (maximum two white LEDs) toward each other and avoid a collision.
// The test will be to place the bots at opposite ends of the longer dimension of the track (the yellow path).
// The two white diodes representing the headlights are allowed as sources of illumination for this challenge.
// A photodiode, phototransistor, or photo resistor is to be used as the detector.
// When the two bots become close enough to detect each other’s presence, they must stop, communicate,
// flash their headlights twice, and illuminate their rear yellow turn signals.








int motor_2_forward = 11; // motor 1 backward
int motor_1_backward = 10;
int motor_2_backward = 5;
int motor_1_forward = 6;
// int motor_enabler_1 = 3; // PWM pin (changed this)
// int motor_enabler_2 = 9;




int headlight_pin = 2;
int brakelight_pin = 1;
int rightturn_pin = 4;
int leftturn_pin = 0;




int LED_ON = 3;
int readSensor = A4;
int sensor_Avg = 0;




bool collision = false;








void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(motor_1_backward, OUTPUT);
pinMode(motor_1_forward, OUTPUT);
pinMode(motor_2_backward, OUTPUT);
pinMode(motor_2_forward, OUTPUT);
pinMode(7, OUTPUT);
//pinMode(motor_enabler_1, OUTPUT);
//pinMode(motor_enabler_2, OUTPUT);




pinMode(9, OUTPUT);
pinMode(headlight_pin, OUTPUT);
pinMode(brakelight_pin, OUTPUT);
pinMode(rightturn_pin, OUTPUT);
pinMode(leftturn_pin, OUTPUT);




pinMode(LED_ON, OUTPUT);
pinMode(readSensor, INPUT);
// pinMode(LED_ON, OUTPUT);
//pinMode(readSensor, INPUT);
}




void loop() {
// // put your main code here, to run repeatedly:
int sensorValue = analogRead(A4);
Serial.println(sensorValue);
detectCollision();


while (collision == true) {
stop();
delay(1000);
blueOn();
delay(1000);
headlightOn();
delay(250);
headlightOff();
delay(250);
headlightOn();
delay(250);
headlightOff();
delay(250);
turnsigOn();
delay(2000);
}
headlightOn();
forward();
delay(250);
detectCollision();
sensorRead();
if (sensor_Avg < 0) {
digitalWrite(LED_ON, HIGH);
delay(100);
digitalWrite(LED_ON, LOW);
delay(100);
} else {
digitalWrite(LED_ON, HIGH);
delay(100);
}


}




void stop() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);








digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);




}




void forward() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
analogWrite(motor_2_backward, 200);








digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
analogWrite(motor_1_backward, 190);




}




void detectCollision() {
int sensorValue = analogRead(A4);
if (sensorValue > 390) {
Serial.println("Collision Detected");
collision = true;
}
}




void headlightOn() {
digitalWrite(headlight_pin, HIGH);
}




void headlightOff() {
digitalWrite(headlight_pin, LOW);
}




void turnsigOn() {
digitalWrite(rightturn_pin, HIGH);
digitalWrite(leftturn_pin, HIGH);
}




void blueOn() {
digitalWrite(7, HIGH);
delay(400);
digitalWrite(7, LOW);
}




void sensorRead() {
for (int i = 0; i <10; i++) {
// readSensor = analogRead(A4);
sensor_Avg += readSensor;
delay(100);
}
sensor_Avg = sensor_Avg/10;
//Serial.println(sensor_Avg);
//delay(1000);
}


