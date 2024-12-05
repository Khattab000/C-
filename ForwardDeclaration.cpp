#include <iostream>



/*A forward declaration allows us to tell the compiler about the existence of an identifier before actually defining the identifier e.g Function A references Function B and Function B references Function A
  if you write that beneath each other without Forward declaration it will lead to an error bc either on of them doesnt exist yet to be referenced and thats where Forward declarations become handy 
   when its too hard to reorder or restructure the code OR telling the compiler about a function in another file */

int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon.  No function body! / without that the below code wouldnt compile bc add() is defined after main()
// the names of the parameters are optional and will be ignored by the compiler so even if it isnt the correct names it still compiles
int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
	return 0;
}

int add(int x, int y)                                            // even though the body of add() isn't defined until here
{
	return x + y;          
}

/*  Declarations vs. definitions
    A declaration tells the compiler about the existence of an identifier and its associated type information. Here are some examples of declarations:
	
	int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
    int x;                 // tells the compiler about an integer variable named x

	A definition is a declaration that actually implements (for functions and types) or instantiates (for variables) the identifier. Here are some examples of definitions:

	// because this function has a body, it is an implementation of function add()
int add(int x, int y)
{
	int z{ x + y };   // instantiates variable z

	return z;
}

int x;                // instantiates variable x


All definitions are declarations but not all declarations are definitions
*/