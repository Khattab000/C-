#include <iostream>
#include "goo.h"  // include this so we can use Goo::doSomething
#include "foo.h"  // include this so we can use Foo::doSomething

int doSomething(int x, int y); // forward declare doSomething bc mistakingly put it under other functions that check for it
namespace Doo
{
	int doSomething(int x, int y)
	{
		return x * y;

	}
}

namespace Loo
{
	int doSomething(int x, int y)
	{
		return x % y;
	} 

	int doSomething2(int x, int y)
	{
		int i{ doSomething(x,y) };       // doSomething from the namespace Loo  x % y
		int k{ ::doSomething(x, y) };    // do someting from the global namespace x / y  
		return k + i;
		/* 
		in this case :: is actually required bc it looks for the definition in the current scope first if ::isnt there it looks through other namespaces that are included
		and then as the last option it looks into the global space, so then it would take the doSomething from Loo but with :: it would look in the global space first
		*/
	}

}

int doSomething(int x, int y)
{
	return x / y;
}
// small tip to avoid naming collisions try to define identifiers in the smallest scope possible

// foo.cpp and goo.cpp are used for the example here to showcase naming collisions and how to fix it 
#if 0
int doSomething(int x, int y); // forward declaration of the function doSomething / after putting doSomething in a namespace this forward declaration wont work anymore bc doSomething isnt in the global name space anymore
#endif
int main()
{
#if 0
	std::cout << doSomething(4, 3) << '\n';   // this will give an error bc doSomething is defined in foo and goo and compiler doesnt know which to use
#endif
	// to fix the naming collision we can create our own namepaces we will do that in foo.cpp and goo.cpp /naming convention for namespaces is to start with an capital letter to avoid any issues

	std::cout << Foo::doSomething(4, 3) << '\n'; // use the doSomething in the namespace Foo in foo.cpp /we need to create Header Files for each of them so they can be included
	std::cout << Goo::doSomething(4, 3) << '\n'; // use the doSomething in the namespace Goo in goo.cpp /we need to create Header Files for each of them so they can be included

	// namespaces can be also defined in the same file e.g

	std::cout << Doo::doSomething(4, 3) << '\n'; // we call doSomething from the namespace Doo
	std::cout << Loo::doSomething(4, 3) << '\n'; // we call doSomething from the namespace Loo
	std::cout << Loo::doSomething2(4, 3) << '\n'; // we call doSomething2 from the namespace Loo this one calls doSomething from the namespace Loo and doSomething from the global namespace 
	std::cout << ::doSomething(4, 3) << '\n';    // we call doSomthing that was defined in this file and ::doSomething(4,3) is the same as doSomething(4,3) this can be useful to make it clear which doSomething is called if there are multiple

	/*
	  btw its also allowed declaring namespace blocks of the same namespace  in multiple locations  e.g 

	  circle.h
	  #pragma once

	  namespace BasicMath
	  {
	    constexpr double pi{3.17};
	  }

	  
	  growth.h
	  #pragma once

	  namespace BasicMath
	  {
	    constexpr double e{ 2.7};
	  }




	*/
	return 0;
}