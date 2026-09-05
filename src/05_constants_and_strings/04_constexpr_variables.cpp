#include <iostream>

int five()
{
    return 5;
}


constexpr double calcCircumference(double radius)
{
    constexpr double pi { 3.14159265359 };
    return 2.0 * pi * radius;
}


constexpr int greater(int x, int y)
{
    return (x > y ? x : y);
}


constexpr double doSomething(int x)
{
    double newVal { x * 0.5f };
    return newVal;
}


int main()
{
    constexpr double gravity { 9.8 };   // ok
    constexpr int sum { 4 + 5 };        // ok
    constexpr int something { sum };    // ok

    std::cout << "Enter your age:";
    int age{};
    std::cin >> age;

    // constexpr int myAge { age };        // compilation error
    // constexpr int f { five() };         // compilation error

    constexpr double circumference { 18.8496 }; // constexpr function evaluated compile-time
    std::cout << "Our circle has circumference " << circumference << "\n";

    int x{ 5 }; // not constexpr
    int y{ 6 }; // not constexpr
    std::cout << greater(x, y) << " is greater!\n"; // will be evaluated at runtime

    constexpr double resultOfDoSomething { doSomething(3) }; // EVALUATED COMPILE TIME
    std::cout << "doSomething output: " << resultOfDoSomething;
    return 0;
}