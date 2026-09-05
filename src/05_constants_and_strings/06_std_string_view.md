# std::string_view introduction (cpp17)

# Introduction
**When an object is initialized, its constructor is called with the provided arguments. Depending on how the constructor parameters are defined, those arguments may be copied, moved, or passed by reference. For fundamental types, references, and pointers, passing/copying is generally extremely cheap; for larger objects, copying can introduce significant overhead.**
eg.
```
int x { 5 };                // x makes a copy of its initializer value
void foo(int x);            // copy: fundamental datatype is cheap
void foo(MyClass);          // copy: potentially expensive
void foo(const MyClass& x); // reference: no copy
void foo(MyClass&& x);      // value reference: enables moving
```
This distinction becomes important with classes.

In the case of C-style strings, the copy into memory allocated for a ```std::string``` is slow, eg., ```std::string s { "Hello world!" }```.

This is very inefficient, because s is created to print the value to the console, and then s is destroyed since it goes out of scope.
```
std::string s { "Hello world!" };
std::cout << s << '\n';

return 0;
```

```std::string_view``` has these features to solve this:

* Imported with ```<string_view>``` header

* Provides **read-only (cannot be modified)** access to an existing string (C-style string, ```std::string``` or another ```std::string_view```)

* Can be initialized with C-style string, ```std::string``` or another ```std::string_view```

* **It does not make a copy from the initilized value, making it very cheap**

* ```std::string_view``` won't implicitly convert to ```std::string``` (for preventing inardvently making an expensing copy). You can explicitly create a ```std::string``` with a ```std::string_viewer``` or use ```static_cast```

* operator= does makes the string_view to see the new value, but does not change the value of the prior variable from it was intialized

* literal suffix ```sv``` can be used to forced ```std::string_view``` literal, imported into the scope using ```using namespace std::string_view_literals;```

* Unlike ```std::string```, has full support con constexpr

* **Preferred ```std::string_view``` over ```const std::string&``` as function parameters** in most cases. Also, ```std::string_view``` best use is as read-only function parameter.

* May or may not be null-terminated, depending if it is viewing a C-style string (null terminated) or ```std::string``` (not null-terminated). Converting  a ```std::string_view``` -> ```std::string``` will become null terminated.
