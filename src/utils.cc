#include <unistd.h>
#include "utils.hh"


size_t readInt(char buff[], size_t& size, size_t& index)
{
	size_t res = 0;
	index = 0;

	if ((size = (size_t)read(STDIN_FILENO, buff, size)))
	{
		for (; index < size && buff[index] != '\n'; ++index)
			res = res * 10 + (size_t)(buff[index] - '0');
		++index;
	}

	return res;
}
