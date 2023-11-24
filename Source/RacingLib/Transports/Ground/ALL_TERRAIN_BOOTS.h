#pragma once
#include "GROUND.h"

class BOOTS : public GROUND {
public:
	BOOTS();
	float raceTime(float _distance) override;
};