#pragma once
#include <string>
class Record
{
public:
	Record();
	Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, int customerNumber);
	~Record();

protected:

private:
	int RentalNum, RentalDays, CustomerNumber;
	std::string CustomberName, CustomerAddress, DateFrom, DateTo;
	double TotalCost;
};

