#include <iostream>

#define MY_NAME "Laurence"

void someFcn()
{
// even though gravity is defined inside the function the preprocessor will replace all subsequent occurrences of gravity in the rest of the file
#define gravity 9.8
}


void printGravity(double gravity)             // will cause a compilation error
{
	std::cout << "gravity: " << gravity << '\n';
}

void printInt(const int x)  // not preferred to use const in function parameter
{
	std::cout << x << '\n';
}

const int getValue()   // dont use const as return value bc the const is simply ignored
{
	return 5; 
}

int main()
{
	[[maybe_unused]] const double constgravity{ 9.8 }; // that is called a named constant /unlike normal variables, its value or its contents cant be changed / preferred use of const before type
	[[maybe_unused]] const int number{}; // must be initialized not only declared otherwise you get an error e.g const int number / number = 3; will give an error bc constants cant be changed

	[[maybe_unused]] int age{ 5 };
	[[maybe_unused]] const int constAge{ age };  // a const can be initialized by a non const variable / naming convention for const arent special but you can add constName to make clear its a const but its up to you

	printInt(5); // 5 will be used as the initializer for x  
	printInt(6); // 6 will be used as the initializer for x

	std::cout << getValue() << '\n';  

	std::cout << "My name is " << MY_NAME << '\n';

	printGravity(3.71);

	// Conclusion: Prefer constant over object-like macros (#define) with substitution text / bc its prone to errors ,harder to debug and it behaves diffrently
	// If you want to use an constant variable for multiple files you can and you should store them all in a central place  we will learn about that later on ( 7.9 -- Sharing global constants across multiple files)
	// const is a type qualifier / C++ has two type qualifiers const and volatile / volatile is rarely used and basically tells the compiler that the object may have its value changed at any time, that might help for certain kinds of optimization

	return 0;
}