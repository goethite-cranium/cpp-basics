#include <iostream>


void createBooleanValues()
{
    bool b1 { true };
    bool b2 { false };
    bool b3 { }; // default initialization to false

    bool b4 { !true };
    bool b5 { !false };

    std::cout << "Plain bool values print" << '\n';
    std::cout << b1 << '\n';
    std::cout << b2 << '\n';

    std::cout << std::boolalpha; // print bools as true or false
    std::cout << "Boolean values using std::boolalpha\n";
    std::cout << b4 << '\n';
    std::cout << b5 << '\n';

    std::cout << std::noboolalpha; // deactivating boolalpha
    std::cout << "std::boolalpha deactivated with std::noboolalpha\n";
    std::cout << b3 << '\n';

}


int main()
{
    createBooleanValues();

    return 0;
}