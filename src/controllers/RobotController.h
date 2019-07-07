/*
 * RobotController.h
 *
 *  Created on: 29 jun. 2019
 *      Author: Diego Corredera
 */

#ifndef SRC_ROBOTCONTROLLER_H_
#define SRC_ROBOTCONTROLLER_H_

#include "../definitions/Pins.h"
#include "Oscillator.h"
#include "CommunicationController.h"
#include "../definitions/TrimValues.h"
#include "../definitions/Definitions.h"

class RobotController {
public:
	RobotController();
	void executeMovement(CommunicationController::RobotMovementsEnum robotMovements);

private:
	Oscillator osc[NUMBER_OF_OSCILLATORS];
	void configureRobot();
	void attachServos();
	void setCalibrationOffset();
	void oscillate(
			int amplitude[NUMBER_OF_OSCILLATORS],
			int offset[NUMBER_OF_OSCILLATORS],
			int period,
			double phase_diff[NUMBER_OF_OSCILLATORS]
	);

	void run		(int steps=1, int period=500);
	void walk		(int steps=1, int period=1000);
	void backward	(int steps=1, int period=1000);
	void turnL		(int steps=1, int period=1000);
	void turnR		(int steps=1, int period=1000);
	void moonWalkL	(int steps=1, int period=1000);
	void moonWalkR	(int steps=1, int period=1000);
	void upDown		(int steps=1, int period=700);
	void home();
	void attack();
	void punchL();
	void punchR();
	void nono	(int period=1000);
	void queno	(int period=300);
};

#endif /* SRC_ROBOTCONTROLLER_H_ */
