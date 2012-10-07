#ifndef TOKEN_HH
# define TOKEN_HH

typedef enum
{
    END     = 0,
    NUMBER  = 1,
    LPAR    = 2,
    PLUS    = 3,
    MINUS   = 4,
    MULT    = 5,
    DIV     = 6,
    MOD     = 7,
    RPAR    = 8,
} e_token;

#endif /* !TOKEN_HH */

