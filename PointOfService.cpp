#include "PointOfService.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <algorithm>

PointOfService::PointOfService() {

}

PointOfService::~PointOfService() {

}

//----------------------------------------------------------------------------
//-------------------------------ERROR HANDLING-------------------------------
//----------------------------------------------------------------------------

int PointOfService::GetIntChoice() {
	std::cin.clear();
	std::cout << "\n-->: ";
	int Input = 0;
	std::cin >> Input;

	while (!std::cin.good()) {
		std::cout << "\nINVALID INPUT..." << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "\nPlease enter a number: ";
		std::cin >> std::setw(1) >> Input;
	}
	return Input;
}

std::string PointOfService::GetStringChoice() {
	std::cin.clear();
	std::cout << "\n-->: ";
	std::string Input = "";
	std::getline(std::cin, Input);
	while (!std::cin.good()) {
		std::cout << "\nINVALID INPUT..." << std::endl;
		std::cin.clear();
		std::cout << "\nPlease enter again: ";
		std::getline(std::cin, Input);
	}
	return Input;
}

std::string PointOfService::GetRegChoice() {
	std::cin.clear();
	std::cout << "\n-->: ";
	std::string Reg = "";
	std::getline(std::cin, Reg);
	while (!CheckRegChars(Reg)) {
		std::cout << "\nINVALID INPUT..." << std::endl;
		std::cin.clear();
		std::cout << "\nPlease enter a correctly formatted Reg (XX00 XXX): ";
		std::getline(std::cin, Reg);
	}
	std::transform(Reg.begin(), Reg.end(), Reg.begin(), ::toupper);
	return Reg;
}

//function here to make the GetRegChoice less messy...
bool PointOfService::CheckRegChars(std::string reg){
	if (reg.length() != 8)
		return false;
	if (!(isspace(reg.at(4))))
		return false;
	if (!(std::count_if(reg.begin() + 2, reg.end() - 5, std::isdigit)))
		return false;
	else
		return true;
}

//----------------------------------------------------------------------------
//--------------------------------ACTUAL CODE---------------------------------
//----------------------------------------------------------------------------

void PointOfService::DisplayMenu() {
	do{
		system("CLS");
		std::cout << "Vehicle Rental System\n---------------------\n" << std::endl;
		std::cout << "Registration Number          Cost Per Day          Vehicle Type" << std::endl;
		std::cout << "-------------------          ------------          ------------" << std::endl;
		storage.DisplayAllVehicles();

	} while (HandleUserInput());
}

