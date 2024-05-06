// Challenge 2: Precise Positioning
// This challenge requires the swarmbot to position itself, perform some  activity and movement, and then position itself at a particular location.
//For test purposes, the swarmbot must take instruction from its companion bot, to perform several  movements, then return to the spot from which it started.
//Detailed Description
// Precise positioning: The two bots communicate with each other sending  commands via the EE31 Server.
// A set of messages are utilized to have one of the bots  move forward twelve inches, stop, turn around 180°, stop, move backwards three inches,  stop, turn left,
// turn right, turn right, and turn right to end up as close as possible to the  bot’s starting position.
// The bots reverse rolls. The second bot is sent messages to perform  the same test.
// The duration of this test is ninety-seconds.
// Each bot has a designated mark  on its exterior surface.
// At the start, the two bots have their marks lined up with each  other.
// At the end of the challenge, the objective is to have the marks line up.
// The distance  between the marks will be measured; the closer they are to each other the once again.
//  The closer the two lines are to each other the better the evaluation score.
// The objective  is to make the difference in distance as close to zero as possible.

#include <SPI.h>
#include <WiFiNINA.h>
#include <ArduinoSTL.h>
//#include "arduino_secrets.h"


// Pin Definitions
int motor_2_forward = 11; // motor 1 backward
int motor_1_backward = 10;
int motor_2_backward = 5;
int motor_1_forward = 6;
// int motor_enabler_1 = 3; // PWM pin (changed this)
// int motor_enabler_2 = 9;      // PWM pins for motor speed control


// WiFi Credentials and Server
char ssid[] = "junior";
char pass[] = "designdesign";
char server[] = "ee31.ece.tufts.edu";  // Server address


WiFiClient client;


void setup() {
 Serial.begin(9600);
 // initializeMotors();
 pinMode(motor_1_backward, OUTPUT);
 pinMode(motor_1_forward, OUTPUT);
 pinMode(motor_2_backward, OUTPUT);
 pinMode(motor_2_forward, OUTPUT);
 connectToWiFi();
}


void loop() {
 if (!client.connected()) {
   reconnectToServer();
 }
 handleServerCommunication();
}


// void initializeMotors() {
//   for (int pin : motorPins) {
//     pinMode(pin, OUTPUT);
//   }
// }


void connectToWiFi() {
 while (WiFi.status() != WL_NO_MODULE && WiFi.status() != WL_CONNECTED) {
   Serial.print("Connecting to WiFi.. ");
   if (WiFi.begin(ssid, pass) == WL_CONNECTED) {
     printWiFiStatus();
     break;
   }
   delay(5000);  // Retry every 5 seconds
 }
}


void reconnectToServer() {
 if (client.connect(server, 80)) {
   Serial.println("Connected to server.");
 }
}


void handleServerCommunication() {
 if (client.available()) {
   readServerResponse();
 } else {
   sendGETRequest("/828BD9E1B7C7/828BD9E1B7C7 HTTP/1.1");
   moveBot();
   sendPOSTRequest("/828BD9E1B7C7/828BD9E1B7C7 HTTP/1.1", "variable1=value1&variable2=value2");
 }
}


void sendGETRequest(const char* route) {
 if (client.connect(server, 80)) {
   client.println("GET " + String(route));
   client.println("Host: " + String(server));
   client.println("Connection: close");
   client.println();
   client.flush();
 }
}


void sendPOSTRequest(const char* route, const char* payload) {
 if (client.connect(server, 80)) {
   client.println("POST " + String(route));
   client.println("Host: " + String(server));
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.println("Content-Length: " + String(strlen(payload)));
   client.println();
   client.print(payload);
   client.flush();
 }
}


void readServerResponse() {
 while (client.available()) {
   char c = client.read();
   Serial.write(c);
 }
 client.stop();  // Close the connection after reading the response
}


void moveBot() {
 // Function to move the bot as per the instructions
 forward();
 delay(1550);
 stop();
 delay(1000);
 pivot();
 delay(1300);
 stop();
 delay(1000);
 backward();
 delay(600);
 stop();
 delay(2000);
 leftpivot();
 delay(1000);
 stop();
 delay(2000);
 righttestpivot();
 delay(700);
 stop();
 delay(2000);
 righttestpivot();
 delay(700);
 stop();
 delay(2000);
 righttestpivot();
 delay(700);
 stop();
 delay(2000);
 backward();
 delay(1500);
 stop();
 delay(2000);
}


void printWiFiStatus() {
 IPAddress ip = WiFi.localIP();
 long rssi = WiFi.RSSI();
 Serial.print("SSID: "); Serial.println(WiFi.SSID());
 Serial.print("IP Address: "); Serial.println(ip);
 Serial.print("Signal strength (RSSI):"); Serial.print(rssi); Serial.println(" dBm");
}




void turn_left() {
 digitalWrite(motor_1_forward, HIGH);
 analogWrite(motor_1_backward, 150);


 digitalWrite(motor_2_forward, HIGH);
 analogWrite(motor_2_backward, 100);
}


void turn_right() {
 digitalWrite(motor_1_forward, HIGH);
 analogWrite(motor_1_backward, 100);


 digitalWrite(motor_2_forward, HIGH);
 analogWrite(motor_2_backward, 150);


}


void backward() {
digitalWrite(motor_2_forward, LOW); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
analogWrite(motor_2_backward, 80);




digitalWrite(motor_1_forward, LOW); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
analogWrite(motor_1_backward, 90);


}


void stop() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);




digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);


}


void forward() {
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
analogWrite(motor_2_backward, 180);




digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
analogWrite(motor_1_backward, 170);


}


void pivot() {
 digitalWrite(motor_2_forward, HIGH);
 analogWrite(motor_2_backward, 150);




 analogWrite(motor_1_forward, 150); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 digitalWrite(motor_1_backward, HIGH);
}


// left or right
void rightpivot(){
 //digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
 //digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 //digitalWrite(motor_1_backward, LOW);
 //analogWrite(motor_2_backward, 180);


 digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
 analogWrite(motor_2_backward, 215);




  digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 analogWrite(motor_1_backward, 100);
}


// left or right
void leftpivot(){
 digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
 digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 digitalWrite(motor_1_backward, HIGH);
 analogWrite(motor_2_backward, 150);
}


void righttestpivot(){
 //digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
 //digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 //digitalWrite(motor_1_backward, LOW);
 //analogWrite(motor_2_backward, 180);


 digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
 digitalWrite(motor_2_backward, HIGH);




  digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
 analogWrite(motor_1_backward, 80);
}


