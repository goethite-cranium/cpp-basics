#include <iostream>


void constInitialization()
{
    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    const int constAge { age }; // initialize using non-const value
}

void constFunctionParametersUsageExample(const int age)
{
    std::cout << "Age introduced was " << age << '\n';
}


int main()
{
    constInitialization();

    constFunctionParametersUsageExample(6);

    return 0;
}