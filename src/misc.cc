#include "misc.hh"

void
print_number (unsigned char* expr, s_number* num)
{
  unsigned char* begin = expr + num->offset;

  for (unsigned i = 0; i < num->size; i++)
    std::cout << begin[i];

  std::cout << std::endl;
}
