# Constexpr variables 

### The compile-time ```const``` challenge
A ```const``` variable with an integral type and a constant expression initializer are usable in constant expresssions, but all other ```const``` variables cannot (previous lesson).
Nevertheless,  ```const``` to create constant expression has few challenges:

1. ==```const``` does not make inmidiately clear whether a variable is usable in a constant expression or not==:
eg.
```
const int a { 5 };          // clearly a constant expression since initializer
                            // is constant expression
const int d { getValue() }; // not obvious wheter d is usable in a 
                            // constant expression or not
```
2. ==```const``` does not provide a way to inform the compiler that we require a variable that is usable in a constant expression== (and that it should halt compilation if it isn't).
3. ==The use of ```const``` to create compile-time constant variables does not extend to non-integral variables.


### The ```constexpr``` keyword
As a solution, ```constexpr``` qualifier can be used instead of ```const``` in a variable declaration. 

**```constexpr``` variable is always compile-time constant, thus must be initialized with a constant expression, otherwise compilation error**. 

eg.
```
int five()
{
    return 5;
}

---

constexpr double gravity { 9.8 };   // ok
constexpr int sum { 4 + 5 };        // ok
constexpr int something { sum };    // ok

std::cout << "Enter your age:";
int age{};
std::cin >> age;

constexpr int myAge { age };        // compilation error
constexpr int f { five() };         // compilation error
```

**Because functions normally execute at runtime, the return value of a normal function is not a constexpr even when the return expression is constant expression**.

**Aditionally, ```constexpr``` works for variables with non-integral types**


### Why ```const``` vs ```constexpr```
For variables:
* **```const``` means that the value of an object cannot be changed after initialization**. The value of the initializer may be known at compile or runtime. The const object can be evaluated at runtime.
* **```constexpr``` means taht the object can be used in constant expression. thus the value of the initializer must be known at compile-time**. The constexpr object can be evaluated at runtime or compile-time.

**Unlike ```const```, ```constexpr``` is not part of object's type, but also has const type**. eg.: ```constexpr int``` is type ```const int``` due to implicit const of constexpr.

---
**Best practice**:
* Any constant variable whose intializer is constant expression should be declared as ```constexpr```
* Any constant variable whose intiliazer is not constant expression (making of it a runtime variable) should be declared as ```const```
---

Types not compatible with ```constexpr``` are ```std::string```, ```std::vector``` and other types of dynamnic allocation, but are compatible with ```const```. Another solution is to choose more suitable type such as ```std::string_view``` or ```std::array```.


### Const and constexpr function parameters
Normal function calls are evaluated at runtime, with the supplied arguments being used to initilize funtion's parameters. This leads to:
1. ```const``` function parametrs are treated as runtime constants always
2. Function parameters cannot be declared as ```constexpr```, since their intialization value isn't determined until runtime.


### Constexpr functions
**constexpr functions are functions that can be called in a cosntant expression**. 
To declare a constexpr function just placed the ```constexpr``` qualifier before, eg., ```constexpr double calcCircumference(double radius)```.

Must be evaluated compile-time when it is part of a must evaluate compile-time expression, such as initializers of constexpr variable. Otherwise may be evaluated at either compile-time if eligible or runtime.
**This means that constexpr function means that the function is allowed to be evaluated a compile time, provided that a particualr call satisfies all requirement for constant evaluation**.

**It is eligible to compile-time if function calls inside are constexpr and arguments are available at compile-time (constant expressions, literals, etc)**. If the parameters of the constexpr function are not constexpr, then it won't failed to compile, but will be evaluated runtime. The statemnts inside the function do not need to be declared constexpr, and local variables do not need to be constexpr to be evaluated compile-time.

constexpr function
        ↓
can participate in constant evaluation
        ↓
particular function call
        ↓
are its arguments and executed operations
valid for constant evaluation?
        ↓
      YES
        ↓
can be evaluated at compile time
        ↓
if the context requires a constant expression
        ↓
MUST be evaluated at compile time