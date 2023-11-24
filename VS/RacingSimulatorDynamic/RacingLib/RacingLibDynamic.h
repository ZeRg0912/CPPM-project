#pragma once
#include "Race/RaceAirGround.h"
#include "Race/RaceAir.h"
#include "Race/RaceGround.h"
#include <iostream>

#ifdef RACING_LIBRARY_EXPORTS
#define RACING_LIBRARY_API __declspec(dllexport)
#else 
#define RACING_LIBRARY_API __declspec(dllimport)
#endif

RACING_LIBRARY_API int setDistance();

class RACING_LIBRARY_API Race {
public:
	void begin();
	void printMenuTable();
	void doRestart(Race& race);
};
