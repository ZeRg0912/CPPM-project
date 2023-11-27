#include "GameManager.h"

int GameManager::setDistance() {
	int distance;
	do {
		std::cout << "������� ����� ��������� (������ ���� ������������): ";
		std::cin >> distance;
		system("cls");
		if (std::cin.fail() || distance <= 0) {
			std::cout << "������� ������������� �����!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else { break; }
	} while (distance <= 0);
	return distance;
}

void GameManager::printMenuTable() {
	std::cout << "����� ���������� � �������� ���������!" << std::endl;
	std::cout << "1. ����� ��� ��������� ����������" << std::endl;
	std::cout << "2. ����� ��� ���������� ����������" << std::endl;
	std::cout << "3. ����� ��� ��������� � ���������� ����������" << std::endl;
	std::cout << "�������� ��� �����: ";
}

void GameManager::doRestart(GameManager& game) {
	int restart;
	do {
		std::cout << "\n1. �������� ��� ���� �����" << std::endl;
		std::cout << "2. �����" << std::endl;
		std::cout << "�������� ��������: ";
		std::cin >> restart;
		system("cls");
		if (std::cin.fail()) {
			std::cout << "������� �����!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (restart < 1 || restart > 2) {
			std::cout << "�������� ����� �� ������!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else { break; }
	} while (restart < 1 || restart > 2);
	system("cls");
	switch (restart) {
	case 1:
		game.begin();
		break;
	}
}

void GameManager::begin() {
	int raceType;
	int distance;
	Race* currentMode = nullptr;
	do {
		printMenuTable();
		std::cin >> raceType;
		system("cls");
		if (std::cin.fail()) {
			std::cout << "������� �����!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (raceType < 1 || raceType > 3) {
			std::cout << "�������� ����� �� ������!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else { break; }
	} while (!isdigit(raceType));
	if (currentMode != nullptr) delete currentMode;
	system("cls");
	distance = setDistance();
	currentMode = new Race;
	currentMode->raceBegin(distance, raceType);
	delete currentMode;
	doRestart(*this);
}