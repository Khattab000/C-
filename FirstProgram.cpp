#include <iostream>

int main()
{
	//First, let’s create a program that asks the user to enter an integer, waits for them to input an integer, then tells them what 2 times that number is.


	std::cout << "Enter an integer: "; 

	int num{};
	std::cin >> num;

	std::cout << "Double " << num <<  " is: " << num * 2 << '\n';
	std::cout << "Triple " << num << " is: " << num * 3 << '\n';   // Extra task add Triple

	return 0;
}