#include "TRANSPORT.h"

std::string TRANSPORT::getName() {
	return name;
}

int TRANSPORT::getSpeed() {
	return speed;
}

int TRANSPORT::getTimeToRest() {
	return timeToRest;
}

int TRANSPORT::getRestTime() {
	return restTime;
}

int TRANSPORT::getDistanceReduction() {
	return distanceReduction;
}

float TRANSPORT::raceTime(float _distance) {
	return distanceTime = _distance / speed;
}

float TRANSPORT::getDistanceTime() {
	return distanceTime;
}
