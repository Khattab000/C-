#include<iostream>


int addition (int p, int y)      // function parameters p and y are local variables / p and y created and initialized here / p and y are created and enter scope here
{
	// p and y are usable only within add()

	int z{ p + y };       // z is a local variable / z created and initialized here / z enters the scope here
	return z;
} // z, y, and p destroyed here / / z, y and p go out of scope and are destroyed here


// x is not in scope anywhere in this function
void doSomething()
{
	std::cout << "Hello\n";

}


int main()
{
	// x can not be used here because it's not in scope yet

	[[maybe_unused]] int x{ 0 };          // x's lifetime begins here / x enters scope here and can now be used within this function
	doSomething();       // x is still alive during this function call


	int a{ 5 };       // a is created, initialized, and enters scope here
	int b{ 6 };       // b is created, initialized, and enters scope here
	//a,b and x are usable only within main()
	std::cout << addition(a, b) << '\n'; 

	return 0;
} // x's lifetime ends here / x goes out of scope here and can no longer be used / b and a go out of scope and are destroyed here

/* important you can name the variables in a function x and y and also the variables in main x and y, but these two x and two y are entirely seperate and not the same and have the usual going
   into and out of scope and are initialzed and diffrent points of time and destroyed at diffrent point of times and dont affect each other bc they are NOT the same
   */

/* In modern C++, the best practice is that local variables inside the function body should be defined as close to their first use as reasonable :
    
   
   std::cout << "Enter an integer: ";
	int x{};       // x defined here
	std::cin >> x; // and used here

	std::cout << "Enter another integer: ";
	int y{};       // y defined here
	std::cin >> y; // and used here

	int sum{ x + y }; // sum can be initialized with intended value
	std::cout << "The sum is: " << sum << '\n';


*/