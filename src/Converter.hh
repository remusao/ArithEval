#pragma once
#ifndef CONVERTER_HH_
# define CONVERTER_HH_


template <typename T>
inline void baseConverter(const char base[], size_t baseSize, T newBase[256], T oldBase[256])
{
    for (T i = 0; i < baseSize; ++i)
    {
        newBase[(size_t)base[i]] = i;
        oldBase[i] = (T)base[i];
    }
}


template <typename T>
inline void convert(const char* expr, T* compressed, Token& token)
{
	// convert and add the number \p token to the compressed size T array
}


/////////////////////////////////////////////////////////////////////////////////
// Convert char[] into another representation T (size_t, unsigned long, etc.)  ////
/////////////////////////////////////////////////////////////////////////////////

template <typename T, unsigned base_size>
inline T convert1(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(1 <= (sizeof (T) * 8) / base_size, "Error");
    return baseConverter[(size_t)expr[index]];
}

template <typename T, unsigned base_size>
inline T convert2(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(2 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << base_size)
    |  baseConverter[(size_t)expr[index + 1]];
}

template <typename T, unsigned base_size>
inline T convert3(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(3 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << base_size)
    | (baseConverter[(size_t)expr[index + 2]]);
}

template <typename T, unsigned base_size>
inline T convert4(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(4 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 3 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 2]] << base_size)
    | (baseConverter[(size_t)expr[index + 3]]);
}

template <typename T, unsigned base_size>
inline T convert5(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(5 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 4 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << 3 * base_size)
    | (baseConverter[(size_t)expr[index + 2]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 3]] << base_size)
    | (baseConverter[(size_t)expr[index + 4]]);
}

template <typename T, unsigned base_size>
inline T convert6(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(6 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 5 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << 4 * base_size)
    | (baseConverter[(size_t)expr[index + 2]] << 3 * base_size)
    | (baseConverter[(size_t)expr[index + 3]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 4]] << base_size)
    | (baseConverter[(size_t)expr[index + 5]]);
}

template <typename T, unsigned base_size>
inline T convert7(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(7 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 6 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << 5 * base_size)
    | (baseConverter[(size_t)expr[index + 2]] << 4 * base_size)
    | (baseConverter[(size_t)expr[index + 3]] << 3 * base_size)
    | (baseConverter[(size_t)expr[index + 4]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 5]] << base_size)
    | (baseConverter[(size_t)expr[index + 6]]);
}

template <typename T, unsigned base_size>
inline T convert8(const char expr[], size_t index, T baseConverter[256])
{
    //static_assert(8 <= (sizeof (T) * 8) / base_size, "Error");
    return
      (baseConverter[(size_t)expr[index]] << 7 * base_size)
    | (baseConverter[(size_t)expr[index + 1]] << 6 * base_size)
    | (baseConverter[(size_t)expr[index + 2]] << 5 * base_size)
    | (baseConverter[(size_t)expr[index + 3]] << 4 * base_size)
    | (baseConverter[(size_t)expr[index + 4]] << 3 * base_size)
    | (baseConverter[(size_t)expr[index + 5]] << 2 * base_size)
    | (baseConverter[(size_t)expr[index + 6]] << base_size)
    | (baseConverter[(size_t)expr[index + 7]]);
}


// TODO ... continue

#endif // CONVERTER_HH_
