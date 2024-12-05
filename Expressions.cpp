#include <iostream>

int five()
{
	return 5;
}
int main()
{
	[[maybe_unused]] int a{ 2 };                // initialize variable a with the literal value 2
	[[maybe_unused]] int b{ 2 + 3 };            // initialize variable b with computed value 5
	[[maybe_unused]] int c{ (2 * 3) + 4 };      // initialize variable c with computed value 10
	[[maybe_unused]] int d{ b };                // initialize variable d with variable value 5
	[[maybe_unused]] int e{ five() };           // initialize variable e with the funtio return value 5
	
	/* 
	   All those have in common that they make use of Expressions which basically evaluate a singular value that remains e.g
	 
	   2                       // 2 is a literal that evaluates to value 2
      "Hello world!"          // "Hello world!" is a literal that evaluates to text "Hello world!"
       x                      // x is a variable that evaluates to the value of x
       2 + 3                  // operator+ uses operands 2 and 3 to evaluate to value 5
       five()                 // evaluates to the return value of function five()

	   But Expressions with side effect are a bit more tricky e.g

	   x = 5                 // x = 5 has a side effect of assigning 5 to x , evaluates/returns x 
	   x = 2 + 3             // has side effect of assigning 5 to x, evaluates/returns  x
	   std::cout << x        //  has side effect of printing value of x to console, evaluates/returns std::cout
	    
	   */

	return 0;

}