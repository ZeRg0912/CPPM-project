#pragma once
#include "RaceTypes.h"

#ifndef STATIC
	#ifdef RaceLib_EXPORTS
	#define RaceLib_API __declspec(dllexport)
	#else
	#define RaceLib_API __declspec(dllimport)
	#endif
	class RaceLib_API GameManager {
	public:
		void begin();
		void printMenuTable();
		void doRestart(GameManager& game);
		int setDistance();
	};
#else
	class GameManager {
	public:
		void begin();
		void printMenuTable();
		void doRestart(GameManager& game);
		int setDistance();
	};
#endif

