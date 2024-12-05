#include <iostream>


int getNumber()
{
	std::cout << "Enter a number: ";
	int y{};
	std::cin >> y;

	return y;
}

// The as-if rule says that the compiler can modify a program however it likes in order to produce more optimized code, so long as those modifications do not affect a program’s “observable behavior”.
int main()
{                                
#if 0	                          // Compile-time evaluation
	int x{ 3 + 4 };               // With optimization turned on this evaluates in compile time to int x{7}; so the calculation happens in compile time instead of run time
	std::cout << x << '\n';       // Advantages of that is using less memory and the program/executable being faster, bc the calculation happens in compile time making it so even if the expression/program is used/ran a million time it only needs to calculate once and then the optimized evaluation is used in runtime not needing to calculate anything
	                              // Disadvantage is the compilation takes a bit longer bc of that optimization but its well worth it
#endif	


	                             // Compile- time constants (Constant Expressions)
	                             // A constant expression is an expression where everything in the expression can be evaluated at compile-time
	                             // e.g Literal(5 ,1.2) , Constexpr variables (preferred over const integral), Const integral variables(const int x{5};), non type template parameters, Enumerators
	                             // Const variables that are not compile time constants are called runtime constants (can not be used in a constant expression) e.g Const non-integral variables are always runtime constants even with a constant expression initializer (if you need it to be compile time constant define them as constexpr instead)
	                             // Operators which support compile time evaluation : Arithmetic operators with operands that are compile time constants (e.g 1 + 2), Constexpr and consteval funtions


	// Non-const variables are always non-constants / Can run on compile time though optimization as long as the expressions is constant
	int a{ 5 };     // 5 is a constant expression
	double b{ 1.2 + 3.4 };   //1.2 + 3.4 is a constant expression
	

	// Const integral / always runs in compile time 
	const int c{ 5 };  //const expression
	const int d{ c };  //const expression
	const long e {c + d };  // const expression

	// Const variables that are runtiume constants / cant run on compile time even with optimization bc of their expression being non constants
	const int f{ a };        // a is not an constant expression
	const int h{ a + c };    // a + c is not an constant expression / even tho c alone would be but bc a is a non constant it doesnt work
	const int i{ getNumber() }; //getNumber() is not an constant expression
	const double k{ 1.2 };   // 1.2 is a constant expression but the type of k isnt an integral  one so its a runtime constant /integral types are : char,short,int,long,long long,

	int x{ 7 };
	std::cout << x << '\n'; // is a runtime expression bc x is not a compile time constant and the << operator doesnt support compile time evaluation when used for output
	                        // but depending on the compiler and how smart it is it might optimize it (in some cases) to some degree even tho the expression and the subexpression are non constants e.g 
	                        /*
							   int x{7};
							   std::cout << 7 << '\n';

							   or evene 

							   std::cout << 7 << '\n';   // optimizing out the int x{7}; bc its not needed and it treats/infer like the x like it doesnt change again (even tho its not a constant)
							   
							   // but that optimization rly depends on the compiler and how complex the program is
							
							*/

	const int z{ 7 };
	std::cout << z << '\n'; // even tho its a runtime expression the subexpression is constant so that subexpression can be optimized with ease unlike the the one with int x{7}; where the compiler had to figure out if the x doesnt change bc the z is a const


	std::cout << 3 + 4 << '\n'; //is a runtime expression but with a constant sub expression (3 + 4) in this case only the 3 + 4 is getting optimized and runs in compile time the rest  is ran in runtime / we call that constant folding

	/*
	   Ranking variables and their likelyhood to be optimized:
	   1. compile time constant variables (always eligble)
	   2. runtime constant variable
	   3. non const variable (likely only in simple cases)
	*/



	// Conclusion: Constant expressions (including constexpr variables and constexpr functions) can help produce code that is faster, smaller, and safer. Some C++ features require constant expressions.
	// One big disadvantage of the optimization is it makes it harder to debug in runtime e.g when a variable or a function is optimized out/away the debugger might behave strangely or skip over those when trying to watch them or step into them and we dont have many tools to debug in compile time thats why most of the time debug builds turn off optimizations so the compiled code will more closely match the source code



	                             

	return 0;
}