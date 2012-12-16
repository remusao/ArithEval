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


int log2(int v)
{
	static const char LogTable256[256] =
	{
#define LT(n) n, n, n, n, n, n, n, n, n, n, n, n, n, n, n, n
		-1, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		LT(4), LT(5), LT(5), LT(6), LT(6), LT(6), LT(6),
		LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7), LT(7)
	};

	unsigned int r;     // r will be lg(v)
	register unsigned int tt; // temporaries

	if ((tt = (unsigned int)(v >> 24)))
		r = 24 + (unsigned int)LogTable256[tt];
	else if ((tt = (unsigned int)(v >> 16)))
		r = 16 + (unsigned int)LogTable256[tt];
	else if ((tt = (unsigned int)(v >> 8)))
		r = 8 + (unsigned int)LogTable256[tt];
	else
		r = (unsigned int)LogTable256[v];

	return (int)r;
}
