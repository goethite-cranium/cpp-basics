// Implementation of ratational << operator or left rotation
#include <iostream>
#include <bitset>
#include <cstdint>

std::bitset<4> rotl(std::bitset<4> x)
{
    const bool bufferedLeftBit {x.test(3)}; // La funcion miembro test no es elegible para constexpr
    x <<= 1;
    if (bufferedLeftBit)
        x.set(0);
    return x;
}


std::bitset<4> rotr(std::bitset<4> x)
{
    const std::bitset<4> mask0 { 0b0001 };
    const std::bitset<4> mask3 { 0b1000 };

    const bool bufferedRightBit{ (x & mask0) != std::bitset<4>{} }; // El operador!= no es elegible para constexpr
    x >>= 1;
    if (bufferedRightBit)
        x |= mask3;
    return x;
}


int main()
{
    std::bitset<4> flags{ 0b1010 };
    flags = rotl(flags);
    std::cout << flags << '\n'; // Should print 0101
    flags = rotr(flags);
    std::cout << flags << '\n'; // Should print 1010

    return 0;
}