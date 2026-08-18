#include <iostream>
#include <iomanip> // For std::setprecision
#include <stdexcept>

double getDouble()
{
    std::cout << "Enter a double value: ";
    double x{};
    std::cin >> x;
    return x;
}

char getOperator()
{
    std::cout << "Enter +, -, * or /:";
    char c{};
    std::cin >> c;
    return c;
}

void printResult(double x, double y, char c)
{
    double result{};
    if (c == '+')
        result = x + y;
    else if (c == '-')
        result = x - y;
    else if (c == '*')
        result = x * y;
    else if (c == '/')
        result = x / y;
    else
        throw std::invalid_argument("The value entered is not among +, -, * or /");

    std::cout << x << ' ' << c << ' ' << y << " is " << result << '\n';
}

void ex1()
{
    double x { getDouble() };
    double y { getDouble() };
    char c   { getOperator() };

    printResult(x, y, c);
}


float getTowerHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    float height {};
    std::cin >> height;

    return height;
}


float getFallenDistance(float seconds)
{
    return 9.8*seconds*seconds/2;
}

void calculateBallHeight(float seconds, float height)
{
    float distanceFromTop { height - getFallenDistance(seconds) };
    if (distanceFromTop <= 0)
        std::cout << "At " << seconds << " seconds, the ball is on the ground\n";
    else
        std::cout << "At " << seconds << " seconds, the ball is at height " << distanceFromTop << " meters\n";
}

void ex2()
{
    double height { getTowerHeight() };

    float a { 0.0 }, b { 1.0 }, c { 2.0 }, d { 3.0 }, e { 4.0 }, f { 5.0 };

    std::cout << std::fixed << std::setprecision(2);
    calculateBallHeight(a, height);
    calculateBallHeight(b, height);
    calculateBallHeight(c, height);
    calculateBallHeight(d, height);
    calculateBallHeight(e, height);
    calculateBallHeight(f, height);
}

int main()
{
    ex1();
    ex2();

    return 0;
}