#pragma once
#ifndef LEXER_HH
# define LEXER_HH

# include "Token.hh"

Token next(const char *expr, size_t exprSize, size_t offset);

#endif /* !LEXER_HH */

