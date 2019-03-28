#ifndef SCANNER_H
#define SCANNER_H

#include <cstdio>
#include "Token.h"

// class Scanner {
// 	int line,
// 		col;
// 	std::string str;
// 	std::FILE* file;
// 	int filter();
// public:
// 	Scanner(std::FILE* f){
// 		this->file = f;
// 		this->line = 0;
// 		this->col = 0;
// 	}
// 	Token::Token getNextToken();
// };

class Scanner {
	int line;
	std::string buffer;
	std::FILE* file;
	int filter();
public:
	Scanner(std::FILE * fp){
		this->file = fp;
		this->line = 0;
	}
	Token::Token getToken();
};

#endif