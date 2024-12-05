#include "add.h"    // Insert contents of add.h at this point.  Note use of double quotes here. 
/* reason for using double quotes instead of angled brackets is, we tell the compiler with "" that its a header file we created so it starts looking throughout our project source code directories firs
  but if we use <> we tell the compiler that its a header file that we didnt write so he doesnt look throughout out source code first and knows where to look for it*/

#include <iostream> // Use the standard library header files without the .h extension. User-defined headers should still use a .h extension.

int main()
{
	std::cout << "The sum of 2 and 3 is: " << add(2, 3) << '\n';   // we can use the function add() bc of the #include "add.h"
	return 0;
}

// avoid #include cpp files 
/*if you want to include a header file from another directory on your pc you can either #include and write down the full path of the header file(which isnt recommended) or just
  right click on the prjoect in the Solution Explorer , then click properties and then click on VC++ Directories and include it there */


/*
  Order of  header files inclusion

  1.The paired header file     (for example in add.cpp the first one is is #include "add.h" bc its the paried header file)
  2.Other headers from your project
  3.3rd party library headers
  4.Standard library headers   (#include <iostream>)


  and if there are multiple of a certain group just sort them alphabetically 
*/
