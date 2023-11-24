#pragma once
#include "GROUND.h"

class CAMEL : public GROUND {
public:
	CAMEL();
	float raceTime(float _distance) override;
};