#include <iostream>
#include "03_global_variables_and_linkage.hpp" // import global variable g_v

int g_x {}; // gloabl variable, by default external linkage
const int g_u { 4 }; // cosnt global, by default internal linkage
constexpr int g_w { 45 }; // cosnt global, by default internal linkage
// const int g_u; error

static int g_z {}; // global variable, changed linkage to internal with static
// is noly usable in this file, definitions in other one won't link to this one
// the same happends with const and constexpr, since they are internal linkage

[[maybe_unused]] extern const int g_z { 3 }; // make const global var an external linkage


namespace GlobaVariable
{
    g_y {}; // global variable wrapped in namespace
}

namespace Constant
{
    [[maybe_unused]] extern const double gravity {9.8}; // RECOMMENDED USE OF GLOBAL VARIABLES
}

void doSomething()
{
    // global vars can be used anywhere in the file
    g_x = 3;
    GlobalVariable::g_y = 5;

    std::cout << "Global variables are " << g_x << " and " << GlobalVariable::g_y << '\n';
}

[[maybe_unused]] static int add(int x, int y) // static function, thus internal linkage and cannot be used in other files
{
    return x + y;
}


int main()
{
    doSomething();

    g_x -= 1;
    ++GlobalVariable::g_y;
    std::cout << "Global variables are " << g_x << " and " << GlobalVariable::g_y << '\n';

    std::cout << "Constant global variables are " << g_u << " and " << GlobalVariable::g_w << '\n';

    std::cout << "External global imported with extern and external linkage " << g_v << '\n';

    return 0;
}