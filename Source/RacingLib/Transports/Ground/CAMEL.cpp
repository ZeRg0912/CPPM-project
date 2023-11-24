#include "CAMEL.h"

CAMEL::CAMEL() : GROUND() {
	this->name = "Верблюд";
	this->speed = 10;
	this->timeToRest = 30;
	this->restTime = 5;
};

float CAMEL::raceTime(float _distance) {
	float time = 0;
	float rest = 0;
	float stops = (_distance / speed) / timeToRest;
	if (static_cast<int>(stops) == stops) stops -= 1;
	stops = static_cast<int>(stops);
	do {			
		if (stops > 1) {
			rest += restTime + 3;
			stops--;
		}
		else if (stops == 1) {
			rest += restTime;
			stops--;
		}
	} while (stops != 0);
	float move = _distance / speed;
	time = rest + move;
	this->distanceTime = time;
	return time;
};