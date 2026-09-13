# Staic local variables
Discusses the use of ```static``` keyword when applied to local variable.

**Using ```static``` keyword on a local variable changes its duration from automatic duration to static duration**: the variable is created at the start of the program and destroyed at the end, like global varibales. Thus, static local variables retain their value even when they go out of the scope. **But it still has block scope**, so they can only be used in the block they where defined in.

How do they work depending on initilization?
* **Static local variables that are zero-initialized or have a constexpr initializer can be initialized at program start**.
* **Static local variables that have no initializer or a non-constexpr initializer are zero-initialized at program start**. Static local variables with a non-constexpr initializer are reinitialized the first time the variable definition is encountered. The definition is skipped on subsequent calls, so no futher reinitialization happens. Because they have static duration, static local variables that are not explicitly initialized will be zero-initialized by default.
> Best practice: initialize static local variables. It is common to use ```s_``` prefix (static duration)

It widely used in unique id generation:
```cpp
int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}
```
First time returns a copy (so no static) with value 0, then 1, then 2, etc. Making a very safe track of the IDs. Also, s_itemID can only be used in that function thanks to block sope, although its value its retained until program finishes.


### Static local constants
Static local variables can be made ```const``` or ```constexpr```.
One use is when a function needs to use a const object, but initialize that object is expensive (for example read a value from database). ```static const``` make sure they are only initialized when program starts and be accessible for the function every call, since it is in duration.


### Do not use statsic local variables to alter flow
For example, in if-else. Because is harder to understand functions that can do different thing depending on a static local value unless implementation is read. **CONTROL FLOW WITH STATIC LOCALS ADD INTERNAL STATE TO FUNCTIONS, AND THAT INTERNAL STATE IS A SOURCE OF MISUNDERSTANDING AND DIFFICULT TO READ**. Better pass that control variables as function parameters (example, s_isFirstCall should be pass thorugh a parameter, not use as internal function state). But, the non-constant static local variables are not recommended.

> Constant static local variables are ok to use.
> Non-constant static local variables are DISCORAGED.

