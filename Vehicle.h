#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include "Record.h"
class Vehicle
{
public:
	~Vehicle();
	void SetValues(char* Model, char* Make, char* Reg, int Age);

	const char* GetModel();
	const char* GetMake();
	const char* GetReg();
	const int GetAge();
	friend std::ostream& operator<<(std::ostream& os, Vehicle& rhs);

	void GetValues();

	void DisplayToMenu();
	void DisplayToSearchMenu();
	void DisplaySpecifics();
	void DisplayRecord(int record);

	virtual double ReturnCost() = 0;
	virtual int GetExtra1() = 0;
	virtual int GetExtra2() = 0;
	
	void ReturnAllRecords();
	const std::string ReturnFilePath();
	void ResizeRecords();

protected:
	virtual std::string GetType() = 0;

private:
	size_t RECORD_SIZE = 1;  
	Record* Records = new Record[RECORD_SIZE];

	int VehicleAge;
	char VehicleModel[31], VehicleMake[31], VehicleReg[9];

};

struct CompareCost {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return lhs->ReturnCost() < rhs->ReturnCost();
	}
};
struct CompareReg {
	bool operator()(Vehicle* lhs, Vehicle* rhs) {
		return (lhs->GetReg())[0] < (rhs->GetReg())[0];
	}
};

inline const char* Vehicle::GetModel() {
	return VehicleModel;
}

inline const char* Vehicle::GetMake() {
	return VehicleMake;
}

inline const char* Vehicle::GetReg() {
	return VehicleReg;
}

inline const int Vehicle::GetAge() {
	return VehicleAge;
}


