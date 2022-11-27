#include "Record.h"

Record::Record() {

}

Record::Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, int customerNumber) :
	RentalNum(rentalNum), DateFrom(dateFrom), DateTo(dateTo), RentalDays(rentalDays), TotalCost(totalCost),
	CustomberName(customberName), CustomerAddress(customerAddress), CustomerNumber(customerNumber) 
{

}

const double Record::ReturnCost() {
	return TotalCost;
}

void Record::DisplayToMenu() {
	std::cout << "\nRental:     " << RentalNum << "\nDate From:     " << DateFrom << "\nDate To :     " << DateTo << "\nRental Days :     " << RentalDays << "\nTotal Cost :     " << TotalCost << "\nCustomer Name :     " << CustomberName << "\nCustomer Address :     " << CustomerAddress << "\nCustomer Number :     " << CustomerNumber << std::endl;
}

Record::~Record() {  

}

