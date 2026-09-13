# Unnamed and inline namespaces

### Unnamed (anonymous) namespaces
**Unnamed or anonymous namespaces**: namespaces that is defined without a name.

Properties:
* **All content declared in an unnamed namespace is treated as if it is part of the parent namespace**, so they are accessible only from the parent namespace. 

* All identifiers inside unnamed namespace are **internal linkage**. This is effective for functions to do the same as declaring them ```static```. In this case, it is usefull to cluster many functions which we want to make internal linkage, instead of adding (and potentially missing) ```static`` keyword.

> Avoid unnamed namespaces in header files.
> Preferred unnamed namespaces when you have content you want to keep local to a tranlation unit.


### Inline namespaces
If you already have a function, but you want to improve it so you create a new version so you can keep original one in other part of the code without braking it, and later you add more and more improvements so new versions, how would you handle it?
The functions can have version preffix, but these functions are almost identically with few improvements and also their names add clutter.

**Inline namespaces** is a namespace that is typically used to version content. Everything declared inside an inline namespace is considered part of the parent namespace (as in unnamed namespace). BUT inline namespaces **do not affect linkage**.
They are declared with ```inline namespace NamespaceName```. 
The inline namespace can be called without qualifiers in the same file. But since it does not affect to linkage, they are usable in another files, calling explicitly for new version if they want, otherwise they fallback to original. (see cpp expample). This can be done in the other direction, pushing newest version by default.


### Summary 
Purposes:
    **Unnamed or anonymous namespaces** -> the wrapped code is private for this translation unit (through forcing internal linkage)
    **inline namespaces** -> the wrapped code are inside parent namespace, falling back to father namespace when its specific namespace qualified is not use. Often use in versioning.

