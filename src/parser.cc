#include "parser.hh"
#include <iostream>

unsigned
parse (Lexer& lex)
{
  int tok;

  while ((tok = lex.get_token ()))
    ;

  return 0;
}
