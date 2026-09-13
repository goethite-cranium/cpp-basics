# Global variables and linkage

Definitions
* **Global variables**: variables defined outside of a function.

* **Linkage**: an identifier's linkage determines whether other declarations of that name refer to the same object or not. Remember local variables has no linkage.

* **```internal linkage```**: if two source files have identically named identifiers with internal linkage, those identifiers are treated as independent (and do not result in a ODR violation). Thus, an identifier that has internal linkage can only be used in that source file.
We would like to make an identifier ```internal linkage``` because:
1. Make an identifier unaccesible from other files to avoid messing arround with helpers, or for private reasons
2. To be pedantic about avoiding name collisions.
> Recomendation: if the variable or function is not going to be used in other files, make it ```internal linkage```.
```#include``` can still be used with headers containing identifiers with internal linkage. However, ```#include``` inserts the definition into each translation unit during preprocessing, so each translation unit gets a separate, independent entity rather than a reference to the original entity. Therefore, these entities do not violate the ODR.

* **```external linkage```**: an identifier with ```external linkage``` can be seen and used both from the file in which it is defined, and from other code files, making it truly global. This exposes the identifiers to name collisions.

* Definition (implementation) is different to declaration (header).

- ```static``` keyworded makes functions and global variables ```internal linkage```. Falling out of favor, consider use unnamed namespaces instead. Making static makes duration be static, which means they are created when the program starts and destroyed when the program ends.
- forward declarations are always ```external linkage```
- non-constant global variables are by default ```external linkage```
- constant or constexpr global variables are ```internal linkage```
- functions are by default ```external linkage```


### How global variables work
* To **declare global variables** the convention is to **do it at the top line just below the includes**

* They are in **global scope (or global namespace scope)**, so they are visible from the point of declaration until the end of the file in which they are declared. Once declare **they can be use in any part of the file**. Better practice is to define them in a namespace.

* global variables **have static duration**, which means global variables are created when program starts (before ```main()``` begin execution), and destroyed when it ends.

* Preferred naming uses prefixed ```g_``` or ```g``` when they are defined in the global namespace. If they are in a user-defined namespace, the prefix can be omited. **Prefix notation that represent *scope* or *duration* in variables add value and thus is ok**.

* Unlike local variables (which are uninitialized by default), variables with static duration are **zero-initialized by default**.

* global variables **can be constant** (and thus constexpr). As normal constants, they must be initialized explicitly.

* **They should be avoided or make them constant**.

* Global variables can have either ```internal linkage``` or ```external linkage```. 
**Non-constant globals have ```external linkage``` by default.**
**```const``` and ```constexpr``` globals have ```internal linkage``` by default.**
**To make a global variable independent, use ```static``` keyword.**
> **IMPORTANT**: functions can also use ```static``` keyword, giving them also ```internal linkage```, since by default they are ```external linkage```.
> This is useful to avoid functions to be imported in another files

* external global variables from the file can be used with ```extern``` keyword, ie., ```extern int g_x;```
In this use, ```extern``` means a forward declaration for an external variable that is defined somewhere else, thus, **Avoid using ```extern``` on a non-constant global variable with intializer**
```extern``` can be used to make constant and constexpr global varibles ```external linkage```, ie., ```extern const int g_x { 3 };```

* **AVOID NON-CONSTANT GLOBAL VARIABLES**. Because:
1. Their value can be changed in any call, loosing track of their value
2. They are always initialized (alongside the rest of static variables) before main, so they cannot be initialized with values from main or forward declarations. 
**Only use them when:**
Reduce program complexity (very rare case) for example a log file string or random generator.
As a rule of thumb, any use of a global variable should meet at least the following two criteria: There should only ever be one of the thing the variable represents in your program, and its use should be ubiquitous throughout your program.