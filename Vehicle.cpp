#include "Vehicle.h"
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>


Vehicle::~Vehicle() {

}

Vehicle::Vehicle(char* Model, char* Make, char* Reg, int Age) {
	strcpy_s(VehicleModel, Model);
	strcpy_s(VehicleMake, Make);
	strcpy_s(VehicleReg, Reg);
	VehicleAge = Age;
	this->Records = Records;
}

std::ostream& operator<<(std::ostream& os, Vehicle& rhs) {
	return os << rhs.VehicleReg << "\n" << rhs.VehicleMake << "\n" << rhs.VehicleModel << "\n" << rhs.VehicleAge << "\n" << rhs.GetExtra1() << "\n" << rhs.GetExtra2();
}

void Vehicle::DisplayToMenu() {
	std::cout << "   " << VehicleReg << "                   " << std::fixed << std::setprecision(2) << ReturnCost() << "                  " << GetType() << std::endl;
}  

void Vehicle::DisplayToSearchMenu() {
	std::cout << "   " << VehicleReg << "              " << std::fixed << std::setprecision(2) << ReturnCost() << "           " << VehicleMake << "        " << VehicleModel << std::endl;
}

const std::string Vehicle::ReturnFilePath() {
	return GetType().append("s/").append(VehicleReg).append(".txt");
}

void Vehicle::DisplaySpecifics() {
	system("CLS");
	std::cout << VehicleReg << ": " << VehicleMake << " " << VehicleModel << "\n--------------------" << std::endl;
	std::cout << "\nCost Per Day: " << std::fixed << std::setprecision(2) << ReturnCost() << "\nTotal Rented Income: " << "\nTotal Days Rented:" << std::endl;
}

void Vehicle::DisplayRecord(int record) {
	Records[record].DisplayToMenu();
}

void Vehicle::ResizeRecords() {
	size_t NEW_SIZE = ++RECORD_SIZE;
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
	for (int i = 0; i <= sizeof(Records); i++) {
		file << Records[i];
	}
}
