# Using declariations and directives


### Qualified and unqualified names

A name can be qualified or unqualified 
* **Qualified name**: includes an associated scope. Often, names are qualified with namepace using scope resolution ```operator::```, e.g., ```std::cout``` or ```::foo```, or a member name qualified by class, e.g., ```MyClass::s_member```, ```obj.x``` or ```ptr->y```.
* **Unqualified name**: does not include a scoping qualifier that indicates scope, e.g., ```cout``` or ```x```.


### ```using``` declarations

**```using``` declaration**: allows us to use an unqualified name (with no scope) as an alias for a qualified name, e.g., ```using std::cout``` allows as to use ```cout``` (no sope qualifier std) instead of ```std::cout```.
They have block scope. If they are used in namespace, then it is applied to all the namespace in which was defined.


### ```using``` directives

**```using``` directives**: allows all identifiers in a given namespace to be referenced without qualification from the scope of the using-directive, e.g., ```using namespace std;```. 
They have block scope. If they are used in namespace, then it is applied to all the namespace in which was defined.

> Avoid ```using``` directives, because they will enter in scope many unused names (potentially colliding)
> Avoid ```using``` declarations and directives (```using``` statements) in header files or before ```#include``` directives
Rule of thumb: ```using``` statements should noot be placed anywhere where they might have an impact on code in different file.
For example, if placed in global namespace of a header file, then every other file that imports the header with #inlcude would also get that ```using``` statement. Even in function bodies in header files are risky.

> Best practice: the best way to control and cancel ```using``` statements is with blocks:
```cpp
int main()
{
    {
        using namespace Foo;
        // calls Foo stuff
    }

    {
        using namespace Goo;
        // calls Goo stuff
    }

}
```