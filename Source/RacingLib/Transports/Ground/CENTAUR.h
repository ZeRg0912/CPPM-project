#pragma once
#include "GROUND.h"

class CENTAUR : public GROUND {
public:
	CENTAUR();
	float raceTime(float _distance) override;
};