#pragma once
#include "Storage.h"
class PointOfService
{
public:
	PointOfService();
	~PointOfService();

	void DisplayMenu();
	bool HandleUserInput();

	void CarSearchMenu();
	void BikeSearchMenu();

	int DisplaySearchMenu();
	void SearchCont(int VehicleIndex);

	void RentVehicle();
	void RecordsMenu();

	void AddVehicle();
	void HandleVehicleInput(std::string& Model, std::string& Make, std::string& Reg, int& age);
	void RemoveVehicle();


	//	ERROR HANDLING
	int GetIntChoice();
	std::string GetStringChoice();
	std::string GetRegChoice();
	bool CheckRegChars(std::string reg);

private:

	Storage storage = Storage();
};

