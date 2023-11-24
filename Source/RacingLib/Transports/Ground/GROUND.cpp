#include "GROUND.h"

GROUND::GROUND() {
	this->speed = 1;
	this->timeToRest = 0;
	this->restTime = 0;
}

float GROUND::raceTime(float _distance) {
	return distanceTime = _distance / speed;
};