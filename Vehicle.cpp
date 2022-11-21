#include "Vehicle.h"
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>


Vehicle::~Vehicle() {

}

void Vehicle::GetValues() {
}

void Vehicle::SetValues(char* Model, char* Make, char* Reg, int Age) {
	strcpy_s(VehicleModel, Model);
	strcpy_s(VehicleMake, Make);
	strcpy_s(VehicleReg, Reg);
	VehicleAge = Age;
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
	std::cout << Records[record];
}


