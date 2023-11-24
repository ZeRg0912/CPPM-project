#pragma once
#include "Transports.h"
#include <vector>

enum class allTransport {
	boots = 1, stick, camel, centaur, eagle, fastCamel, magicCarpet
};

enum class airTransport {
	stick = 1, eagle, magicCarpet
};

enum class groundTransport {
	boots = 1, camel, centaur, fastCamel
};

class RaceAll {
protected:

public:
	virtual void printRegisterTableMenu() {
		std::cout << "1. ������� - ���������" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "3. �������" << std::endl;
		std::cout << "4. �������" << std::endl;
		std::cout << "5. ����" << std::endl;
		std::cout << "6. ������� - ���������" << std::endl;
		std::cout << "7. ����� - �������" << std::endl;
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
	}

	void printResultTable(std::vector<Transport*>& arr) {
		system("cls");
		int num = 1;
		std::cout << "���������� �����: " << std::endl;
		for (const auto& obj : arr) {
			std::cout << num << ". " << obj->getName() << ". �����: " << obj->getDistanceTime() << std::endl;
			num++;
		}
	}

	void printRegistredTransports(std::vector<Transport*>& arr) {
		std::cout << "������������������ ������������ ��������: ";
		int lastIndex = 0;
		for (const auto& obj : arr) {
			std::cout << obj->getName();
			if (lastIndex != arr.size() - 1) std::cout << ", ";
			lastIndex++;
		}
		std::cout << std::endl;
	}

	void printLastRegistredTransport(std::vector<Transport*>& TransportsForRace) {
		if (TransportsForRace.size()) {
			printRegistredTransports(TransportsForRace);
		}
	}

	void startRace(std::vector<Transport*>& arr, int distance) {
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->calcTimeRide(distance);
		}
	}

	void raceTimeSort(std::vector<Transport*>& arr) {
		for (int i = 0; i < arr.size(); i++) {
			Transport* key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j]->getDistanceTime() > key->getDistanceTime()) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = key;
		}
	}

	void registerTransport(std::vector<Transport*>& Transports, Transport* type) {
		bool registred = false;
		for (const auto& obj : Transports) {
			if (obj->getName() == type->getName()) {
				registred = true;
				break;
			}
			else {
				registred = false;
			}
		}
		if (registred == false) {
			std::cout << "���������: " << type->getName() << " ������� ���������������!" << std::endl;
			Transports.push_back(type);
		}
		else {
			std::cout << "��������� " << type->getName() << " ��� ���������������!" << std::endl;
		}
	}

	virtual std::vector<Transport*> createTransports(std::vector<Transport*>& TransportsForRace, int distance) {
		allTransport typeTransport;
		int type;
		do {
			do {
				std::cout << "����� ��� �������� � ���������� ����������. ����������: " << distance << std::endl;
				printLastRegistredTransport(TransportsForRace);
				printRegisterTableMenu();
				std::cin >> type;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "������� �����!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (type < 0 || type > 7) {
					std::cout << "�������� ����� �� ������!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else { break; }
			} while (!isdigit(type));
			typeTransport = static_cast<allTransport>(type);
			system("cls");
			switch (typeTransport) {
			case allTransport::boots:
				registerTransport(TransportsForRace, new Boots());
				break;
			case allTransport::stick:
				registerTransport(TransportsForRace, new Stick());
				break;
			case allTransport::camel:
				registerTransport(TransportsForRace, new Camel());
				break;
			case allTransport::centaur:
				registerTransport(TransportsForRace, new Centaur());
				break;
			case allTransport::eagle:
				registerTransport(TransportsForRace, new Eagle());
				break;
			case allTransport::fastCamel:
				registerTransport(TransportsForRace, new FastCamel());
				break;
			case allTransport::magicCarpet:
				registerTransport(TransportsForRace, new Carpet());
				break;
			}
		} while (type != 0);
		return TransportsForRace;
	}

	void clearTransports(std::vector<Transport*>& arr) {
		for (auto obj : arr) {
			delete obj;
		}
		arr.clear();
	}

	void raceBegin(int distance) {
		system("cls");
		std::vector<Transport*> TransportsForRace;
		int input;
		do {
			do {
				if (TransportsForRace.size() < 2) std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
				std::cout << "1. ���������������� ���������" << std::endl;
				if (TransportsForRace.size() >= 2) std::cout << "2. ������ �����" << std::endl;
				std::cout << "�������� ��������: ";
				std::cin >> input;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "�������� ����� �� ������!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else { break; }
			} while (!isdigit(input) || (input != 1) || (input != 2));
			if (TransportsForRace.size() >= 2) {
				switch (input) {
				case 1:
					TransportsForRace = createTransports(TransportsForRace, distance);
					break;
				case 2:
					if (TransportsForRace.size() >= 2) startRace(TransportsForRace, distance);
					break;
				default:
					std::cout << "�������� ����� �� ������!" << std::endl;
				}
			}
			else {
				switch (input) {
				case 1:
					TransportsForRace = createTransports(TransportsForRace, distance);
					break;
				default:
					std::cout << "�������� ����� �� ������!" << std::endl;
				}
			}
		} while (TransportsForRace.size() < 2 || input != 2);
		raceTimeSort(TransportsForRace);
		printResultTable(TransportsForRace);
		clearTransports(TransportsForRace);
	}
};

