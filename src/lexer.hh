#ifndef LEXER_HH_
# define LEXER_HH_

# include "structfwd.hh"

class Lexer
{
  public:
    Lexer (char* expr, char* table,
           unsigned expr_size, char* op)
      : num_ (s_number ()),
        expr_ (expr), 
        offset_ (0),
        table_ (table),
        expr_size_ (expr_size),
        op_ (op) {}
    ~Lexer () {}

    unsigned get_token ();

    s_number num_;

  private:

    int
    get_op_ (char c)
    {
      return (int)op_[(int)c];
    }

    char* expr_;
    unsigned offset_;
    char* table_;
    unsigned expr_size_;
    char* op_;
};

#endif /* !LEXER_HH_ */
