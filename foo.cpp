// used in UserDefinedNamespaceAndScopeResolutionOperator.cpp with goo.cpp
#include <iostream>
#include "foo.h"  // dont forget to include the corrosponding header file
namespace Foo // we created namespace Foo so now we can call the function by using Foo::doSomething()
{
	int doSomething(int x, int y)
	{
		return x + y;    // the same as the one in goo but + instead of -
	}
}
