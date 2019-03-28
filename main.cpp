#include "ScannerTester.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main(int argc, char *argv[]) {

	if ( argc > 1 ) {

		std::FILE* file = std::fopen(argv[1],"r+");
		if (!file){
			std::printf("Error: Could not open file: \"%s\". Terminating\n",
					argv[1]);
			return -1;
		}

		//char str[80];
		// char c;
		// std::string str;

		// c = fgetc(file);

		// //In letter state
		// if( isalpha(c) ) {
		// 	printf("c is a letter\n");
		// 	str+=c;
		// }

		// if( isdigit(c) ) {
		// 	printf("c is a digit\n");
		// }
		
		// while( c != ' ' ){
		// 	c = fgetc(file);
		// 	str+=c;
		// }

		//std::printf("First word of file: %s\n", str.c_str());

		//std::printf("Putting %c back into the file\n", c);

		// if ( fputc(c, file) == EOF ){
		// 	perror("Main: Error putting character back into file\n");
		// }

		TestScanner(file);
		std::fclose(file);
	}

//Keyboard input condition
	else {

		std::FILE* file = std::fopen(argv[1],"r+");
		if (!file){
			std::printf("Error: Could not open file: \"%s\". Terminating\n",
					argv[1]);
			return -1;
		}

		// while ( getline(std::cin, input) ) {
		// 	file << input;
		// }

		TestScanner(file);
		std::fclose(file);
	}

	return 0;

}

