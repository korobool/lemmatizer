#include <iostream>
#include <cstdlib>
//#include "traindataparser.h" // ###
#include "utf8file.h" // ###

int main(int argc, char *argv[])
{
#if 0
	TrainDataParser tdp;
	if (!tdp.read("data/train_data.txt")) {
		std::cerr << "Failed to read train data: " << tdp.errorString() << std::endl;
		return EXIT_FAILURE;
	}
#endif

	Utf8File file;
	std::cout << "Reading file..." << std::endl;
	if (!file.read("data/train_data.txt")) {
		std::cerr << "Input file reading failure: " << file.errorString() << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "File was read" << std::endl;

	Utf8File::Data data = file.data();
	for (size_t i = 0; i < 3; ++i) {
		for (size_t j = 0; j < (*data)[i].size(); ++j) {
			std::wcout << "0x" << std::hex << (unsigned short)(*data)[i][j];
			std::wcout << " " << (char)((*data)[i][j]) << std::endl;
		}
		std::cout << "--------" << std::endl;
	}

	return EXIT_SUCCESS;
}
