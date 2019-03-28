#include "Scanner.h"
#include "Token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctype.h>

const char * Alphabet[] = {
	"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r",
	"s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J",
	"K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1",
	"2","3","4","5","6","7","8","9","=","<",">",":","+","-","*","/","%",".",
	"(",")",",","{","}",";","[","]"," ","\n","\r","&"
};

const char * tokenArray[] = {
	"iter","void","return","scan","print",
	"program","cond","then","let","int"
	,"=","<",">",":","+","-","*","/","%",".",
	"(",")",",","{","}",";","[","]","identifier",
	"integer","EOF","error"
};


// int Scanner::filter() {

// }

// Token::Token Scanner(std::FILE* file) {
// 	Token::Token token;
// 	int input, c, position = -1;

// 	while( (input = fgetc(this->file)) != EOF ) {

// 		if (input == ' ')
// 			continue;

// 		else if (input == '\n')
// 			line++;

// 		// Process Letter
// 		else if (isalpha(input)){
		
// 			for( c = fgetc(this->file); isalnum(c); c = fgetc(this->file) ){
// 				position = (position + 1) % 8;
// 				token.instance[position] = c;
// 			}

// 			// Cleanup from getchar()
// 			token.instance[position] = ' ';
// 			fputc(c, this->file);
// 			position = -1;
			
// 		}

// 		// Process Digit
// 		else if(isdigit(input)){
			
// 			while( isdigit( ( c = getchar() ) ) ) {
// 				position = (position + 1) % 8;
// 				token.instance[position] = c;
// 			}

// 			// Cleanup from getchar()
// 			token.instance[position] = ' ';
// 			fputc(c, this->file);
// 			position = -1;

// 		}
// 	}
// }

int Scanner::filter(){

	// Safety Checks
	if( !this->file ){
		perror("Filter: File pointer invalid\n");
		return -1;
	}

	char c = std::fgetc(this->file);
	if( std::ferror(this->file) ) {
		perror("Filter: Error reading from file");
		this->buffer="Filter: Error reading from file\n";
		return -1;
	}

	// // Handle spaces
	// if ( c == '\n' ) 
	// 	this->line++;

	//If it makes it through the filter, put it back
	// else{
	// 	fputc(c,this->file);
	// 	return 1;
	// }
}

// enum Id{
// 	Keyword=0,
// 	Integer,
// 	Identifier,
// 	Operator,
// 	Delimiter,
// 	EoF,
// 	Error
// };

Token::Token Scanner::getToken() {
	Token::Token token;
	

	// if (filter() != 1){
	// 	token.line = this->line;
	// 	token.instance = this->buffer;
	// 	this->buffer.clear();
	// 	//token.id = Token::Id::errTk;
	// 	return token;
	// }

	// else {
	// 	token.line = this->line;
	// 	token.instance = "Made it through";
	// 	this->buffer.clear();
	// 	//token.id = Token::Id::assignTk;
	// 	return token;
	// }

	// const auto SetToken = [&](){
	// 	token.line = this->line;
	// 	token.instance = this->buffer;
	// 	this->buffer.clear();
	// }

	char input, c;
	//(input = fgetc(this->file)) != EOF
	while(1) {

		input = fgetc(this->file);

		if (input == ' ')
			continue;

		else if (input == '\n'){
			line++;
			input = fgetc(this->file);
		}

		else if (input == EOF ){
			token.line = this -> line;
			token.instance = "EOF reached";
			return token;
		}

		// Process Letter
		else if (isalpha(input)){

			while ( isalnum(input) ){
				this -> buffer += input;
				input = fgetc(this->file);
			}

			token.line = this -> line;
			token.instance = this -> buffer;
			printf("Here is the buffer: %s\n", this->buffer.c_str());
			this->buffer.clear();
			token.id = Token::Id::Identifier;
			//Token::Id token.id = Token::Identifier;
			return token;
		}

		// Process Digit
		else if(isdigit(input)){
			
			while( isdigit(input) ){
				if ( isalpha(input) ){

				}
				this -> buffer += input;
				input = fgetc(this->file);
			}

		}
	}
}