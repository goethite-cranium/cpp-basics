#include <iostream>
#include <string>
#include <limits>


// https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/
void quizSolution()
{
    std::cout << "Enter your full name: ";
    std::string fullName {};
    std::getline(std::cin >> std::ws, fullName);

    std::cout << "Enter your age: ";
    int age {};
    std::cin >> age;

    int nameLen { static_cast<int>(fullName.length()) };
    std::cout << "Your age + length name is: " << age + nameLen << '\n';
}


int main()
{
    std::cout << "Hello world\n";         // "Hello world is a C-style string literal"

    std::string name {};                // empty string initialization
    std::string otherName { "Alex" };   // initialization with string literal
    otherName = "Jay";                  // change, note different length is accepted

    // Use .length() mehtod to get the length in terms of chars
    std::cout << "Current name: " << otherName << ",  and has " << otherName.length() << " chars" << '\n';
    std::cout << "Current name length extracted with std::ssize() is " << std::ssize(otherName) << '\n';
    // Assign length (size_t) to an int variable
    int currentNameLength { static_cast<int>(otherName.length()) };
    std::cout << "Again, current name has " << currentNameLength << "chars\n";

    std::cout << "Type your full lname: ";
    std::string fullName {};            // if typed John Doe...
    std::cin >> fullName;               // Here only John is extracte, Doe is buffered
    
    std::cout << "Enter a color: ";
    std::string color {};               // no matter what has been typed, Doe is the next chain between whitespaces,
    std::cin >> color;                  // so color = Doe, and the typed color is buffered again

    std::cout << "Your name is " << fullName << " and your chosen color is " << color << '\n';

    // Flush std::cin buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());

    std::cout << "Type a phrase to see how std::getline() extracts until new line and keep whitespaces: ";
    std::string phrase {};
    std::getline(std::cin >> std::ws, phrase);

    using namespace std::string_literals; // easy access to the s suffix

    std::cout << "foo\n";                 // no suffix, C-style string literal
    std::cout << "goo\n"s;                // s suffix, std::string literal

    return 0;
}