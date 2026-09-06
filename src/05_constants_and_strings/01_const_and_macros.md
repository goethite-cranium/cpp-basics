# Constant variables (named constants)
Constant vars don't change their values durign program's execution.
C++ support two types of constants:
* **Named constants or symbolic constants** (associated with an identifier)
* **Literal constants** (constants not associated with an identifier)


# Types of named constants
* **Constant variables** (covered in this lesson)
* **Object-like macros with substitution text** (a macro is a rule that defines how input text is converted into replacement output text, such as wiht #include)
* **Numereted constants** (covered in lesson 13)


### Named constants: Constanted variables
* Defining constant variables helps ensure that this values isn't accidentally changed
* Potentially provides more chances for compiler optimization
* Reduces semantically the complexity of our programs, reducing work during debugging, reducing movable parts

To define a const variable, it is used the const keyword or const qualifier (eg., ```const double gravity { 9.8 };```)
Altertnatively, though discoraged, can be employed the east const contation: ```double const gravity { 9.8 };```

**const variables must be initialized, otherwise error**
```
const double gravity; // error
gravity = 9.8; // error
```

**Const does not necessarily mean compile-time constant**
```const``` means that the object cannot be modified thorugh that name after initialization. It does **not**, by itself, guarantee that its value is known at compile time (**compile-time constant**).
* **const** -> cannot be modified after initialization
* **compile-time constant / constant exession** -> Value can be evaluated during compilation
* **constexpr** -> explicitly declares that a variable/functions is intended and required to be usable in constant-evaluation contexts

**Notation**: as they act as normal variables, they follow the normal variable convention, though some programmers might named them upper-case (EARTH_GRAVITY) or with suffix k (kEarthGravity)

**Const function parametrs**: function parameters can be casted to const, though this is discoraged since we do not care if they are const or not, since those are copies from the original values and will be destroyed after function execution. Also, adds small amount of unnecessary clutter to the function prototype (Unless viewer, references, etc.)
(eg. ```void exampleWithConstParameters(const int x);```)

**Const return values**: The funtion output may also made const (eg. ```const int getValue()```). This is discoraged because:
* for fundamental datatypes, const qualifier on retuyrn type is ingnored and the compiler may generate a warning
* For other types, this has no point because they are temporary copies that will be destroyed anyway
* Prevents certain kinds of compiler optimization

**Constant variables are preferred over object-like macros**: object-like macros have three major problems:
1. They do not follow the standard cpp scoping rules, so every varible with the same name will be substitude, even in parameters, for example:
```
#include <iostream>

void someFcn()
{
// Even though gravity is defined inside this function
// the preprocessor will replace all subsequent occurrences of gravity in the rest of the file
#define gravity 9.8
}

void printGravity(double gravity) // including this one, causing a compilation error
{
    std::cout << "gravity: " << gravity << '\n';
}

int main()
{
    printGravity(3.71);

    return 0;
}
```
2. Harder to debug because macros cannot be seen by the compiler, since the preprocessor is the one that substitudes text
3. Behaves extrangely, so some inadvertent mistakes can happen


### Named constants: Object-like macros with substitution text
When the preprocessor process the file, it replaces all macro variables with their definition. 
They are alson constant.

example:
```
#include <iostream>

#define MY_NAME "Alex"

int main()
{
    std::cout << "My name is " << MY_NAME << '\n';

    return 0;
}
```


# Type qualifiers
Are kwords taht are applied to a type tahat modifies how that type behaves. 
```volatile``` qualifier is ery rarely used, and also disables certain optimizations. It tells that variable may have its value changed at any time. const and volatile can are known also as **cv-qualifiers**.


# Introduction to optimization
The compiler has the optimizer deactivated by default, to avoid dificulting the debugging.
Thus, this must be switched on when the program works. 
There are two types of informal type constants whether the time the constant has been deduced:
* **Compile-time constant**, ==its value can be determined during compilation==, such as literals and constant objects whose initializers are compile-time constants.
* **Runtime constant**, ==its value cannot be determined until runtime, but one initialized it cannot be modified==, such as constant function parameters and constant objects whose intializers are non-constants or runtime constants.

```
#include <iostream>

int five()
{
    return 5;
}

int pass(const int x) // x is a runtime constant
{
    return x;
}

int main()
{
    // The following are non-constants:
    [[maybe_unused]] int a { 5 };

    // The following are compile-time constants:
    [[maybe_unused]] const int b { 5 };       // b is compile-time
    [[maybe_unused]] const double c { 1.2 };  // c is runtime (not int type)
    [[maybe_unused]] const int d { b };       // b is a compile-time constant

    // The following are runtime constants:
    [[maybe_unused]] const int e { a };       // a is non-const
    [[maybe_unused]] const int f { e };       // e is a runtime constant
    [[maybe_unused]] const int g { five() };  // return value isn't known until runtime
    [[maybe_unused]] const int h { pass(5) }; // return value isn't known until runtime

    return 0;
}
```


NOTE:
A const variable initialized with a constant expression can itself be a compile-time constant, including floating-point types. However, some specific C++ contexts require an integral constant expression, in which case a double does not qualify.