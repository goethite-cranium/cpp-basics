#include <iostream>


void ifStatement1()
{
    std::cout << "Enter an integer: ";
    int x {};

    if (x == 0)
        std::cout << "The value is zero\n";
}


void ifStatement2()
{
    std::cout << "Enter an integer: ";
    int x {};

    if (x == 0)
        std::cout << "The value is zero\n";
    else
        std::cout << "The value is not zero\n";
}


void ifStatement3()
{
    std::cout << "Enter an integer: ";
    int x {};

    if (x == 0)
        std::cout << "The value is zero\n";
    else if (x > 0)
        std::cout << "The value is positive\n";
    else
        std::cout << "The value is negative\n";
}


void ifStatement4()
{
    int x {10};

    int result { x > 0 ? 100 : -100 }; // ternary operator
}


void silentlyBooleanConversion()
{
    std::cout << "Enter an integer as boolean value: ";
    int x {};
    std::cin >> x;
    
    if (x) // silently converts to boolean
        std::cout << "The value is converted to true\n";
    else
        std::cout << "The value is converted to false\n";
}



int main()
{
    ifStatement1();

    ifStatement2();

    ifStatement3();

    ifStatement4();

    silentlyBooleanConversion();

    return 0;
}