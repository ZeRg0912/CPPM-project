#pragma once
#include "AIR.h"

class MAGIC_CARPET : public AIR {
public:
	MAGIC_CARPET();
	float raceTime(float _distance) override;
};