/*
  A debugger is a computer program that allows the programmer to 
  control how another program executes and examine the prgram state
  while that program is running, a debugger can be used to examine 
  a program line by line for example to check the variable and how
  it changes throughout
*/
// first we try out stepping where we go through the code step by step
// step into : The step into command executes the next statement in the normal execution path of the program, and then pauses execution of the program so we can examine the program’s state using the debugger. If the statement being executed contains a function call, step into causes the program to jump to the top of the function being called, where it will pause.
// step out : basically helps you get out of a funtction by executing the rest of the function if afer you stepped into it and also executes the next step
// step over: skips the function by executing the funtion fully and then proceeds instead of stepping in and going line by line , you use it if your not interested in a function, there is no function or if its part of the standard library

#include <iostream>

void printValue(int value)
{

    std::cout << value << '\n';
}

int main()
{
    #if 1  
    std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging) , makes it so that std::cout doesnt buffer bc in some cases the buffer makes it that the output wont appear right away, so if you need the output to appear right away and to not buffer use that
    #endif
    printValue(5);


    return 0;
}
