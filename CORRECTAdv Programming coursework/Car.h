#pragma once
#include "Vehicle.h"
class Car : public Vehicle
{
public:
	Car(char* Model, char* Make, char* Reg, int Age, int Doors, int Seats);
	~Car();

	void GetExtraData();

protected:
	virtual int GetExtra1()override;
	virtual int GetExtra2()override;
	virtual double ReturnCost()override;
	virtual std::string GetType()override;

private:
	int DoorNum, SeatNum;

};

inline int Car::GetExtra1() {
	return DoorNum;
}

inline int Car::GetExtra2() {
	return SeatNum;
}

