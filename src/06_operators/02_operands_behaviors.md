# Operands behaviors

### operator/
```operator/``` division outputs different values depending on type operands: if any operand float -> output float. If both are int -> outpunt int
eg., ```7.0 / 4 = 1.75```, ```7.0 / 4.0 = 1.75```, ```7 / 4.0 = 1.75```, ```7 / 4 = 1```, ```-7 / 4 = -1```.
So, to make sure we choose the desired output, use ```static_cas<>``` on the operands whether is necessary.
Division by ```/ 0``` is undefined behavior and likely crash program.
Division by ```/ 0.0 ``` is implementation-defined (determined by compiler/architecture), many times resulting on Nan or Inf


### Power operator
**There is no exponenent operator, rather the function ```std::pow(x, y)```. It is imported with header ```<cmath>```**. Preferred use with long (double)
because of float lack precission. **There is no pow function for integers** and should be user-implementd.


### operator%
```operator%``` is called reminder operator OR modulos operator, it is preferred to compore its output to 0 to avoid unexpected negative outputs, 
like when checking if a number is odd: ```return (x % 2) != 0;``` preferred over ```return (x % 2) == 1```


### Incremental/decremental oeprators
**Incremental/decremental operators** has pre and post versions: 
* **Pre version -> increment var, then return var** (```++x```, ```--x```)
    This means that
    ```cpp
    int x { 5 };
    int y { ++x }; // y = 6
    ```
    > PREFERRED: **FAVOR PREFIX VERIONS SINCE ARE MORE EFFICIENT AND LESS ERROR PRONE**
* **Post version -> copy var, then increment/decrement, then return copy** (```x++```, ```x--```)
    Then:
    ```cpp
    int x { 5 };
    int y { x++ }; // y = 5
    ```
    Because first copy of the operand is made, then the operand (not copy) is incremented, and finally the copy (not original) is evaluated.
    > Best practice: Use only when the alternative code is way more messy

The side effect of incremental/decremental operators of modifying the variable **can cause order evaluation issues**:
```cpp
int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x { 5 };
    int value{ add(x, ++x) }; // undefined behavior: is this 5 + 6, or 6 + 6?
    // It depends on what order your compiler evaluates the function arguments in

    std::cout << value << '\n'; // value could be 11 or 12, depending on how the above line evaluates!
    return 0;
}
```
> **CPP HAS NOT DEFINE THE ORDER EVALUATION OF FUNCTION ARGUMENTS OR THE OPERANDS OF OPERATORS**
> Then do not use variable that has a side effect applied to it more than once in a given statement, because may be undefined,
> only exception is for simple assignment expressions such as ```x = x + y``` equiv to ```x += y```


### operator,
```operator,``` comma allows you to evaluate multiple expressions wherever a single expression is allowed, evaluating first the left the the right, 
and and then **returns the result of the right**
```cpp
int x { 1 };
int y { 2 };
std::cout << (++x, ++y) << '\n'; // increment x and y, then returns right, printing "3\n"

z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated and discarded because of priority
```
> **Avoid using coma operator except for loop expressions**, because is obscure and difficult to interpret at first sight
This is different from separator, fot example:
```cpp
add(x, y);                    // separator comma
constexpr int z{ 3 }, w{ 5 }; // separator comma
```


### operator?:
```operator?:```, conditional operator, is a ternary operator and acts like a if else inline expression returning the chosen statement based on condition:
**```condition ? expression1 : expression2;```**
Can help to compact code.
```cpp
int x { getValue() };
int y { getValue() };
int max { (x > y) ? x : y };
std::cout << "The max of " << x <<" and " << y << " is " << max << ".\n";
```
**It can be used wherever an expression is admitted, also in constant expressions if operands are also constant expressions**.
```cpp
constexpr bool inBigClassroom { false };
constexpr int classSize { inBigClassroom ? 30 : 20 };
```
**That is difficult to replace with if else**:
THIS WON'T COMPILE
```
constexpr bool inBigClassroom { false };

if (inBigClassroom)
    constexpr int classSize { 30 };
else
    constexpr int classSize { 20 };

std::cout << "The class size is: " << classSize << '\n'; // Compile error: classSize not defined
```

