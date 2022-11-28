#include "Bike.h"

Bike::Bike(const char* Reg,const char* Make, const char* Model, int Age, int Eng, int Wheels) : EngSize(Eng), WheelNum(Wheels), Vehicle(Model, Make, Reg, Age) {

}

Bike::~Bike() {

}

void Bike::WriteSelfToDisk() {
	std::ofstream out(ReturnFilePath());
	out << *this;
}

double Bike::ReturnCost() {

	return ((1500 + (double)EngSize) - ((1500 + EngSize) % 100)) / 100;
}

std::string Bike::GetType() {
	return "Bike";
}