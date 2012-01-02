#include "converter.hh"

void
build_table (char* base, unsigned base_size, char* table)
{
  for (unsigned i = 0; i < base_size; i++)
    table[(int)base[i]] = i;
}

void
convert_back (char* expr, unsigned expr_size, char* base, unsigned offset)
{
  for (unsigned i = offset; i < expr_size; i++)
    expr[i] = base[(int)expr[i]];
}

void
build_op (char* op)
{
  op[0] = 1;
  op[(int)'+'] = PLUS;
  op[(int)'-'] = MINUS;
  op[(int)'*'] = MULT;
  op[(int)'/'] = DIV;
  op[(int)'%'] = MOD;
  op[(int)'('] = LPAR;
  op[(int)')'] = RPAR;
}
