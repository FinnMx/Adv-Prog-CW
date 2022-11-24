#include "Car.h"

Car::Car(char* Reg, char* Make, char* Model, int Age, int Doors, int Seats) : DoorNum(Doors), SeatNum(Seats), Vehicle(Model, Make, Reg, Age) {
}

Car::~Car() {

}

void Car::WriteSelfToDisk() {
	std::ofstream out(ReturnFilePath());
	out << *this;
}

double Car::ReturnCost() {

	return (2500 - (((double)GetAge() * 150) - ((double)DoorNum * 200))) / 100;
}

std::string Car::GetType() {

	return "Car";
}
