#include <iostream>

namespace // unnamed namespace
{
    void doSomething() // can only be accessed in this file
    {
        std::cout << "v1\n";
    }
}


static void doSomething2() // can only be accessed in this file, same effect as unnamed naspace
{
    std::cout << "v1\n";
}


inline namespace V1 // version 1
{
    void doSomethingInline()
    {
        std::cout << "doSomethingInline() v1\n";
    }
}


namespace V2 // version 2
{
    void doSomethingInline()
    {
        std::cout << "doSomethingInline() v2\n";
    }
}


int main()
{
    doSomething(); // we can call doSomething() without a namespace prefix (qualifier)

    V1::doSomethingInline(); // calls the V1 version of doSomethingInline()
    V2::doSomethingInline(); // calls the V2 version of doSomethingInline()

    doSomethingInline(); // calls the inline version of doSomethingInline() (which is V1)

    return 0;
}