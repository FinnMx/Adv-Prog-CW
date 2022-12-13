#pragma once
#include "Storage.h"
class PointOfService
{
public:
	PointOfService();
	~PointOfService();

	int HandleUserInput();

private:
	//	ERROR HANDLING
	const int GetIntChoice(int min, int max);
	const std::string GetStringChoice();
	const std::string GetRegChoice();
	bool CheckRegChars(std::string reg);

	void DisplayMenu();
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

inline void PointOfService::RemoveVehicle() {
	std::cout << "\nPlease enter the registration of the vehicle you want to remove:" << std::endl;
	std::cin.ignore();
	storage.RemoveVehicle(GetRegChoice());
}
