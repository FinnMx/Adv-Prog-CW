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
	void DisplayVehicleInfo();
	void RetrieveVehicleInfo(int op);
	void DisplayRecord(int& record);

	bool DoRecordsExist();

	std::string ReturnDate(int offset);

	void ReadFromDisk(std::string dir);
	void WriteToDisk();

	void InsertRecord(int days, std::string name, std::string address);
	void SaveRecords();

	void AddVehicle(std::string model, std::string make, std::string reg, int age, int extra1, int extra2, int op);
	void RemoveVehicle(std::string reg);

	void SortByCost();
	void SortByReg();

	void SearchByReg(std::string reg);
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