class RaceAir : public RaceAll{
	void printRegisterTableMenu() override {
		std::cout << "1. �����" << std::endl;
		std::cout << "2. ����" << std::endl;
		std::cout << "3. ����� - �������" << std::endl;
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
	}

	std::vector<Transport*> createTransports(std::vector<Transport*>& TransportsForRace, int distance) override {
		airTransport typeTransport;
		int type;
		do {
			do {
				std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
				printLastRegistredTransport(TransportsForRace);
				printRegisterTableMenu();
				std::cin >> type;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "������� �����!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (type < 0 || type > 3) {
					std::cout << "������� ����� �� ������!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else { break; }
			} while (!isdigit(type));
			typeTransport = static_cast<airTransport>(type);
			system("cls");
			switch (typeTransport) {
			case airTransport::stick:
				registerTransport(TransportsForRace, new Stick());
				break;
			case airTransport::eagle:
				registerTransport(TransportsForRace, new Eagle());
				break;
			case airTransport::magicCarpet:
				registerTransport(TransportsForRace, new Carpet());
				break;
			}
		} while (type != 0);
		return TransportsForRace;
	}
};

class RaceGround : public RaceAll {
	void printRegisterTableMenu() override {
		std::cout << "1. ������� - ���������" << std::endl;
		std::cout << "2. �������" << std::endl;
		std::cout << "3. �������" << std::endl;
		std::cout << "4. ������� - ���������" << std::endl;
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
	}

	std::vector<Transport*> createTransports(std::vector<Transport*>& TransportsForRace, int distance) override {
		groundTransport typeTransport;
		int type;
		do {
			do {
				std::cout << "����� ��� �������� ����������. ����������: " << distance << std::endl;
				printLastRegistredTransport(TransportsForRace);
				printRegisterTableMenu();
				std::cin >> type;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "������� �����!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (type < 0 || type > 4) {
					std::cout << "������� ����� �� ������!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else { break; }
			} while (!isdigit(type));
			typeTransport = static_cast<groundTransport>(type);
			system("cls");
			switch (typeTransport) {
			case groundTransport::boots:
				registerTransport(TransportsForRace, new Boots());
				break;
			case groundTransport::camel:
				registerTransport(TransportsForRace, new Camel());
				break;
			case groundTransport::centaur:
				registerTransport(TransportsForRace, new Centaur());
				break;
			case groundTransport::fastCamel:
				registerTransport(TransportsForRace, new FastCamel());
				break;
			}
		} while (type != 0);
		return TransportsForRace;
	}
};