#include <iostream>

bool isEqual(int x, int y)
{
	return x == y; // operator == returns true when equal and false when not equal
}

int abs (int x)
{
	if (x < 0)
	{
		return -x; // early return (only when x < 0) / early return can also be used in main function if you want your program to finish executing early if a certain condition is met before finishing the full program and reaching return 0; or abort early due to some error condition, in some cases you can also type return; without anything but will be covering that later 
		 
	}

	return x;

}

bool isAllowedToTakeFunRideBadVersion()       // if you have a function with an if statement that returns a bool you can save some time and space and write return height >= 140.0 bc that returns true if its true and false if its false so no need for if statement here / keep that in mind for funtions
{
	std::cout << "How tall are you? (cm)\n";

	double height{};
	std::cin >> height;

	if (height >= 140.0)
		return true;
	else
		return false;
}

bool isAllowedToTakeFunRideGoodVersion()
{
	std::cout << "How tall are you? (cm)\n";

	double height{};
	std::cin >> height;

	return height >= 140.0;      // returns true or false depending on the input with that you save yourself writing an if statement
}
int main()
{
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	if (x > 0) // the condition of an if statement evaluates to a boolean value true or false 
	{
		std::cout << "The value is bigger then zero\n";  // the format without { } can be used if only one statement is in the if statment but its recommended just to use {} to increase readability
	}   
	else if (x < 0)     // you can chain as many else if() as you want
	{
		std::cout << "The value is smaller then zero\n";
	}
	else
	{
		std::cout << "The value is zero\n";
	}

	bool zero{ (x == 0) };  // depending on the input its true or false 

	if (zero)  // if true 
	{
		std::cout << "The value is zero\n"; 
	}
	if (!zero) // if false / it works bc even tho normally the condition needs to be true with the ! operator we look for smth false and then make the statment go true  / thats just for education but in this case you can just use else
	{
		std::cout << "The value is not zero\n";
	}

	int y{ 4 };
	if (isEqual(x, y)) // if true bc the function returns a boolean type
	{
		std::cout << x << " and " << y << " are equal.\n";
	}
	else
	{
		std::cout << x << " and " << y << " are not equal.\n";
	}

	if (4) // every nonzero int gets converted to a 1 so its always true /is treated as a warning tho so to try out disable warning level to 1
	{
		std::cout << "working\n";
	}
	else if (0) // zero int gets converted to 0 in bool and is always false /only way to make it true to use the ! operator before the zero
	{
		std::cout << "not working\n";
	}
	else
	{
		std::cout << "not sure\n";
	}

	std::cout << abs(4) << '\n';
	std::cout << abs(-3) << '\n'; // output is 3 bc of the early return in the function

	std::cout << "Enter a prime Number: ";
	int prime{};
	std::cin >> prime;

	if (prime == 2 || prime == 3|| prime == 5|| prime == 7)  // || is or operator / && is and operator / you could also make a switch statement instead 
	{
		std::cout << "its a prime number";
	}
	else
	{
		std::cout << "its not a prime number";
	}

	return 0;
}