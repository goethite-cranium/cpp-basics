#include <iostream>
#include <stdexcept>


void ex1()
{
    std::cout << "Enter a double value: ";
    double x {};
    std::cin >> x;

    std::cout << "Enter a double value: ";
    double y {};
    std::cin >> y;

    std::cout << "Enter +, -, * or /:"
    char c {};
    std::cin >> c;

    double result {};
    if (c == '+')
        result = x + y;
    else if (c == '-')
        result = x - y;
    else if (c == '*')
        result = x * y;
    else if (c == '/')
        result = x / y;
    else
        throw std::invalid_argument( "The value entered is not among +, -, * or /");
    
    std::cout << x << ' ' << c << ' ' << y << " is " << result;
}

int main()
{
    ex1();

    return 0;
}