// ServoMotor - Version: Latest 
#include <ServoMotor.h>

#include <Servo.h>

Servo FrontLeft;
Servo FrontRight;
Servo BackLeft;
Servo BackRight;

char command = 'N';  // Initialize to 'N' (Idle) command

void IdleFunction() {
    FrontLeft.write(90);    // Adjust these values as needed
    FrontRight.write(90);   // Adjust these values as needed
    BackLeft.write(90);     // Adjust these values as needed
    BackRight.write(90);    // Adjust these values as needed

    Serial.println("Drone is idle");
    delay(10);
}

void ForwardFunction() {
    FrontLeft.write(180);   // Adjust these values as needed
    FrontRight.write(0);    // Adjust these values as needed
    BackLeft.write(180);    // Adjust these values as needed
    BackRight.write(0);     // Adjust these values as needed

    Serial.println("Drone is moving Forward");
    delay(10);
}

void BackwardFunction() {
    FrontLeft.write(0);     // Adjust these values as needed
    FrontRight.write(180);  // Adjust these values as needed
    BackLeft.write(0);      // Adjust these values as needed
    BackRight.write(180);   // Adjust these values as needed

    Serial.println("Drone is moving Backward");
    delay(10);
}

void setup() {
    Serial.begin(9600);

    FrontLeft.attach(9);
    FrontRight.attach(10);
    BackLeft.attach(11);
    BackRight.attach(12);

    Serial.println("Drone Has Started");

    // Drone at idle
    IdleFunction();
}

void loop() {
    if (Serial.available() > 0) {
        command = Serial.read();
    }

    if (command == 'W') {
        ForwardFunction();
    } else if (command == 'N') {
        IdleFunction();
    } else if (command == 'S') {
        BackwardFunction();
    }
}
