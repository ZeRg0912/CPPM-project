#pragma once
#include "AIR.h"

class BROOMSTICK : public AIR {
public:
	BROOMSTICK();
	float raceTime(float _distance) override;
};