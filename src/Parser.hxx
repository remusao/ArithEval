
template <template <typename> class Lexer, typename Expression>
Parser<Lexer, Expression>::Parser(
        const Lexer<Expression>& lexer,
        Expression& expr)
    : lexer_ (lexer),
      expr_ (expr)
{
}

template <template <typename> class Lexer, typename Expression>
Parser<Lexer, Expression>::~Parser()
{
}

template <template <typename> class Lexer, typename Expression>
void
Parser<Lexer, Expression>::parse(unsigned& start, unsigned& end)
{
    // TODO
    start = 0;
    end = 0;
    // END TODO

    opLen_ = 0;
    outputLen_ = 0;
    offset_ = 0;
    token_ = operators_[static_cast<unsigned>(expr_[offset_])];

    while (token_)
    {
        // Operator or Parenthesis
        if (token_ > NUMBER)
        {
            switch (token_)
            {
                case LPAR:
                    op_[opLen_].token = LPAR;
                    op_[opLen_].begin = offset_;
                    op_[opLen_].end = offset_;
                    ++opLen_;
                    break;
                case RPAR:
                    while (op_[--opLen_].token != LPAR)
                        output_[outputLen_++] = op_[opLen_];
                    break;
                // Operator
                default:
                    while (opLen_ && token_ <= operators_[op_[opLen_ - 1].token])
                        output_[outputLen_++] = op_[--opLen_];
                    // FIX ME
                    op_[opLen_++] = expr_[offset_];
                    break;
            }
            ++offset_;
        }
        // Number
        else
        {
            output_[outputLen_].token = NUMBER;
            output_[outputLen_].begin = offset_;
            // Find the end of the number
            while (operators_[expr_[++offset_]] == NUMBER)
                ;
            output_[outputLen_].end = offset_;
            ++outputLen_;
        }

        token_ = operators_[static_cast<unsigned>(expr_[offset_])];
    }
}
