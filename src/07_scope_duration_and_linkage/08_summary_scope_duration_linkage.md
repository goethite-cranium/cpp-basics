# Scope, Duration, and Linkage Summary

## Scope summary

An identifier's **scope** determines where the identifier can be accessed within the source code.

### Block (local) scope

Variables with block scope can be accessed from their point of declaration until the end of the block in which they are declared, including nested blocks.

This includes:

* Local variables
* Function parameters
* Program-defined types (such as enums and classes) declared inside a block

### Global scope

Variables and functions with global scope can be accessed from their point of declaration until the end of the file.

This includes:

* Global variables
* Functions
* Program-defined types (such as enums and classes) declared inside a namespace or at global scope

---

## Duration summary

A variable's **duration** determines when it is created and destroyed.

| Duration      | Description                                                                   | Examples                                 |
| ------------- | ----------------------------------------------------------------------------- | ---------------------------------------- |
| **Automatic** | Created when its definition is reached and destroyed when its block is exited | Local variables, function parameters     |
| **Static**    | Created when the program begins and destroyed when the program ends           | Global variables, static local variables |
| **Dynamic**   | Created and destroyed according to programmer request                         | Dynamically allocated variables          |

---

## Linkage summary

An identifier's **linkage** determines whether another declaration of that identifier refers to the **same entity** or to a different entity.

### No linkage

Local variables have no linkage. Each declaration of an identifier with no linkage refers to a unique entity.

Examples:

* Local variables
* Program-defined type identifiers declared inside a block, such as enums and classes

### Internal linkage

An identifier with internal linkage refers to the same object or function when declared within the same translation unit.

Examples:

* `static` global variables
* `static` functions
* `const` global variables
* Unnamed namespaces and their contents

### External linkage

An identifier with external linkage refers to the same object or function throughout the program.

Examples:

* Non-`static` functions
* Non-`const` global variables
* `extern const` global variables
* `inline const` global variables
* Namespaces

Identifiers with external linkage generally cause a duplicate-definition linker error if their definitions are compiled into multiple `.cpp` files, because this violates the One Definition Rule.

Exceptions include:

* Types
* Templates
* `inline` functions
* `inline` variables

---

# Variable scope, duration, and linkage summary

| Type                                     | Example                           | Scope  | Duration  | Linkage  | Notes                        |
| ---------------------------------------- | --------------------------------- | ------ | --------- | -------- | ---------------------------- |
| Local variable                           | `int x;`                          | Block  | Automatic | None     |                              |
| Static local variable                    | `static int s_x;`                 | Block  | Static    | None     |                              |
| Dynamic local variable                   | `int* x { new int{} };`           | Block  | Dynamic   | None     |                              |
| Function parameter                       | `void foo(int x)`                 | Block  | Automatic | None     |                              |
| Internal non-const global variable       | `static int g_x;`                 | Global | Static    | Internal | Initialized or uninitialized |
| External non-const global variable       | `int g_x;`                        | Global | Static    | External | Initialized or uninitialized |
| Inline non-const global variable (C++17) | `inline int g_x;`                 | Global | Static    | External | Initialized or uninitialized |
| Internal constant global variable        | `constexpr int g_x { 1 };`        | Global | Static    | Internal | Must be initialized          |
| External constant global variable        | `extern const int g_x { 1 };`     | Global | Static    | External | Must be initialized          |
| Inline constant global variable (C++17)  | `inline constexpr int g_x { 1 };` | Global | Static    | External | Must be initialized          |

---

# Forward declaration summary

A forward declaration can be used to access a function or variable defined in another file.

The declared identifier has the scope it would normally have: global scope for globals and block scope for locals.

| Type                                      | Example                     | Notes                            |
| ----------------------------------------- | --------------------------- | -------------------------------- |
| Function forward declaration              | `void foo(int x);`          | Prototype only; no function body |
| Non-constant variable forward declaration | `extern int g_x;`           | Must be uninitialized            |
| Const variable forward declaration        | `extern const int g_x;`     | Must be uninitialized            |
| Constexpr variable forward declaration    | `extern constexpr int g_x;` | Not allowed                      |

A `constexpr` variable is implicitly `const`, so it can be forward declared using:

```cpp
extern const int g_x;
```

When accessed through that declaration, it is treated as `const`, rather than `constexpr`.

---

# Storage class specifiers

The `static` and `extern` keywords are called **storage class specifiers** when used as part of an identifier declaration. In this context, they affect the identifier's storage duration and linkage.

C++ has the following storage class specifiers:

| Specifier      | Meaning                                                                          | Note                                                |
| -------------- | -------------------------------------------------------------------------------- | --------------------------------------------------- |
| `extern`       | Static (or `thread_local`) storage duration and external linkage                 |                                                     |
| `static`       | Static (or `thread_local`) storage duration and internal linkage                 |                                                     |
| `thread_local` | Thread storage duration                                                          |                                                     |
| `mutable`      | Allows an object to be modified even when its containing class object is `const` |                                                     |
| `auto`         | Automatic storage duration                                                       | Deprecated as a storage class specifier since C++11 |
| `register`     | Automatic storage duration and a hint to place the object in a register          | Deprecated since C++17                              |

> **Note:** The term *storage class specifier* is primarily encountered in formal C++ documentation.
