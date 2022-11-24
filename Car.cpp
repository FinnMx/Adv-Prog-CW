#include "Car.h"

Car::Car(char* Reg, char* Make, char* Model, int Age, int Doors, int Seats) : DoorNum(Doors), SeatNum(Seats), Vehicle(Model, Make, Reg, Age) {
}

Car::~Car() {

}

void Car::GetExtraData() {
	std::cout << "Please enter the number of doors" << std::endl;
	std::cin >> DoorNum;
	std::cout << "Please enter the number of seats" << std::endl;
	std::cin >> SeatNum;
}

double Car::ReturnCost() {

	return (2500 - (((double)GetAge() * 150) - ((double)DoorNum * 200))) / 100;
}

std::string Car::GetType() {

	return "Car";
}
