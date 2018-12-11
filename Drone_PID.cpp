/*
 * Drone_PID.h - PID Library
 * TODO description
 * Created by Michael Lazernik and Dillon Haughton
 * MIT License
 */

#include "Drone_PID.h"

PID::PID(double kp, double ki, double kd, double minIn, double maxIn) {
	KP = kp;
	KI = ki;
	KD = kd;
	previousTime = -1.0;
	inputMax = maxIn;
	inputMin = minIn;
	saturated = false;
}

double PID::run(double input, double sp, double minOut, double maxOut) {
	double dt, p, i, d, pid, error;
	double cIn = ( (input - inputMin) / (inputMax - inputMin) ) * 100;
	double time = millis();

	setPoint = ((sp - inputMin) / (inputMax - inputMin)) * 100.0;

	if (previousTime == -1.0) {
		dt = 0.0;
	}
	else {
		dt = time - previousTime;
	}

	error = setPoint - cIn;

	p = error * KP;

	if (dt == 0.0) {
		d = 0.0;
		errorAccum = 0.0;
	}
	else {
		d = (-1.0 * ((cIn - previousInput)/dt)) * KD;
		if (!saturated) {
			errorAccum = ( ( (error + previousError) / 2.0 ) * dt) + (0.9 * errorAccum);
		}
	}

	i = errorAccum * KI;

	pid = p + i + d;

	if (pid > maxOut) {
		saturated = true;
		pid = maxOut;
	}
	else if (pid < minOut) {
		saturated = true;
		pid = minOut;
	}
	else {
		saturated = false;
	}

	previousInput = cIn;
	previousError = error;
	previousTime = time;

	return pid;
}

void PID::reset() {
	PID(KP, KI, KD, inputMin, inputMax);
}
