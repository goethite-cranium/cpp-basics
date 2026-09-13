#include <iostream>
#include <cstdint>

// using InventedNamespace; // This would apply to entire :: global namespace, not just a block

int main()
{
    using std::cout; // using declaration, tells compiler that cout should resolve to std::cout
    cout << "Hello world!\n";

    using namespace std; // all names from std namespace are now accessible without qualifiers
    int16_t x { 2 }; // thus no perfix std needed here

    return 0;
} // using-directives ends at the end of current scope.