#pragma once
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"

namespace fs = std::experimental::filesystem;

class Storage
{
public:
	Storage();
	~Storage();

	void DisplayAllVehicles();
	void ReadFromDisk(std::string dir);
	void WriteToDisk();

	void AddVehicle(char model[31], char make[31], char reg[9], int age, int extra1, int extra2, int op);
	void RemoveVehicle(const char reg[9]);

	void SortByCost();
	void SortByReg();

	void SearchForCar(int op);
	void SearchForBike(int op);

private:
	const std::string BikeDir = "Bikes/";
	const std::string CarDir = "Cars/";

	std::list<Vehicle*> vehicles;

};
