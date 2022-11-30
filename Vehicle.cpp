#include "Vehicle.h"
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <assert.h>

Vehicle::~Vehicle() {
	delete[] VehicleModel;
	delete[] VehicleMake;
	delete[] VehicleReg;
}

Vehicle::Vehicle(const std::string Model,const std::string Make,const std::string Reg, int Age) : VehicleAge(Age), RECORD_SIZE(0), CURRENT_RECORDS(0), Records(Records),
VehicleModel(strcpy(new char[Model.length() + 1], Model.c_str())),
VehicleMake(strcpy(new char[Make.length() + 1], Make.c_str())),
VehicleReg(strcpy(new char[Reg.length() + 1], Reg.c_str())) {

}

std::string Vehicle::ReturnDataForSave() {
	std::string tmp;
	auto s = std::to_string(VehicleAge);
	tmp = tmp.append(VehicleReg).append("\n").append(VehicleMake).append("\n").append(VehicleModel).append("\n").append(s);
	return tmp;
}


void Vehicle::DisplayToMenu() {
	std::cout << "   " << VehicleReg << "                   " << std::fixed << std::setprecision(2) << ReturnCost() << "                  " << GetType() << std::endl;
}  

void Vehicle::DisplayToSearchMenu() {
	std::cout << "   " << VehicleReg << "              " << std::fixed << std::setprecision(2) << ReturnCost() << "           " << VehicleMake << "        " << VehicleModel << std::endl;
}

//JUSTIFICATION FOR USING A 'GETTYPE' METHOD INSTEAD OF TYPEID.NAME!!
//TypeID returns the structs name including if it is a class of structure, when doing comparisons of 2 typeids its fine but when
//using it to return a string it requires tinkering to just get the raw name.
const std::string Vehicle::ReturnFilePath() {
	return GetType().append("s/").append(VehicleReg).append(".txt");
}

void Vehicle::DisplaySpecifics() {
	system("CLS");
	std::cout << VehicleReg << ": " << VehicleMake << " " << VehicleModel << "\n--------------------" << std::endl;
	if (RECORD_SIZE != 0)
		std::cout << "\nCost Per Day: " << std::fixed << std::setprecision(2) << ReturnCost() << "\nTotal Rented Income: " << std::fixed << std::setprecision(2) << ReturnTotalRentedIncome() << "\nTotal Days Rented: " << ReturnTotalRentedDays() << std::endl;
	else
		std::cout << "\nNo records exist for the vehicle..." << std::endl;
}

const double Vehicle::ReturnTotalRentedIncome() {
	double total = 0;
	for (int i = 0; i < RECORD_SIZE; i++) {
		total += Records[i].ReturnCost();
	}
	return total;
}

const int Vehicle::ReturnTotalRentedDays() {
	int days = 0;
	for (int i = 0; i < RECORD_SIZE; i++) {
		days += Records[i].ReturnDays();
	}
	return days;
}

//method may seem long but the if blocks stop the user from going over/out of bounds of the record list and makes the system work nicely
void Vehicle::DisplayRecord(int& record) {
	if (record >= RECORD_SIZE && record > 0) {
		Records[RECORD_SIZE - 1].DisplayToMenu();
		record = RECORD_SIZE - 1;
	}
	else if(record < 0){
		Records[0].DisplayToMenu();
		record = 0;
	}
	else
		Records[record].DisplayToMenu();
}

void Vehicle::ResizeRecords() {
	size_t NEW_SIZE = RECORD_SIZE + 1;
	Record* ResizedRecords = new Record[NEW_SIZE];
	memcpy(ResizedRecords, Records, RECORD_SIZE * sizeof(Record));
	RECORD_SIZE = NEW_SIZE;
	delete[] Records;
	Records = ResizedRecords;
}

void Vehicle::ReturnAllRecords() {
	std::string dir = "Records/";
	std::ifstream file(dir.append(VehicleReg).append(".txt"));
	int i = 0;
	std::string line[9];
	//refactor to a for loop, cut out bare lines
	while (std::getline(file, line[i])) {
		if (line[i] == "/") {
			Record r(std::stoi(line[i - 8]), line[i - 7], line[i - 6], std::stoi(line[i - 5]), std::stod(line[i - 4]), line[i - 3], line[i - 2], std::stoi(line[i - 1]));
			InsertRecord(r);
			i = 0;
		}
		else
			i++;
	}
}

int Vehicle::ReturnNextRecNum() {
	return CURRENT_RECORDS + 1;
}

double Vehicle::ReturnTotalCost(int days) {
	return (this->ReturnCost() * days);
}

void Vehicle::InsertRecord(Record r) {
	if (CURRENT_RECORDS >= RECORD_SIZE) {
		ResizeRecords();
		InsertRecord(r);
	}
	else
		Records[CURRENT_RECORDS++] = r;
}

const char Vehicle::RegLetter() {
	return VehicleReg[0];
}

int Vehicle::CompareReg(const char* reg) {
	return strcmp(VehicleReg, reg);
}

void Vehicle::SaveRecords() {
	std::string dir = "Records/";
	std::ofstream file(dir.append(VehicleReg).append(".txt"));
	for (int i = 0; i < RECORD_SIZE; i++) {
		file << Records[i];
	}
}
