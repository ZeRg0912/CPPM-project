#pragma once
#include "../TRANSPORT.h"

class AIR : public TRANSPORT {
public:
	AIR();
	float raceTime(float _distance) override;
};