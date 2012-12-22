#include <alloca.h>
#include <functional>
#include <cstdlib>

#include "utils.hh"
#include "Parser.hh"
#include "Token.hh"
#include "Lexer.hh"
#include "Converter.hh"
#include "BackConverter.hh"

// Debug
#ifdef _DEBUG
# include <iostream>
#endif

#define MAX_SIZE 1000000
// Define the type in which we will store our numbers
typedef unsigned long long numberType;


# define BASE_SELECTOR(n, data)													\
	case n: numberConverter = convert<numberType, n>; break;

int
parse(const char* base, size_t baseSize, const char* expr, size_t exprSize)
{
	////////////////////////////////////////
	//   Create optimisation structures   //
	////////////////////////////////////////

    // Allocate a tab of numberType to store the compressed numbers
    int log2BaseSize = (int)(log2((int)baseSize)) + 1;
	unsigned number = (sizeof (numberType) * 8) / log2BaseSize;
    size_t newSize = (exprSize / number); // * log2BaseSize) / sizeof (numberType);
    numberType* compressedExpression = (numberType*)malloc(newSize);

    // Convert bases
    numberType newBaseConverter[255];
    numberType oldBaseConverter[255];
    baseConverter(base, baseSize, newBaseConverter, oldBaseConverter);

	std::function<Token(const char[], Token&, numberType[], unsigned, numberType[255])> numberConverter;

#ifdef _DEBUG
	std::cout << "sizeof (T)     = " << sizeof (numberType) << std::endl;
	std::cout << "baseSize       = " << baseSize << std::endl;
	std::cout << "log2(baseSize) = " << log2BaseSize << std::endl;
#endif

	switch (log2BaseSize)
	{
		REPEAT(64, BASE_SELECTOR, 0);
	};

	/////////////////////////////
	//   Evaluate expression   //
	/////////////////////////////

	size_t outIndex = 0, opIndex = 0, compressedOffset = 0;
	Token *output = (Token*)malloc(sizeof (Token) * 2 * MAX_SIZE);
	e_token *op = (e_token*)malloc(sizeof (e_token) * MAX_SIZE);

	Token token;

	do
	{

#ifdef _DEBUG
		// Check for errors
		if (outIndex >= 2 * MAX_SIZE || opIndex >= MAX_SIZE || compressedOffset >= newSize)
		{
			std::cout << "Bim" << std::endl;
			break;
		}
#endif

		// Read a token
		token = next(expr, exprSize, token.offset_ + token.len_);

#ifdef _DEBUG

		int tmpIndex;
		switch (token.type_)
		{
			case END: std::cout << "End\t\t"; break;
			case NUMBER:
				std::cout << "Number(";
				for (int i = 0; i < token.len_; ++i)
					std::cout << expr[token.offset_ + i];
				std::cout << ")\t";
				break;
			case RPAR: std::cout << ")\t\t"; break;
			case PLUS: std::cout << "Plus\t\t"; break;
			case MINUS: std::cout << "Minus\t\t"; break;
			case MULT: std::cout << "Mult\t\t"; break;
			case DIV: std::cout << "Div\t\t"; break;
			case MOD: std::cout << "Mod\t\t"; break;
			case LPAR: std::cout << "(\t\t"; break;
		};
		std::cout << " - offset : " << token.offset_ << " - len : " << token.len_ << std::endl;

#endif

		if (token.type_ == NUMBER)
		{
			output[outIndex++] = numberConverter(expr, token, compressedExpression, compressedOffset, newBaseConverter);
			compressedOffset += output[outIndex - 1].len_;

#ifdef _DEBUG
			Token tmpToken = output[outIndex - 1];
			std::cout << "> ";
			for (int i = 0; i < tmpToken.len_; ++i)
				std::cout << std::hex << compressedExpression[tmpToken.offset_ + i] << " ";
			std::cout << "\t\t - offset : " << tmpToken.offset_ << " - len : " << tmpToken.len_ << std::endl;
#endif

		}
		else // Operator
		{
			if (token.type_ == LPAR)
				op[opIndex++] = LPAR;
			else if (token.type_ == RPAR)
			{
				while (op[opIndex - 1] != LPAR)
				{
					--opIndex;
					--outIndex;
					// Do operation
				}
				--opIndex; // Delete the LPAR token
			}
			else
			{
				while (opIndex > 0 && token.type_ < op[opIndex - 1])
				{
					--opIndex;
					--outIndex;
					// Do operation
				}
				op[opIndex++] = token.type_;
			}
		}
	} while (token.type_ != END);


	// When the expression is entirely parsed
	// compute the remaining operations in the operator stack
	while (opIndex > 1)
	{
		--opIndex;
		--outIndex;
		// Comput operation
	}

	// ---
	// Output the result
	// ---

	free(output);
	free(op);
	free(compressedExpression);


	return (outIndex == 1 ? 0 : 1);
}
