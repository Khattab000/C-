/*
Call Stack can be accessed in the debug section

Call Stack is mainly used to see what functions are called 
and where to go (the exact line where to go back)
back after the funtion is called 

whenever a funtion is called it goes to the top of the list

for debugging purposes put breakpoints on the functions
for better overview when it gets called 

and Call Stack also gives you the line where the function
that was called is 
*/

/*
  The line numbers after the function names show the 
  next line to be executed in each function.
*/
#include <iostream>

void a()
{
    std::cout << "a() called\n";
}


void b()
{
    std::cout << "b() called\n";
    a();
}




int main()
{
    a();
    b();

    return 0;
}
