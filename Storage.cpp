#include "Storage.h"
#include <iostream>
#include <string>
#include <cstring>
#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <list>

Storage::Storage() {
	Storage::ReadFromDisk("\Bikes");
	Storage::ReadFromDisk("\Cars");
}

Storage::~Storage() {

}

void Storage::DisplayAllVehicles() {
	int index(0);
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		std::cout << ++index << ")";
		(**it++).DisplayToMenu();
	}
}

void Storage::ReadFromDisk(std::string dir) {
	//routine to get a list of each doccument in the vehicle list folder using c++ 17 filesystem lib...
	std::ifstream file();
	std::string tmp;
	char tmpval[6][31];
	for (auto const& dir_entry : fs::directory_iterator{ dir }) {
		//read from the current tmp string store of the file dir.
		std::ifstream file(dir_entry.path().string());
		int i(0);
		while (std::getline(file, tmp)) {
			strcpy_s(tmpval[i], tmp.c_str());
			i++;
		}
		if (dir == "Bikes") {
			Bike* n = new Bike(tmpval[0], tmpval[1], tmpval[2], std::stoi(tmpval[3]), std::stoi(tmpval[4]), std::stoi(tmpval[5]));
			vehicles.push_back(n);
		}
		else if (dir == "Cars") {
			Car* n = new Car(tmpval[0], tmpval[1], tmpval[2], std::stoi(tmpval[3]), std::stoi(tmpval[4]), std::stoi(tmpval[5]));
			vehicles.push_back(n);
		}
	}
}

void Storage::WriteToDisk() {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		std::string bikeDir = BikeDir;
		std::string carDir = CarDir;
		//std::ofstream out("");
		if (typeid(**it) == typeid(Bike)) {
			std::ofstream out(bikeDir.append((**it).GetReg()).append(".txt"));
			out << (**it++);
		}
		if (typeid(**it) == typeid(Car)) {
			std::ofstream out(carDir.append((**it).GetReg()).append(".txt"));
			out << (**it++);
		}
	}
}

void Storage::AddVehicle(char model[31], char make[31], char reg[9], int age, int extra1, int extra2, int op) {
	switch (op) {
	case 1:
	{
		Car* c = new Car(reg, make, model, age, extra1, extra2);
		vehicles.push_back(c);
	}
	break;
	case 2:
	{
		Bike* b = new Bike(reg, make, model, age, extra1, extra2);
		vehicles.push_back(b);
	}
	break;
	}
}

void Storage::RemoveVehicle(const char reg[9]) {
	//ALMOST FUNCTIONAL, NEED TO REMOVE FROM FILE....
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if (strcmp((**it).GetReg(), reg) == 0) {
			std::remove((**it).ReturnFilePath().c_str());
			delete(*it);
			vehicles.remove((*it));
			return;
		}
		it++;
	}
}

void Storage::SortByCost() {
	vehicles.sort(CompareCost());
}

void Storage::SortByReg() {
	vehicles.sort(CompareReg());
}

void Storage::SearchForCar(int op) {

}

void Storage::SearchForBike(int op) {

}