#include <iostream>
#include "parser.hh"
#include "converter.hh"


// ----------------------------------------------------------------------------
/// @brief Main function that get base, expr, etc .. and call parser that will
// scan, parse and evaluate the expression.
///
/// @return 0 if all went ok, 1 otherwise
// ----------------------------------------------------------------------------
int
main ()
{
  char newline;

  unsigned base_size;
  std::cin >> base_size;
  std::cin.get(newline);

  char* base = new char[base_size + 1];
  std::cin.read (base, base_size + 1);
  base[base_size] = '\0';

  unsigned expr_size;
  std::cin >> expr_size;
  std::cin.get(newline);

  char* expr = new char[expr_size + 1];
  std::cin.read (expr, expr_size + 1);
  expr[expr_size] = '\0';

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
}
