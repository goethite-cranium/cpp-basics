#include <iostream>
#include <iomanip> // output manipulation,
// for std::setw (which sets the width of the subsequent output)
// std::left (which left aligns the subsequent output)
// std::setprecision (which sets the precision of the subsequent output) 

// output manipulation are sticky (if use them, they will remain set)
// except for std::setw

#include <climits> // for CHAR_BIT
#include <cstdint> // for fixed width integer types
#include <cstddef> // for std::size_t
#include <limits>  // for std::.numeric_limits

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

    std::cout << std::setw(16) << "bool"         << sizeof(bool)        << " bytes\n";
    std::cout << std::setw(16) << "char:"        << sizeof(char)        << " bytes\n";
    std::cout << std::setw(16) << "short:"       << sizeof(short)       << " bytes\n";
    std::cout << std::setw(16) << "int:"         << sizeof(int)         << " bytes\n";
    std::cout << std::setw(16) << "long:"        << sizeof(long)        << " bytes\n";
    std::cout << std::setw(16) << "long long:"   << sizeof(long long)   << " bytes\n";
    std::cout << std::setw(16) << "float:"       << sizeof(float)       << " bytes\n";
    std::cout << std::setw(16) << "double:"      << sizeof(double)      << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
}


void overflowingSignedIntExample()
{
    int x { 2'147'483'647 }; // maximum value for a 32-bit signed integer
    std::cout << "Signed int x = " << x << "\n";

    x += 1; // overflow
    std::cout << "Signed int overflowed x = " << x << "\n\n";
}


void overflowingUnsignedIntExample()
{
    unsigned short x { 65'535 }; // maximum value for a 16-bit unsigned integer

    std::cout << "Unsigned int x = " << x << "\n";

    x += 1; // overflow
    std::cout << "Unsigned int overflowed x = " << x << "\n\n";
}


void fixedWidthDemostration()
{
    std::int32_t x { 32767 };
    std::cout << "Fixed width int x = " << x << "\n";

    std::int8_t y { 65 }; //  wont print a number, but a character ascii
    std::cout << "Fixed width int y = " << y << ", though is 65 int-8\n";
}


void fastestMinIntegers()
{
	std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";
}


void getSizeOf()
{
    int x { 5 };
    std::size_t s { sizeof(x) }; // size of variable x in bytes
    std::cout << "Size of x: " << s << " bytes\n";
}


void scientificNotationAndTypeForced()
{
    double x { 3.14159e-10 }; // 3.14159 * 10^-10
    std::cout << "Scientific notation x = " << x << "\n";

    auto a { 3.14 };   // double
    auto b { 3.14e0 }; // double
    auto c { 3.14f };  // float
    auto d { 3 };      // int 
}



void getNumericLimits()
{
    std::cout << std::boolalpha; // print bool as true/false rather tahn 0/1
    
    std::cout << "float limit: " << std::numeric_limits<float>::max() << "\n";
    std::cout << "double limit: " << std::numeric_limits<double>::max() << "\n";
    std::cout << "long double limit: " << std::numeric_limits<long double>::max() << "\n";
}


void outputFloatingPointValues()
{ // Truncating 6 digits
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << "\n\n";

    std::cout << std::setprecision(17);
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double
}


void supportingOfInfAndNaN()
{
    double zero { 0.0 };

    double posinf { 5.0 / zero }; // positive infinity
    std::cout << posinf << '\n';

    double neginf { -5.0 / zero }; // negative infinity
    std::cout << neginf << '\n';

    double z1 { 0.0 / posinf }; // positive zero
    std::cout << z1 << '\n';

    double z2 { -0.0 / posinf }; // negative zero
    std::cout << z2 << '\n';

    double nan { zero / zero }; // not a number (mathematically invalid)
    std::cout << nan << '\n';
}



int main()
{
    getDatatypesSize();

    overflowingSignedIntExample();

    overflowingUnsignedIntExample();

    fixedWidthDemostration();

    fastestMinIntegers();

    getSizeOf();

    scientificNotationAndTypeForced();

    getNumericLimits();

    supportingOfInfAndNaN();

    return 0;
}