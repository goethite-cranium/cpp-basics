# Operators precedence and associativity

### Table of operator precedence and associativity
Level 1 is highest precedent level and 17 the lowest. Higher precendence means theya re grouped first
L->R means left to right associativity, R->L right to left


| Precedence / Associativity | Operator           | Description                                      | Pattern                                |
| -------------------------: | :----------------- | :----------------------------------------------- | :------------------------------------- |
|                  **1 L→R** | `::`               | Global scope (unary)<br>Namespace scope (binary) | `::name`<br>`class_name::member_name`  |
|                  **2 L→R** | `()`               | Parentheses                                      | `(expression)`                         |
|                            | `()`               | Function call                                    | `function_name(arguments)`             |
|                            | `type()`           | Functional cast                                  | `type(expression)`                     |
|                            | `type{}`           | List initialization temporary object (C++11)     | `type{expression}`                     |
|                            | `[]`               | Array subscript                                  | `pointer[expression]`                  |
|                            | `.`                | Member access from object                        | `object.member_name`                   |
|                            | `->`               | Member access from object pointer                | `object_pointer->member_name`          |
|                            | `++`               | Post-increment                                   | `lvalue++`                             |
|                            | `--`               | Post-decrement                                   | `lvalue--`                             |
|                            | `typeid`           | Run-time type information                        | `typeid(type)` or `typeid(expression)` |
|                            | `const_cast`       | Cast away `const`                                | `const_cast<type>(expression)`         |
|                            | `dynamic_cast`     | Run-time type-checked cast                       | `dynamic_cast<type>(expression)`       |
|                            | `reinterpret_cast` | Cast one type to another                         | `reinterpret_cast<type>(expression)`   |
|                            | `static_cast`      | Compile-time type-checked cast                   | `static_cast<type>(expression)`        |
|                            | `sizeof...`        | Get parameter pack size                          | `sizeof...(expression)`                |
|                            | `noexcept`         | Compile-time exception check                     | `noexcept(expression)`                 |
|                            | `alignof`          | Get type alignment                               | `alignof(type)`                        |
|                  **3 R→L** | `+`                | Unary plus                                       | `+expression`                          |
|                            | `-`                | Unary minus                                      | `-expression`                          |
|                            | `++`               | Pre-increment                                    | `++lvalue`                             |
|                            | `--`               | Pre-decrement                                    | `--lvalue`                             |
|                            | `!`                | Logical NOT                                      | `!expression`                          |
|                            | `not`              | Logical NOT                                      | `not expression`                       |
|                            | `~`                | Bitwise NOT                                      | `~expression`                          |
|                            | `(type)`           | C-style cast                                     | `(new_type)expression`                 |
|                            | `sizeof`           | Size in bytes                                    | `sizeof(type)` or `sizeof(expression)` |
|                            | `co_await`         | Await asynchronous call                          | `co_await expression` (C++20)          |
|                            | `&`                | Address of                                       | `&lvalue`                              |
|                            | `*`                | Dereference                                      | `*expression`                          |
|                            | `new`              | Dynamic memory allocation                        | `new type`                             |
|                            | `new[]`            | Dynamic array allocation                         | `new type[expression]`                 |
|                            | `delete`           | Dynamic memory deletion                          | `delete pointer`                       |
|                            | `delete[]`         | Dynamic array deletion                           | `delete[] pointer`                     |
|                  **4 L→R** | `->*`              | Member pointer selector                          | `object_pointer->*pointer_to_member`   |
|                            | `.*`               | Member object selector                           | `object.*pointer_to_member`            |
|                  **5 L→R** | `*`                | Multiplication                                   | `expression * expression`              |
|                            | `/`                | Division                                         | `expression / expression`              |
|                            | `%`                | Remainder                                        | `expression % expression`              |
|                  **6 L→R** | `+`                | Addition                                         | `expression + expression`              |
|                            | `-`                | Subtraction                                      | `expression - expression`              |
|                  **7 L→R** | `<<`               | Bitwise shift left / insertion                   | `expression << expression`             |
|                            | `>>`               | Bitwise shift right / extraction                 | `expression >> expression`             |
|                  **8 L→R** | `<=>`              | Three-way comparison (C++20)                     | `expression <=> expression`            |
|                  **9 L→R** | `<`                | Less than                                        | `expression < expression`              |
|                            | `<=`               | Less than or equal                               | `expression <= expression`             |
|                            | `>`                | Greater than                                     | `expression > expression`              |
|                            | `>=`               | Greater than or equal                            | `expression >= expression`             |
|                 **10 L→R** | `==`               | Equality                                         | `expression == expression`             |
|                            | `!=`               | Inequality                                       | `expression != expression`             |
|                 **11 L→R** | `&`                | Bitwise AND                                      | `expression & expression`              |
|                 **12 L→R** | `^`                | Bitwise XOR                                      | `expression ^ expression`              |
|                 **13 L→R** | `\|`               | Bitwise OR                                       | `expression \| expression`             |
|                 **14 L→R** | `&&`               | Logical AND                                      | `expression && expression`             |
|                            | `and`              | Logical AND                                      | `expression and expression`            |
|                 **15 L→R** | `\|\|`             | Logical OR                                       | `expression \|\| expression`           |
|                            | `or`               | Logical OR                                       | `expression or expression`             |
|                 **16 R→L** | `throw`            | Throw expression                                 | `throw expression`                     |
|                            | `co_yield`         | Yield expression (C++20)                         | `co_yield expression`                  |
|                            | `?:`               | Conditional                                      | `expression ? expression : expression` |
|                            | `=`                | Assignment                                       | `lvalue = expression`                  |
|                            | `*=`               | Multiplication assignment                        | `lvalue *= expression`                 |
|                            | `/=`               | Division assignment                              | `lvalue /= expression`                 |
|                            | `%=`               | Remainder assignment                             | `lvalue %= expression`                 |
|                            | `+=`               | Addition assignment                              | `lvalue += expression`                 |
|                            | `-=`               | Subtraction assignment                           | `lvalue -= expression`                 |
|                            | `<<=`              | Bitwise shift left assignment                    | `lvalue <<= expression`                |
|                            | `>>=`              | Bitwise shift right assignment                   | `lvalue >>= expression`                |
|                            | `&=`               | Bitwise AND assignment                           | `lvalue &= expression`                 |
|                            | `\|=`              | Bitwise OR assignment                            | `lvalue \|= expression`                |
|                            | `^=`               | Bitwise XOR assignment                           | `lvalue ^= expression`                 |
|                 **17 L→R** | `,`                | Comma operator                                   | `expression, expression`               |

