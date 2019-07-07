/*
 * RobotController.cpp
 *
 *  Created on: 29 jun. 2019
 *      Author: Diego Corredera
 */

#include "RobotController.h"

RobotController::RobotController() {
	configureRobot();
	home();
	nono();
}

void RobotController::executeMovement(CommunicationController::RobotMovementsEnum robotMovements){
	switch(robotMovements){
		case CommunicationController::movementWalk:
			walk(1,1200);
			break;

		case CommunicationController::movementBackward:
			backward();
			break;

		case CommunicationController::movementTurnR:
			turnR();
			break;

		case CommunicationController::movementTurnL:
			turnL();
			break;

		case CommunicationController::movementUpDown:
			upDown();
			break;

		case CommunicationController::movementPunchR:
			punchR();
			delay(300);
			break;

		case CommunicationController::movementPunchL:
			punchL();
			delay(300);
			break;

		case CommunicationController::movementAttack:
			attack();
			delay(300);
			break;

		case CommunicationController::movementQueNo:
			queno();
			break;

		case CommunicationController::movementNono:
			nono(1000);
			break;

		default:
			home();
			break;
	}
}

void RobotController::configureRobot(){
	attachServos();
	setCalibrationOffset();
}

void RobotController::attachServos(){
	osc[OSCILATOR_INDEX_ANKLE_RIGHT].attach(PIN_ANKLE_RIGHT);
	osc[OSCILATOR_INDEX_ANKLE_LEFT]	.attach(PIN_ANKLE_LEFT);
	osc[OSCILATOR_INDEX_HIP_RIGHT]	.attach(PIN_HIP_RIGHT);
	osc[OSCILATOR_INDEX_HIP_LEFT]	.attach(PIN_YAW_LEFT);
	osc[OSCILATOR_INDEX_SR]			.attach(PIN_SR);
	osc[OSCILATOR_INDEX_SL]			.attach(PIN_SL);
	osc[OSCILATOR_INDEX_AR]			.attach(PIN_AR);
	osc[OSCILATOR_INDEX_AL]			.attach(PIN_AL);
	osc[OSCILATOR_INDEX_HEAD]		.attach(PIN_HEAD);
}

void RobotController::setCalibrationOffset(){
	osc[OSCILATOR_INDEX_ANKLE_RIGHT].setCalibrationOffset(TRIM_RR);
	osc[OSCILATOR_INDEX_ANKLE_LEFT]	.setCalibrationOffset(TRIM_RL);
	osc[OSCILATOR_INDEX_HIP_RIGHT]	.setCalibrationOffset(TRIM_YR);
	osc[OSCILATOR_INDEX_HIP_LEFT]	.setCalibrationOffset(TRIM_YL);
	osc[OSCILATOR_INDEX_SR]			.setCalibrationOffset(TRIM_SR);
	osc[OSCILATOR_INDEX_SL]			.setCalibrationOffset(TRIM_SL);
	osc[OSCILATOR_INDEX_AR]			.setCalibrationOffset(TRIM_AR);
	osc[OSCILATOR_INDEX_AL]			.setCalibrationOffset(TRIM_AL);
	osc[OSCILATOR_INDEX_HEAD]		.setCalibrationOffset(TRIM_H);
}

void RobotController::oscillate(
								int amplitude[NUMBER_OF_OSCILLATORS],
								int offset[NUMBER_OF_OSCILLATORS],
								int period,
								double phase[NUMBER_OF_OSCILLATORS]
						  	  ){
	for (int i=0; i<NUMBER_OF_OSCILLATORS -1; i++) {
		osc[i].initOscillator(offset[i],amplitude[i], period, phase[i]);
	}
	double ref=millis();
	for (double x=ref; x<period+ref; x=millis()){
	 for (int i=0; i< NUMBER_OF_OSCILLATORS - 1; i++){
		osc[i].refresh();
	 }
	}
}

