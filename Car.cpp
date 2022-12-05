#include "Car.h"

Car::Car(std::string Reg, std::string Make, std::string Model, int Age, int Doors, int Seats) : DoorNum(Doors), SeatNum(Seats), Vehicle(Model, Make, Reg, Age) {
}

Car::~Car() {

}

double Car::ReturnCost() {
	double cost = (2500 - (((double)GetAge() * 150) - ((double)DoorNum * 200))) / 100;
	if (cost > 10)
		return cost;
	else
		return 10.00;
}
