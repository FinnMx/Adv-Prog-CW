#include <iostream>
#include <string>
//#include <filesystem>
#include <experimental/filesystem>
#include <fstream>
#include "Storage.h"
#include "PointOfService.h"

namespace fs = std::experimental::filesystem;

int main() {

	PointOfService pos = PointOfService();
	pos.DisplayMenu();
	
	return 0;
}