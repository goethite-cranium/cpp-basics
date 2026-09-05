#include <iostream>
#include <string>


void printSV(std::string_view str) // very cheap since it is an string_view avoiding normal copy
{
    std::cout << str << '\n';
}

void printS(std::string str)
{
    std::cout << str << '\n';
}



int main()
{
    std::string_view s1 { "Hello world!" };
    std::cout << s1 << '\n';

    std::string s { "Hello world!" };
    std::string_view s2 { s };
    std::cout << s2 << '\n';

    std::string_view s3 { s2 };
    std::cout << s3 << '\n';

    printSV(s3);                // very cheap since parameter is an string_view
    printSV("Hello world!");    // implicitly converted to string_view
    printSV(s);                 // implicitly converted to string_view
    
    // printS(s1);              // won't compile! implicit conversion std::string -> std::string_view not allowed         
    printS(static_cast<std::string>(s1)); // explicit conversion allowed

    s2 = "Again, hello world!"; // now s2 "see" this C-string, but does not change the value of s
    printSV(s2);
    printSV(s);

    using namespace std::string_literals;       // access to s suffix
    using namespace std::string_view_literals;  // access to sv suffix

    std::cout << "foo\n";       // C-style string literal
    std::cout << "goo\n"s;      // std::string literal
    std::cout << "moo\n"sv;     // std::string_view literal

    constexpr std::string_view s4 { "Constexpr hello world!" }; // s4 is a symbolic constant
    std::cout << s4 << '\n';    // s4 will be replaced by "Constexpr hello world!" at compile-time

    return 0;
}