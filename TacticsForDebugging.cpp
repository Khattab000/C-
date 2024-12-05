/*1.Figure out how to reproduce the problem
  2.Run the program and gather information to narrow down where the problem is
  3.Repeat the prior step until you find the problem*/

/*
Debugging tactic #1: Commenting out your code

int main()
{
  getNames();     //ask user to enter names
  doMaintenance();// do some random stuff
  sortNames();   // sort names alphqabetically
  printNames();  // print the sorted list

  return 0;
}

Let’s say this program is supposed to print 
the names the user enters in alphabetical order,
but its printing them in reverse alphabetical
order. So now where is the error it could be 
getNames or sortNames or even printNames. But
we suspect that it prob doesnt have anything
to do with doMaintenance so we decide to
comment out that first to check if the error 
is still there, if the error is still there then 
the problem isnt in doMaintenance, if the error
disappers then the problem is in doMaintenance
and if another error appears it basically means
that doMaintenance is important for another 
part of the code so we need to uncomment it and
find another way or try another funtion
*/


//Debugging tactic #2 Validating your code flow

#if 0 
#include <iostream>

int getValue()
{
	return 4;
}

int main()
{
    std::cout << getValue << '\n';

    return 0;
}
#endif
// this program only compiles if you disable "Treat warning as errors" so you need to remove or comment out "-Wall","-Weffc++","-Wextra","-Wconversion","-Wsign-conversion", from tasks.json
// you expect the code to output 4 but it doesnt it outputs 1 (or 00101424)

// lets add some debugging statements to these functions
#if 0
#include <iostream>
int getValue()
{
std::cerr<< "getValue() called\n";
    return 4;
}

int main ()
{
std::cerr << "main() called\n";
    std::cout<< getValue <<'\n';

    return 0;

}
#endif
/*the output of that is gonna be:
  main() called
  1

  meaning that main was called but not getValue
  we use that debugging method so we have a clear
  way to see which function is called and which isnt 
  bc we make them print that they get called when 
  they get called , we use std::cerr for that 
  instead of std::cout for two simple reasons,
  reason 1 cerr doesnt buffer so it still prints
  even if the program crashes shortly after being 
  used unlike cout which does buffer, and reason 2
  is to indicate that its there only for debugging reasons 
  so we dont forget to remove it later on thats
  why we also dont use the formatting on std::cerr on
  purpose so it looks out of place and not correctly 
  intendet. So now we know that the incorrect
  input is happening bc getValue isnt called
  and the error being that we forgot to put () 
  after getValue so the correct way to write it is 
  getValue().

  So now lets try to write the code correctly

*/
#if 0
#include <iostream>

int getValue()
{
std::cerr << "getValue() called\n";
	return 4;
}

int main()
{
std::cerr << "main() called\n";
    std::cout << getValue() << '\n'; // added parenthesis here

    return 0;
}
#endif 
/* Now the output is :
   main() called 
   getValue() called
   4

   And now we can remove the temporary debugging stat
   And on a side note we used #if 0 and #endif
   to basically comment out earlier code 
*/

/* Debugging tactic #3: Printing values
   
   Basically the same tactic #2 but instead
   of checking if the funtion is called we check
   if the correct value is passed on by printing
   those diffrent values so we can observe them

*/
#if 0
#include <iostream>

int add(int x, int y)
{
	return x + y;
}

void printResult(int z)
{
	std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	int x{ getUserInput() };
	[[maybe_unused]] int y{ getUserInput() };  // i had to put [maybe_unused] here to make the program run

	int z{ add(x, 5) };
	printResult(z);

	return 0;
}
#endif
/* Here is the output of the program if you input 4 and 3 :

Enter a number: 4
Enter a number: 3
The answer is: 9

Now lets add some debugging statements to see where it all went wrong

*/
#if 0
#include <iostream>

int add(int x, int y)
{
	return x + y;
}

void printResult(int z)
{
	std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	int x{ getUserInput() };
std::cerr << "main::x = " << x << '\n';
	int y{ getUserInput() };
std::cerr << "main::y = " << y << '\n';

	int z{ add(x, 5) };
std::cerr << "main::z = " << z << '\n';
	printResult(z);

	return 0;
}
#endif
/*
 Now we added a debuggung statements after every 
 function call the ouput now is : 

 Enter a number: 4
 main::x = 4
 Enter a number: 3
 main::y = 3
 main::z = 9
 The answer is: 9

Variable x and y are getting the right values but
z isnt so the problem should be inbetween x and y getting ther variable and z getting its variable,
so our prime suspect is add() lets use a debugging
statement on that too
*/
#if 0
#include <iostream>

int add(int x, int y)
{
std::cerr << "add::x = "<< x << " add::y = "<<y <<'\n';
	return x + y;
}

void printResult(int z)
{
	std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	int x{ getUserInput() };
std::cerr << "main::x = " << x << '\n';
	int y{ getUserInput() };
std::cerr << "main::y = " << y << '\n';

	int z{ add(x, y) };
std::cerr << "main::z = " << z << '\n';
	printResult(z);
	return 0;
}
#endif
/*
Variable x had 4 and Variable y had 3 but somehow our add function gives us 9
The error seems to be that we passed the wrong argument instead of 
passing y we passed 5 so that was our error to correct it it would 
look like this:
               int z{add(x,y)};

So we now finally fixed our code and should get 7 as a result
and after you fix it dont forget to remove the debug statements
*/

// One more example (similare code as in tactic #3)
// smth is wrong lets start with adding debug statements
// like std::cerr<<"add() called\n"; for function calls
// or std::cerr << "main::x =" << x << '\n'; for values
// dont forget to intend them to make it visible that it is a debug statement
#if 0
#include <iostream>

int add(int x, int y)
{
std::cerr<<"add() called\n";
	return x + y;
}

void printResult(int z)
{
std::cerr<<"printResult() called\n";
	std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
std::cerr << "getUserInput() called\n";
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return --x;
}

int main()
{
std::cerr << "main() called\n";
	int x{ getUserInput() };
std::cerr << "main::x = " << x << '\n';
	int y{ getUserInput() };
std::cerr << "main::y = " << y << '\n';
  int z { add(x, y) };
std::cerr << "main z = " << z << '\n';
	printResult(z);

	return 0;
}
#endif
/*
The Output is : 
main() called
getUserInput() called
Enter a number: 5
main::x = 4
getUserInput() called
Enter a number: 3
main::y = 2
add() called
main z = 6
printResult() called
The answer is: 6

with that we can tell for sure that the issue is with the 
getUserInput() bc it subtracts the given value by one with the
-- operator infront of the retruned variable which is clearly the
mistake , so we found the error now we fix it and remove the 
debug statements
*/

#include <iostream>

int add(int x, int y)
{
	return x + y;
}

void printResult(int z)
{
	std::cout << "The answer is: " << z << '\n';
}

int getUserInput()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x; // removed -- in front of x which does -1 
}

int main()
{
	int x{ getUserInput() };
	int y{ getUserInput() };

	int z{ add(x, y) };
	printResult(z);

	return 0;
}

/* even tho using print to debug can be useful it isnt great bc :
   Debug statements clutter your code.
   Debug statements clutter the output of your program.
   Debug statements require modification of your code to both add and to remove, which can introduce new bugs.
   Debug statements must be removed after you’re done with them, which makes them non-reusable.

   in the next lesson we will learn better ways 

*/
