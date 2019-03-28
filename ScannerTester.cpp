#include "ScannerTester.h"
#include "Scanner.h"
//#include "Token.h"

void TestScanner(std::FILE* file) {

	Token::Token token;
	std::printf("[Line#] : Instance\n");
	Scanner scanner(file);
	//while(token.line == 0){
		token = scanner.getToken();
		printf("[%3d] : %s\n",
			token.line, token.instance.c_str());
		// switch(token.id){
		// 	case Token::eofTk:
		// 	case Token::errTk:
		// 		return;
		// 	default:
		// 		break;
		// }
	//}
}
