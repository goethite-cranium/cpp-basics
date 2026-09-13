#include <iostream>
#include "goo"

void constexpr doSomething(int x, int y)
{
    x -= 15;
    std::cout << x << ", " << y << '\n';
}


namespace Foo 
{
    void constexpr doSomething(int x, int y)
    {
        x += 1;
        std::cout << x << ", " << y << '\n';
        ::doSomething(x, y); // global namespace scope
    }
}

namespace Doo::Too //nested abreviate namespaces
{
    void constexpr doSomething(int x, int y)
    {
        x -= 6;
        std::cout << x << ", " << y << '\n';
    }
}


int main()
{
    constexpr int x{ 2 }, y{ 2 };

    doSomothing(x, y);

    Foo::doSomething(x, y);

    Goo::doSomething(x, y);

    namespace Active = Doo::Too; // alias
    Active::doSomething(x, y);

    
}
