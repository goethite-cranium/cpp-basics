# Constant expressions

### Introduction and definitions
**Expression definition**: In general programming, an expression is a non-empty sequence of literals, variables, operators, and function calls that calculates a value, an object, a function or nothing. **Epression is only the part that is being evaluted, not the variable assigned to**

By default, expression evaluate at runtime because inputs might not be known yet.
Nevertheless, the compiler may choose whether to evaluate certain expressions at runtime or compile-time
eg.
```
const double x { 1.2 };
const double y { 3.4 };
const double z { x + y }; // x + y may evaluate at runtime or compile-time because x and y are known at compile-time
```

**constexpr variables** require an initializer that can be evaluated at compile-time:
```
constexpr int x { expr }; 
```
Because variable x is a constexpr, expr must be evaluated at compile-time. If constant expression ir required, such in this case, and not provided, error will be risen.

**Constant expression**: expression that must be evaluated at compile-time.

---
COMMON CASES WHERE A COMPILE-TIME EVALIATABLE EXPRESSION IS REQUIERED
* The initializer of a constexpre variable
* A non-type template argument
* The defined length of a ```std::array```
---

### Benefits of compile-time programming
The compiler does not guarantee to evaluate in compile-time these expressions, so we can make it explecit to guarantee it. The benefits of compile-time evaluation are:
* Performance: programs are smaller and faster.
* Versatility
* Predictability: we can have the compiler halt compilation if it determines taht code cannot be executed at compile-time
* Quality: we can have the compiler reliably detect certain kinds of programming errors at compile-time, and halt the build if encounters them, avoiding debugging in runtime. **Undefined behavior is not allowed in runtime**.

Most fundational features to compile-time programming in cpp, an they make **use of constant expressions**:
* **constexpr variables**
* **constexpr functions**
* **templates**
* **static_assert** 

# MOST IMPORTANT
### What constant expressions can and can't contain
They can contain:
* Literals
* Most operators with constant expression operands, eg., ```3+4```, ```2*sizeof(int)```
* Constexpr variables
* Constexpr functions
* **Const integral (int) variables with a constant expresssion initializer**, eg., ```const int x {5};```, which it is an exception, so it is discoraged in favor of constexpr variables
* Non-type template parameters
* Enumerators
* Type traits
* Constexpr lambda expressions

**REMINDER: const variables can be usable (and, thus, constant expressions) in constant expressions only if its initializer satisfies rules for constant expressions and thus it is known at runtime**.

Note: ```std::abs``` was not made ```constexpr``` until cpp23


### When constant expressions are evaluated at compile-time
**The compiler is only required to evaluate constant expressions at compile-time in contexts that require a constant experssion**.
eg.
```
const int x { 3 + 4 }; // constant expression 3+4 MUST be evaluated at compile time (because fits usable at compile time)
int y { 3 + 4 };       // constant expression 3+4 may be evaluated at compile-time or runtime
const double d { 1.2 };// constant expression 1.2 may be evaluated at compile-time or runtime, because it is not usable in constant expression
```
