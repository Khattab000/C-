/*Question #2 Quiz Chapter 2

Modify the program you wrote in exercise #1 so that readNumber() and writeAnswer() live in a separate file called “io.cpp”.Use a forward declaration to access them from main().*/

#include "io.h"
#include <iostream>

int readNumber()
{
	std::cout << "Please input a number to add them together: \n";
	int num{};
	std::cin >> num;
	return num;
}

void writeAnswer(int num)
{
	std::cout << "The answer is: " << num << '\n';
}