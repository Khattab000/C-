#include <iostream>
#include <cmath>    // for exponent operation std::pow(x,y) / x^y
#include <cassert>  // for assert
#include <cstdint>  // for std::int64_t

// you can use #include <limits> to use std::numeric_limits to build a safer but slower version which also checks for overflowing
//note: exponent must be non-negative 
//note: does not perform range/overflow checking, use with caution
constexpr std::int64_t powint(std::int64_t base, int exp)   // constexpr allows function to run in compile time if the argument is a constant expression
{
	assert(exp >= 0 && "powint: exp parameter has a negative value");  // assert checks if the condition inside its bracket is true if its true nothing happens and the program just continue but if its false stop the program and show the error message written in the assert function
	if (base == 0)
	{
		return (exp == 0) ? 1 : 0;
	}
	std::int64_t result{ 1 };
	while (exp > 0)
	{
		if (exp & 1) // if exp is odd / that is a bitwise operation which you will learn in a future chapter
		{
			result *= base;
		}
		exp /= 2;
		base *= base;
	}
	return result;
}

constexpr bool isEven(int x) 
{
	/* Initial answer even tho correct there is a way to simplify the preffered answer is below
	if ((x % 2) == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
	*/
	return (x % 2) == 0;  // if that statement is true it returns true but if its false it returns false /
}

int main()
{
	// Important the remainder operator only works with int variables not float and others
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	std::cout << "Remainder is: " << x % y << '\n';   // the result of the remainder always takes the sign of the first variable in this example x so if x is positive then the remainder is also positve and if x is negative the remainder is also negative regardless what sign y has
	
	if ((x % y) == 0)     // you can also use (x % 2) == 0  to check if a variable is even or odd, even when this is true and off when its false 	                  
	{                     // if you want to check for odd use (x%2) != 0; instead of (x % 2) == 1 bc in case x is negative the remainder of an odd negative will be -1 which isnt 1 
		std::cout << x << " is evenly divisible by " << y << '\n';
	}
	else
	{
		std::cout << x << " is not evenly divisible by " << y << '\n';
	}
	// Conclusion prefer to compare the result of a remainder operator against 0 if possible e.g to find out if its odd or even


	//We make exponents using std::pow() dont forget to #include <cmath> e.g

	double p{ std::pow(3.0,4.5) }; // 3^4.5   / unlike remainder, exponent uses float only so if you want to use integer or get an integer result make your own algorithm 
	std::cout << p << '\n';

	// unlike remainder, exponent uses float only so if you want to use integer or get an integer result make your own algorithm e.g powint() /its a self written function
	std::cout << powint(-7, 13) << '\n';  // now we can use int instead of float /keep in mind no negative exponents for this function
	// but in a lot of cases exponentiation will overflow for integral types thats why its preffered to use std::pow() with the double type and thats also a reason why std::pow is included in the standard library

	//Small tasks
	std::cout << "Enter an integer: ";
	int i{};
	std::cin >> i;

	if (isEven(i))
	{
		std::cout << i << " is even\n";
	}
	else
	{
		std::cout << i << " is odd\n";
	}

	return 0;
}