
inline Expression::Expression()
    : baseSize_ (0),
      exprSize_ (0),
      base_ (nullptr),
      expression_ (nullptr)
{
}

inline Expression::~Expression()
{
    if (expression_ != nullptr)
        delete expression_;
    if (base_ != nullptr)
        delete base_;
}

inline void
Expression::read(std::istream& in)
{
    char newline;

    // Improve performances
    in.sync_with_stdio(false);

    std::cin >> baseSize_;
    std::cin.get(newline);

    base_ = new char[baseSize_ + 1];
    std::cin.read(base_, baseSize_ + 1);
    base_[baseSize_] = '\0';

    std::cin >> exprSize_;
    std::cin.get(newline);

    expression_ = new char[exprSize_ + 1];
    std::cin.read(expression_, exprSize_ + 1);
    expression_[exprSize_] = '\0';
}

// Accessors

inline unsigned
Expression::baseSizeGet() const
{
    return baseSize_;
}

inline unsigned
Expression::exprSizeGet() const
{
    return exprSize_;
}

inline char*
Expression::baseGet() const
{
    return base_;
}

inline char*
Expression::expressionGet() const
{
    return expression_;
}

inline char&
Expression::operator[](unsigned index) const
{
    return expression_[index];
}
