#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace Token{

	enum Id {
		iterTk, voidTk, returnTk, scanTk, printTk,
		programTk, condTk, thenTk, letTk, intTk,

		assignTk, lessTk, greaterTk, colonTk, plusTk, minusTk,
		multTk, bslashTk, modTk, dotTk, lparenTk, rparenTk, commaTk,
		lcbracketTk, rcbracketTk, semicolonTk, lbracketTk, rbracketTk,

		identifierTk, integerTk, eofTk, errTk
	};

	// enum Id{
	// 	Keyword=0,
	// 	Integer,
	// 	Identifier,
	// 	Operator,
	// 	Delimiter,
	// 	EoF,
	// 	Error
	// };

	// typedef enum tokenInstances {

	// 	//Keywords
	// 	ITER, VOIDtk, VAR, RETURN, SCAN, PRINT, PROGRAM, COND,
	// 	THEN, LET, INTtk,

	// 	//Digits / Identifiers
	// 	DIGIT, 
	// 	IDENTIFIER, 

	// 	//Operators / Delimiter / White Space
	// 	ASSIGN, LESS, GREATER, COLON, PLUS, MINUS, MULT, BSLASH
	// 	MOD, DOT, LPAREN, RPAREN, COMMA, LCBRACKET, RCBRACKET, 
	// 	SEMICOLON, LBRACKET, RBRACKET, SPACE

	// } Instance;

	// const string IdName[] = {
	// 	"Keyword",
	// 	"Integer",
	// 	"Identifier",
	// 	"Operator",
	// 	"Delimiter",
	// 	"EoF",
	// 	"Error"
	// };

	// const string Keywords[] = {
	// 	"iter",
	// 	"void",
	// 	"return",
	// 	"scan",
	// 	"print",
	// 	"program",
	// 	"cond",
	// 	"then",
	// 	"let",
	// 	"int"
	// };

	typedef struct Token_T {
		Token::Id id;
		//char instance[8];
		std::string instance;
		int line;
	}Token;

} 
#endif