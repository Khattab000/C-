#include <iostream>

/*
Write a program that asks the user to enter a number, and then enter a second number. The program should tell the user what the result of adding and subtracting the two numbers is.

The output of the program should match the following (assuming inputs of 6 and 4):

Enter an integer: 6
Enter another integer: 4
6 + 4 is 10.
6 - 4 is 2.
Hint: To print a period and a newline, use ".\n", not '.\n'.
*/

int main()
{
	std::cout << "Enter an integer: ";
	int num1{};
	std::cin >> num1;

	std::cout << "Enter another integer: ";
	int num2{};
	std::cin >> num2;

	std::cout << num1 << " + " << num2 << " is " << num1 + num2 << ".\n";   // make sure to only use ' ' for singular characters (excluding operators and integers) or '\n' (without the dot) otherwise ALWAYS " " bc otherwise you get garbage values
	std::cout << num1 << " - " << num2 << " is " << num1 - num2 << ".\n";

	return 0;
}