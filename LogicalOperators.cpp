#include <iostream>

// There are 3 Logical Operators: ! (NOT), && (AND), || (OR)


int main()
{
#if 0
	// ! (Not operator)
	int x{ 200 };
	bool tooLarge{ x > 100 }; // tooLarge is true if x > 100
	if (!tooLarge)
	{
		std::cout << "not to large\n";
	}
	else
	{
		std::cout << "too large\n";
	}
	// One mistake beginners do with the ! operator e.g:
	int y{ 700 };

	if (!x > y)
	{
		std::cout << x << " is not greater than " << y << '\n';
	}
	else
	{
		std::cout << x << " is greater than " << y << '\n';
	}
	/*
	This prints 200 is greater than 700 (this only works when warning level is turned down) the reason for that is the that the Logical !operator has a much higher precedence than
	the > operator so the expression actually evaluated to (!x) > y , x = 200 and !x = 0 so 0 > y evaluates to false making the else statemment evaluate, correct way :
	*/
	if (!(x > y)) // so it evaluates the x > y first and gets a bool in this case false and then the ! operator turns it to true making the first statement execute instead
	{
		std::cout << x << " is not greater than " << y << '\n';
	}
	else
	{
		std::cout << x << " is greater than " << y << '\n';
	}
	// In conclusion dont forget the paranthesis if Logical Not is intended to operate on the result of the operation
#endif
#if 0
	// Logical || (OR)

	std::cout << "Enter a number: ";
	int value {};
	std::cin >> value;

	if (value == 0 || value == 1) //if either or both are true it evaluates to true if neither are its false 
	{
		std::cout << "You picked 0 or 1\n";
	}
	else
	{
		std::cout << "You did not pick 0 or 1\n";
	}
	// A mistake beginners make to compare if a value are one of the two values is :
	if (value == 0 || 1); // incorrect: if value is 0 or if 1 , and bc if 1 is always true the if statement is always true regardless of value you you have to split them just like above
	
	if (value == 0 || value == 1 || value == 2 || value == 3) // correct way to do it 
	{
		std::cout << "You picked either 0,1,2 or 3 \n";  
	}

#endif
	// Logical && (And)
	std::cout << "Enter a number: ";
	int i{};
	std::cin >> i;

	
	if (i > 10 && i < 20 && i != 16)  // With the && operator all conditions need to be true so it evaluates to true
	{
		std::cout << i << " is between 10 and 20\n";
	}
	else
	{
		std::cout << i << " is not between 10 and 20 or is 16\n";
	}
	


	/*
	One important thing is that most compiler make short circuit evaluation, for example the && operator, x && y in this statement it will check the left side first and it if its true
	then it checks the right part, but if the the left part (x) is false it doesnt check the right part (y) bc there is no reason for that so y never evaluates. Smth similar happens 
	with the || operator, x||y for this one it checks the left first (x) if its true it doesnt check the right (y) bc it doesnt need to bc only one needs to be true so left (y) never
	evaluates. This is done for optimization purposes (only works with built in versions not overloaded versions that are changed to work with custom types)

	Here is small example how this can have negative side effects tho:
	if(x==1 && ++y == 2)
	the y is only incremented when x = 1 which shouldnt be the case bc we want it to be incremented regardless

	The Logical OR || and the Logical AND && are an exception to the rule that the operands may evaluate in any order, in their case the left operand must evaluate first
	*/

	/*
	When mixing Logical && and Logical ||, its important to keep in mind that && has a higher precedence than || so its advised to use paranthesis to make sure it gets evaluated 
	the way you want it to and in the order you wanted it. e,g

	value1 || value2 && value3 

	some would assume bc of the left to right association it evaluates to (value1 || value2) && value3 but bc of && higher precedence it evaluates to value1 || (value2 && value3)

	so to not make any mistakes and to increase readability and make sure if locical AND and logical OR are used in a singel expression you use paranthesis to ensure they evaluate
	as you intend
	*/

	/*
	De Morgans Laws
	Many programmers make the mistake of thinking  that !(x&&y) is the same thing as !x && !y but unfortunatly  you can not distribute logical NOT in that manner.
	De Morgans law tells us how the logical NOT should be distributed in these cases :
	!(x && y) is equivalent to !x || !y 
	!(x || y) is equivalent to !x && !y

	You can prove that with the truth table putting in true and false for : x, y,!x,!y, !(x&&y) and !x||!y
                                                     or for the other case: x, y,!x,!y, !(x||y) and !x&&!y
													 (keep in mind if x = true and y = false or vice versa then x&&y = false and x||y = true)
	*/

	/*
	Logical XOR

	Logical XOR is a logical operator that returns true if exactly one of the conditions is true otherwise its false (e.g if its true and true then its false).
	C++ doesnt provide a explicit logical XOR Operator (operator ^ is a bitwise XOR not logical) and unlike logical OR and logical AND , logical XOR cannot be short circuit evaluated,
	so making XOR out of AND and OR is gonna be challenging.
	However, operator != produces the same result as logcal XOR when given bool operands e.g:
	*/
#if 0
	if (a != b) // a XOR b, assuming a and b are bool /this returns true if exactly one operand is true 
		// we can even use more e.g
	if (a != b != c)// a XOR b XOR c , assuming a.b and c are bool /this returns true if exactly one operand is true 

			// if the operands are not of type bool, using != to imolement logical XOR will not work as expected 

			// if you need a form of logical XOR that works with non boolean operands you can static_cast your operands to bool e.g 

	if (static_cast<bool>(a) != static_cast<bool>(b) != static_cast<bool>(c)) // a XOR b XOR c , for any type that can be converted to bool
				// there is a much more concise way using !! e.g:
	if (!!a != !!b != !!c) // a XOR b XOR c, for any type that can be converted to bool / !! is used to convert the operands to bool the first ! (logical NOT ) already converts the value to bool but it inverts it thats why the second ! is needed to get back to the original boolean value of the operand 

	// In C++ the logical operators can be also used by using there keyword alternate names && = and , || = or ,! = not   e.g
	std::cout << !a && (b || c);
	std::cout << not a and (b or c); // exactly the same as above but the the symbols are the preferred way bc most existing codes use the symbols

#endif

	// Question 2

	bool isEven(int x)
	{
		return !(x % 2); // we use ! instead of == 1 bc if its even it should evaluate to zero and with ! the 0 is reversed to evaluate to true (bc 0 normally means false in bool and ! converts the value to bool) but if its odd it will evaluate to 1 and the ! inverts that so it evaluates to the bool false (1 normally is true in bool)
	}
	return 0;
}