#pragma once
#include "Vehicle.h"
#include "Bike.h"
#include "Car.h"
#include <vector>

namespace fs = std::experimental::filesystem;

class Storage
{
public:
	Storage();
	~Storage();

	void DisplayAllVehicles();
	void DisplaySearchResults();
	void DisplayVehicleInfo(int op);
	void DisplayRecord(int& record);

	void ReadFromDisk(std::string dir);
	void WriteToDisk();
	void SaveRecords();

	void AddVehicle(char model[31], char make[31], char reg[9], int age, int extra1, int extra2, int op);
	void RemoveVehicle(const char reg[9]);

	void SortByCost();
	void SortByReg();

	void SearchByReg(char reg[9]);
	void SearchBySeats(int seats);
	void SearchByDoors(int doors);
	void SearchByEngine(int engsize);
	void SearchByWheels(int wheels);

private:
	const std::string BikeDir = "Bikes/";
	const std::string CarDir = "Cars/";

	std::list<Vehicle*> vehicles;
	std::vector<Vehicle*> ReturnedFromSearch;
	Vehicle* v;

	int index = 0;

};
