#include "AIR.h"

AIR::AIR() {
	this->speed = 0;
	this->distanceReduction = 1;
}

float AIR::raceTime(float _distance) {
	return distanceTime = _distance / speed;
};