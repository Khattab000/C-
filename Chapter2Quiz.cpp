/*Question #1 Quiz Chapter 2

Write a single - file program(named main.cpp) that reads two separate integers from the user, adds them together, and then outputs the answer.The program should use three functions :

A function named “readNumber” should be used to get(and return) a single integer from the user.
A function named “writeAnswer” should be used to output the answer.This function should take a single parameter and have no return value.
A main() function should be used to glue the above functions together.

Question #2

Modify the program you wrote in exercise #1 so that readNumber() and writeAnswer() live in a separate file called “io.cpp”. Use a forward declaration to access them from main().

*/

#include "io.h"
#include <iostream>


int main()
{
	int num1{ readNumber() }, num2{ readNumber() };
	writeAnswer(num1 + num2);
	return 0;
}