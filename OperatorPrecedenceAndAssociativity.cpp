#include <iostream>

int getValue()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

void printCalculation(int x, int y, int z)
{
	std::cout << x + (y * z) << '\n';
}

int main()
{

	
	std::cout << 4 + 2 * 3 << '\n';  // compiler first parses (analyzes) the expression to determine how operands and operators are grouped together using the precedence and associativity rule
	printCalculation(getValue(), getValue(), getValue()); /*this will lead to either undefined behaviour or not unambigious variables bc the
	                                                        compiler might not evaluate the first function call first instead he evaluates the second or last function call first 
															making the input be in the wrong order. The output for 1 2 and 3 is 5 which is wrong*/
	int x{ getValue()};  // first
	int y{ getValue() }; // second
	int z{ getValue() }; // third
	printCalculation(x, y, z);                           /* now we made sure that the getValue() is evaluated in the right order making sure that it is unambigious unlike
	                                                        printCalculation(getValue(), getValue(), getValue());. The output for 1 2 and 3 is 7 which is correct*/

	// Key Insight: Operands, function argument and subexpression may be evaluated in any order so keep this in mind bc precedence and associativity doesnt affect that so keep that in mind when using function call using opernads evaluation order

	// small tasks add paranthesis to show the order of evaluation of the expression
	x = 3 + 4 + 5;
	x = ((3 + 4) + 5); // + has a higher prcedence than = so the  + expression is evaluated first and the + uses left to righ association so the 3 + 4 is first 

	x = y = z;
	x = (y = z);  // unlike +, = has right to left association so y = z is evaluated first

	z *= ++y + 5;
	z *= ((++y) + 5); // first is ++ bc it has the highest precedence, then + and then last *= with the lowest precedence

	a || b && c || d;
	(a || (b && c)) || d; // first is && bc it has the highest precedence then a || bc || uses left to right associativit and then ||d as last one

	return 0;
}