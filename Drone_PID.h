/*
 * Drone_PID.h - PID Library
 * TODO description
 * Created by Michael Lazernik and Dillon Haughton
 * MIT License
 */

#ifndef DFRduino_GPS_h
#define DFRduino_GPS_h

#include "Arduino.h"

class PID {
	public: 
		PID(double kp, double ki, double kd, double minIn, double maxIn);
		double run(double input, double sp, double minOut, double maxOut);
		void reset();
		double KP;
		double KI;
		double KD;
		double setPoint;
		double inputMax;
		double inputMin;
	private:
		double previousInput;
		double errorAccum;
		double previousError;
		double previousTime;
		boolean saturated;

};

#endif
