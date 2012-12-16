#include <alloca.h>

#include "utils.hh"
#include "Parser.hh"
#include "Token.hh"
#include "Lexer.hh"
#include "Converter.hh"
#include "BackConverter.hh"

// Debug
#include <iostream>

#define MAX_SIZE 1000
// Define the type in which we will store our numbers
typedef size_t numberType;

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
    numberType newBaseConverter[256] = {0};
    numberType oldBaseConverter[256] = {0};
    baseConverter(base, baseSize, newBaseConverter, oldBaseConverter);

	/////////////////////////////
	//   Evaluate expression   //
	/////////////////////////////

	size_t outIndex = 0, opIndex = 0;
	Token output[MAX_SIZE];
	e_token op[MAX_SIZE];

	Token token;

	do
	{
		// Read a token
		token = next(expr, exprSize, token.offset_ + token.len_);
		if (token.type_ == NUMBER)
		{
			convert(expr, compressedExpression, token);
			output[outIndex++] = token;
		}
		else // Operator
		{
			while (token.type_ < op[opIndex - 1])
			{
				--opIndex;
				outIndex -= 2;
				// Do operation
			}
			op[opIndex++] = token.type_;
		}
	} while (token.type_ != END);


	// When the expression is entirely parsed
	// compute the remaining operations in the operator stack
	while (opIndex > 1)
	{
		--opIndex;
		outIndex -= 2;
		// Comput operation
	}

	if (outIndex != 1)
		return 1;
	else
	{
		// Print res
		return 0;
	}
}