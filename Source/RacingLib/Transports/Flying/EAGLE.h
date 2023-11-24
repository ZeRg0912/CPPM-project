#pragma once
#include "AIR.h"

class EAGLE : public AIR {
public:
	EAGLE();
	float raceTime(float _distance) override;
};