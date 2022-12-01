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
	for (Vehicle* v : vehicles) {
		delete v;
		v = nullptr;
	}
	for (Vehicle* v : ReturnedFromSearch) {
		delete v;
		v = nullptr;
	}
}

void Storage::DisplayAllVehicles() {
	std::list<Vehicle*>::iterator it;
	for (it = vehicles.begin(); it != vehicles.end(); it++) {
		(**it).DisplayToMenu();
	}
}

void Storage::ReadFromDisk(std::string dir) {
	//routine to get a list of each doccument in the vehicle list folder using c++ 17 filesystem lib...
	std::string tmp;
	std::string tmpval[6];
	for (auto const& dir_entry : fs::directory_iterator{ dir }) {
		//read from the current tmp string store of the file dir.
		std::ifstream file(dir_entry.path().string());
		int i(0);
		while (std::getline(file, tmp)) {
			tmpval[i] = tmp;
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
		(**it++).WriteSelfToDisk();
	}
}

//make an int or bool and regturn the ting
void Storage::AddVehicle(std::string model, std::string make, std::string reg, int age, int extra1, int extra2, int op) {
	SearchByReg(reg);
	if (ReturnedFromSearch.size() == 0)
		(this->*Choice[op])(model, make, reg, age, extra1, extra2);
	ReturnedFromSearch.clear();
}

void Storage::AddCar(std::string model, std::string make, std::string reg, int age, int extra1, int extra2) {
	Car* c = new Car(reg, make, model, age, extra1, extra2);
	vehicles.push_back(c);
}

void Storage::AddBike(std::string model, std::string make, std::string reg, int age, int extra1, int extra2) {
	Bike* b = new Bike(reg, make, model, age, extra1, extra2);
	vehicles.push_back(b);
}

void Storage::RemoveVehicle(std::string reg) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if ((**it).CompareReg(reg.c_str()) == 0) {
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

void Storage::SearchByReg(std::string reg) {
	std::list<Vehicle*>::iterator it(vehicles.begin());
	while (it != vehicles.end()) {
		if ((**it).CompareReg(reg.c_str()) == 0) {
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

bool Storage::RetrieveVehicleInfo(int op) {
	if (ReturnedFromSearch.size() != 0 && (op -1) <= ReturnedFromSearch.size()) {
		v = ReturnedFromSearch[op - 1];
		v->ReturnAllRecords();
		ReturnedFromSearch.clear();
		return true;
	}
	else
		return false;

}

//this method could be classified as pointless considering the fact that we have already returned the state of records, 
//however another menu (without a display records) would need to be implemented if we were to remove this.
//additionally were reusing another function to actually check the state so it isnt the most stupid way of doing this.
bool Storage::DoRecordsExist() {
	if (!(v->ReturnNextRecNum() - 1))
		return false;
	else
		return true;
}

void Storage::DisplayVehicleInfo() {
	v->DisplaySpecifics();
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
//i couldnt figure out a way to get a future date based on days rented, i saw some librarys e.t.c online but it seems like
//more effort than what its worth, it isnt really an integral part of the system. i could of just forced the user to enter formatted
//dates but this seems unintuitive.
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