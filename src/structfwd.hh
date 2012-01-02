#ifndef STRUCTFWD_HH_
# define STRUCTFWD_HH_

typedef struct
{
  unsigned  offset;
  unsigned  size;
} s_number;

typedef enum
{
  PLUS    = 3,
  MINUS   = 4,
  MULT    = 5,
  DIV     = 6,
  MOD     = 7,
  LPAR    = 2,
  RPAR    = 8,
  NUMBER  = 1
} e_token;


#endif /* !STRUCTFWD_HH_ */
