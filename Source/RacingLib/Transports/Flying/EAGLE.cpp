#include "EAGLE.h"

EAGLE::EAGLE() : AIR() {
	this->name = "Îð¸ë";
	this->speed = 8;
	this->distanceReduction = 0.94;
};

float EAGLE::raceTime(float _distance) {
	float time = 0;
	float move = _distance / speed;
	time = move * distanceReduction;
	this->distanceTime = time;
	return time;
};