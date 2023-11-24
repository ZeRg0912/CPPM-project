#pragma once
#include "../TRANSPORT.h"

class GROUND : public TRANSPORT {
public:
	GROUND();
	float raceTime(float _distance) override;
};