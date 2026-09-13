int max(int x, int y) // x and y enter scope here
{
    // assign the greater of x or y to max
    int max{ (x > y) ? x : y }; // max enters scope here

    return max;
} // max, y, and x leave scope here and destroyed


int main()
{
    int i { 5 }; // i enters scope
    double d { 4.0 }; // d enters scope

    { // nested block
        int y { 7 }; // y enters scope and is created here
    
        // i and d are both in scope here
        std::cout << i << " + " << d << " = " << i + d << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    return 0;
} // d and then i go out of scope and destroyed