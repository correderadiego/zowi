//--------------------------------------------------------------
//-- Oscillator.pde
//-- Generate sinusoidal oscillations in the servos
//--------------------------------------------------------------
//-- (c) Juan Gonzalez-Gomez (Obijuan), Dec 2011
//-- GPL license
//--------------------------------------------------------------
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif
#include "Oscillator.h"
#include <Servo.h>

Oscillator::Oscillator(int calibrationOffset=0) {
	this->calibrationOffset = calibrationOffset;
}

void Oscillator::initOscillator(
		unsigned int offset,
		unsigned int amplitude,
		unsigned int period,
		double phase){
	this->offset 	= offset;
	this->amplitude = amplitude;
	this->period 	= period;
	this->phase 	= phase;
}

void Oscillator::setAmplitude(unsigned int amplitude) {
	this->amplitude=amplitude;
}

void Oscillator::setOffset(unsigned int offset) {
	this->offset=offset;
};

void Oscillator::setPhase(double phase){
  this->phase = phase;
}

void Oscillator::setPeriod(unsigned int period){
  this->period=period;
  calculateOscillatorParameters(this->period, this->samplingPeriod);
};

void Oscillator::setCalibrationOffset(int calibrationOffset){
	this->calibrationOffset=calibrationOffset;
};

int Oscillator::getCalibrationOffset(){
	return calibrationOffset;
}

void Oscillator::setPosition(int position){
  servo.write(position+calibrationOffset);
};

void Oscillator::attach(int pin, bool reverseMode){
	if(servo.attached()){
	  return;
	}

	servo.attach(pin);
	servo.write(SERVO_HOME_POSITION);

	initOscillatorParameters(reverseMode);
}

void Oscillator::detach(){
  if(!servo.attached()){
	  return;
  }
  servo.detach();
}

void Oscillator::initOscillatorParameters(bool reverseMode){
	this->samplingPeriod		= DEFAULT_SAMPLING_PERIOD;
	this->period				= DEFAULT_PERIOD;
	this->amplitude				= DEFAULT_AMPLITUDE;
	this->previousMillis		= 0;
	this->currentPhase			= 0;
	this->phase					= 0;
	this->offset				= 0;
	this->oscillatorState		= enabled;

	this->reverseMode = reverseMode;
	calculateOscillatorParameters(period, samplingPeriod);
}

void Oscillator::reset(){
	this->currentPhase = 0;
}

void Oscillator::disableOscillator(){
	oscillatorState = disabled;
}

void Oscillator::enableOscillator(){
	oscillatorState = enabled;
}

bool Oscillator::isNextSampleAvailable(){
  currentMillis = millis();

  if(currentMillis - previousMillis > samplingPeriod) {
    previousMillis = currentMillis;
    return true;
  }

  return false;
}

void Oscillator::calculateOscillatorParameters(unsigned int period, unsigned int samplingPeriod){
	numberOfSamples 	= period/samplingPeriod;
	incrementOfPhase 	= 2*M_PI/numberOfSamples;
}

void Oscillator::refresh(){
	if(!isNextSampleAvailable()) {
		return;
	}

	currentPhase = currentPhase + incrementOfPhase;
	if(oscillatorState == disabled){
		return;
	}

	currentServoPosition = round(amplitude * sin(currentPhase + phase) + offset);
	if (reverseMode) {
		currentServoPosition=-currentServoPosition;
	}
	servo.write(currentServoPosition + SERVO_HOME_POSITION + calibrationOffset);

}
