#include <iostream>


void printDouble(double x)
{
    std::cout << x << '\n';
}


void printInt(int x)
{
    std::cout << x << '\n';
}


void implicitConversionExample()
{
    int x { 5 };
    printDouble(x); // implicit conversion from int to double
    // Uses a temporary object of type double to hold the value of x
}


void explicitConversionExample()
{
    double x { 5.5 };
    printInt(static_cast<int>(x)); // explicit conversion from double to int
    // Prevents the compiler throwing unsafe implicit conversion warning
}

void explicitCharConversionExample()
{
    char ch { 'a' };
    std::cout << static_cast<int>(ch) << '\n';
}


void explicitUnsignedSignedConversionExample()
{
    // Safe conversion
    unsigned int u1 { 5 };
    int s1 { static_cast<int>(u1) };

    int s2 { 5 };
    unsigned int u2 { static_cast<unsigned int>(s2) };

    // Unsafe conversion resulting in modulo wrapping
    int s3 { -1 };
    std::cout << "Int -1 to unsigned int: " << static_cast<unsigned int>(s3) << '\n';

    unsigned int u3 { 4294967295 }; // Maximum value for unsigned int
    std::cout << "Unsigned int 4294967295 to int: " << static_cast<int>(u3) << '\n';
}

int main()
{
    implicitConversionExample();
    explicitConversionExample();
    explicitCharConversionExample();
    explicitUnsignedSignedConversionExample();
    
    return 0;
}