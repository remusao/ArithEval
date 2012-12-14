#include <alloca.h>
#include <unistd.h>
#include <stdio.h>

#include "utils.hh"
#include "convert.hh"
#include "backConvert.hh"

// For test purpose

// Define the type in which we will store our numbers
typedef size_t numberType;

int main()
{
	size_t baseSize, exprSize, index, size;
	char buffer[10];


	///////////////////
	//   Read base   //
	///////////////////
	size = 4; // baseSize is at most 4 octets (including the trailing \n
	baseSize = readInt(buffer, size, index);
    char* base = (char*)alloca(baseSize + 1);
	for (size_t i = index; i < size; ++i)
		base[i - index] = buffer[i];

	read(STDIN_FILENO, base + (4 - index), baseSize - (4 - index) + 1);
    base[baseSize] = '\0';


	/////////////////////////
	//   Read expression   //
	/////////////////////////
	size = 10;
	exprSize = readInt(buffer, size, index);
    char* expression = (char*)alloca(exprSize + 1);
	for (size_t i = index; i < size; ++i)
		expression[i - index] = buffer[i];

    read(STDIN_FILENO, expression + (10 - index), exprSize - (4 - index) + 1);
    expression[exprSize] = '\0';


	////////////////////////////////////////
	//   Create optimisation structures   //
	////////////////////////////////////////

    // Allocate a tab of numberType to store the numbers
    numberType* compressedExpression = (numberType*)alloca(0); // TODO

    // Convert bases
    numberType newBaseConverter[256] = {0};
    numberType oldBaseConverter[256] = {0};
    baseConverter(base, baseSize, newBaseConverter, oldBaseConverter);

	
	/////////////////////////////
	//   Evaluate expression   //
	/////////////////////////////

	// TODO



    return 0;
}
