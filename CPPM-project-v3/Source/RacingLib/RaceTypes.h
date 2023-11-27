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
			str = "Ботинки - вездеходы";
			break;
		case allTransport::stick:
			str = "Метла";
			break;
		case allTransport::camel:
			str = "Верблюд";
			break;
		case allTransport::centaur:
			str = "Кентавр";
			break;
		case allTransport::eagle:
			str = "Орел";
			break;
		case allTransport::fastCamel:
			str = "Верблдюд - скороход";
			break;
		case allTransport::magicCarpet:
			str = "Ковер - самолет";
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
				//отображение типа гонки
				printRaceType(distance, raceType);
				// Отображение зарегестрированных средств
				printRegistredTransports(transport_race, selected);
				printRegisterTableMenu();
				std::cin >> type;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "Введите номер!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else if (type < 0 || type > 7) {
					std::cout << "Выберите номер из списка!" << std::endl;
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
						std::cout << "Ботинки - вездеходы уже зарагестрированы!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Boots;						
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					} 
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::stick:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Метла уже зарагестрирована!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Stick;						
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::camel:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Верблюд уже зарагестрирован!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Camel;
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::centaur:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Кентавр уже зарагестрирован!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Centaur;						
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::eagle:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Орел уже зарагестрирован!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Eagle;					
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::fastCamel:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Верблюд - быстроход уже зарагестрирован!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::air || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new FastCamel;						
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
				case allTransport::magicCarpet:
					if (checkRegistred(transport_race, selected, type)) {
						std::cout << "Ковер - самолет" << " уже зарагестрирован!" << std::endl;
						errorType = true;
					}
					else if (static_cast<RaceType>(raceType) != RaceType::ground || static_cast<RaceType>(raceType) == RaceType::all) {
						transport_race[selected] = new Carpet;						
						std::cout << "Танспорт " << transport_race[selected]->getName() << " успешно зарагестрирован!" << std::endl;
					}
					else {
						std::cout << "Неподходящий вид транспортного средства!" << std::endl;
						errorType = true;
					}
					break;
			}
			if (selected == 7) {
				std::cout << "Зарегестрированны все возможные транспортные средства" << std::endl;
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
		std::cout << "Результаты гонки: " << std::endl;
		for (int i = 0; i < selectedTransports; i++) {
			std::cout << num << ". " << results[i].transport_name << ". Время: " << results[i].time << std::endl;
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
				if (selectedTransports < 2) std::cout << "Должно быть зарегестрировано хотя бы 2 транспортных средства" << std::endl;
				std::cout << "1. Зарегестрировать транспорт" << std::endl;
				if (selectedTransports >= 2) std::cout << "2. Начать гонку" << std::endl;
				std::cout << "Выберите действие: ";
				std::cin >> input;
				system("cls");
				if (std::cin.fail()) {
					std::cout << "Выберите номер из списка!" << std::endl;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
				else { break; }
			} while (!isdigit(input) || (input != 1) || (input != 2));
			if (selectedTransports >= 2) {
				switch (input) {
				case 1:
					//заполнение ТС
					transport_race = makeTransportsForRace(transport_race, selectedTransports, distance, raceType);
					break;
				case 2:
					if (selectedTransports >= 2) {
						//массив с результатами
						results = new RaceResults[selectedTransports];
					}
					break;
				default:
					std::cout << "Выберите номер из списка!" << std::endl;
				}
			}
			else {
				switch (input) {
				case 1:
					//отображение типа гонки
					printRaceType(raceType, distance);
					transport_race = makeTransportsForRace(transport_race, selectedTransports, distance, raceType);
					break;
				default:
					std::cout << "Выберите номер из списка!" << std::endl;
				}
			}
		} while (selectedTransports < 2 || input != 2);
	}

public:
	void printRegisterTableMenu() {
		std::cout << "1. Ботинки - вездеходы" << std::endl;
		std::cout << "2. Метла" << std::endl;
		std::cout << "3. Верблюд" << std::endl;
		std::cout << "4. Кентавр" << std::endl;
		std::cout << "5. Орел" << std::endl;
		std::cout << "6. Верблюд - быстроход" << std::endl;
		std::cout << "7. Ковер - самолет" << std::endl;
		std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
	}

	void printRaceType(int distance, int raceType) {
		switch (static_cast<RaceType>(raceType)) {
		case RaceType::ground:
			std::cout << "Гонка для назеного транспорта. Расстояние: " << distance << std::endl;
			break;
		case RaceType::air:
			std::cout << "Гонка для воздушного транспорта. Расстояние: " << distance << std::endl;
			break;
		case RaceType::all:
			std::cout << "Гонка для назеного и воздушного транспорта. Расстояние: " << distance << std::endl;
			break;
		}
	}

	void printRegistredTransports(Transport** transports, size_t& totalTransports) {
		std::cout << "Зарегестрированные транспортные средства: ";
		int lastIndex = 0;
		for (int i = 0; i < totalTransports; i++) {
			std::cout << transports[i]->getName();
			if (lastIndex != totalTransports - 1) std::cout << ", ";
			lastIndex++;
		}
		std::cout << std::endl;
	}

	void raceBegin(int distance, int raceType) {
		//массив всех транспортов
		Transport** transport_all = makeTransports();

		//массив выбранных транспортов
		//создание массивов транспорта и результатов
		size_t selectedTransports = 0;
		Transport** transport_race = makeTransports();
		RaceResults* results = new RaceResults[selectedTransports];

		//заполнение массива выбранных транспортов
		registrationAndStart(transport_race, results, distance, raceType, selectedTransports);

		//рассчет и заполнение массива результатами
		calcTimeTransports(results, selectedTransports, distance, transport_race);

		//сортировка результатов
		raceTimeSort(results, selectedTransports);

		//отображение результатов
		printResults(results, selectedTransports, distance);

		//освобождение памяти
		deleteTransports(transport_all);
		delete[] results;		
	}
};