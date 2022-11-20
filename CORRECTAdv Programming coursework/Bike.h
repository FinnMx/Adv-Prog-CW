#pragma once
#include "Vehicle.h"
class Bike : public Vehicle
{
public:
	Bike(char* Model, char* Make, char* Reg, int Age, int Eng, int Wheels);
	~Bike();

	void GetExtraData();

protected:
	virtual int GetExtra1()override;
	virtual int GetExtra2()override;
	virtual double ReturnCost()override;
	virtual std::string GetType()override;

private:
	int EngSize, WheelNum;


};
inline int Bike::GetExtra1() {
	return EngSize;
}

inline int Bike::GetExtra2() {
	return WheelNum;
}

