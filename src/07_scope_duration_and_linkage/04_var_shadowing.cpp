#include <iostream>
int value { 5 }; // global variable

void foo()
{   
    int value { 8 };
    ++value;
    std::cout << "'value' variable: " << value << '\n'; 
    std::cout << "global 'value' variable: " << ::variable << '\n';
}


int main()
{
    int apples { 5 }; // outer block apples

    {
        // apples refers to outer block apples here
        std::cout << apples << '\n'; 

        int apples{ 0 }; // define apples in the scope of the nested block

        // apples now refers to the nested block apples
        // the outer block apples is temporarily hidden

        apples = 10; // value 10 to nested block apples

        std::cout << apples << '\n'; // print value of nested block apples
    } // nested block apples destroyed


    std::cout << apples << '\n'; // prints value of outer block apples

    std::cout << "global 'value' variable: " << value << '\n'; // only exists global here, so no need of ::
    return 0;
}