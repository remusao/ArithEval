#include "lexer.hh"

unsigned
Lexer::get_token ()
{
  if (offset_ >= expr_size_)
    return 0;

  int tok = get_op_ (expr_[offset_++]);

  if (tok)
    return tok;

  expr_[offset_ - 1] = table_[(int)expr_[offset_ - 1]];

  num_ = s_number ();
  num_.offset = offset_ - 1;
  unsigned length = 1;

  while (!op_[(int)expr_[offset_]])
  {
    expr_[offset_] = table_[(int)expr_[offset_++]];
    length++;
  }

  num_.size = length;

  return NUMBER;
}
