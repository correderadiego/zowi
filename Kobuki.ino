#include <Arduino.h>
#include <Servo.h>
#include <Oscillator.h>
#include "../src/controllers/RobotController.h"
#include "../src/controllers/CommunicationController.h"

RobotController* robotController;
CommunicationController* communciationController;

void setup(){
    robotController = new RobotController();
    communciationController = new CommunicationController();
    delay(1000);
    communciationController->printValue("Starting kobuki software");
}

void loop(){
	robotController->executeMovement(communciationController->readInput());
}
