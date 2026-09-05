#include <iostream>
#include <string>
#include <string_view>


std::string getName(int num)
{
    std::cout << "Enter the name of person " << num << "#: ";
    std::string person{};
    std::getline(std::cin >> std::ws, person);
    return person;
}

int getAge(std::string_view name)
{
    std::cout << "Enter age of person " << name << ": ";
    int age{};
    std::cin >> age;
    return age;
}

void printPersonShortedByAge(
    std::string_view person1, int person1Age,
    std::string_view person2, int person2Age)
{
    if (person1Age > person2Age)
        std::cout << person1 << "(age " << person1Age << ") is older than " 
                  << person2 << "(age " << person2Age << ").\n";
    else
        std::cout << person2 << "(age " << person2Age << ") is older than " 
                  << person1 << "(age " << person1Age << ").\n";
}

int main() 
{

    const std::string person1 { getName(1) };
    const int age1 { getAge(person1) };

    const std::string person2 { getName(2) };
    const int age2 { getAge(person2) };

    printPersonShortedByAge(person1, age1, person2, age2);
}