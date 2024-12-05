#include <iostream>
#include <type_traits> // is std::is_constant_evaluated

constexpr double calcCircumference(double radius)  // you need to make the fucntion return constexpr so it can be called by a constexpr variable / with that the function call and the constexpr variables are ran in compile time 
{
	constexpr double pi{ 3.14159265359 };
	return 2.0 * pi * radius;                      // the function can only be constexpr if two things are considered: The arguments used in the function call must be known at compile time AND all statements, expressions and other functions in the function must be evaluated in compile time
} 


consteval auto compileTimeEval(auto value) // just a helper function for already exisiting constexpr to force them into evaluating in compile time
{                                          // auto type so it works with any type thats why we put auto type in parameter and return
	return value;            
}


constexpr int greater(int x, int y)
{
	return (x > y ? x : y);    
}


int getValue(int x)
{
	return x;
}

// function foo runs in runtime without any problems but will have a compilation error when trying to run it in compile time bc it calls a non-constexpr function
constexpr int foo(int x)
{
	return getValue(x);      // call to  a non-constexpr function
}

// c is not an constexpr and cannot be used in a constant expression
consteval int goo(int c) // consteval fuction can take non constexpr parameters like a constexpr function but unlike constexpr where it might run in runtime consteval ALWAYS evaluates in compile time so you need to make sure that what the function does and where the function is called is able to evaluate in compile time otherwise you get an error
{
	return c;             // now c is a 
}




consteval int bigger(int x, int y) // function is now consteval
{
	return (x > y ? x : y);
}


// b is not an constexpr and cannot be used in a constant expression even if the parameter passed down to it was a constexpr
constexpr int doo(int b)
{
	constexpr int b2{ b }; // compile error  bc constexpr variable requires constant expression initializer
	return goo(b);         // compile error  consteval function requires constant expression

}

