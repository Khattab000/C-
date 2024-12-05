// used in UserDefinedNamespaceAndScopeResolutionOperator.cpp with foo.cpp
#include<iostream>
#include "goo.h" // dont forget to include the corrosponding header file

namespace Goo // we created a namespace Goo so we can call the function by using Goo::doSomething()
{
	int doSomething(int x, int y)
	{
		return x - y;   // the same as the one in goo but - instead of +
	}
}