**The only possible replacement is to embedded that in a function**
```cpp
constexpr int getClassSize(bool inBigClassroom)
{
    if (inBigClassroom)
        return 30;
    else
        return 20;
}

int main()
{
    constexpr int classSize { getClassSize(false) };
    std::cout << "The class size is: " << classSize << '\n';

    return 0;
}
```

To avoid mistakes due to low priority precedence, then **this parenthisazation is recommended**:
```cpp
return isStunned ? 0 : movesLeft;           // not used in compound expression, condition contains no operators
int z { (x > y) ? x : y };                  // not used in compound expression, condition contains operators
std::cout << (isAfternoon() ? "PM" : "AM"); // used in compound expression, condition contains no operators (function call operator excluded)
std::cout << ((x > y) ? x : y);             // used in compound expression, condition contains operators
```
> **VERY IMPORTANT: THE TYPE OF THE SECOND AND THIRD OPERAND MUST MATCH OR ABLE TO FIND A CONVERSION**
> Alternatively, on or both second and third operands is allow to be throw expression.
eg.
```cpp
std::cout << (true ? 1 : 2) << '\n';    // okay: both operands have matching type int

std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

std::cout << (true ? -1 : 2u) << '\n';  // surprising result: -1 converted to unsigned int, result out of range

constexpr int x{ 5 };
std::cout << ((x != 5) ? x : "x is 5"); // compile error: compiler can't find common type for constexpr int and C-style string literal

int y{ 5 }; // intentionally non-constexpr for this example
// We can explicitly convert the types to match
std::cout << ((y != 5) ? std::to_string(y) : std::string{"y is 5"}) << '\n';
```


### Relational operators
operators ```>```, ```<```, ```>=```, ```<=```, ```==```, ```!=```
> Careful when comparing ```==``` or ```!=``` with floating point numbers due to precision
eg.
```cpp
std::cout << std::boolalpha << (0.3 == 0.2 + 0.1); // prints false
```
One exception: compare a var initialize with a literal against a literal or constexpr of the same type with their significant digits covered in full supported precission.

The best option is use a user-defined function that assumes numbers based on precision rounding or approximation:

```cpp
#include <cmath> // for std::abs()

// absEpsilon is an absolute value
bool approximatelyEqualAbs(double a, double b, double absEpsilon)
{
    // if the distance between a and b is less than or equal to absEpsilon, then a and b are "close enough"
    return std::abs(a - b) <= absEpsilon;
}
```

or scaling epsilon based on the magnitude of the compared number, though it can have issues when approx 0:

```cpp
#include <algorithm> // for std::max
#include <cmath>     // for std::abs

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}
```

Other operators can be considered also unreliable if numbers are close for the same reasons, sometimes one is greater or lower unpredictively


### Logical operators
operators ```!```, ```&&```, ```||```

**Short circuit evaluation**: happens with ```statement1 && statement2``` and ```statement1 || statement2```.
```statement1 && statement2```: Because both statements must be true to return true, if ```statement1``` evaluates to ```false```, then due to optimization the ```statement2``` is not evaluated. If the ```statement2``` have operands with side effect, they are not evaluated unexpectively when ```statement1``` is ```false```.
In the case of ```statement1 || statement2```, if ```statement1``` is ```true``` happens the same.
> **NEVER USE SIDE EFFECT OPERANDS IN RIGHT SIDE STATEMENT OF ```&&``` OR ```||```
DO NOT DO this:
```cpp
if (x == 1 && ++y == 2)
    // do something
```

> When mixing logical AND and OR in a single expression, explicitly parenthesize each operation to ensure they evaluate how intended

**De Morgan's laws**
```!(x && y)``` is equivalent to ```!x || !y```
```!(x || y)``` is equivalent to ```!x && !y```

There is no logical XOR, ```operator^``` is bitwise XOR. **But ```operator!=``` outputs same result as logical XOR when bool operands**.