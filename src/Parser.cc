#include <alloca.h>
#include <functional>

#include "utils.hh"
#include "Parser.hh"
#include "Token.hh"
#include "Lexer.hh"
#include "Converter.hh"
#include "BackConverter.hh"

// Debug
#include <iostream>

#define MAX_SIZE 1000000
// Define the type in which we will store our numbers
typedef size_t numberType;


# define BASE_SELECTOR(n, data)													\
	case n: numberConverter = convert<numberType, n>; break;

int
parse(const char* base, size_t baseSize, const char* expr, size_t exprSize)
{
	////////////////////////////////////////
	//   Create optimisation structures   //
	////////////////////////////////////////

    // Allocate a tab of numberType to store the compressed numbers
    size_t newSize = (exprSize * (size_t)log2((int)baseSize)) / sizeof (numberType);
    numberType* compressedExpression = (numberType*)alloca(newSize);

    // Convert bases
    numberType newBaseConverter[255];
    numberType oldBaseConverter[255];
    baseConverter(base, baseSize, newBaseConverter, oldBaseConverter);

	std::function<Token(const char[], Token&, numberType[], unsigned, numberType[255])> numberConverter;
	switch (baseSize)
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
		// Check for errors
		if (outIndex >= 2 * MAX_SIZE || opIndex >= MAX_SIZE)
		{
			std::cout << "Bim" << std::endl;
			break;
		}

		// Read a token
		token = next(expr, exprSize, token.offset_ + token.len_);
		if (token.type_ == NUMBER)
		{
			output[outIndex++] = numberConverter(expr, token, compressedExpression, compressedOffset, newBaseConverter);
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
				while (token.type_ < op[opIndex - 1])
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

	free(output);
	free(op);

	// Output the result
	if (outIndex != 1)
		return 1;
	else
	{
		// Print res
		return 0;
	}
}
