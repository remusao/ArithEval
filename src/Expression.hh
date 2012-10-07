#ifndef EXPRESSION_HH
# define EXPRESSION_HH

# include <iostream>


class Expression
{
public:
    inline Expression();
    inline ~Expression();

    inline void     read(std::istream& in = std::cin);

    // Accessors
    inline unsigned baseSizeGet() const;
    inline unsigned exprSizeGet() const;
    inline char*    baseGet() const;
    inline char*    expressionGet() const;

    inline char& operator[](unsigned index) const;

private:
    Expression(const Expression&);
    Expression& operator= (const Expression&);

    /* data */
    unsigned baseSize_;
    unsigned exprSize_;
    char*    base_;
    char*    expression_;
};

# include "Expression.hxx"

#endif /* !EXPRESSION_HH */

