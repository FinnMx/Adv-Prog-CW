#include "Bike.h"

Bike::Bike(char* Reg, char* Make, char* Model, int Age, int Eng, int Wheels) : EngSize(Eng), WheelNum(Wheels), Vehicle(Model, Make, Reg, Age) {

}

Bike::~Bike() {

}

void Bike::GetExtraData() {
	std::cout << "Please enter the engine size" << std::endl;	
	std::cin >> EngSize;
	std::cout << "Please enter the number of wheels" << std::endl;
	std::cin >> WheelNum;
}

double Bike::ReturnCost() {

	return ((1500 + (double)EngSize) - ((1500 + EngSize) % 100)) / 100;
}

std::string Bike::GetType() {
	return "Bike";
}