int main()
{
#if 0
	constexpr double radius{ 3.0 };
	constexpr double pi{ 3.14159265359 };
	constexpr double circumference{ 2.0 * radius * pi };  // but having that complex of a initializer isnt ideal so lets make it into a function

	std::cout << "Our circle has circumference " << circumference << '\n';  // this compiles bc constexpr can be used without any problems to initialize here if the type fits




	constexpr double circumference{ calcCircumference(3.0) };  //is only possible bc the functions is a constexpr function otherwise most function calls wouldnt be permissable / so bc its run in compile time the function call is replaced with the return value of the function
	std::cout << "Our circle has circumference " << circumference << '\n';

	int x{ 5 };  // not constexpr
	int y{ 6 };  // not constexpr 

	std::cout << greater(x, y) << " is greater!\n"; // will be evaluated at runtime bc the arguments passed to the function arent constexpr if they were constexpr the function would have beein ran at compile time

	int h{ greater(6,7) }; // may evlauate at runtime or compile time bc even tho we passed 2 constants to the function, the variable doesnt necessary need a constexpr variable so bc of that the compiler may decide to run the function and variable in runtime instead compile time / compile time evaluation is only guaranteed when a constant expression is required


	int z{ foo(5) }; // runs normally in run time
	constexpr int t{ 7 }; // compile error bc foo cant evaluate in compile time

	//Conclusion: All constexpr functions should be able to evaluate in compile time as they need to when used with constant expressions so always test if it runs with constexpr in compile time

#endif
	constexpr int a{ 5 };
	std::cout << doo(a); // okay a constand exo


	/*
	When a Constexpr/Consteval function is evaluated in compile time the compiler need to see the full definition so an forward declaration wouldnt suffice, so everytime its used it needs
	to be defined which normally would be a violation of the ODR bc of that constexpr functions are implicitly inline so they are exempt from this rule, in result constexpr are often
	defined in header files if used in multiple times so you can just include it in any cpp file you need

	so if constexpr/consteval function is used in one file then  just put it in the source file ,if multiple use a header file to distribute the function

	but if its a constexpr call that is run in runtime and not compile time a forward declaration will suffice

	also keep in mind marking a function constexpr means it can be used in an constant expression but it doesnt mean it evaluates in compile time every time if used in other cases
	*/
	// To make it more clear when it runs in run or compile time lets look at 4 cases

	constexpr int g{ greater(5,6) };                       // case 1: always evaluated at compile time
	std::cout << g << " is greater!\n";

	std::cout << greater(5, 6) << " is greater!\n";        // case 2: may be evaluated at either runtime or compile-time

	int x{ 5 };  // not a constexpr but value known at compile time
	std::cout << greater(x, 6) << " is greater!\n";        // case 3: likely evaluated in runtime

	std::cin >> x;
	std::cout << greater(x, 6) << " is greater!\n";        // case 4: always evaluated at runtime

	//even non-constexpr functions could be evaluated at compile time under the as-if-rule
	// C++ does not currently provide an reliable mechanisms to determine if a function call is evaluatin in run time or compile time
	/*
	there are some tools e.g std::is_constant_evaluated() (older version) or if consteval (newer version) which will return true or false if the the compiler is being forced
	to evaluate the function in compile time BUT there are cases where the compiler isnt forced but does it regardless (depending on optimization level) so those tools arent rly reliable
	*/
	
	
	constexpr int s{ bigger(5,6) };     // okay will evaluate at compile time
	std::cout << s << '\n';
	
	std::cout << bigger(5, 6) << '\n';  // okay will evaluate at compile time#

	int e{ 5 }; // not constexpr
	std::cout << bigger(e,6) << '\n';   //error: costeval functions must evaluate at compile time

	// Use consteval if you need to make sure that your function MUST run in compile time for some reason (but the parameters dont need to be constexpr and the function can only run in compile time so its not as flexible as constexpr functions)

	// If you want to have a way to force constexpr to run in compile time but still be flexible about you can use a helper function consteval auto  (btw the parameter is also auto) e.g:

	std::cout << bigger(5, 6) << '\n';   //may or may not execute at compile time
	std::cout << compileTimeEval(bigger(5, 6)) << '\n'; // will execute at compile time 

	int x{ 5 };
	std::cout << bigger(5, 6) << '\n';  // we can still call the constexpr version at runtime if we wish

	/*
	Inside  a consteval/constexpr function we can use local variables that arent constexpr and the values of those can change in the fucntion e.g :

	consteval int doSomething(int x,int y) //Function is consteval
	{
	   x += 2;      // we can modify the value of non const function parameters
	   int z{x + y}; // we can instantiate non-const local variables
	   if (x > y)
	   {
	     z -= 1;     // and then modify their values
	   }
	}


	int main()
	{
	  constexpr int g{doSomething(5,6)};
	  std::cout << g << '\n';
	  return 0;
	
	}

	so the compiler basically executes the function in compile time and returns the calculated value

	Another interesting thing is that constexpr/consteval functions can use their parameters or local variables for constexpr function calls even if those parameters or local variables
	arent constexpr the most important rule is if a constexpr/consteval function that runs in compile time is calling another constexpr function, this function needs to also run in
	compile time so with that even with no constexpr values it allows the constexpr function called to still run in compile time e.g:

constexpr int goo(int c) // goo() is now constexpr
{
	return c;
}

constexpr int foo(int b) // b is not a constant expression within foo()
{
	return goo(b);       // if foo() is resolved at compile-time, then `goo(b)` can also be resolved at compile-time but if its resolved in run time goo is also resolved in runtime
}

int main()
{
	std::cout << foo(5);

	return 0;
}


There is also a way for a constexpr funtion to call a non constexpr function but thats only possible without error if the constexpr is in a non constant context and evaluated in runtime e.g:

constexpr int someFunction()
{
  if(std::is_constant_evaluated())
      return someConstexprFunction();

  else
      return someNonConstexprFunction();

}


or another e.g :

constexpr int someFunction(bool b)
{
	if (b)
		return someConstexprFcn();
	else
		return someNonConstexprFcn();  // someFunction(false) is legal if the constexpr function isnt in a constant context or evaluates in compile time
}

In conclusion: Avoid calling non constexpr functions in constexpr functions but if you need smth like that use if coneteval or (std::is_constant_evaluated()) to make sure that they are
conditionalized and alwas test your constexpr functions in constant context bc it migh run without any error in runtime but has a compiler error in compile time

Why not make ever function constexpr: Bc first you dont want invalid functions to be able to be called by constexpr functions if they arent able to to function in a constant context.
Second removing it afterwards might break the code if certain functions required it to be constexpr. Last it makes functions harder to debug bc you cant inspect them in runtime bc they are
evaluated in compile time.

Reasons to using constexpr: First there isnt much downside to it and it may help make the program faster and smaller and be optimized, Second even if you dont call it in compile time yet you might in
the future if the program extended or is getting modified so you dont miss out on the performance boost, Last Repetition helps ingrain best practices so you dont forget about it and its worth
spending some time to do it right the first time so you dont have to redo/test it later on and risk breaking parts of the code or the function.

So in General if a function can be evaaluated in a constant expression (evaluated in compile time) it should be made into a constexpr function even if its isnt currently used that way
and a function that cannot be evaluated as part of a constant expression (evaluated in compile time) should not be marked as constexpr





Here is a simple summary:

const: Value can’t change after initialization but can be set at runtime.

constexpr: Value must be known and set at compile-time but can be used at runtime too.

consteval: Value must be evaluated at compile-time, always.
	*/
	return 0;
}