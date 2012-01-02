#ifndef CONVERTER_HH_
# define CONVERTER_HH_

# include "structfwd.hh"

void
build_op (char* op);

void
build_table (char* base, unsigned base_size,
             char* table);

void
convert_back (char* expr, unsigned expr_size,
              char* base, unsigned offset);

#endif /* !CONVERTER_HH_ */
