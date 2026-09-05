#include <iostream>
#include <string>
#include <string_view>

void printSV(std::string_view str) // now a std::string_view, creates a view of the argument
{
    std::cout << str << '\n';
}


void viewModificationFunctionsExample()
{
    std::string_view sv { "Peach" };
    std::cout << sv << '\n';

    sv.remove_prefix(1);
    std::cout << sv << '\n';

    sv.remove_suffix(2);
    std::cout << sv << '\n';

    sv = "Peach"; // reset view
    std::cout << sv << '\n';
}


int main()
{
    printSV("Hello, world!"); // call with C-style string literal

    std::string s2{ "Hello, world!" };
    printSV(s2); // call with std::string

    std::string_view s3 { s2 };
    printSV(s3); // call with std::string_view

    return 0;
}

