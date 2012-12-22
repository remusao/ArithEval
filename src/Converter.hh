#pragma once
#ifndef CONVERT_HH_
# define CONVERT_HH_

# include "repeatMacro.hh"
# include "Token.hh"


/// Create base converters to get contigus symbols in the base
template <typename T>
inline void baseConverter(const char base[], size_t baseSize, T newBase[255], T oldBase[255])
{
    for (T i = 0; i < baseSize; ++i)
    {
        newBase[(size_t)base[i]] = i;
        oldBase[i] = (T)base[i];
    }
}



/////////////////////////////////////////////////////////////////////////////////
// Convert char[] into another representation (size_t, unsigned long, etc.)  ////
/////////////////////////////////////////////////////////////////////////////////

#define COMPRESS(n, max)														\
| (baseConverter[(size_t)expr[index + (max - n)]] << (n - 1) * base_size)


#define CONVERT(n)																\
template <typename T, unsigned base_size>										\
inline T convert##n(const char expr[], size_t index, T baseConverter[255])		\
{																				\
    static_assert(1 <= (sizeof (T) * 8) / (float)base_size, "Error");			\
    return 0 REPEAT(n, COMPRESS, n) ;											\
}

CONVERT(1)  CONVERT(2)  CONVERT(3)  CONVERT(4)  CONVERT(5)  CONVERT(6)  CONVERT(7)  CONVERT(8)
CONVERT(9)  CONVERT(10) CONVERT(11) CONVERT(12) CONVERT(13) CONVERT(14) CONVERT(15) CONVERT(16)
CONVERT(17) CONVERT(18) CONVERT(19) CONVERT(20) CONVERT(21) CONVERT(22) CONVERT(23) CONVERT(24)
CONVERT(25) CONVERT(26) CONVERT(27) CONVERT(28) CONVERT(29) CONVERT(30) CONVERT(31) CONVERT(32)
CONVERT(33) CONVERT(34) CONVERT(35) CONVERT(36) CONVERT(37) CONVERT(38) CONVERT(39) CONVERT(40)
CONVERT(41) CONVERT(42) CONVERT(43) CONVERT(44) CONVERT(45) CONVERT(46) CONVERT(47) CONVERT(48)
CONVERT(49) CONVERT(50) CONVERT(51) CONVERT(52) CONVERT(53) CONVERT(54) CONVERT(55) CONVERT(56)
CONVERT(57) CONVERT(58) CONVERT(59) CONVERT(60) CONVERT(61) CONVERT(62) CONVERT(63) CONVERT(64)


// -----------------------------------------------------------------------------


# define TAB_ENTRY(n, data)														\
convert##n<T, base_size>,


/// Convert a number (char[]) into the same number encoded into a T[] (with
/// sizeof (T) >= sizeof (char))
template <typename T, unsigned base_size>
Token convert(const char expr[], const Token& token, T output[], unsigned offset, T baseConverter[255])
{
	// Function ptr on convert##n
	typedef T (*fun)(const char[], size_t, T[]);
	// Used to access the right convert function
	static const fun converters[] =
	{
		nullptr, // there is no function : convert0
		REPEAT(64, TAB_ENTRY, 0)
	};
	static const unsigned number = (sizeof (T) * 8) / base_size;


	unsigned len = token.len_;
	unsigned tok_offset = token.offset_;

	// Resulting token
	Token res(NUMBER, offset, token.len_ / number);

	for (; len >= number; len -= number, ++offset)
	{
		output[offset] = converters[number](expr, tok_offset++, baseConverter); // call CONVERT(number)
	}

	if (len > 0)
	{
		++res.len_;
		output[offset] = converters[len](expr, tok_offset, baseConverter); // call CONVERT(len)
	}

	return res;
}


#endif // CONVERT_HH_
