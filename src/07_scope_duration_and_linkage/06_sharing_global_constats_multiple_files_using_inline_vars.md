# Sharing global constants accorss multiple files (using inline variables)
Constant variables such as PI, AVOGRADO'S constant, etc, should be declared once in a central location and then use it wherever needed.

### Prior to cpp17: global variables as internal variables
The easist solution is:
1. Create a header file to hold those constants
2. Inside that header, define a namespace
3. Add constants in that header with ```constexpr```
4. Use ```operator::``` to access to the namespace once #included in .cpp files to use the variables

e.g.
cosntants.h
```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define your own namespace to hold constants
namespace constants
{
    // Global constants have internal linkage by default
    constexpr double pi { 3.14159 };
    constexpr double avogadro { 6.0221413e23 };
    constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
```

main.cpp
```cpp
#include "constants.h" // include a copy of each constant in this file
#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
```

When this header gets #included into a .cpp file, each of these variables defined in the header will be copied into that code file at the point of inclusion. Because these variables live outside of a function, they’re treated as global variables within the file they are included into, which is why you can use them anywhere in that file.
Because const globals have internal linkage, each .cpp file gets an independent version of the global variable that the linker can’t see. In most cases, because these are constexpr, the compiler will simply optimize the variables away.
Downside: **every time the header is #included in different code file, each of the variables are copied into the includign code file**. Thus, changing a single constant makes recompilation needed for all source files in which was included, and if constants are large in size may waste a lot of memory. 

Advantages:
* Works prior to C++17.
* Can be used in constant expressions in any translation unit that includes them.
Disadvantages:
* Changing anything in the header file requires recompiling files including the header.
* Each translation unit including the header gets its own copy of the variable.


### Prior to cpp17: Global constants as external variables
Making the variables external linkage they can be initialized once (a single var exists) and it is shared accross files.
1. Define constants in a .cpp file (to ensure definition exists only in one place)
2. Make forward declaration of the global variables as ```extern constexpr``` in the header file.

e.g., 
constants.cpp
```cpp
#include "constants.h"

namespace constants
{
    // We use extern to ensure these have external linkage
    extern constexpr double pi { 3.14159 };
    extern constexpr double avogadro { 6.0221413e23 };
    extern constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
}
```

constants.h
```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants
{
    // Since the actual variables are inside a namespace, the forward declarations need to be inside a namespace as well
    // We can't forward declare variables as constexpr, but we can forward declare them as (runtime) const
    extern const double pi;
    extern const double avogadro;
    extern const double myGravity;
}

#endif
```

main.cpp
```cpp
#include "constants.h" // include all the forward declarations

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
```

Advantages:
* Works prior to C++17.
* Only one copy of each variable is required.
* Only requires recompilation of one file if the value of a constant changes.
Disadvantages:
* Forward declarations and variable definitions are in separate files, and must be kept in sync.
* Variables not usable in constant expressions outside of the file in which they are defined.


### cpp17+: Global constants as inline variables (preferred)
Constexpr functions are implicitly inline, but constexpr variables are not, so they need ```inline``` keyword.
1. Create a header file with namespace to hold global constants
2. Define global constants as ```inline constexpr``` in header

e.g.,
cosntants.h
```cpp
#ifndef CONSTANTS_H
#define CONSTANTS_H

// define your own namespace to hold constants
namespace constants
{
    inline constexpr double pi { 3.14159 }; // note: now inline constexpr
    inline constexpr double avogadro { 6.0221413e23 };
    inline constexpr double myGravity { 9.2 }; // m/s^2 -- gravity is light on this planet
    // ... other related constants
}
#endif
```

main.cpp
```cpp
#include "constants.h"

#include <iostream>

int main()
{
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}
```

Advantages:
* Can be used in constant expressions in any translation unit that includes them.
* Only one copy of each variable is required.

Downsides:
* Only works in C++17 onward.
* Changing anything in the header file requires recompiling files including the header.