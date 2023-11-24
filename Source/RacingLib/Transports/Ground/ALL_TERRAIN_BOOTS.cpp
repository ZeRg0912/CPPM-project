#include "ALL_TERRAIN_BOOTS.h"

BOOTS::BOOTS() : GROUND() {
	this->name = "Ботинки-вездеходы";
	this->speed = 6;
	this->timeToRest = 60;
	this->restTime = 10;
};

float BOOTS::raceTime(float _distance) {
	float time = 0;
	float rest = 0;
	float stops = (_distance / speed) / timeToRest;
	if (static_cast<int>(stops) == stops) stops -= 1;
	stops = static_cast<int>(stops);
	do {
		if (stops > 1) {
			rest += restTime - 5;
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