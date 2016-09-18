#ifndef COUNTRYCODES_COMMON_IMPL_HPP_HPP
#define COUNTRYCODES_COMMON_IMPL_HPP_HPP

#include "Common.hpp"

#include <cstddef>

inline
common::Random::Random()
    : x(3)
    , y(5)
    , z(7)
    , w(9)
    , byteEnd(reinterpret_cast<char *>(&numbers[0]))
{
    this->fill();
}



template <typename T1, typename T2>
ptrdiff_t
byteDistance(T1 const * p1, T2 const * p2)
{
    char const * c1 = reinterpret_cast<char const *>(p1);
    char const * c2 = reinterpret_cast<char const *>(p2);
    ptrdiff_t distance = c2 - c1;
    return distance;
};



inline
void
common::Random::fill()
{
    ptrdiff_t const bytesFilled = byteDistance(std::begin(numbers), byteEnd);
    ptrdiff_t const intsFilled = bytesFilled / 4;

    for (ptrdiff_t i = intsFilled; i < BUFF_SIZE; ++i)
    {
        numbers[i] = this->generate();
    }
    byteEnd = reinterpret_cast<char *>(std::end(numbers));
}



inline
uint32_t
common::Random::generate()
{
    auto t = x;
    t ^= t << 11;
    t ^= t >> 8;
    x = y;
    y = z;
    z = w;
    w ^= w >> 19;
    w ^= t;
    return w;
}



inline
char
common::Random::operator()()
{
    --byteEnd;
    return *byteEnd;
}



template <size_t N>
void
common::genrateNumbers(
    std::array<char[9], N> & numbers,
    Random & random)
{
    random.fill();

    for (size_t d = 0; d < N; ++d)
    {
        char (&digits)[9] = numbers[d];

        int_fast8_t i = 0;
        do
        {
            char const byte = random();
            char const high = static_cast<char>((byte >> 4) & 0xF);
            const char low = static_cast<char>(byte & 0xF);
            if (high < 10)
                digits[i++] = '0' + high;
            if (low < 10)
                digits[i++] = '0' + low;
        } while (i < 8);

        digits[8] = '\0';
    }
}


#endif //COUNTRYCODES_COMMON_IMPL_HPP_HPP
