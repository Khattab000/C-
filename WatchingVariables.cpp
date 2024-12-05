/*
Now we are using the debugger to examine variables
and how they behave and change throughout the execution
*/

// while debugging you can hover above the variable to see the current value depending at what steps you executed 

/*
You can also use the quick watch feature (right click
on a variable and click on quick watch to keep track
of that variable) or even better and usable in VSC is 
adding the variable to the Watch Window (which should be on the
debug options ) where you can add a variable and see how
it changes (you can do that manually by writing the 
varriable in the watch window or right click on the
variable while debugging and clicking on add to Watch)
and in the watch window you can hover above the variable 
to find out what type it is e.g int

some ide/compiler let you put a breakpoint on a variable
instead of the whole line , while debugging you go into the
watch window and right click on it and set a break point
called "Break when value changes" basically stopping
whenever the value of the variable changes (
need to re-enable everytime while debugging)

You can also put expression into the watch window like 
x + 2 , but it always evaluates the current value of x,
if your interested in an expression in your code and what it 
evaluates to then just hover above the variable after executing
the expression
*/

/*
Now if you want to keep track of all local variables
instead of adding them manually one by one to the 
watch window, you can use the Variable window , its 
located at the same place as the watch window in the 
debug section and it keeps track of ever variable in the
code (in VS ot om the Locals section which is also near the
debug section)
*/
#include <iostream>

int main()
{
    int x{1};
    std::cout << x << ' ';

    x = x + 2;
    std::cout << x << ' ';

    x = x + 3;
    std::cout << x << ' ';

    return 0;
}


