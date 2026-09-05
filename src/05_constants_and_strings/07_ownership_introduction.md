# Introduction to ownership
This introduction will be based on ```std::string``` (sole owner or single ownership) and ```std::string_view``` (view or not owner)


### Analogy of ownership
Let’s sidebar into an analogy for a moment. Say you’ve decided that you’re going to paint a picture of a bicycle. But you don’t have a bicycle! What are you to do?

Well, you could go to the local cycle shop and buy one. You would own that bike. This has some benefits: you now have a bike that you can ride. You can guarantee the bike will always be available when you want it. You can decorate it, or move it. There are also some downsides to this choice. Bicycles are expensive. And if you buy one, you are now responsible for it. You have to periodically maintain it. And when you eventually decide you don’t want it any more, you have to properly dispose of it.

Ownership can be expensive. As an owner, it is your responsibility to acquire, manage, and properly dispose of the objects you own.

On your way out of the house, you glance out your window front. You notice that your neighbor has parked their bike across from your window. You could just paint a picture of your neighbor’s bike (as seen from your window) instead. There are lots of benefits to this choice. You save the expense of having to go acquire your own bike. You don’t have to maintain it. Nor are you responsible for disposing of it. When you are done viewing, you can just shut your curtains and move on with your life. This ends your view of the object, but the object itself is not affected by this. There are also some potential downsides to this choice. You can’t paint or customize your neighbors bike. And while you are viewing the bike, your neighbor may decide to change the way the bike looks, or move it out of your view altogether. You may end up with a view of something unexpected instead.

Viewing is inexpensive. As a viewer, you have no responsibility for the objects you are viewing, but you also have no control over those objects.


### Summary

**Ownership** means being responsible for the lifetime of a resource. It can have more overhead than merely viewing a resource, but provides control and safety over its lifetime.
* An owner is responsible for managing the lifetime of the resource it owns. Ownership does not necessarily mean copying the resource into the owner. Creating or copying an owning object may require copying or allocating the resource, adding huge overhead.
* When the owner is destroyed, the owned resource is normally destroyed/released as well, depending on the ownership mechanism.
* The owner can generally access and modify the owned resource, provided the type and access permissions allow it.

**Viewer** (non-owner) means accessing a resource without being responsible for its lifetime.
* A viewer does not take ownership or create a copy merely by viewing the resource.
* A viewer **may** be read-only or mutable depending on the type of view/reference used.
* A viewer does not control the resource's lifetime and must ensure that the resource remains valid while it is being used.
* Having multiple viewers of a viewed resource is fine.

to know if a resource should be owned or view, ask:
1. Could resource be destroyed/modified while the manager is still using it?
2. Is the resource being modified in a way the caller would not expect?


### ```std::string``` as a sole owner
```std::string``` makes an expensive copy of its initializer because, when the object is instantiated, memory is allocated for that object to store whatever data it needs to use throughout its lifetime (safe space). Once the initialization value has been copied, the object is no longer reliant on the initializer.
It is similar to a function: the caller is passing the object, when iniatialization is done, control returns back to the caller. Then, as initialization is complete, these can happen.
a. If the initializer was a temporary value or obj, that temp is destroyed
b. If initializer was a var, the caller still has access to that obj (no control ob the callee/instantiated obj)

Thus, ```std::string``` is responsible for acquaring its string data from the initializer, managing access to the string data, and properly disposing of the string data when its destroyed.

But, not always a copy is needed...

eg.
```

void printString(std::string str) // str makes a copy of its initializer
{
    std::cout << str << '\n';
}

int main()
{
    std::string s{ "Hello, world!" }; //makes a copy of the temp var (literal)
    printString(s);

    return 0;
}
```

### ```std::string_view``` as a viewer
```std::string``` creates cheap viewing, and can be used whenever access to the string is required. It just views, so it cannot modified the viewed string or destroy it.
BUT, if the viewed resource is destroyed or modified while the view is still being used, result on undefined behavior. **This is known as dangling view for the destroyed viewed resouce case**.
Thus, **its best used is as read-only function parameters**, since the main program will wait until the function finishes and the ```std::string_view``` is destroyed, avoiding dangling view.


### Viewers can view only part of the original resource
This can be done with **view modification functions**, and they do not modify the original resource. It's like peaking a subsample of the original resource. For the ```std::string_view```, some of this modifications are:
* ```remove_prefix()``` member function: removes chars from the left side of the view
* ```remove_suffix()``` member function: removes chars from the right side of the view

This means ```std::string_view``` can see a **substring, which is a contiguous sequence of characters withing an existing string**.



### Improperly using ```std::string_view``` (and viewers)
1. 
```cpp
int main()
{
    std::string_view sv{};

    { // create a nested block
        std::string s{ "Hello, world!" }; // create a std::string local to this nested block
        sv = s; // sv is now viewing s
    } // s is destroyed here (out of scope), so sv is now viewing an invalid string

    std::cout << sv << '\n'; // undefined behavior

    return 0;
}
```

2. 
```cpp
std::string getName()
{
    std::string s { "Alex" };
    return s;
}

int main()
{
  std::string_view name { getName() }; // name initialized with return value of function, then temp string is destroyed, so owner kills the resource
  std::cout << name << '\n'; // undefined behavior

  return 0;
}
```

3. 
```cpp
int main()
{
    using namespace std::string_literals;
    std::string_view name { "Alex"s }; // "Alex"s creates a temporary std::string
    std::cout << name << '\n'; // undefined behavior

    return 0;
}
```

Do not initilize ```std::string_view``` with string literal, since the temp variable, and owner, is destroyed after initialization.


4. 
```cpp
int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, a!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';   // undefined behavior

    return 0;
}
```

Modifying a ```std::string``` causes an undefined behavior in its ```std::string_viewer``` because ```std::string``` uses reallocate memory for the new string due to its mutable size, so the memory viewed by the viewer is no longer part of the string.
But, **the view can be revalidated**, for example assigning again the view to the changed string:

```cpp
int main()
{
    std::string s { "Hello, world!" };
    std::string_view sv { s }; // sv is now viewing s

    s = "Hello, universe!";    // modifies s, which invalidates sv (s is still valid)
    std::cout << sv << '\n';   // undefined behavior

    sv = s;                    // revalidate sv: sv is now viewing s again
    std::cout << sv << '\n';   // prints "Hello, universe!"

    return 0;
}
```

**Note: C-string stype literal are guarantee to exist for the entire program, so is safe to return a ```std::string_view``` of them. Also, returning a function parameter of type ```std::string_view``` is ok, since the original value still exists after the call is completed**
So, this will work:
```cpp
std::string_view getBoolName(bool b)
{
    if (b)
        return "true";  // return a std::string_view viewing "true"

    return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed at the end of the function
```

But this not:
```cpp
std::string_view getBoolName(bool b)
{
    std::string t { "true" };  // local variable
    std::string f { "false" }; // local variable

    if (b)
        return t;  // return a std::string_view viewing t

    return f; // return a std::string_view viewing f
} // t and f are destroyed at the end of the function
```