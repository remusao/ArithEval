#ifndef macroREPEAT_HH
# define macroREPEAT_HH

# define REPEAT1(macro, data) macro(1, data)
# define REPEAT2(macro, data) macro(2, data) REPEAT1(macro, data)
# define REPEAT3(macro, data) macro(3, data) REPEAT2(macro, data)
# define REPEAT4(macro, data) macro(4, data) REPEAT3(macro, data)


#endif /* !macroREPEAT_HH */

