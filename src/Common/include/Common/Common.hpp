#ifndef PROJECT_COMMON_HPP_HPP
#define PROJECT_COMMON_HPP_HPP

#include <array>

namespace common
{
    class Random;

    template<size_t N>
    void genrateNumbers(std::array<char[9], N> & numbers, Random & random);

    class Random
    {
    public:
        Random();

        void fill();

        char operator()();

    private:
        uint32_t generate();

    private:
        static constexpr uint32_t BUFF_SIZE = 2048;
        uint32_t x, y, z, w;
        uint32_t numbers[BUFF_SIZE];
        char * byteEnd;
    };
}


#include "Common_impl.hpp"

#endif //PROJECT_COMMON_HPP_HPP
