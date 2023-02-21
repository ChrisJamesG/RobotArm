#include <Servo.h>

Servo myservo1;  // create servo object control a servo
Servo myservo2;  // create servo object control a servo
Servo myservo3;  // create servo object control a servo
Servo myservo4;  // create servo object control a servo

// twelve servo objects can be created on most boards

int pos1 = 30;  // variable store the servo position
int pos2 = 45;  // variable store the servo position
int pos3 = 120;  // variable store the servo position
int pos4 = 0;  // variable store the servo position

void setup() {
  Serial.begin(9600); // initialize serial communication
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  myservo1.attach(3);   // attaches the servo on pin 9 the servo object
  myservo2.attach(9);   // attaches the servo on pin 9 the servo object
  myservo3.attach(10);  // attaches the servo on pin 9 the servo object
  myservo4.attach(11);  // attaches the servo on pin 9 the servo object
}

void loop() {
  while (Serial.available()) {
    char input = Serial.read(); // read the incoming byte
    switch (input) {
      case '1': // servo signal for key 'a'
        pos2 += 1;
        myservo2.write(pos2); // move the servo 1 degrees
        break;
      case '2': // servo signal for key 'd'
        pos2 -= 1;
        myservo2.write(pos2); // move the servo 1 degrees
        break;
      case '3': // servo signal for key 'w'
        pos3 += 1;
        myservo3.write(pos3); // move the servo 1 degrees
        break;
      case '4': // servo signal for key 's'
        pos3 -= 1;
        myservo3.write(pos3); // move the servo 1 degrees
        break;
      case '5': // servo signal for key 'e'
        pos4 += 1;
        myservo4.write(pos4); // move the servo 1 degrees
        break;
      case '6': // servo signal for key 'q'
        pos4 -= 1;
        myservo4.write(pos4); // move the servo 1 degrees
        break;
      default:
        break;
    }
  }
}