/*
 * CommunicationController.h
 *
 *  Created on: 29 jun. 2019
 *      Author: Diego Corredera
 */

#ifndef SRC_COMMUNICATIONCONTROLLER_H_
#define SRC_COMMUNICATIONCONTROLLER_H_

#include <Arduino.h>
#include "../definitions/Pins.h"

#define COMMUNICATION_BAUDRATE 9600
class CommunicationController {
public:
	enum RobotMovementsEnum{
		noMovement,
		movementWalk,
		movementTurnR,
		movementTurnL,
		movementBackward,
		movementUpDown,
		movementPunchR,
		movementPunchL,
		movementAttack,
		movementNono,
		movementQueNo,
		movementHome
	};
	RobotMovementsEnum readInput();
	CommunicationController();
	void printValue(String value);
private:
	RobotMovementsEnum parseInput(char input);
	char input;
};

#endif /* SRC_COMMUNICATIONCONTROLLER_H_ */
