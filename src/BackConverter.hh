#pragma once
#ifndef BACK_CONVERTER_HH_
# define BACK_CONVERTER_HH_


/*
// Compute the number of char that would be necessary
// to store number encoded in a variable of type T with
// a given base size.
template <typename T, size_t base_size>
size_t sizeInChar(T number)
{
}

///
// Convert a number back to chars
///

template <size_t base_size>
void convertBack(char number, char res[], size_t index)
{
    res[index] = (number & 0xF0) >> base_size;
    res[index + 1] = number & 0x0F;
}

template <size_t base_size>
void convertBack(size_t number, char res[], size_t index)
{
}

template <size_t base_size>
void convertBack(unsigned long int number, char res[], size_t index)
{

}
*/
#endif // BACK_CONVERTER_HH_
