#include <iostream>
#include <string>

// Conditional Operator: Symbol ?:    Form  c?x:y   If conditional c is true then evaluate x, otherwise evaluate y

int main()
{
#if 0
	int x{};
	int y{};
	int greater{};
	if (x > y)
	{
		greater = x;
	}
	else
	{
		greater = y;
	}

	greater = ((x > y) ? x : y);      // using conditional operator that would be the same as the if statement above / helps to make code more compact but isnt advised for more complex if statements


	constexpr bool inBigClassroom{ false };
	constexpr int classSize{ inBigClassroom ? 30 : 20 };  // unlike the usual if statement (which is a statement) the Conditional Operator is an expression so that means it can be used to initialize variables
	// and in this case you cant even turn it into an if statement bc just like how variables defined inside a function die at the end of the function , variables defined inside of an if statement die at the end of the if statement / you could write a function tho that have if statements and pass that down to initialize it with but thats just a lot of extra work

	std::cout << "The class size is: " << classSize << '\n';

	// C++ prioritizes the evaluation of most operators above the evaluation of the conditional operator so you need to pay attention for mistakes e.g:

	int r{ 2 };
	int s{ 1 };
	int z{ 10 - r > s ? r : s };    // you expect that to evaluate to 8 but instead it evaluates to 2 bc the - is prioritized making it {(10-r) > s ? r:s} / it doing the calculation first makes it not give us an warning when used with brace initialization
	int o{ 10 - ((r > s) ? r : s) }; // this evaluates to 8 bc using paranthesis (which is recommended to always use paranthesis ont he whole conditional operator and paranthesis on the condition itself) makes it so the conditional operator is evaluated first and the calculation happen / for that reason tho that the calculation happens last the compiler will give us a warning so to compile that turn of warning level 

	std::cout << z << ' ' << o << '\n';


	// now some examples to how to use paranthesis on conditional operators

	return isStunned ? 0 : movesLeft;
	int z{ (x > y) ? x : y };
	std::cout << (isAfternoon() ? "PM" : "AM");
	std::cout << ((x > y) ? x : y);



#endif

	// the operator tries to convert one type to the other /if both are the same it stays the same/ if they are diffrent then it tries to find a common type without any loss of data for example int to double bc int to double doesnt lose data but the reverse isnt true/it the types are diffrent by signed or unsigned then the compiler tries to convert signed to unsigned regardless
	std::cout << (true ? 1 : 2) << '\n';   //okay both operands are int 
	std::cout << (false ? 1 : 2.2) << '\n'; // okay int value 1 is converted to double
	std::cout << (true ? -1 : 2u) << '\n';   // not okay bc of surprising result bc -1 tries to convert to unsigned int but its out of range causing Overflow / 2u = unsigned int 2
#if 0
	// if compiler cant find a way to vonvert the second and third operand it will give you an compile error e.g
	constexpr int l{ 5 };

	std::cout << ((l != 5) ? l : "l is 5");   // compile error compiler cant find common tpye for constexpr int and C-style string literal
#endif
	int l{ 5 };   // changed to int for issues with if statements and possible warnings/errors
	std::cout << ((l != 5) ? std::to_string(l) : std::string{ "l is 5" }) << '\n'; // no compiler error bc we did explicit conversion so the compiler didnt have to do it 

	if (l != 5)             // you can also do if statements instead to avoid conversion all together
	{
		std::cout << l << '\n';
	}
	else
	{
		std::cout << "l is 5" << '\n';
	}

	// Conclusion: Use conditional Operator for: Initializing one of two values to objects, assigning one of two values to objects, passing one of two values to funtion , returning one of two values from a function, printing one of two values
	// Avoid it for complicated expression and be careful about conversions bc it needs to do conversion if one of two values arent the same type

	return 0;
}