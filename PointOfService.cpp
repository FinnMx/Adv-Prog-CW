#include "PointOfService.h"
#include <iostream>
#include <iomanip>

PointOfService::PointOfService() : Input(0) {

}

PointOfService::~PointOfService() {

}

//----------------------------------------------------------------------------
//-------------------------------ERROR HANDLING-------------------------------
//----------------------------------------------------------------------------

int PointOfService::GetIntChoice() {
	Input = 0;

	//std::cin.ignore();
	std::cout << "\nPlease choose an option: ";
	std::cin >> std::setw(1) >> Input;

	while (!std::cin.good()) {
		std::cout << "\nINVALID INPUT..." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "\nPlease choose an option: ";
		std::cin >> std::setw(1) >> Input;
	}
	return Input;
}

std::string PointOfService::GetStringChoice() {
	std::string Input = "";

	std::cin.ignore();
	std::getline(std::cin, Input);
	while (!std::cin.good()) {
		std::cout << "\nINVALID INPUT..." << std::endl;

		std::cin.ignore();
		std::getline(std::cin, Input);
	}
	return Input;
}

//----------------------------------------------------------------------------
//--------------------------------ACTUAL CODE---------------------------------
//----------------------------------------------------------------------------

void PointOfService::DisplayMenu(Storage& storage) {
	do{
		system("CLS");
		std::cout << "Vehicle Rental System\n---------------------\n" << std::endl;
		std::cout << "Registration Number          Cost Per Day          Vehicle Type" << std::endl;
		std::cout << "-------------------          ------------          ------------" << std::endl;
		storage.DisplayAllVehicles();

	} while (HandleUserInput(storage));
}

//make return a value 
bool PointOfService::HandleUserInput(Storage& storage) {
	std::cout << "\n1)Add Vehicle\n2)Remove Vehicle\n3)Search for a Car\n4)Search for a bike\n5)Sort Vehicles by registration number\n6)Sort by cost per day\n9)Exit\n" << std::endl;
	switch (GetIntChoice())
	{
	case 1:
		AddVehicle(storage);
		break;
	case 2:
		RemoveVehicle(storage);
		break;
	case 3:
		CarSearchMenu(storage);
		break;
	case 4:
		BikeSearchMenu(storage);
		break;
	case 5:
		storage.SortByReg();
		break;
	case 6:
		storage.SortByCost();
		break;
	case 9:
		storage.WriteToDisk();
		return false;
		break;
	default:
		std::cout << "\nplease choose a given option..." << std::endl;
	}
}

void PointOfService::CarSearchMenu(Storage& storage) {
	std::cout << "Search for a car by:\n--------------------\n1) Registration number\n2) Number of seats\n3) Number of doors\n9) Return to main menu" << std::endl;
	switch (GetIntChoice()) {
	case 1:
		DisplaySearchByReg();
		storage.SearchByReg(GetStringChoice());
		break;
	case 2:
		DisplaySearchBySeats();
		storage.SearchBySeats(Extra2);
		break;
	case 3:
		DisplaySearchByDoors();
		storage.SearchByDoors(Extra1);
		break;
	default:
		return;
		break;
	}
	SearchCont(storage, DisplaySearchMenu(storage));
}

void PointOfService::BikeSearchMenu(Storage& storage) {
	std::cout << "Search for a Bike by:\n--------------------\n1) Registration number\n2) Engine Size\n3) Number of wheels\n9) Return to main menu" << std::endl;
	switch (GetIntChoice()) {
	case 1:
		DisplaySearchByReg();
		storage.SearchByReg(Reg);
		break;
	case 2:
		DisplaySearchByEngine();
		storage.SearchByEngine(Extra1);
		break;
	case 3:
		DisplaySearchByWheels();
		storage.SearchByWheels(Extra2);
		break;
	default:
		return;
		break;
	}
	SearchCont(storage, DisplaySearchMenu(storage));
}

void PointOfService::SearchCont(Storage& storage, int VehicleIndex) {
	int op = 0;
	while(op != 9){
		storage.DisplayVehicleInfo();
		std::cout << "\n1) Rent Vehicle\n2) View historic rentals\n9) Return to main menu" << std::endl;
		op = GetIntChoice();
		switch (op) {
		case 1:
			RentVehicle(storage);
			break;
		case 2:
			RecordsMenu(storage);
			break;
		case 9:
			storage.SaveRecords();
			break;
		default:
			std::cout << "\nPlease enter a valid choice..." << std::endl;
			break;
		}
	}
}

