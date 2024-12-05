#include <iostream>

bool isEqual(int x, int y)
{
	return x == y; // operator  == returns true if x equals y, and false otherwise /that returns a true or false statement
}

int main()
{
	//bool b;           // without initialization no value at default /is commented out  bc compiler warning is treated as error 
	[[maybe_unused]] bool c{};         // with initialization default value is false
	[[maybe_unused]] bool d{ true };
	[[maybe_unused]] bool e{ false };

	d = false;

	[[maybe_unused]] bool f{ !false }; // true
	[[maybe_unused]] bool g{ !true };  // false

	// boolean values arent stored as word in the boolean variable but instead as numbers 1 for true and 0 for false so if evaluated they either are 1 or 0 so when you print boolean values you get either a 1 or 0

	std::cout << true << '\n'; // 1
	std::cout << !true << '\n'; // 0

	bool h{ false };
	std::cout << h << '\n'; // 0
	std::cout << !h << '\n'; // 1

	std::cout << std::boolalpha; // Input/Output Manipulation if you want to print the boolean value as true or false instead of 1 or 0 or when asking for input so the user doesnt need to use 1 or 0 and can type lowercase true or false instead
	std::cout << true << '\n'; // true 
	std::cout << false << '\n'; // false
	std::cout << std::noboolalpha; // use that to disable boolalpha again

	bool foo{}; // default to false
	std::cout << "Enter a boolean value: ";
	std::cin >> foo;                           // btw if you give an invalid input the program just silently fails and doesnt even let you do the second input below
	std::cout << "You entered: " << foo << '\n';
	// common mistake is that you think typing in true or false works as an input thats why when you do the output is 0 even when you typed in true you need to input 1 or 0 as boolean value
	// but if you wanna enable inputting true or false use std::cin >> std::boolalpha;
	std::cin >> std::boolalpha; // important if activated 1 and 0 arent valid anymore until you disable with std::cin >> std::noboolalpha;
	std::cout << std::boolalpha; // so the output is also true or false instead of 1 or 0
	std::cout << "Enter a boolean value: ";
	std::cin >> foo;
	std::cout << "You entered: " << foo << '\n';

	std::cout << "Enter an Integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another Integer: ";
	int y{};
	std::cin >> y;

	std::cout << x << " and " << y << " are equal ? ";
	std::cout << isEqual(x, y) << '\n'; // will return true or false





	
	return 0;
}