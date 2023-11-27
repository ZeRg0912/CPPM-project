#pragma once
#include <iostream>
#include <string>

enum class TransportType {
	Ground,
	Air,
};

class Transport {
public:
	virtual const char* getName() const = 0;
	virtual TransportType getType() const = 0;
	virtual double calcTimeRide(int distance) { return 1; };
	virtual bool getReg() { return false; }
	virtual void setReg() {};
};


// ÍÀÇÅÌÍÛÅ ÑĞÅÄÑÒÂÀ
class GroundTransport : public Transport {
public: 
	TransportType getType() const {
		return TransportType::Ground;
	}
};

// ÂÅĞÁËŞÄ
class Camel : public GroundTransport {
protected:
	int speed = 10;
	int timeToRest = 30;
	int restTime = 5;
	bool registred = false;

public:
	const char* getName() const {
		return "Âåğáëşä";
	}

	double calcTimeRide(int distance) override {
		double rest = 0;
		double stops = (distance / speed) / timeToRest;
		if (static_cast<int>(stops) == stops) stops -= 1;
		stops = static_cast<int>(stops);
		do {
			if (stops > 1) {
				rest += restTime + 3;
				stops--;
			}
			else if (stops == 1) {
				rest += restTime;
				stops--;
			}
		} while (stops != 0);
		double move = distance / speed;
		double time = rest + move;
		return time;
	}

	void setReg() { this->registred = true; }
};

// ÂÅĞÁËŞÄ - ÁÛÑÒĞÎÕÎÄ
class FastCamel : public GroundTransport {
protected:
	int speed = 40;
	int timeToRest = 10;
	int restTime = 5;
	bool registred = false;

public:
	const char* getName() const {
		return "Âåğáëşä - áûñòğîõîä";
	}

	double calcTimeRide(int distance) override {
		double rest = 0;
		double stops = (distance / speed) / timeToRest;
		if (static_cast<int>(stops) == stops) stops -= 1;
		stops = static_cast<int>(stops);
		do {
			if (stops > 2) {
				rest += restTime + 3;
				stops--;
			}
			else if (stops == 2) {
				rest += restTime + 1.5;
				stops--;
			}
			else if (stops == 1) {
				rest += restTime;
				stops--;
			}
		} while (stops != 0);
		double move = distance / speed;
		double time = rest + move;
		return time;
	}

	void setReg() override { this->registred = true; }
};

// ÊÅÍÒÀÂĞ
class Centaur : public GroundTransport {
protected:
	int speed = 15;
	int timeToRest = 8;
	int restTime = 2;
	bool registred = false;

public:
	const char* getName() const {
		return "Êåíòàâğ";
	}

	double calcTimeRide(int distance) override {
		double rest = 0;
		double stops = (distance / speed) / timeToRest;
		if (static_cast<int>(stops) == stops) stops -= 1;
		stops = static_cast<int>(stops);
		do {
			rest += restTime;
			stops--;
		} while (stops != 0);
		double move = distance / speed;
		double time = rest + move;
		return time;
	}

	void setReg() override { this->registred = true; }
};

// ÁÎÒÈÍÊÈ - ÂÅÇÄÅÕÎÄÛ
class Boots : public GroundTransport {
protected:
	int speed = 6;
	int timeToRest = 60;
	int restTime = 10;
	bool registred = false;

public:
	const char* getName() const {
		return "Áîòèíêè - âåçäåõîäû";
	}

	double calcTimeRide(int distance) override {
		double rest = 0;
		double stops = (distance / speed) / timeToRest;
		if (static_cast<int>(stops) == stops) stops -= 1;
		stops = static_cast<int>(stops);
		do {
			if (stops > 1) {
				rest += restTime - 5;
				stops--;
			}
			else if (stops == 1) {
				rest += restTime;
				stops--;
			}
		} while (stops != 0);
		double move = distance / speed;
		double time = rest + move;
		return time;
	}

	void setReg() override { this->registred = true; }
};


// ÂÎÇÄÓØÍÛÅ ÑĞÅÄÑÒÂÀ
class AirTransport : public Transport {
public:
	TransportType getType() const {
		return TransportType::Air;
	}
};

// ÊÎÂÅĞ - ÑÀÌÎËÅÒ
class Carpet : public AirTransport {
protected:
	int speed = 10;
	bool registred = false;

public:
	const char* getName() const {
		return "Êîâåğ - ñàìîëåò";
	}

	double calcTimeRide(int distance) override {
		double time = 0;
		double move = distance / speed;
		if (distance < 1000) {
			time = move;
		}
		else if (distance >= 1000 && distance < 5000) {
			time = move * 0.97;
		}
		else if (distance >= 5000 && distance < 10000) {
			time = move * 0.9;
		}
		else if (distance >= 10000) {
			time = move * 0.95;
		}
		return time;
	}

	void setReg() override { this->registred = true; }
};

// ÎĞÅË
class Eagle : public AirTransport {
protected:
	int speed = 8;
	bool registred = false;

public:
	const char* getName() const {
		return "Îğåë";
	}

	double calcTimeRide(int distance) override {
		double move = static_cast<double>(distance) / speed;
		double time = move * 0.94;
		return time;
	}

	void setReg() override { this->registred = true; }
};

// ÌÅÒËÀ
class Stick : public AirTransport {
protected:
	int speed = 20;
	bool registred = false;

public:
	const char* getName() const {
		return "Ìåòëà";
	}

	double calcTimeRide(int distance) override {
		double move = distance / speed;
		double distanceReduction = (100 - (static_cast<int>(distance / 1000)));
		double time = move * (distanceReduction / 100);
		return time;
	}

	void setReg() override { this->registred = true; }
};