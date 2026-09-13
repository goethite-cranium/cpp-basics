# Variable shadowing or name hiding

Definition:
* **Variable shadowing or name hiding in local variables**: A variable with the same identifier can be created in different nested blocks because each block creates its own scope region. When this happens, the nested variable (or the variable that are in its scoped in that moment) hides the outer variable in areas where both are in scope.

* **Variable shadowing or name hiding in global variables**: The same can happen with global variables, but also in other functions, since they are always in scoped for the file. Though as they belong to the global scope, **they can be invoke explicitly with ```::``` prefix, such as ```::g_x```**.

**Variable shadowing should be avoided**, and GCC and Clang support flags ```-Wshadow``` to generate warnigs for it (alongside its variants).