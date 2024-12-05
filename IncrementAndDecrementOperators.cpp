#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int main()
{
	// Increment and decrement operators: ++x (increment x then return x), --x (decrement x then return x), x++ (copy x, then increment x, then return copy) , x-- (copy x, then decrement x, then return copy)

	int x{ 5 };
	// we call that prefix increment/decrement
	int y{ --x }; // x is decremented to 4, x is evaluated to 4, and 4 is assigned to y / keep in mind the value of x is also 4 now so the operator changed the variable x too
	std::cout << x << ' ' << y << '\n'; // returns 4 4

	int a{ 8 };
	// we call that postfix increment/decrement
	int b{a++ }; // a is copied so b is initialized with 8, then increment a so it evaluates to 9,  / so b initializes with 8 so a is the only one who changes it changes to 9 thats the main diffrence of post and prefix bc in prefix both a and b would have been incremented/decremented so in postfix only the original variable is incremented
	std::cout << a << ' ' << b << '\n';


	int c{ 5 };
	int d{ 5 };
	std::cout << c << ' ' << d << '\n';   // return 5 5
	std::cout << ++c << ' ' << --d << '\n'; // prefix /return 6 4
	std::cout << c << ' ' << d << '\n';     // return 6 4
	std::cout << c++ << ' ' << d-- << '\n'; // postfix / return 6 4
	std::cout << c << ' ' << d << '\n';     // return 7 3

	//Note that postfix is not as performant as prefix bc of the extra steps postfix does (like the copy)
	//Conclusion in most cases prefix and postfix do basically the same but you should favor the prefix version as it is more performant and less prune to cause surprises


	// Side effect are when a function or an expression has an observable effect beyong producing a return value e.g
	x = 5; // the assignment operator has side effect of changing value of x
	++x; // operator ++ has side effect of incrementing x
	std::cout << x << '\n'; // operator << has the side effect of modifying the state of the console
	// Most times side effects are useful but in some cases it can cause order of evaluation issues e.g
	int j{ 5 };
	int value{ add(j, ++j) };  // undefined behavior: is this 5 + 6 or 6 + 6 ? / It depends on what order your compiler evaluates the function arguments in
	std::cout << value << '\n'; // could be 11 or 12 depending how the above line evaluates
	// and also the side effects dont have a specific order when they apply e.g
	x + ++x; // Visual studio evaluates this as 2 + 2 but some other compilers evaluate it as 1 + 2 bc C++ does not define the order of evaluation so that the compiler can use the best and most performant order
	// so always be aware of of the side effects and its undefined behavior, so try to limit the usage of operators with side effect to only use per statement on the same variable exception are very simple statement like x = x + y which essentially is just x+=y
	


	return 0;
}