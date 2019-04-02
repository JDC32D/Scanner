#include "ScannerTester.h"
#include <fstream>

const bool DEBUG = 0;

int main(int argc, char *argv[]) {

	std::string fileName;

	// File input
	if ( argc > 1 ) {

		fileName = argv[1];
		fileName.append(".sp19");

		// std::FILE* file = std::fopen(argv[1],"r");
		std::FILE* file = std::fopen(fileName.c_str(),"r");
		if (!file){
			std::perror("Main:");
			if(DEBUG)
				std::printf("fileName: %s\n", fileName.c_str());
			return -1;
		}

		TestScanner(file);
		std::fclose(file);
		
	}

	// Keyboard input 
	else {

		// std::FILE* file = std::fopen("Test","r");
		// if (!file){
		// 	std::perror("Main: Unable to open file");
		// 	return -1;
		// }

		TestScanner(stdin);
		//std::fclose(file);
	}

	return 0;

}
