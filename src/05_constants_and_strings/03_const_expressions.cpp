#include <iostream> 


int getNumber()
{
    std::cout << "Enter a number: ";
    int y{};
    std::cin >> y; // executed at runtime

    return y;      // this return expression is a runtime expression
}

// The return value of a non-constexpr function is a runtime expression
// even when the return expression is a constant expression
int five()
{
    return 5;
}

int main()
{
    // Literals can be used in constant expressions
    5;                      // constant expression
    1.2;                    // constant expression
    "Hello world!";         // constant expression

    // Most operators that have constant expression operands can be used in constant expressions
    5 + 6;                  // constant expression
    1.2 * 3.4;              // constant expression
    sizeof(int) + 1;        // constant expression

    // The return values of non-constexpr functions can only be used in runtime expressions
    getNumber();            // runtime expression
    five();                 // runtime expression (even though the return expression is a constant expression)
    
    // Operators without constant expression operands can only be used in runtime expressions
    std::cout << 5;         // runtime expression (std::cout isnt a consant expression operand) 

    const int a { 5 };      // a is usable in constant expressions
    const int b { a };      // b is usable in constant expressions
    const long c { a + 2 }; // c is usable in constant expressions (operator+ has constant expression operands)

    // Other variables cannot be used in constant expressions (even when they have a constant expression initializer)
    int d { 5 };            // d is not usable in constant expressions since the variable is not constant
    const int e { d };      // e is not usable in constant expressions since initializer is not a constexpr
    const double f { 1.2 }; // f is not usable in constant expressions since it has been initialized with floating point without being explicitly constexpr (only integer type allowed in this case for usable)

    char g { 'q' };         // g is not usable, since it is not a constant expression because is not const, though initializer liter it is
    const int h { g * 2 };  // h is not a constant expression, not usable, because intializer isn't it also because of g
    // IN CASE const g { 'q' }; it wold be because is an INTEGER TYPE variable!!!
    
    const double i { 1.2 }; // i is not usable (no constant expression) because its initializer is not integer type, though literal is constant expression, even with const qualifier
    const int j { d * 2 };  // not constant expression because of d
    
    return 0;
}