void RobotController::walk(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1]	 = {18, 18, 20, 20, 20, 20, 15, 15};
    int offset[NUMBER_OF_OSCILLATORS - 1] 		 = {0, 0, 0, 0, -60, 60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS -1]  = { DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90),
                             DEG2RAD(270), DEG2RAD(270), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++) oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::turnR(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {15, 15, 10, 30, 20, 20, 15, 15};
    int offset[NUMBER_OF_OSCILLATORS - 1] 	 	 = {0, 0, 0, 0, -60, 60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90),
                            DEG2RAD(270), DEG2RAD(270), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++) oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::turnL(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {15, 15, 30, 10, 20, 20, 15, 15};
    int offset[NUMBER_OF_OSCILLATORS - 1] 	 	 = {0, 0, 0, 0, -60, 60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(0), DEG2RAD(0), DEG2RAD(90), DEG2RAD(90),
                            DEG2RAD(270), DEG2RAD(270), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++) oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::backward(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {15, 15, 25, 25, 20, 20, 15, 15};
    int offset[NUMBER_OF_OSCILLATORS - 1] 	 	 = {0, 0, 0, 0, -60, 60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(180), DEG2RAD(180), DEG2RAD(90), DEG2RAD(90),
                            DEG2RAD(90), DEG2RAD(90), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++) oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::moonWalkR(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {25, 25, 0, 0, 0, 0, 10, 10};
    int offset[NUMBER_OF_OSCILLATORS - 1] 		 = {-15, 15, 0, 0, 60, -60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(0), DEG2RAD(180 + 120), DEG2RAD(90), DEG2RAD(90),
                            DEG2RAD(180), DEG2RAD(180), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++)oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::moonWalkL(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {25, 25, 0, 0, 0, 0, 20, 20};
    int offset[NUMBER_OF_OSCILLATORS - 1] 		 = {-15, 15, 0, 0, 60, -60, -30, 30};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(0), DEG2RAD(180 - 120), DEG2RAD(90), DEG2RAD(90),
                            DEG2RAD(0), DEG2RAD(0), DEG2RAD(0), DEG2RAD(0)};

    for(int i=0;i<steps;i++)oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::upDown(int steps, int period){
    int amplitude[NUMBER_OF_OSCILLATORS - 1] 	 = {25, 25, 0, 0, 0, 0, 35, 35};
    int offset[NUMBER_OF_OSCILLATORS - 1] 		 = {-25, 25, 0, 0, -60, 60, 0, 0};
    double phase_diff[NUMBER_OF_OSCILLATORS - 1] = {DEG2RAD(0), DEG2RAD(180), 0, 0,
                            0, 0, DEG2RAD(0), DEG2RAD(180)};

    for(int i=0;i<steps;i++)oscillate(amplitude,offset, period, phase_diff);
}

void RobotController::home(){
    osc[OSCILATOR_INDEX_ANKLE_RIGHT].setPosition(90);
    osc[OSCILATOR_INDEX_ANKLE_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_RIGHT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_SR]			.setPosition(10);
    osc[OSCILATOR_INDEX_SL]			.setPosition(170);
    osc[OSCILATOR_INDEX_AR]			.setPosition(50);
    osc[OSCILATOR_INDEX_AL]			.setPosition(130);
    osc[OSCILATOR_INDEX_HEAD]		.setPosition(90);
}

void RobotController::attack(){
    osc[OSCILATOR_INDEX_ANKLE_RIGHT].setPosition(90);
    osc[OSCILATOR_INDEX_ANKLE_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_RIGHT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_SR]			.setPosition(90);
    osc[OSCILATOR_INDEX_SL]			.setPosition(90);
    osc[OSCILATOR_INDEX_AR]			.setPosition(40);
    osc[OSCILATOR_INDEX_AL]			.setPosition(140);
}

void RobotController::punchL(){
    osc[OSCILATOR_INDEX_ANKLE_RIGHT].setPosition(40);
    osc[OSCILATOR_INDEX_ANKLE_LEFT]	.setPosition(70);
    osc[OSCILATOR_INDEX_HIP_RIGHT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_SR]			.setPosition(10);
    osc[OSCILATOR_INDEX_SL]			.setPosition(170);
    osc[OSCILATOR_INDEX_AR]			.setPosition(90);
    osc[OSCILATOR_INDEX_AL]			.setPosition(30);
}

void RobotController::punchR(){
    osc[OSCILATOR_INDEX_ANKLE_RIGHT].setPosition(110);
    osc[OSCILATOR_INDEX_ANKLE_LEFT]	.setPosition(140);
    osc[OSCILATOR_INDEX_HIP_RIGHT]	.setPosition(90);
    osc[OSCILATOR_INDEX_HIP_LEFT]	.setPosition(90);
    osc[OSCILATOR_INDEX_SR]			.setPosition(10);
    osc[OSCILATOR_INDEX_SL]			.setPosition(170);
    osc[OSCILATOR_INDEX_AR]			.setPosition(150);
    osc[OSCILATOR_INDEX_AL]			.setPosition(90);
}

void RobotController::nono(int period){
    home();
    int steps = 4;
    osc[OSCILATOR_INDEX_HEAD].initOscillator(0,30, period, 0);

    double ref = millis();
    for (double x=ref; x<steps*period+ref; x=millis()){
        osc[OSCILATOR_INDEX_HEAD].refresh();
    }
    osc[OSCILATOR_INDEX_HEAD].setPosition(90);
}

void RobotController::queno(int period){
    home();
    int steps = 4;
    osc[OSCILATOR_INDEX_HEAD].initOscillator(0,30, period*2, 0);
    osc[OSCILATOR_INDEX_AR].initOscillator	(0,30, period, 0);
    osc[OSCILATOR_INDEX_AL].initOscillator	(0,30, period, DEG2RAD(180));

    double ref = millis();
    for (double x=ref; x<steps*period+ref; x=millis()){
        osc[OSCILATOR_INDEX_AR].refresh();
        osc[OSCILATOR_INDEX_AL].refresh();
        osc[OSCILATOR_INDEX_HEAD].refresh();
    }
    osc[OSCILATOR_INDEX_AR]		.setPosition(50);
    osc[OSCILATOR_INDEX_AL]		.setPosition(130);
    osc[OSCILATOR_INDEX_HEAD]	.setPosition(90);
}
