#include <iostream>               // when the file is compiled its first getting preprocessed and the preprocessor starts with every #include e.g #include <iostream> basically compiling every file in there and then starting with the main file 
                                  // the identifier after define is always in capital letters
#define MY_NAME "Alex"            // When the preprocessor encounters this directive, any further occurrence of the identifier is replaced by substitution_text ("Alex"). Thats called Object-like macros with substitution text

#define USE_YEN                   /*Object-like macros without substitution text the diffrence here is that every occurence of the identifier is substituted with nothing and are also recommended to be used
								    its main use being to check if smth is defined in the first place with #ifdef or check if its not defined with #ifndef but dont forget after checking and putting
									the command in what to do if its exist or it doesnt exist finish with #endif  */

int main()
{
	std::cout << "My name is " << MY_NAME << ".\n";    // every instance of MY_NAME is replaced by "Alex" / its an old practice and using Object-like macros with substitution text is discouraged and not recommended to use
#ifdef USE_YEN
	std::cout << "Yen\n";     // will be compiled since USE_YEN is defined
#endif
	
#ifdef USE_EURO
	std::cout << "Euro\n"     // will be excluded since USE_EURO is not defined
#endif

#ifndef BOB
		std::cout << "Bob\n";  // will be compiled since BOB is not defined 
#endif

#if 0                       // Don't compile anything starting here  #if 0 can be used instead of commenting out code if for example it already has a multi line comment in between or if you want to remove it temporarily. If you want to re-enable thhe code  just put 1 instead of 0 after #if
	std::cout << "Daniel\n";
	/* Some
	 * multi-line
	 * comment here
	 */
	std::cout << "Steve\n";
#endif                      // until this point

#if 1                      // always true, so the following code will be compiled opposite of #if 0 
	std::cout << "Daniel\n";
	/* Some
	 * multi-line
	 * comment here
	 */
	std::cout << "Steve\n";
#endif

	return 0;                                           
}

// You can also write #if defined(PLACE_HOLDER) or #if !defined(PLACE_HOLDER) instead of #ifdef and #ifndef
/*
#define FOO 9 // Here's a macro substitution

#ifdef FOO // This FOO does not get replaced because it’s part of another preprocessor directive
	std::cout << FOO << '\n'; // This FOO gets replaced with 9 because it's part of the normal code
#endif

*/

/*
IMPORTANT the scope of #define goes even outside of functions e.g

#include <iostream>

void foo()
{
#define MY_NAME "Alex"
}

int main()
{
	std::cout << "My name is: " << MY_NAME << '\n';

	return 0;
}

even tho its in the function and the funtion isnt called the #define is still valid bc the preprocessor doesn work with functions and just looks at the #include and #define but generally you want to avoid
that and write #define outside of functions

and #define also works if its in other files but you need to #include them first e.g
Alex.h:

#define MY_NAME "Alex"

main.cpp:

#include "Alex.h" // copies #define MY_NAME from Alex.h here  /*btw if its a sole function you can just use forward declaration instead but in this case we need to use #include to get the full library 
                                                                of the code its very useful to just use #inlcude if you are planning to use multiple functions of a file instead of doing a forward declaration
																for each funtction (if they are in the same file/
#include <iostream>

int main()
{
	std::cout << "My name is: " << MY_NAME << '\n'; // preprocessor replaces MY_NAME with "Alex"

	return 0;
}

another example of the scope : 

function.cpp:
#include <iostream>

void doSomething()
{
#ifdef PRINT
	std::cout << "Printing!\n";
#endif
#ifndef PRINT
	std::cout << "Not printing!\n";
#endif
}


main.cpp:
void doSomething(); // forward declaration for function doSomething()

#define PRINT

int main()
{
	doSomething();

	return 0;
}
This will print "Not Printing!" bc even tho PRINT is defined in main it doesnt have any consequences on code of other file bc its only defined for main.cpp and not in the functions original file
*/