#pragma once
#include <string>
#include <iostream>
class Record
{
public:
	//for some reason this defualt constructor is needed?
	Record();
	Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, std::string number);
	~Record();

	friend std::ostream& operator<<(std::ostream& os, const Record& rhs);
	void DisplayToMenu();

	const double ReturnCost();
	const int ReturnDays();

protected:

private:
	int RentalNum, RentalDays;
	std::string CustomberName, CustomerAddress, DateFrom, DateTo, CustomerNumber;
	double TotalCost;
};

inline std::ostream& operator<<(std::ostream& os, const Record& rhs) {
	return os << rhs.RentalNum << "\n" << rhs.DateFrom << "\n" << rhs.DateTo << "\n" << rhs.RentalDays << "\n" << rhs.TotalCost << "\n" << rhs.CustomberName << "\n" << rhs.CustomerAddress << "\n" << rhs.CustomerNumber << "\n/\n";
}

inline const double Record::ReturnCost() {
	return TotalCost;
}

inline const int Record::ReturnDays() {
	return RentalDays;
}

inline void Record::DisplayToMenu() {
	std::cout << "\nRental:     " << RentalNum << "\nDate From:     " << DateFrom << "\nDate To :     " << DateTo << "\nRental Days :     " << RentalDays << "\nTotal Cost :     " << TotalCost << "\nCustomer Name :     " << CustomberName << "\nCustomer Address :     " << CustomerAddress << "\nCustomer Number :     " << CustomerNumber << std::endl;
}
