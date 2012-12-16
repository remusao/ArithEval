#pragma once
#ifndef TOKEN_HH
# define TOKEN_HH

# include <cstddef>

typedef enum
{
    END     = 0,
    NUMBER  = 1,
    RPAR    = 2,
    PLUS    = 3,
    MINUS   = 4,
    MULT    = 5,
    DIV     = 6,
    MOD     = 7,
    LPAR    = 8
} e_token;


struct Token
{
	Token()
		: offset_(0),
		  len_(0),
		  type_(END)
	{
	}

	Token(e_token type, unsigned offset, unsigned len)
		: offset_(offset),
		  len_(len),
		  type_(type)
	{
	}

	unsigned offset_;
	unsigned len_;
	e_token type_;
};

#endif /* !TOKEN_HH */

