#include "Bike.h"

Bike::Bike(std::string Reg, std::string Make, std::string Model, int Age, int Eng, int Wheels) : EngSize(Eng), WheelNum(Wheels), Vehicle(Model, Make, Reg, Age) {

}

Bike::~Bike() {

}

double Bike::ReturnCost() {
	double cost = ((1500 + (double)EngSize) - ((1500 + EngSize) % 100)) / 100;
	if (cost > 10)
		return cost;
	else
		return 10.00;
}
