/*
 * CommunicationController.cpp
 *
 *  Created on: 29 jun. 2019
 *      Author: Diego Corredera
 */

#include "CommunicationController.h"

CommunicationController::CommunicationController() {
	Serial.begin(COMMUNICATION_BAUDRATE);
}

void CommunicationController::printValue(String value){
	Serial.println(value);
}

CommunicationController::RobotMovementsEnum CommunicationController::readInput(){
	if(!Serial.available()){
		return movementHome;
	}

    input = "";
	while (Serial.available()) {
		input = Serial.read();
	}
	return parseInput(input);
}

CommunicationController::RobotMovementsEnum CommunicationController::parseInput(char input){
	Serial.println("Echo value " + (String)input);
	switch(input){
		case 'A':
			return movementWalk;
			break;

		case 'C':
			return movementBackward;
			break;

		case 'B':
			return movementTurnR;
			break;

		case 'D':
			return movementTurnL;
			break;

		case 'E':
			return movementUpDown;
			break;

		case 'F':
			return movementPunchR;
			break;

		case 'H':
			return movementPunchL;
			break;

		case 'G':
			return movementAttack;
			break;

		case 'I':
			return movementQueNo;
			break;

		case 'J':
			return movementNono;
			break;

		default:
			return movementHome;
			break;
	}
}
