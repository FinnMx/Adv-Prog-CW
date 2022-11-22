#include "Record.h"

Record::Record() : RentalNum(1), DateFrom("22/11/2022"), DateTo("22/11/2022"), RentalDays(1), TotalCost(3),
	CustomberName("jeff"), CustomerAddress("t"), CustomerNumber(22) {

}

Record::Record(int rentalNum, std::string dateFrom, std::string dateTo, int rentalDays, double totalCost, std::string customberName, std::string customerAddress, int customerNumber) :
	RentalNum(rentalNum), DateFrom(dateFrom), DateTo(dateTo), RentalDays(rentalDays), TotalCost(totalCost),
	CustomberName(customberName), CustomerAddress(customerAddress), CustomerNumber(customerNumber) 
{

}

Record::~Record() {  

}

