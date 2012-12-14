#include <alloca.h>
#include <unistd.h>
#include <stdio.h>
#include "convert.hh"
#include "backConvert.hh"

// For test purpose
// #include <iostream>

// Define the type in which we will store our numbers
typedef size_t numberType;

int
main ()
{
	size_t baseSize, exprSize;
    //char newline;

	// Read base
    //std::cin >> baseSize;
    //std::cin.get(newline);
    scanf("%zi%*[ \r\n\t]", &baseSize);

    char* base = (char*)alloca(baseSize + 1);
    read(STDIN_FILENO, base, baseSize + 1);
    //std::cin.read(base, baseSize + 1);
    base[baseSize] = '\0';

	// Read expression
    //std::cin >> exprSize;
    //std::cin.get(newline);
    scanf("%zi%*[ \r\n\t]", &exprSize);

    char* expression = (char *)alloca(exprSize + 1);
    read(STDIN_FILENO, expression, exprSize + 1);
    //std::cin.read(expression, exprSize + 1);
    expression[exprSize] = '\0';

    // Convert bases
    //numberType newBaseConverter[256] = {0};
    //numberType oldBaseConverter[256] = {0};
    //baseConverter(base, baseSize, newBaseConverter, oldBaseConverter);

    // Lexing / Parsing / Evaluate
    // TODO
    printf("%s\n%s\n", base, expression);
/*    for (std::streamsize i = 0; i < baseSize; ++i)
    	std::cout << base[i];
	std::cout << std::endl;

    for (std::streamsize i = 0; i < exprSize; ++i)
    	std::cout << expression[i];
	std::cout << std::endl;
*/
    return 0;
}
