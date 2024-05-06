
#include <SPI.h>
#include <WiFiNINA.h>
#include <ArduinoSTL.h>
using namespace std;

// WiFi Credentials and Server
char ssid[] = "junior";
char pass[] = "designdesign";
char server[] = "ee31.ece.tufts.edu";  // Server address

String our_id = "828BD9E1B7C7";
String companion_team_id = "F392FC86D8D7";

String getRoute = "GET /" + our_id + "/" + companion_team_id + " HTTP/1.1";
String postRoute = "POST /" + companion_team_id + "/" + our_id + " HTTP/1.1";

WiFiClient client;

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
int beeper_pin = 9;


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

connectToWiFi();

}




void loop() {

if (!client.connected()) {
  reconnectToServer();
}
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
forward();
delay(4500);

//FIRST WALL COLLISION
while(collision == false){
forward();
detectCollision();
}


while(collision == true){
stop();
delay(1150);
pivot();
delay(1250);
forward();
delay(1000);
while(color != 1) {
forward();
delay(100);
both_colors();
if (color == 1) {
stop();
digitalWrite(red_led, HIGH);
delay(100);
forward();
delay(400);
leftpivot();
delay(1000);
collision = false;
}
}
}
// HITS RED PATH
stop();
//Send Server Message
POST(postRoute, "you_can_go_from_1");
digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, HIGH);
while (GET(getRoute) != "you_can_go_from_2") {

    stop();
    delay(500);

  }
beep();
digitalWrite(9, LOW);
delay(450);
beep();
digitalWrite(9, LOW);
delay(450);
delay(1000);
digitalWrite(headlight_pin, LOW);
digitalWrite(brakelight_pin, LOW);
delay(250);
digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, HIGH);
beep();
digitalWrite(9, LOW);
delay(450);
beep();
digitalWrite(9, LOW);
delay(450);
digitalWrite(beeper_pin, LOW);
delay(250);
digitalWrite(headlight_pin, LOW);
digitalWrite(brakelight_pin, LOW);


while (collision == false) {
both_colors();
// DETECT YELLOW
if (color == 1 ) {
leftpivot();
delay(100);
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
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
delay(250);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
delay(250);


//Send Server Message
//Recieve Message


digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
delay(250);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
delay(250);
digitalWrite(red_led, HIGH);
delay(250);
digitalWrite(red_led, LOW);
delay(250);




digitalWrite(green_led, HIGH);
backward();
delay(250);


leftpivot();
delay(1000);
collision = false;




while (collision == false){
forward();
both_colors();
// IF COLOR IS YELLOW
if(color == 4){
stop();
delay(250);
beep();
digitalWrite(9, LOW);
delay(450);
beep();
digitalWrite(9, LOW);
delay(450);
beep();
digitalWrite(9, LOW);
delay(450);
beep();
digitalWrite(9, LOW);
delay(450);
digitalWrite(beeper_pin, LOW);
digitalWrite(green_led, LOW);
digitalWrite(yellow_led, HIGH);
forward();
delay(500);
leftpivot();
delay(1000);
collision = true;
}
}
collision = false;


while (collision == false) {
both_colors();
// DETECT YELLOW
if (color == 4 ) {
leftpivot();
delay(120);
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
backward();
delay(250);
leftpivot();
delay(850);
forward();
delay(1000);
stop();
delay(10000000000);
collision = false;
}
//WAIT FOR POST FROM BOT 2

POST(postRoute, "bot_one_done!");




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
analogWrite(motor_2_backward, 200);






digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW //LEFT MOTOR
analogWrite(motor_1_backward, 187);


digitalWrite(headlight_pin, HIGH);
digitalWrite(brakelight_pin, LOW);
digitalWrite(rightturn_pin, LOW);
digitalWrite(leftturn_pin, LOW);




}




void detectCollision() {
int sensorValue = analogRead(A4);
Serial.println(sensorValue);
if (sensorValue > 398) {
Serial.println("Collision Detected");
collision = true;
}
}




int colors(int sensorValue){




//int color;




if((sensorValue > 90) && (sensorValue < 115)){
//red
color = 1;
} else if((sensorValue > 60) && (sensorValue < 80)){
//blue
color = 2;
} else if((sensorValue > 20) && (sensorValue < 50)){
//black
color = 3;
} else if((sensorValue > 120) && (sensorValue < 200)){
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
}




void leftpivot(){
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
digitalWrite(motor_1_backward, HIGH);
analogWrite(motor_2_backward, 130);
}




void pivotright(){
digitalWrite(motor_2_forward, HIGH); //motor 2 forward when motor_1_backward HIGH and motor_2_A low
digitalWrite(motor_2_backward, HIGH);








digitalWrite(motor_1_forward, HIGH); //motor 1 forward when motor_2_B HIGH and motor_1_forward LOW
analogWrite(motor_1_backward, 110);
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

void POST(String theRoute, String message) {

  message = "message=" + message;

  if (client.connect(server, 80)) {
    client.println(theRoute);
    client.print("Host: ");
    client.println(server);
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.print("Content-Length: ");
    int postBodyLength = message.length();
    client.println(postBodyLength);
    client.println();
    client.print(message);
  }

}

void readServerResponse() {
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  client.stop();  // Close the connection after reading the response
}

void printWiFiStatus() {
  IPAddress ip = WiFi.localIP();
  long rssi = WiFi.RSSI();
  Serial.print("SSID: "); Serial.println(WiFi.SSID());
  Serial.print("IP Address: "); Serial.println(ip);
  Serial.print("Signal strength (RSSI):"); Serial.print(rssi); Serial.println(" dBm");
}

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

String GET(String theRoute) {

  if (client.connect(server, 80)) {

    client.println(theRoute);

    client.print("Host: ");

    client.println(server);

    // client.println("Connection: close");

    client.println();

    // get the message from the server

    // place in appropriate form and variable

    // if the server's disconnected, stop the client:

    if (!client.connected()) {

      client.stop();

    }

    delay(500);

    String result = "";

    while (client.available()) {

      char message = client.read();

      result += message;

    }

    return process_message(result);

  }

}

 

String process_message(String message) {

  // Serial.println(message);

  int index = 0;

  int count_new_line = 0;

  while (index < message.length() and count_new_line < 3) {

    if (message[index] == '&') {

      count_new_line += 1;

    }

    index++;

  }

  index += 8;

  String output_string = "";

  while (index < message.length()) {

    output_string += message[index];

    index++;

  }

  return output_string;

}

 
