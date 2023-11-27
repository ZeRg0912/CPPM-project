#pragma once
#include "Transports.h"
#include <vector>

#define allTransports 7

enum class allTransport {
	boots = 1, stick, camel, centaur, eagle, fastCamel, magicCarpet
};

enum class RaceType {
	ground = 1, air, all
};

class Race {
protected:
	Transport** makeTransports() {
		Transport** transArr = new Transport*[allTransports];
		for (int i = 0; i < allTransports; i++) {
			transArr[i] = 0;
		}
		return transArr;
	}

	bool checkRegistred(Transport** transport_race, size_t& selected, int type) {
		bool registred = false;
		allTransport tmp = static_cast<allTransport>(type);
		std::string str;
		switch (tmp) {
		case allTransport::boots:
			str = "������� - ���������";
			break;
		case allTransport::stick:
			str = "�����";
			break;
		case allTransport::camel:
			str = "�������";
			break;
		case allTransport::centaur:
			str = "�������";
			break;
		case allTransport::eagle:
			str = "����";
			break;
		case allTransport::fastCamel:
			str = "�������� - ��������";
			break;
		case allTransport::magicCarpet:
			str = "����� - �������";
			break;
		}
		for (int i = 0; i < selected; i++) {
			if (str == transport_race[i]->getName()) {
				registred = true;
				break;
			}
			else {
				registred = false;
			}
		}
		return registred;
	}

	Transport** makeTransportsForRace(Transport**& transport_race, size_t& selected, int distance, int raceType) {
		int type;
		do {
			do {
				//����������� ���� �����
				printRaceType(distance, raceType);
				// ����������� ������������������ �������
				printRegistredTransports(transport_race, selected);
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
			system("cls");
			bool errorType = false;
			switch (static_cast<allTransport>(type)) {
				case allTransport::boots:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "������� - ��������� ��� ����������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Boots;						
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					} 
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::stick:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "����� ��� ����������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Stick;						
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::camel:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "������� ��� ���������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Camel;
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::centaur:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "������� ��� ���������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Centaur;						
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::eagle:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "���� ��� ���������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Eagle;					
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::fastCamel:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "������� - ��������� ��� ���������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new FastCamel;						
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::magicCarpet:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "����� - �������" << " ��� ���������������!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Carpet;						
						std::cout << "�������� " << transport_race[selected]->getName() << " ������� ���������������!" << std::endl;
					}
					else {
						std::cout << "������������ ��� ������������� ��������!" << std::endl;
						errorType = true;
					}
					break;
			}
			if (selected == 7) {
				std::cout << "����������������� ��� ��������� ������������ ��������" << std::endl;
			}
			else {
				if (!errorType && type != 0) selected++;
			}
		} while (type != 0);
		return transport_race;
	}

	void deleteTransports(Transport** transports) {
		for (int i = 0; i < allTransports; i++) {
			delete transports[i];
		}
		delete[] transports;
	}

	struct RaceResults {
		std::string transport_name;
		double time;
	};

	void printResults(RaceResults* results, size_t selectedTransports, int distance) {
		system("cls");
		int num = 1;
		std::cout << "���������� �����: " << std::endl;
		for (int i = 0; i < selectedTransports; i++) {
			std::cout << num << ". " << results[i].transport_name << ". �����: " << results[i].time << std::endl;
			num++;
		}
	}

	void calcTimeTransports(RaceResults* results, size_t selectedTransports, int distance, Transport** transport_race) {
		for (int i = 0; i < selectedTransports; i++) {
			results[i].transport_name = std::string(transport_race[i]->getName());
			results[i].time = transport_race[i]->calcTimeRide(distance);
		}
	}

	void raceTimeSort(RaceResults* results, size_t selectedTransports) {
		for (int i = 0; i < selectedTransports; i++) {
			double tmpTime = results[i].time;
			std::string name = results[i].transport_name;
			int j = i - 1;
			while (j >= 0 && results[j].time > tmpTime) {
				results[j + 1] = results[j];
				j--;
			}
			results[j + 1].transport_name = name;
			results[j + 1].time = tmpTime;
		}
	}

	void registrationAndStart(Transport**& transport_race, RaceResults*& results, int distance, int raceType, size_t& selectedTransports) {
		int input;
		do {
			do {
				if (selectedTransports < 2) std::cout << "������ ���� ���������������� ���� �� 2 ������������ ��������" << std::endl;
				std::cout << "1. ���������������� ���������" << std::endl;
				if (selectedTransports >= 2) std::cout << "2. ������ �����" << std::endl;
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
			if (selectedTransports >= 2) {
				switch (input) {
				case 1:
					//���������� ��
					transport_race = makeTransportsForRace(transport_race, selectedTransports, distance, raceType);
					break;
				case 2:
					if (selectedTransports >= 2) {
						//������ � ������������
						results = new RaceResults[selectedTransports];
					}
					break;
				default:
					std::cout << "�������� ����� �� ������!" << std::endl;
				}
			}
			else {
				switch (input) {
				case 1:
					//����������� ���� �����
					printRaceType(raceType, distance);
					transport_race = makeTransportsForRace(transport_race, selectedTransports, distance, raceType);
					break;
				default:
					std::cout << "�������� ����� �� ������!" << std::endl;
				}
			}
		} while (selectedTransports < 2 || input != 2);
	}

public:
	void printRegisterTableMenu() {
		std::cout << "1. ������� - ���������" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "3. �������" << std::endl;
		std::cout << "4. �������" << std::endl;
		std::cout << "5. ����" << std::endl;
		std::cout << "6. ������� - ���������" << std::endl;
		std::cout << "7. ����� - �������" << std::endl;
		std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
	}

	void printRaceType(int distance, int raceType) {
		switch (static_cast<RaceType>(raceType)) {
		case RaceType::ground:
			std::cout << "����� ��� �������� ����������. ����������: " << distance << std::endl;
			break;
		case RaceType::air:
			std::cout << "����� ��� ���������� ����������. ����������: " << distance << std::endl;
			break;
		case RaceType::all:
			std::cout << "����� ��� �������� � ���������� ����������. ����������: " << distance << std::endl;
			break;
		}
	}

	void printRegistredTransports(Transport** transports, size_t& totalTransports) {
		std::cout << "������������������ ������������ ��������: ";
		int lastIndex = 0;
		for (int i = 0; i < totalTransports; i++) {
			std::cout << transports[i]->getName();
			if (lastIndex != totalTransports - 1) std::cout << ", ";
			lastIndex++;
		}
		std::cout << std::endl;
	}

	void raceBegin(int distance, int raceType) {
		//������ ���� �����������
		Transport** transport_all = makeTransports();

		//������ ��������� �����������
		//�������� �������� ���������� � �����������
		size_t selectedTransports = 0;
		Transport** transport_race = makeTransports();
		RaceResults* results = new RaceResults[selectedTransports];

		//���������� ������� ��������� �����������
		registrationAndStart(transport_race, results, distance, raceType, selectedTransports);

		//������� � ���������� ������� ������������
		calcTimeTransports(results, selectedTransports, distance, transport_race);

		//���������� �����������
		raceTimeSort(results, selectedTransports);

		//����������� �����������
		printResults(results, selectedTransports, distance);

		//������������ ������
		deleteTransports(transport_all);
		delete[] results;		
	}
};