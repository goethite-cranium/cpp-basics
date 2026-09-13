# Local scopes and variables

Definitions:
* **Local variables**: variables defined inside a function body with block scope
* **(storaged) duration or lifetime**: determines what rules govern when and how a variable will be created (instantiated) and destroyed.
* **linkage property**: an idenfier's linkage determines whether a declaration of that same idenrifier in a different scope refers to the same object or function.
Scope and linkage can be similar, but the key difference is that **scope determines where declaration of a single identifier can be seen and used in the code, while linkage determines whether multiple declarations of the same identifier refer to the same object or not**.
* **shadowing**: Shadowing occurs when a declaration in an inner scope uses the same identifier as a declaration in an outer scope, hiding the outer declaration within the inner scope.
---

* **Local variables have block scope**: they are in scope from their point of definition to the end of the block they are define within
> Variables are destroyed when they reach the end of the scope in inverse order of declaration

* **Local variables have automatic (storage) duration**: local variables have automatic duration because they are created at the point of definition and destroyed at the end of the block they are defined in.

* **Local variables defined in a nested block is destroyed at the end of its nested block's level**. Outer blocks are considered to be in scope in the inner nested ones.

* **Local variables have no linkage**: each declaration of an identifier refers to a unique object or function. a local variable declared in a block cannot be referred to by the same identifier from another scope. However, different local variables can have the same identifier if they belong to different nested scopes.
```cpp
int main()
{
    int x { 2 }; // local variable, no linkage
    {
        int x { 3 }; // this declaration of x refers to a different object than the previous x because of shadowing
    }
    return 0;
}
```

* **Local variables must be declare in the level of scoped in nested blocks where they are going to be used** 



