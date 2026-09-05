#include <iostream>

void integerLiteralsExample()
{
    std::cout << 5 << '\n';     // int by default
    std::cout << 5L << '\n';    // long
    std::cout << 5u << '\n';    // unsigend

    int a { 5 };            // ok: types match
    unsigned int b { 6 };   // ok: compiler will convert int value 6 to uint value 6
    long c { 7 };           // ok: compiler will convert int value 7 to long value 7
}


void floatLiteralsExample()
{
    std::cout << 5.0 << '\n';   // long by default
    std::cout << 5.0f << '\n';  // float 
}


int main()
{
    integerLiteralsExample();

    floatLiteralsExample();

    return 0;
}