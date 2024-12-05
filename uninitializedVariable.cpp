#include <iostream>

int main()
{
	int x{};                          // if you print that you get 0 bc its initialized and has the default 0 / if you would have use int x; instead you would have gotten an error or garbage value bc that doesnt initialize
	std::cout << x << '\n';

	std::cout << sizeof(int) << '\n'; /* print how many bytes of memory an int value takes / most platforms will produce 4 but some rare ones might produce 2 depending on the compiler
										try to avoid those cases that are compiler depended to make sure that the code works fine on any compiler*/

	return 0;
}

/*if you write int x{}; x is initialized with a default value(0) if you write int x; x is not initialized / for most times the first way is better but the second way also has some small adavntage for performance
  for example if you have 100 000 variables rdy to be filled with data it would take less time letting them be uninitialzed if you gonna change them anyways but its not a big diffrence*/

  /*if you wanna trick your compiler into running a program with uninitialized values you can do that

#include <iostream>

void doNothing(int&) // Don't worry about what & is for now, we're just using it to trick the compiler into thinking variable x is used
{
}

int main()
{
	// define an integer variable named x
	int x; // this variable is uninitialized

	doNothing(x); // make the compiler think we're assigning a value to this variable

	// print the value of x to the screen (who knows what we'll get, because x is uninitialized)
	std::cout << x << '\n';

	return 0;
}

*/