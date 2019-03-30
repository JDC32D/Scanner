#include "Scanner.h"
//#include "Token.h"
//#include <fstream>

char tokenArray[] = {
	'=','<','>',':','+','-','*','/','%','.',
	'(',')',',','{','}',';','[',']'
};


 std::string Keywords[] = {
 	"iter",
 	"void",
 	"return",
 	"scan",
 	"print",
 	"program",
 	"cond",
 	"then",
 	"let",
 	"int"
 };


int Scanner::filter(){

	if( !this->file ){
		perror("Filter: File pointer invalid\n");
		return -1;
	}

	char c = std::fgetc(file);
	if( std::ferror(file) ) {
		perror("Filter: Error reading from file");
		buffer="Buffer: Error";
		return -1;
	}

}

/*
Current Bugs:
	1) Starting a newline with a space gives me a character not in alphabet
	2) A single period is not read when it follows a word / is at the end of a line?
*/

/*
Attempted Solutions:
	1)	-continue out of loop 
		-break out of loop 

	2) -Loop through delimeters and operators while scanning for an identifier.
	   -70 pt assignment reads that there will always be spaces between them. 
*/

Token::Token Scanner::getToken() {
	Token::Token token;
	line = 1;
	char input;

	while(1) {

		input = fgetc(file);

		// Check for comment
		if (input == '&') {
			// Read until I get to newline
			while (input != '\n') {
				// If I reach the end of file instead, return
				if (input == EOF) {
					token.line = line;
					token.instance = "EOF";
					buffer.clear();
					token.id = Token::Id::eofTk;
					return token;
				}

				input = fgetc(file);
			}

		}

		// Check for spaces
		if (input == ' ') {
			input = fgetc(file);
		}

		// Windows newline is \r\n
		if (input == '\r') {
			input = fgetc(file);
		}

		if (input == '\t') {
			//input = fgetc(file);
		}

		// Normal newline
		if (input == '\n'){
			line++;
			input = fgetc(file);
		}

		// Operators and Delimeters checks
		if (input == '=') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::assignTk;
			return token;
		}

		if (input == '<') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::lessTk;
			return token;
		}

		if (input == '>') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::greaterTk;
			return token;
		}

		if (input == ':') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::colonTk;
			return token;
		}

		if (input == '+') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::plusTk;
			return token;
		}

		if (input == '-') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::minusTk;
			return token;
		}

		if (input == '*') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::minusTk;
			return token;
		}

		if (input == '/') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::bslashTk;
			return token;
		}

		if (input == '%') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::modTk;
			return token;
		}

		if (input == '.') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::dotTk;
			return token;
		}

		if (input == '(') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::lparenTk;
			return token;
		}

		if (input == ')') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::rparenTk;
			return token;
		}

		if (input == ',') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::commaTk;
			return token;
		}

		if (input == '{') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::lcbracketTk;
			return token;
		}

		if (input == '}') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::rcbracketTk;
			return token;
		}

		if (input == ';') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::semicolonTk;
			return token;
		}

		if (input == '[') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::lbracketTk;
			return token;
		}

		if (input == ']') {
			buffer += input;
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::rbracketTk;
			return token;
		}

		if (input == EOF) {
			token.line = line;
			token.instance = "EOF reached";
			buffer.clear();
			token.id = Token::Id::eofTk;
			return token;
		}

		// Process Letter
		if (isalpha(input)){

			while ( isalpha(input) || isdigit(input) ){
				buffer += input;
				input = fgetc(file);
			}

			for (int i = 0; i < 9; i++) {
				if (buffer == Keywords[i]) {
					token.line = line;
					token.instance = buffer;
					buffer.clear();
					token.id = static_cast<Token::Id>(i);
					return token;
				}
			}

			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::identifierTk;
			return token;
		}

		// Process Digit
		if(isdigit(input)){
			
			while( isdigit(input) ){

				// Check that all entries are digits
				if ( isalpha(input) ){
					token.line = line;
					token.instance = buffer;
					token.id = Token::Id::errTk;
					std::printf("Digit: Letter found while processing digit\n");
					return token;
				}

				buffer += input;
				input = fgetc(file);
			}
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::integerTk;
			return token;

		}

		// Fallthrough condition
		else {
			buffer = "ERROR";
			token.line = line;
			token.instance = buffer;
			buffer.clear();
			token.id = Token::Id::errTk;
			std::printf("Error: read character not in alphabet\n");
			return token;
		}
	}
}

/*
Commented out code for later use
//const char * Alphabet[] = {
//	"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r",
//	"s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J",
//	"K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1",
//	"2","3","4","5","6","7","8","9","=","<",">",":","+","-","*","/","%",".",
//	"(",")",",","{","}",";","[","]"," ","\n","\r","&"
//};
//
//const char * tokenArray[] = {
//	"iter","void","return","scan","print",
//	"program","cond","then","let","int"
//	"=","<",">",":","+","-","*","/","%",".",
//	"(",")",",","{","}",";","[","]","identifier",
//	"integer","EOF","error"
//};

//char Alphabet[] = {
//	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r',
//	's','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J',
//	'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1',
//	'2','3','4','5','6','7','8','9','=','<','>',':','+','-','*','/','%','.',
//	'(',')',',','{','}',';','[',']',' ','\n','\r','&'
//};
//
//const char * tokenArray[] = {
//	'iter','void','return','scan','print',
//	'program','cond','then','let','int'
//	,'=','<','>',':','+','-','*','/','%','.',
//	'(',')',',','{','}',';','[',']','identifier',
//	'integer','EOF','error'
//};
*/