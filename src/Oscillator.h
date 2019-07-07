//--------------------------------------------------------------
//-- Oscillator.pde
//-- Generate sinusoidal oscillations in the servos
//--------------------------------------------------------------
//-- (c) Juan Gonzalez-Gomez (Obijuan), Dec 2011
//-- GPL license
//--------------------------------------------------------------
#ifndef Oscillator_h
#define Oscillator_h

#include <Servo.h>
#include <Arduino.h>

#define SERVO_HOME_POSITION 	90
#define DEFAULT_SAMPLING_PERIOD 30;
#define DEFAULT_PERIOD 			2000;
#define DEFAULT_AMPLITUDE		45;

#ifndef DEG2RAD
  #define DEG2RAD(g) ((g)*M_PI)/180
#endif

class Oscillator{
  public:
    Oscillator(int trim=0);
    void initOscillator(unsigned int offset,unsigned int amplitude,unsigned int period,double phase);
    void setAmplitude(unsigned int amplitude);
    void setOffset(unsigned int offset);
    void setPhase(double phase);
    void setPeriod(unsigned int period);
    void setCalibrationOffset(int calibrationOffset);
    int getCalibrationOffset();
    void setPosition(int position);

    void attach(int pin, bool rev =false);
    void detach();

    void reset();

    void disableOscillator();
    void enableOscillator();

    void refresh();
    
  private:
    enum OscillatorStateEnum{
    	enabled,
		disabled
    };

    Servo servo;
    void initOscillatorParameters(bool reverseMode);
    void calculateOscillatorParameters(unsigned int period, unsigned int samplingPeriod);
    bool isNextSampleAvailable();

    //-- Oscillators parameters
    unsigned int amplitude;  	//-- Amplitude (degrees)
    unsigned int offset;  		//-- Offset (degrees)
    unsigned int period;  		//-- Period (miliseconds)
    double phase;   			//-- Phase (radians)
    
    //-- Internal variables
    int currentServoPosition;   //-- Current servo pos
    int calibrationOffset;      //-- Calibration offset
    double currentPhase;    	//-- Current phase
    double incrementOfPhase;    //-- Increment of phase
    double numberOfSamples;     //-- Number of samples
    unsigned int samplingPeriod; //-- sampling period (ms)
    
    long previousMillis = 0;
    long currentMillis  = millis();
    bool reverseMode;
    
    OscillatorStateEnum oscillatorState = enabled;
};

#endif
