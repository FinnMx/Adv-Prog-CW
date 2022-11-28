#pragma once
#include "Storage.h"
class PointOfService
{
public:
	PointOfService();
	~PointOfService();

	void DisplayMenu(Storage &storage);
	bool HandleUserInput(Storage &storage);

	void CarSearchMenu(Storage& storage);
	void BikeSearchMenu(Storage& storage);

	int DisplaySearchMenu(Storage& storage);
	void SearchCont(Storage& storage, int VehicleIndex);

	void RentVehicle(Storage& storage);
	void RecordsMenu(Storage& storage);

	void DisplaySearchByReg();
	void DisplaySearchBySeats();
	void DisplaySearchByDoors();
	void DisplaySearchByEngine();
	void DisplaySearchByWheels();

	void AddVehicle(Storage& storage);
	void HandleVehicleInput(std::string& Model, std::string& Make, std::string& Reg, int& age);
	void RemoveVehicle(Storage& storage);


	//	ERROR HANDLING
	int GetIntChoice();
	std::string GetStringChoice();

private:
	int Input;

	//vars for input of vehicle creation... create locally within functions
	//int Extra1, Extra2, Age;
	//char Model[31], Make[31], Reg[9];
};

