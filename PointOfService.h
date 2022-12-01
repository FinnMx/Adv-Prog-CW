#pragma once
#include "Storage.h"
class PointOfService
{
public:
	PointOfService();
	~PointOfService();

	void DisplayMenu();
	bool HandleUserInput();

private:
	//	ERROR HANDLING
	const int GetIntChoice();
	const std::string GetStringChoice();
	const std::string GetRegChoice();
	bool CheckRegChars(std::string reg);

	void CarSearchMenu();
	void BikeSearchMenu();

	int DisplaySearchMenu();
	void SearchCont(int VehicleIndex);

	void RentVehicle();
	void RecordsMenu();

	void AddVehicle();
	void HandleVehicleInput(std::string& Model, std::string& Make, std::string& Reg, int& age);
	void RemoveVehicle();

	Storage storage = Storage();
};

