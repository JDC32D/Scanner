#include "ScannerTester.h"
#include <fstream>

int main(int argc, char *argv[]) {

	//std::string fileName;

	// File input
	if ( argc > 1 ) {

		// fileName = argv[1];
		// fileName.append(".sp19");
		std::FILE* file = std::fopen(argv[1],"r");
		if (!file){
			std::perror("Main: Unable to open file");
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
