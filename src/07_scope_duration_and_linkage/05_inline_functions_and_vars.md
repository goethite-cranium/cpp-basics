# Inline functions and inline variables

**Downside of using normal functions**: every time a function is called, there is a certain amount of performance **overhead** that occurs (store current address to return later, store the variables,  copy intialization of the function parameters, and jumping back after function's return).
**If the function body is large, the overhead is neglictable, but for small functions, this can be impactful if it is constantly used**.


### Inline expansion
**Inline expansion avoids this overhead replacing a funciton call by the code from the function's defition.**
Downside: expansion cost is greater the larger the function's body is. **Thus, inline expansion is only suitable for short and simple functions**.

When are functions inline expanded?
* May be expanded (most functions fall in this category). Modern compilers decide it after assesing the candidate function.
* Can't be expanded. Most of them is because the function's definition is in another transicion unit (file).
Since modern optimizers evaluate inline expansions, keyword ```inline``` is not longer recommended and usable.


### ```inline``` keyword usage in modern cpp
* Issue: The functions with external linkage shouldn't be implemented implemented in header files because when those headers are included into multiple .cpp files, the function definition will be copied into multiple .cpp files. This files then will be compiled, and the linker will throw an error beacause it will note that you've defined the same function more than once, violating ODR (one-definition rule).

* Solution: **```inline``` has evolved to mean "multiple definitions are allowed". Thus, an inline fuinctions is one that is allowed to be defined in multiple translation units without violating ODR.**
Requirements:
- The compiler needs to be able to see the full defintion of an inline function in each translation unit where the function is used (**forwar declarations not valid**)
- The definition can ocurr after the pint of use if a forward declaration is also provided. However, the compiler will likely not be able to perform inline expansion until it has seen the defintion (**any uses between the declaration and definition will probably not be canddidates for inline expansion**)
- Every definition for an inline function with external linkage must be identical, otherwise undefined behavior.

Example:
main.cpp
```cpp
#include <iostream>

double circumference(double radius); // forward declaration

inline double pi() { return 3.14159; }

int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}
```

math.cpp
```cpp
inline double pi() { return 3.14159; }

double circumference(double radius)
{
    return 2.0 * pi() * radius;
}
```

Both files have function pi defined, however, since they have been keyworded as ```inline```, this is acceptable and the linker will de-duplicate them. If ```inline``` is removed, then a violation of ODR.


**Inline functions are typically defined in header files, where they can be included into the top of any code file that need to see the full definition of the identifier. This ensures that all inline definitions for an identifier are identical**:

Example:
pi.h
```cpp
#ifndef PI_H
#define PI_H

inline double pi() { return 3.14159; }

#endif
```

main.cpp
```cpp
#include "pi.h" // will include a copy of pi() here
#include <iostream>

double circumference(double radius); // forward declaration

int main()
{
    std::cout << pi() << '\n';
    std::cout << circumference(2.0) << '\n';

    return 0;
}
```

math.cpp
```cpp
#include "pi.h" // will include a copy of pi() here

double circumference(double radius)
{
    return 2.0 * pi() * radius;
}
```


**Useful for header-only libraries, which are one or more header files that implement some capability (no .cpp files are included)**. They are popular because no additional source files have to be added to a project to use them and nothing that need to be linked. Simply #inlcude the header-only library and then can use it.

> **VERY IMPORTANT**: YOU SHOULD NOT MARK YOUR FUNCTIONS OR VARIABLES AS INLINE UNLESS YOU ARE DEFINING THEM IN A HEADER FILE (AND THEY ARE NOT IMPLICITLY INLINE SUCH AS methods from class, struct or union type definitions, constexpr / consteval functions, and functions implicitly instantiated from function templates).

Do not make all functions ```inline``` and defined in header file because it will increase the compile time.
1. When a header containing an inline function is #included into a source file, that function definition will be compiled as part of that translation unit. An inline function #included into 6 translation units will have its definition compiled 6 times (before the linker deduplicates the definitions). Conversely, a function defined in a source file will have its definition compiled only once, no matter how many translation units its forward declaration is included into.
2. Second, if a function defined in a source file changes, only that single source file needs to be recompiled. When an inline function in a header file changes, every code file that includes that header (either directly or via another header) needs to recompiled. On large projects, this can cause a cascade of recompilation and have a drastic impact.

This means header-only libraries have downsides such as more compilation time and the implementation code is exposed.
Advantages are that implement things that needs to know the user-types, such as templates, since the compiler need to see the implemetation. Thus, templates are always placed in headers. Also for small libraries.

> **IMPORTANT SUMMARY**: When a header is #included, its contents are effectively copied into the target .cpp file during preprocessing. Therefore, if the header contains a function definition, including it in multiple .cpp files normally results in multiple definitions of that function, violating the ODR. Marking the function as inline allows the same definition to appear in multiple translation units. 
> If the header contains only a declaration (e.g. a forward declaration), no multiple definitions are created, so inline is not needed. The function can then have a single definition in one .cpp file.