### Quick mental model

```text
Higher precedence
        ↓
1   ::                  Highest
2   () [] . -> ++ --    Postfix
3   + - ! ~ ++ -- * &   Unary
4   ->* .*
5   * / %
6   + -
7   << >>
8   <=>
9   < <= > >=
10  == !=
11  &
12  ^
13  |
14  &&
15  ||
16  ?: = += -= ...      Assignment
17  ,                   Lowest
        ↑
Lower precedence
```

### Important rule
Precedence and associativity determine **how an expression is grouped**, **not the order in which operands are evaluated**.
For example:
```cpp
4 + 2 * 3
```
is grouped as:
```cpp
4 + (2 * 3)
```
because `*` has higher precedence than `+`.

The evaluation of operands is often not important, but scripts like this are wrong because we do not know when each function call is going to be
evaluated, so it is unpredictible the result. For clang, the getValue() calls are going to be resolve right-left, while other compiler may do it 
left-right. **OPERATORS, FUNCTION ARGUMENTS AND SUBESEXPRESSION MAY BE EVALUATED IN ANY ORDER**.
```cpp
#include <iostream>

int getValue()
{
    std::cout << "Enter an integer: ";

    int x{};
    std::cin >> x;
    return x;
}

void printCalculation(int x, int y, int z)
{
    std::cout << x + (y * z);
}

int main()
{
    printCalculation(getValue(), getValue(), getValue()); // this line is ambiguous

    return 0;
}
```