#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class TRANSPORT {
protected:
	std::string name = "Транспорт";
	int speed = 1;
	int timeToRest = 0;
	int restTime = 0;
	float distanceReduction = 0;
	float distanceTime = 0;

public:
	std::string getName();
	int getSpeed();
	int getTimeToRest();
	int getRestTime();
	int getDistanceReduction();
	float getDistanceTime();

	virtual float raceTime(float _distance);
};