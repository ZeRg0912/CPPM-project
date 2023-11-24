#include "CENTAUR.h"

CENTAUR::CENTAUR() : GROUND() {
	this->name = "Кентавр";
	this->speed = 15;
	this->timeToRest = 8;
	this->restTime = 2;
};

float CENTAUR::raceTime(float _distance) {
	float time = 0;
	float rest = 0;
	float stops = (_distance / speed) / timeToRest;
	if (static_cast<int>(stops) == stops) stops -= 1;
	stops = static_cast<int>(stops);
	do {
		rest += restTime;
		stops--;
	} while (stops != 0);
	float move = _distance / speed;
	time = rest + move;
	this->distanceTime = time;
	return time;
};