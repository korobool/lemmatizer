#include <iostream>
#include <cstdlib>
#include "traindataparser.h"

int main(int argc, char *argv[])
{    
	TrainDataParser tdp;
	if (!tdp.read("data/train_data.txt")) {
		std::cerr << "Failed to read train data: " << tdp.errorString() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
