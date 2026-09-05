# Summary

### Nomenclature recap
A **constant** is a value that may not be changed during the program’s execution. C++ supports two types of constants: named constants, and literals.

A **named constant** is a constant value that is associated with an identifier. A Literal constant is a constant value not associated with an identifier.

A variable whose value can not be changed is called a **constant variable**. The ```const``` keyword can be used to make a variable constant. Constant variables must be initialized. Avoid using ```const``` when passing by value or returning by value.

A **type qualifier** is a keyword that is applied to a type that modifies how that type behaves. As of C++23, C++ only supports ```const``` and ```volatile``` as type qualifiers.

A **constant expression** is an expression that can be evaluated at compile-time. An expression that is not a constant expression is sometimes called a ```runtime expression```.

A **compile-time constant** is a constant whose value is known at compile-time. A **runtime constant** is a constant whose initialization value isn’t known until runtime.

A **constexpr** variable must be a compile-time constant, and initialized with a constant expression. Function parameters cannot be constexpr.

**Literals** are values inserted directly into the code. Literals have types, and literal suffixes can be used to change the type of a literal from the default type.

A **magic number** is a literal (usually a number) that either has an unclear meaning or may need to be changed later. Don’t use magic numbers in your code. Instead, use symbolic constants.

In everyday life, we count using **decimal** numbers, which have 10 digits. Computers use **binary**, which only has 2 digits. C++ also supports **octal** (base 8) and **hexadecimal** (base 16). These are all examples of numeral systems, which are collections of symbols (digits) used to represent numbers.

A **string** is a collection of sequential characters that is used to represent text (such as names, words, and sentences). String literals are always placed between double quotes. String literals in C++ are C-style strings, which have a strange type that is hard to work with.

```std::string``` offers an easy and safe way to deal with text strings. ```std::string``` lives in the ```<string>``` header. ```std::string``` is expensive to initialize (or assign to) and copy.

```std::string_view``` provides read-only access to an existing string (a C-style string literal, a ```std::string```, or a char array) without making a copy. A ```std::string_view``` that is viewing a string that has been destroyed is sometimes called a **dangling view**. When a ```std::string``` is modified, all views into that ```std::string``` are invalidated, meaning those views are now invalid. Using an invalidated view (other than to revalidate it) will produce undefined behavior.

Because C-style string literals exist for the entire program, it is okay to set a std::string_view to a C-style string literal, and even return such a std::string_view from a function.

A substring is a contiguous sequence of characters within an existing string.


### Quick guide on when to use ```std::string``` vs ```std::string_view``` vs ```const std::string&```
**Variables**:

* Use a ```std::string``` variable when:
    You need a string that you can modify.
    You need to store user-inputted text.
    You need to store the return value of a function that returns a ```std::string```.

* Use a ```std::string_view``` variable when:
    You need read-only access to part or all of a string that already exists elsewhere and will not be modified or destroyed before use of the ```std::string_view``` is complete.
    You need a symbolic constant for a C-style string.
    You need to continue viewing the return value of a function that returns a C-style string or a non-dangling ```std::string_view```.

**Function parameters**:

* Use a ```std::string``` function parameter when:
    The function needs to modify the string passed in as an argument without affecting the caller. This is rare.
    You are using language standard C++14 or older and aren’t comfortable using references yet.

* Use a ```std::string_view``` function parameter when:
    The function needs a read-only string.
    The function needs to work with non-null-terminated strings.

* Use a ```const std::string&``` function parameter when:
    You are using language standard C++14 or older, and the function needs a read-only string to work with (as ```std::string_view``` is not available until C++17).
    You are calling other functions that require a ```const std::string```, ```const std::string&```, or const C-style string (as s```td::string_view``` may not be null-terminated).

Use a ```std::string& function``` parameter when:
    You are using a ```std::string``` as an out-parameter.
    You are calling other functions that require a ```std::string&```, or non-const C-style string.

**Return types**:

Use a ```std::string``` return type when:
    The return value is a ```std::string``` local variable or function parameter.
    The return value is a function call or operator that returns a ```std::string``` by value.

Use a ```std::string_view``` return type when:
    The function returns a C-style string literal or local ```std::string_view``` that has been initialized with a C-style string literal.
    The function returns a ```std::string_view``` parameter.

Use a ```std::string_view``` return type when:
    Writing an accessor for a ```std::string_view``` member.

Use a ```std::string&``` return type when:
    The function returns a ```std::string&``` parameter.

Use a ```const std::string&``` return type when:
    The function returns a ```const std::string&``` parameter.
    Writing an accessor for a ```std::string``` or ```const std::string``` member.
    The function returns a static (local or global) ```const std::string```.