// Challenge 5: Precision Speed Test
// The swarmbot must perform a precision speed test  where it moves at 1.25 inches/section for 20 seconds in a straight line.
// The swarmbot  must perform this challenge on the test track.
// A ruler will measure the distance traveled in 20 seconds, and then divide this by 20 seconds to determine the average speed during  the challenge.
// The deviation from the acceptable average speed between 1 inch per  second and 1.5 inches per second to successfully pass the test.




int motor_2_forward = 11; // motor 1 backward
int motor_1_backward = 10;
int motor_2_backward = 5;
int motor_1_forward = 6;
int motor_enabler_1 = 3; // PWM pin (changed this)
int motor_enabler_2 = 9;


void setup() {
 // put your setup code here, to run once:


 Serial.begin(9600);
 pinMode(motor_1_backward, OUTPUT);
 pinMode(motor_1_forward, OUTPUT);
 pinMode(motor_2_backward, OUTPUT);
 pinMode(motor_2_forward, OUTPUT);


}


void loop() {
 // put your main code here, to run repeatedly:
 forward();
 //delay(20000);
 //stop();
 //delay(20000);
}




void forward() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
//digitalWrite(motor_2_backward, LOW);
analogWrite(motor_2_backward, 196);
digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
//digitalWrite(motor_1_backward, LOW);
digitalWrite(motor_1_backward, HIGH);
delay(1);
digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
//digitalWrite(motor_1_backward, LOW);
analogWrite(motor_1_backward, 194);
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
//digitalWrite(motor_2_backward, LOW);
digitalWrite(motor_2_backward, HIGH);
delay(1);
}


void stop() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);




digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);
}

