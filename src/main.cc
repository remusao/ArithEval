#include <alloca.h>
#include <unistd.h>
#include <cstdlib>

#include "utils.hh"
#include "Parser.hh"


int main()
{
	size_t baseSize, exprSize, index, size;
	char buffer[10];

	///////////////////
	//   Read base   //
	///////////////////
	// > Base size
	size = 4; // baseSize is at most 4 octets (including the trailing \n
	baseSize = readInt(buffer, size, index);
    char* base = (char*)malloc(baseSize + 1);
	for (size_t i = index; i < size; ++i)
		base[i - index] = buffer[i];

	// > Base
	read(STDIN_FILENO, base + (size - index), baseSize - (size - index) + 1);
    base[baseSize] = '\0';


	/////////////////////////
	//   Read expression   //
	/////////////////////////
	// > Expression size
	size = 10;
	exprSize = readInt(buffer, size, index);
    char* expression = (char*)malloc(exprSize + 1);
	for (size_t i = index; i < size; ++i)
		expression[i - index] = buffer[i];

	// > Expression
    read(STDIN_FILENO, expression + (size - index), exprSize - (size - index) + 1);
    expression[exprSize] = '\0';

	// Eval
	int return_code = parse(base, baseSize, expression, exprSize);
	free(base);
	free(expression);

	return return_code;
}
