/*
Question #1

The following program is supposed to add two numbers,
but doesn’t work correctly.

Use the integrated debugger to step through this 
program and watch the value of x. Based on the 
information you learn, fix the following program:
*/

/* #include <iostream>

int readNumber (int x)
{
    std::cout << "Please enter a number: ";
    std::cin >> x;
    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum is: " << x << '\n';
}

int main()
{
    int x {};
    
    x= readNumber(x) + readNumber(x);  // initially line 29 readNumber(x); line 30 x= x + readNumber(x);
                           // the issue was the first function call to readNumber() doesnt save the variable anywhere so x stays 0 the fix is putting both funtion calls on the same line and saving it in x
    writeAnswer(x);           

    return 0;
} */

/*
Question #2

The following program is supposed to divide two 
numbers, but doesn’t work correctly.

Use the integrated debugger to step through this
program. For inputs, enter 8 and 4. Based on the
information you learn, fix the following program: */
/*
#include <iostream>

int readNumber()
{
	std::cout << "Please enter a number: ";
	int x {};
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The quotient is: " << x << '\n';
}

int main()
{
	int x{};
	int y{};
	x = readNumber();
	y = readNumber();                   // initially line 67 x = readNumber(); so we call the function twice for x and but not for y which we should do instead // btw y is initialized (or at least it shows that in the variable window) with 8 kinda weird but no idea why it does that should have been initialzed with 0 by default but it kinda changes to 0 the first a function is called so the 8 was kinda temporary
	writeAnswer(x/y);                   // also to you could also write int x {readNumber()}; and int y {readNumber()}; to shorten the code

	return 0;
} */

/*
  Question #3

  What does the call stack look like in the following 
  program when the point of execution is on line 4
  (the one that has //here) ? 
  Only the function names are needed for this exercise,
  not the line numbers indicating the point of return.
*/

/* #include <iostream>

void d()
{ // here
}

void c()
{
}

void b()
{
	c();
	d();
}

void a()
{
	b();
}

int main()
{
	a();

	return 0;
}

// the answer is d() 
//               b()
//               a()
//               main() */

/*
  Extra credit: The following program is supposed to
  add two numbers, but doesn’t work correctly.
  Use the integrated debugger to step through this
  program. For inputs, enter 8 and 4. Based on the
  information you learn, fix the following program:
*/

#include <iostream>

int readNumber()
{
    std::cout << "Please enter a number: ";
    int x{};               // initially line 129 char x{};  the error is that this a initialization for a character and not a string bc of that undefined behaviour is struck and some garbage values are used instead so the calculation will be wrong (technically not a grabage value bc char have their own value but we get into that in the future)
    std::cin >> x;

    return x;
}

void writeAnswer(int x)
{
    std::cout << "The sum is: " << x << '\n';
}

int main()
{
    int x { readNumber() };
    int y {readNumber() };
    writeAnswer(x + y);

    return 0;
}
