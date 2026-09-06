# std::string and output manipulators indtroduction

### Introduction
C-style string literals notes in 05/02_Literals.md.
C-style string literals are odd since they are const and can be dangerous (copy larger C-string into the space allocated for a shorter C-string, undefined behavior). In modern cpp they are avoided.

```std::string``` and ```std::string_view``` (cpp17) are recommended. Not fundamental types (rather class types) and are imported with ```<string>``` header.

### std::string features
* Have common initialization and copy assigment

* ==**Handles strings literals of different lengths**(request memory at runtime using dynamic memory allocation). **This makes the ```std::string``` flexible but slower than C-style strings**.
Length can be accessed with ```.length()``` mehtod, and return the exact number of chars, ignoring null-terminator char. It return an unsigned integer, normaly a ```size_t```. To assignt it to int, ```static_cast``` is needed.
cpp20 allows to use ```std::ssize()``` function to get the length of a ```std::string``` as a large signed integral type (usually ```std::ptrdiff_t```). Since ```std::ptrdiff_t``` may be larger than an ```int```, ```static_cast``` is also needed.==

* **Initializing a ```std::string``` is expensive** since a copy of the string is used to perform the initialization, and string copies is very expensive.

* **Do not pass ```std::string``` by value** since the copy will be intialized so the point before happens again, adding overhead. This copy is very expensive. Instead, use ```std::string_view``` or reference.

* **Sometimes is ok to return ```std::string``` by value**. Usually, the return value is copied from function back to the caller, but in the case of ```std::string``` this does not happen when the return statement resolves this any of these cases (support move semantics, that allows an object that will be destroyed at the end of the function to instead be returned by value without making a copy):
    1. a local variable of type ```std::string```
    2. a ```std::string``` that has been returned by value from another function call or operator
    3. a ```std::string``` temporary that is crearted as part of the return statement
**But is prefered to avoid returning ```std::string``` by value, since other circumstances this won't happen. If returning a C-style string literal, use ```std::string_view``` instead as return type.**

* To avoid using the odd type C-string type strings, **s suffix forces a string literal to be type ```std::string```**. The suffix has to be imported with ```using namespace std::string_literals;```. **They are only important in type deduction**.

* Has odd interaction with ```std::cin```: ```operator>>``` used to extract a string from ```std::cin``` only return chars up to first whitspace, the rest is buffered, so they will extracted in next request even typed new things (see code). To avoid this and **extract chain after \n (line), use ```std::getline()``` with ```std::cin >> std::ws``` ant target variable string, eg., 
```
std::string color {};
std::getline(std::cin >> std::ws, color);
```

* Is null terminated, but its methods and interactions ignore it. **You can access to its internal C-style string with .c_str() member**


### Output manipulators
We can override default behavior of ```std::cout``` and ```std::cin``` with **output manipulators**.
**Output manipulators are sticky**, this is, they remain set, except for ```std::stew``` and ```std::ws```.
* ```std::ws``` from ```std::getline(std::cin >> std::ws, color);``` is an output manipulator that tells ```std::cin``` to ignore any leading whitespace before extraction. If ```std::ws``` wasn't have used, the line would have terminated after first whitespace. ```std::cin >> std::ws``` can be interpreted as output also the whitespaces from the input to the target.
* ```std::cin >> std::boolalpha;``` or ```std::cout << std::boolalpha;```to allow the console to interpret true or false in command line as bools. Deactibated with ```std::noboolalpha```
* ```std::setprecision()``` modifies the ```std::cout``` default behhavior of 6 digits as max precision for floating point types, eg., 
``` 
std::cout << std::setprecision(2);
std::cout << 6.123456789;
```

### constexpr strings
```constexpr std::string``` is not supported at all in cpp17 or earlier, and works in limited cases for cpp20+
If needed a constexpr string, then use ```std::string_view```
