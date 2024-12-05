#include<iostream>

void doSomething(int) // ok: unnamed parameter will not generate warning / you can also write a comment after the int to explain what it was used for in the past /its mainly useful if you changed the functio but its too much work to change every instance of it being used so instead you just remove the remove the name bc otherwise the amount of arguments does not match so the amount of arguments will stay the same
{
	//When a function parameter exists but is not used in the body of the function, do not give it a name.You can optionally put a name inside a comment.
}

void doPrint()
{
	std::cout << "In doPrint()\n";
}


void printValue(int x)              
{
	std::cout << x << '\n';
}

void printValues(int x, int y)
{
	printValue(x);
	printValue(y);
}
int add(int x, int y)
{
	return x + y;
}

int multiply(int x, int y)
{
	return x * y;
}

int doubleNumber(int x)
{
	return x * 2;
}

int main()
{
	
	doPrint();                             // this call has no arguments
	printValue(2);                         // 2 is the argument passed to function printValue()
	std::cout << add(5,6) << '\n';         // 5 and 6 are the arguments passed to function add()
	printValues(6, 9);
	
	std::cout << add(3, 6) << '\n';        // within add() x=3, y=6, so x+y=9
	std::cout << add(4 - 7, 5 * 9) << '\n';// within add() x=-3, y=45, so x+y=42

	int a{ 5 };
	std::cout << add(a, a) << '\n';        // evaluates (5 + 5)

	std::cout << add(1, multiply(2, 3)) << '\n';  //  evaluates 1 + (2 * 3)
	std::cout << add(1, add(2, 3)) << '\n';       // evaluates 1 + (2 + 3)

	std::cout << "Please enter a number so it can be doubled: ";
	int num{};
	std::cin >> num;
	printValue(doubleNumber(num));

	return 0;
}