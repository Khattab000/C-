#include <iostream>
// syntax error are basically like grammar errors where you either write smth wrongly or forget a sign like for example a semicolon or curly braces 

int add(int x, int y) // this function is supposed to perform addition
{
    return x - y; // but it doesn't due to the wrong operator being used
}

int main()
{
    int a{10};
    int b{0};
    std::cout << a <<" / "<<b<<" = "<<a / b<<'\n';   /*even tho its not a syntax error its still considered an error 
                                                       we call that a semantic error bc we cant divide with 0 so the result will be having an undefined behaviour*/

    int x;                       // no initializer provided
    std::cout<< a << x << '\n';  // use of uninitialized variable leads to undefined , its not a syntax error but a semantic



    return 0;

    std::cout << "Hello, world!\n"; // so this never executes bc its after the return 0
}
