#include <iostream>
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <climits> // for CHAR_BIT

// --------- void type ---------

/*
compiles for compatibility reasons, but void keyword
is considered deprecated. Prefered int getValue()
*/
int getValue(void)
{
    int x{};
    std::cin >> x;

    return x;
}

// --------- sizeof operator ---------
// Returns the size of a variable or data type in bytes
// Sizeof does not include dynamically allocated memory (heap memory) or memory used by the operating system for the program
void getDatatypesSize()
{
    std::cout << "A byte is " << CHAR_BIT << " bits" << std::endl;
    std::cout << std::left; // left align the output

    std::cout << std::setw(16) << "bool" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
}

int main()
{
    getDatatypesSize();

    return 0;
}