#include <iostream>

int five()
{
	return 5;  // The return value of a non-constexpr function is not a constant expression
}

int main()
{
#if 0
	int a{ 5 };          // not const at all
	const int b{ a };    // obviously a runtime const 
	const int c{ 5 };    // compile time const

	const int d{ someVar };    // not obvious wether runtime or compile time const
	const int e{ getValue() }; // not obvious wether runtime or compile time const

	// to make sure its a compile time const every time we can use constexpr instead but for that to work we need to give it an constant expression otherwise it will give us a compile error
	// and constexpr objects can be evaluated in run time or compile time and in compile time its guaranteed but const object are guaranteed to run in run time but only in certain cases in compile time

	constexpr double gravity(9.8); // expression is a constant / double only works bc of constexpr without it it wouldnt be eligble to be a const expression only integrals are
	constexpr int sum{ 4 + 5 }; // expression is a constant
	constexpr int something{ sum }; // expression is a constant

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	constexpr int myAge{ age };   // compile error: age is not a constant expression
	constexpr int f{ five() };    // compile error: return value of five() is not an constant expression / and functions normally executes at runtime so even if the return type was constant it wouldnt be a constant expression


#endif

	// Conclusion: Any constant variable whose initializer is a constant expression should be declared constexpr to make sure its ran in compile time. (we will discuss later tho types that arent compatible with constexpr where you wanna use const instead)
	// Any constant variable whose initializer is not an constant expression (making it a runtime constant) should be declared const.
	// Important in case of functions: const function parameters are treated as runtime constants regardless and you cant use constexpr as a parameter since the initialization value isnt determined until runtime /Exception are consteval functions and a way to pass compile time constant to  a function which we will cover in a future lesson

	return 0;
}