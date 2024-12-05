#include <iostream>

// The comma operator allows you to evaluate multiple expression wherever a single expression is allowed, the comma operator evaluates the left operand first and then the right operand and then returns the right operand e.g


int main()
{
	int x{ 1 };
	int y{ 2 };
	std::cout << (++x, ++y) << '\n'; // increment x and then y, evealuates to the right operand y / returns 3

	//But keep in mind comma has one of the lowest precedence even lower the assignment e.g
	int z{};
	z = (x, y); // evaluates (x,y) first bc () has higher precedence then = and so it gets the result of y and then assigns that value to the variable z / z = 3
	z = x, y;   // evaluates z = x first bc = has a higher precedence then  ,  so z gets assigned the value of x, and y is evaluated and then discarded  / z = 2

	// knowing that the comma operator is kinda dangerous bc of his low precedence  and not preferred/advised unless used for for loops 
	// the first code can be written as this to make it safer e.g:

	++x;
	std::cout << ++y << '\n'; // removing ++x and putting it above the print statement, so it stays the same and we avoided the comma operator

#if 0
	// There is one case where using comma is completely fine and encouraged and that wont invoke the comma operator, if used as a seperator e.g  in functions or passing down multiple variables/values to a function

	void foo(int x, int y) // Seperator comma used to seperate parameters in function definition
	{
		add(x, y); // Seperator comma used to seperate arguments in function call
		constexpr int z{ 3 }, w{ 5 }; // Seperator comma used to seperate multiple variables being defined on the same line (dont do this tho its not recommended)
	}
#endif



	return 0;
}