// Used with math.cpp and pi.h so include it in the project 
#include <iostream>
#include "pi.h"

int min(int x, int y)
{
	return (x < y) ? x : y;
}

inline int max(int x, int y)    // we call that an inline function if the inline command is used / but that was mainly used in the past before compilers became smarter
{
	return (x > y) ? x : y;
}


double circumference(double radius); // forward declaration / function in math.cpp so you need to include it in the project


int main()
{
	// If the function is called multiple times like min() it takes more performance to do we call that performance overhead if its a complex function that isnt called often that doesnt matter, but if its a simple funtion called a lot of times that leads to a performance penalty and we might wann consider putting the funtion in main
	std::cout << min(5, 6) << '\n';
	std::cout << min(3, 2) << '\n';

	//We can use Inline Expansion , which basically moves the code of the function into main where its called so the process of Overhead isnt needed bc there is no reason to go overhead to the function and making function calls
	/*
	using Inline would make the code look like this when compiled :

	std::cout << ((5 < 6) ? 5 : 6) << '\n';
	std::cout << ((3 < 2) ? 3 : 2) << '\n';

	with inline you save the effort of going up to the function and also even open up the code for additional optimization in compile time (if optimization is turned on) e.g ((5 < 6) ? 5 : 6) is turned to  5 in compile time so at runtime its std::cout << 5 << '\n'

	*/
	// But inline Expansion can be slower too if the body of the funcion takes more instructions then the function call would have so if used try to use it on simple and small functions (that are called multiple times e.g loops) to assure that you get a performance improvement

	// Functions fall in 2 categories : may be expanded and cant be expanded , most functions fall into the may be expanded

	// most modern Compilers with Optimization turned on decide themselves if a function should be inline expanded or not but you can do it manually too:

	//In the past compilers couldnt do that on their own so we used the command inline before the function to give the compiler a hint to consider doing the inline Expansion:

	std::cout << max(5, 6) << '\n';
	std::cout << max(3, 2) << '\n';

	/*
	In modern C++ the inline keyword in functions isnt used anymore bc for multiple reasons :

	1. Using inline expansion is a premature optimization and missuse can actually harm the performance
	2. The inline keyword is just a suggestion so the compiler might ignore it or even optimize functions without the keyword depending on the optimization
	3. Even tho inline keyword is defined on a function definition it is determined by each function call so there might be some cases where one call gets the inline expansion and the other call doesnt

	So in Conclusion in most cases the compiler himself knows when to use it and most of time bettern than humans so avoid using the inline keyword and let the compiler do it himself
	*/

	/*
	   In modern times the inline keyword is mostly used for: Being able to define the same function multiple times across linked files
	   without causing an error (but they need to be the EXACT same and be written out not just a declaration) and being able to put functions in header files and them being
	   transferred correctly if said headerfile is called
	   And then the linker will consolidate all inline functions for an identifier into a single function (bc it assumes all are identical
	   and with that still adhering to the one definition rule)
	   e.g:
	*/

	std::cout << pi() << '\n';
	std::cout << circumference(2.0) << '\n';


	// Conclusion its preferred to use inline mostly in header files (so try to avoid them) so you can add functions or variables that where defined in a header file to other files by including the .h file / Forward Declaration works too if its a specific one only
	// Reason why not to make all functions inline and defined in header files bc that actually increases the compile time considerably and if there is any change to it every file using the header files have to recompile which is gonna take a long time
	// We will be talking about Inline Variables (basically the same as the counterpart, can be defined in multiple files and adheres to the same rules) and more use cases for Inline functions in future lessons 
	return 0;
}