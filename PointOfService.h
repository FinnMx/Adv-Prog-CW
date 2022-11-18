#pragma once
#include "Storage.h"
class PointOfService
{
public:
	PointOfService();
	~PointOfService();

	void DisplayMenu(Storage &storage);
	void HandleUserInput(Storage &storage);

	void CarSearchMenu(Storage& storage);
	void BikeSearchMenu(Storage& storage);

	void AddVehicle(Storage& storage);
	void HandleVehicleInput();
	void RemoveVehicle(Storage& storage);

private:
	int Input;
	bool Exit;

	//vars for input of vehicle creation...
	int Extra1, Extra2, Age;
	char Model[31], Make[31], Reg[9];
};
