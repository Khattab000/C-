#include <iostream>

int add(int, int);  // this time we used a forward declaration for a function in another file (its in the add.cpp file to be exact) bc without that the compiler wouldnt know what add is and couldnt use it here
                    //  needed so main.cpp knows that add() is a function defined elsewhere

int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';
	return 0;
}

/*its important to not use the same name for a function if the name is already used in a file in the same project bc that would cause an error(compiling error if the two same function names are in
 the same file and linking error if its two diffrent files int the same  prgram/project */

/* 
 Namespaces are like Übergruppierungen to ensure that you can use two funtions of the same name e.g math::add and add can be both used if the funtion add is defined in main and the other add is defined
 in the namespace math

 The :: symbol is an operator called the scope resolution operator. The identifier to the left of the :: symbol identifies the namespace that the name to the right of the :: symbol is contained within. If no identifier to the left of the :: symbol is provided, the global namespace is assumed.

So when we say std::cout we’re saying “the cout that is declared in namespace std“.

This is the safest way to use cout, because there’s no ambiguity about which cout we’re referencing (the one in the std namespace).

you can also :

#include <iostream>

using namespace std; // this is a using-directive that allows us to access names in the std namespace with no namespace prefix

int main()
{
    cout << "Hello world!";
    return 0;
}

but you should AVOID using "using namespace std;" bc in this case ofc its easier bc you can just write cout but if you define your own function named cout in main it wouldnt work bc it wouldnt know which one to use and would
make the main reasons for namespaces obsolete

curly braces can be used to open a scope inside of a scope e.g

#include <iostream> // imports the declaration of std::cout into the global scope

void foo(int x) // foo is defined in the global scope, x is defined within scope of foo()
{ // braces used to delineate nested scope region for function foo()
    std::cout << x << '\n';
} // x goes out of scope here

int main()
{ // braces used to delineate nested scope region for function main()
    foo(5);

    int x { 6 }; // x is defined within the scope of main()
    std::cout << x << '\n';

    return 0;
} // x goes out of scope here
// foo and main (and std::cout) go out of scope here (the end of the file)
*/