#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include <iomanip>
#include "Record.h"
class Vehicle
{
public:
	//constructor stuff
	Vehicle(const std::string Model, const std::string Make, std::string Reg, int Age);
	~Vehicle();

	//comparison functions
	int CompareReg(const char* reg);
	const char RegLetter();

	//op overloads
	std::string ReturnDataForSave();

	//display function
	void DisplayToMenu();
	void DisplayToSearchMenu();
	void DisplaySpecifics();
	void DisplayRecord(int& record);

	virtual double ReturnCost() = 0;
	virtual void WriteSelfToDisk() = 0;
	
	//record stuff
	void ReturnAllRecords();
	const std::string ReturnFilePath();
	void InsertRecord(Record r);
	void SaveRecords();
	int ReturnNextRecNum();
	double ReturnTotalCost(int days);

protected:
	virtual std::string GetType() = 0; //I KNOWW YOU CAN USE TYPEID to return a std::type_info, read the justification for the method within my .cpp.
	const int GetAge();


private:
	//private methods...
	const double ReturnTotalRentedIncome();
	const int ReturnTotalRentedDays();
	void ResizeRecords();
	//record array
	size_t RECORD_SIZE;
	size_t CURRENT_RECORDS;
	Record* Records = new Record[RECORD_SIZE];

	int VehicleAge;

	const char* VehicleModel;
	const char* VehicleMake;
	const char* VehicleReg;

};

struct CompareCost {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return lhs->ReturnCost() < rhs->ReturnCost();
	}
};

struct CompareReg {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return (lhs->RegLetter() < rhs->RegLetter());
	}
};

inline const int Vehicle::GetAge() {
	return VehicleAge;
}

//----------------------------------------------------------------------------
//-------------------------------DISPLAY METHODS------------------------------
//----------------------------------------------------------------------------

inline void Vehicle::DisplayToMenu() {
	std::cout << "     " << VehicleReg << "                   " << std::fixed << std::setprecision(2) << ReturnCost() << "                  " << GetType() << std::endl;
}

inline void Vehicle::DisplayToSearchMenu() {
	std::cout << "   " << VehicleReg << "              " << std::fixed << std::setprecision(2) << ReturnCost() << "           " << VehicleMake << "        " << VehicleModel << std::endl;
}

//----------------------------------------------------------------------------
//--------------------------------RECORD METHODS------------------------------
//----------------------------------------------------------------------------

inline int Vehicle::ReturnNextRecNum() {
	return CURRENT_RECORDS + 1;
}

inline double Vehicle::ReturnTotalCost(int days) {
	return (this->ReturnCost() * days);
}

inline const char Vehicle::RegLetter() {
	return VehicleReg[0];
}

inline int Vehicle::CompareReg(const char* reg) {
	return strcmp(VehicleReg, reg);
}


