/*
Run to cursor is basically putting a pause point on a certain line so
the program executes until that point and then you can start debugging
from that point onwards.
For run to cursor right click on a statement while debugging 
*/

/*
Continue is basically the same as the word when you
start debugging or use Run to cursor its gonna be 
paused on that point waiting for you to decide what 
to do next and the Continue button (which looks like
the run button) does that and it executes the whole program
*/

/*
Start is basically the twin of continue but the main
diffrence is it starts from the beggining towards the end
it basically is Run with the main diffrence 
being that with Start we can use Breakpoints
(in VS there is a dedicated start button
but in VS Code you use the Run button you made yourself)
*/
/*
Breakpoint is basically similar to Run to cursor funtion
wise, you put a point by clicking on the left of the numbers 
line to set a breakpoint, in debug mode breakpoints 
are never skipped at stops the program on its tracks regardless 
even when you clicked on continiue beforehand(you can
continue afterwards when you reach the breakpoint),
the main diffrence to run to cursor is that run to 
cursor is a temporary breakpoint which dissapears after you
you reach it, breakpoint stays until you manually remove it
e.g in the below code run to cursor if put on the line of 
the funtion body it only stops the execution once 
even tho the function is callled 3 times bc the 
temprorary breakpoint disappears BUT with Breakpoint
on the same line it will stop 3 times bc the function
is called 3 times and breakpoint only dissapears when
you remove it manually 
Note that breakpoints placed on lines that are not in the path 
of execution will not cause the debugger to halt execution of the code.
*/

/*
Set next statement (Jump to cursor) is basically
you deciding what next  code is getting executed and with
that you can completely skip lines without ever executing
them e.g if you are at printValue(5) and then use jump
to cursor to get to printValue(7) then printValue(6)
is getting skipped.
(it seems tho that VSCode isnt able to do that but VS is)
And that is useful if you dont wanna modify your code
by commenting out parts so that a workaround for that too
and you can also jumnp backwards to do smth again like 
execute printValue(5) and then printValue(6) and then jumping back
to 5 to do 5 and 6 again. But this wont change the program
itself just the execution of this one run. And be careful
if you use to jump to another function that might bring
undefined behaviour and probably a crash bc. And one last 
note variables retain there values before the jump so keep that 
in mind
*/

/*
“Step back” rewinds the state of everything, 
as if you’d never gone past that point in the first
place. Any changes to variable values or other 
program state is undone. This is essentially an “undo”
command for stepping.

“Set next statement” when used to jump backwards 
only changes the point of execution. Any changes
to variable values or other program state are 
not undone.
*/


#include <iostream>

void printValue(int value)
{
    std::cout << value << '\n';
}

int main()
 {
    printValue(5);

    printValue(6);

    printValue(7);

    return 0;
}
