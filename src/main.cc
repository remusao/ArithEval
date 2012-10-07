#include "Expression.hh"
#include "Parser.hh"
#include "Lexer.hh"


// For test purpose
#include <iostream>

// ----------------------------------------------------------------------------
/// @brief Main function that get base, expr, etc .. and call parser that will
// scan, parse and evaluate the expression.
///
/// @return 0 if all went ok, 1 otherwise
// ----------------------------------------------------------------------------
int
main ()
{
    Expression expr;

    // Read the expression
    expr.read();

    Lexer<Expression> lexer(expr);
    Parser<Lexer, Expression> parser(lexer, expr);

    unsigned start = 0, end = 1;
    parser.parse(start, end);

    /*
       char* table = new char[256];
       build_table (base, base_size, table);

       char* op = new char[256];
       build_op (op);

       Lexer lex (expr, table, expr_size, op);

       unsigned offset;
       offset = parse (lex);

    // Convert only the result part
    convert_back (expr, expr_size, base, offset);

    std::cout << expr + offset;
    std::cout.flush ();
    */

    return 0;
}