bool PointOfService::HandleUserInput() {
	std::cout << "\n1)Add Vehicle\n2)Remove Vehicle\n3)Search for a Car\n4)Search for a bike\n5)Sort Vehicles by registration number\n6)Sort by cost per day\n9)Exit\n" << std::endl;
	switch (GetIntChoice())
	{
	case 1:
		AddVehicle();
		break;
	case 2:
		RemoveVehicle();
		break;
	case 3:
		CarSearchMenu();
		break;
	case 4:
		BikeSearchMenu();
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

void PointOfService::CarSearchMenu() {
	std::cout << "Search for a car by:\n--------------------\n1) Registration number\n2) Number of seats\n3) Number of doors\n9) Return to main menu" << std::endl;
	switch (GetIntChoice()) {
	case 1:
		std::cin.ignore();
		storage.SearchByReg(GetRegChoice());
		break;
	case 2:
		storage.SearchBySeats(GetIntChoice());
		break;
	case 3:
		storage.SearchByDoors(GetIntChoice());
		break;
	default:
		return;
		break;
	}
	SearchCont(DisplaySearchMenu());
}

void PointOfService::BikeSearchMenu() {
	std::string input;
	std::cout << "Search for a Bike by:\n--------------------\n1) Registration number\n2) Engine Size\n3) Number of wheels\n9) Return to main menu" << std::endl;
	switch (GetIntChoice()) {
	case 1:
		std::cin.ignore();
		storage.SearchByReg(GetRegChoice());
		break;
	case 2:
		storage.SearchByEngine(GetIntChoice());
		break;
	case 3:
		storage.SearchByWheels(GetIntChoice());
		break;
	default:
		return;
		break;
	}
	SearchCont(DisplaySearchMenu());
}

void PointOfService::SearchCont(int VehicleIndex) {
	int op = 0;
	while(op != 9){
		storage.DisplayVehicleInfo();
		std::cout << "\n1) Rent Vehicle\n2) View historic rentals\n9) Return to main menu" << std::endl;
		op = GetIntChoice();
		switch (op) {
		case 1:
			RentVehicle();
			break;
		case 2:
			RecordsMenu();
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

int PointOfService::DisplaySearchMenu() {
	int Input = 0;
	std::cout << "\nRegistration Number" << "     " << "Cost Per Day" << "	    " << "Make" << "        " << "Model" << std::endl;
	std::cout << "-------------------" << "     " << "------------" << "	    " << "----" << "        " << "-----" << std::endl;
	storage.DisplaySearchResults();
	std::cout << "\nPlease enter a number to choose the vehicle, or any number to return to main menu: " << std::endl;
	Input = GetIntChoice();
	if (storage.RetrieveVehicleInfo(Input))
		return Input;
	else
		DisplayMenu();
}

void PointOfService::RentVehicle() {
	std::string name, address, number;
	std::cout << "\nHow many days do you want to rent the vehicle for: " << std::endl;
	int days = GetIntChoice();
	std::cout << "\nPlease enter your full name: " << std::endl;
	std::cin.ignore();
	name = GetStringChoice();
	std::cout << "Please enter the first line of your address: " << std::endl;
	std::cin.clear();
	address = GetStringChoice();
	std::cout << "Please enter your postcode: " << std::endl;
	std::cin.clear();
	address = address.append(GetStringChoice());
	storage.InsertRecord(days,name,address);
}

void PointOfService::RecordsMenu() {
	int index = 0;
	int Input = 0;
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

void PointOfService::HandleVehicleInput(std::string& Model, std::string& Make, std::string& Reg, int& age) {
	std::cout << "Please enter the Model" << std::endl;
	std::cin.ignore();
	Model = GetStringChoice();
	std::cout << "Please enter the Make" << std::endl;
	Make = GetStringChoice();
	std::cout << "Please enter the Reg" << std::endl;
	Reg = GetRegChoice();
	std::cout << "Please enter the Age" << std::endl;
	age = GetIntChoice();
}

void PointOfService::AddVehicle() {
	int Extra1, Extra2, Age, Input;
	std::string Model, Make, Reg;
	std::cout << "\nPlease Select An Option:\n1)Car\n2)Bike" << std::endl;
	Input = GetIntChoice();
	HandleVehicleInput(Model, Make, Reg, Age);
	switch (Input)
	{
	case 1:
		std::cout << "Please enter the number of doors" << std::endl;
		Extra1 = GetIntChoice();
		std::cout << "Please enter the number of seats" << std::endl;
		Extra2 = GetIntChoice();
		storage.AddVehicle(Model,Make,Reg,Age,Extra1,Extra2,Input);
		break;
	case 2:
		std::cout << "Please enter the engine size" << std::endl;
		Extra1 = GetIntChoice();
		std::cout << "Please enter the number of wheels" << std::endl;
		Extra2 = GetIntChoice();
		storage.AddVehicle(Model, Make, Reg, Age, Extra1, Extra2, Input);
		break;
	default:
		std::cout << "Invalid entry, returning to menu" << std::endl;
		break;
	}
}

void PointOfService::RemoveVehicle() {
	std::cout << "\nPlease enter the registration of the vehicle you want to remove:" << std::endl;
	storage.RemoveVehicle(GetRegChoice());
}