int PointOfService::DisplaySearchMenu(Storage& storage) {
	std::cout << "\nRegistration Number" << "     " << "Cost Per Day" << "	    " << "Make" << "        " << "Model" << std::endl;
	std::cout << "-------------------" << "     " << "------------" << "	    " << "----" << "        " << "-----" << std::endl;
	storage.DisplaySearchResults();
	std::cout << "\nPlease enter a number to choose the vehicle, or any key to return to main menu: " << std::endl;
	Input = GetIntChoice();
	storage.RetrieveVehicleInfo(Input);
	return Input;
}

void PointOfService::RentVehicle(Storage& storage) {
	std::string name, address, number;
	std::cout << "\nHow many days do you want to rent the vehicle for: " << std::endl;
	int days = GetIntChoice();
	std::cout << "\nPlease enter your full name: " << std::endl;
	name = GetStringChoice();
	std::cout << "Please enter the first line of your address: " << std::endl;
	address = GetStringChoice();
	std::cout << "Please enter your postcode: " << std::endl;
	address = address.append(GetStringChoice());
	storage.InsertRecord(days,name,address);
}

void PointOfService::RecordsMenu(Storage& storage) {
	int index = 0;
	if(storage.DoRecordsExist()){
		while (Input != 9) {
			storage.DisplayRecord(index);
			std::cout << "\n1) View the previous record\n2) View the next record\n9) Return to vehicle information screen" << std::endl;
			std::cin >> Input;
			if (Input == 1)
				index--;
			else if (Input == 2)
				index++;
		}
	}
}

void PointOfService::DisplaySearchByReg() {
	std::cout << "Please enter the registration number of the vehicle:" << std::endl;
	std::cin.ignore();
	std::cin.getline(Reg, sizeof(Reg));
}

void PointOfService::DisplaySearchBySeats() {
	std::cout << "Please enter the number of seats in the vehicle:" << std::endl;
	std::cin >> Extra2;
}

void PointOfService::DisplaySearchByDoors() {
	std::cout << "Please enter the number of doors in the vehicle:" << std::endl;
	std::cin >> Extra1;
}

void PointOfService::DisplaySearchByEngine() {
	std::cout << "Please enter the engine size of the bike:" << std::endl;
	std::cin >> Extra1;
}

void PointOfService::DisplaySearchByWheels() {
	std::cout << "Please enter the number of wheels on the bike:" << std::endl;
	std::cin >> Extra2;
}

void PointOfService::HandleVehicleInput(std::string& Model, std::string& Make, std::string& Reg, int& age) {
	std::cout << "Please enter the Model" << std::endl;
	std::cin.ignore();
	std::cin.getline(Model, sizeof(Model));
	std::cout << "Please enter the Make" << std::endl;
	std::cin.getline(Make, sizeof(Make));
	std::cout << "Please enter the Reg" << std::endl;
	std::cin.getline(Reg, sizeof(Reg));
	std::cout << "Please enter the Age" << std::endl;
	std::cin >> Age;
}

void PointOfService::AddVehicle(Storage& storage) {
	int Extra1, Extra2, Age;
	std::string Model, Make, Reg;
	std::cout << "\nPlease Select An Option:\n1)Car\n2)Bike" << std::endl;
	std::cin >> Input;
	HandleVehicleInput(Model, Make, Reg, Age);
	switch (Input)
	{
	case 1:
		std::cout << "Please enter the number of doors" << std::endl;
		std::cin >> Extra1;
		std::cout << "Please enter the number of seats" << std::endl;
		std::cin >> Extra2;
		storage.AddVehicle(Model,Make,Reg,Age,Extra1,Extra2,Input);
		break;
	case 2:
		std::cout << "Please enter the engine size" << std::endl;
		std::cin >> Extra1;
		std::cout << "Please enter the number of wheels" << std::endl;
		std::cin >> Extra2;
		storage.AddVehicle(Model, Make, Reg, Age, Extra1, Extra2, Input);
		break;
	default:
		std::cout << "Invalid entry, returning to menu" << std::endl;
		break;
	}
}

void PointOfService::RemoveVehicle(Storage& storage) {
	std::cout << "\nPlease enter the registration of the vehicle you want to remove:" << std::endl;
	std::cin.ignore();
	std::cin.getline(Reg, sizeof(Reg));
	storage.RemoveVehicle(Reg);
}