#include "Storage.h"
#include <iostream>
#include <string>
#include <cstring>
#include <experimental/filesystem>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <ctime>

Storage::Storage() : v(v){
	Storage::ReadFromDisk("Bikes");
	Storage::ReadFromDisk("Cars");
}

Storage::~Storage() {

}

void Storage::DisplayAllVehicles() {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		std::cout << ++index << ")";
		(**it++).DisplayToMenu();
	}
	index = 0;
}

//Cars and bikes should know where to read themselves
void Storage::ReadFromDisk(std::string dir) {
	//this shits aids fix up
	//routine to get a list of each doccument in the vehicle list folder using c++ 17 filesystem lib...
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

//Cars and Bike should know where to save themselves
void Storage::WriteToDisk() {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		(**it++).WriteSelfToDisk();
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
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if ((**it).CompareReg(reg) == 0) {
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

void Storage::SearchByReg(char reg[9]) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if ((**it).CompareReg(reg) == 0) {
			ReturnedFromSearch.push_back(*it);
		}
		it++;
	}
}

void Storage::SearchBySeats(int seats) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if (typeid(**it) == typeid(Car) && dynamic_cast<Car*>(*it)->CompareSeats(seats)) {
			ReturnedFromSearch.push_back(*it);
		}
		it++;
	}
}

void Storage::SearchByDoors(int doors) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if (typeid(**it) == typeid(Car) && dynamic_cast<Car*>(*it)->CompareDoors(doors)) {
			ReturnedFromSearch.push_back(*it);
		}
		it++;
	}
}

void Storage::SearchByEngine(int engsize) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if (typeid(**it) == typeid(Bike) && dynamic_cast<Bike*>(*it)->CompareWheels(engsize)) {
			ReturnedFromSearch.push_back(*it);
		}
		it++;
	}
}

void Storage::SearchByWheels(int wheels) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if (typeid(**it) == typeid(Bike) && dynamic_cast<Bike*>(*it)->CompareWheels(wheels)) {
			ReturnedFromSearch.push_back(*it);
		}
		it++;
	}
}

void Storage::DisplaySearchResults() {
	for(Vehicle* var : ReturnedFromSearch)
	{
		std::cout << ++index << ")";
		var->DisplayToSearchMenu();
	}
	index = 0;
}

void Storage::RetrieveVehicleInfo(int op) {
	v = ReturnedFromSearch[op - 1];
	v->ReturnAllRecords();
	ReturnedFromSearch.clear();
}

void Storage::DisplayVehicleInfo() {
	//v = ReturnedFromSearch[op - 1];
	//v->ReturnAllRecords();

	v->DisplaySpecifics();
	//ReturnedFromSearch.clear();
}

void Storage::SaveRecords(){
	v->SaveRecords();
}

void Storage::InsertRecord(int days, std::string name, std::string address) {
	srand(time(nullptr));
	int randID = 1 + (std::rand() % (1000));

	Record r(v->ReturnNextRecNum(), ReturnDate(0), ReturnDate(days), days, v->ReturnTotalCost(days), name, address, randID);
	v->InsertRecord(r);
}

std::string Storage::ReturnDate(int offset) {
	std::time_t t = std::time(0);
	std::tm* date = std::localtime(&t);
	std::string day = std::to_string(date->tm_mday + offset);
	std::string month = std::to_string(date->tm_mon + 1);
	std::string year = std::to_string(date->tm_year + 1900);
	std::string formatted = day.append("/").append(month).append("/").append(year);
	return formatted;
}

void Storage::DisplayRecord(int& record) {
	v->DisplaySpecifics();
	v->DisplayRecord(record);
}