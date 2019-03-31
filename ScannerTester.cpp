#include "ScannerTester.h"
#include "Scanner.h"

void TestScanner(std::FILE* file) {

	Token::Token token;
	std::printf("[L#] [Instance] | Identifier\n----------------------------\n");
	Scanner scanner(file);
	while(1){
		token = scanner.getToken();
		printf("[%2d] [%8s] | %s \n",
			token.line, token.instance.c_str(), 
			Token::Idname[token.id].c_str() );
		 switch(token.id){
		 	case Token::eofTk:
		 	case Token::errTk:
		 		return;
		 	default:
		 		break;
		 }
	}
}
