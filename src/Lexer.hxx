

template <typename Expression>
inline Lexer<Expression>::Lexer(const Expression& exp)
    : exp_ (exp),
      offset_ (0),
      tmpToken_ (0)
{
}

template <typename Expression>
inline Lexer<Expression>::~Lexer()
{
}


template <typename Expression>
inline unsigned
Lexer<Expression>::next(unsigned& start, unsigned& end) const
{
    // End of lexing
    if (offset_ >= exp_.exprSizeGet())
        return 0;

    // Maj of the start
    start = offset_;

    // We check if the current char is an operator
    tmpToken_ = Lexer<Expression>::operators_[static_cast<unsigned> (exp_[offset_++])];

    // If it is, we return it
    if (tmpToken_)
        return tmpToken_;

    --offset_;
    // If not, it's a number and we will find the next op
    while ((exp_[offset_])
            && !operators_[static_cast<unsigned> (exp_[++offset_])])
        ;

    end = offset_ - 1;

    return NUMBER;
}
