#include <iostream>
#include <algorithm> // for std::max
#include <cmath> // for std::abs (std::abs became constexpr in C++23)

#if 0
// absEpsilon is an absolute value 
bool approximatelyEqualAbs(double x, double y, double absEpsilon)
{
	//if the distance between x and y is less than or equal to absEpsilon, then x and y are "close enough" and return true (1)
	return std::abs(x - y) <= absEpsilon;
	// even tho the function might work its not recommended bc its doesnt cover very small numbers and very big numbers properly and its not written by some famous scientist
}
#endif

// better version of the function bc it covers all numbers regardless of its size and it uses percentage to achieve that
constexpr bool approximatelyEqualRel(double x, double y, double relEpsilon)
{
	//Epsilon this time is not an absolute its a relative number changing to the magnitude of x or y

	return (std::abs(x - y) <= (std::max(std::abs(x), std::abs(y)) * relEpsilon)); // std::abs() returns the absolute value so the value is always postive/ std::max returns the largest value from the variables passed in
	
	//first the distance is calculated and then compared to see if its equal or lower then the larger absolute value * Epsilon(percentage of how big the diffrence can be)
	// Return true if the diffrence between x and y is within epsilon percent of the larger of x and y
	// But we have decide ourselves what we want epsilon to be or how small the diffrence can be for example if the diffrence can only be 1% or lower (Epsilon{0.01}) or 0.2% (Epsilon{0.002})  

	// if you want inequality just use the same function and use the logical not (!) operator in front of the function e.g if (!approximatelyEqualRel(a, b, 0.001))
}

// Return true if the diffrence between x and y is less than or equal to absEpsilon, or within relEpsilon percent pf the larger of x and y 
constexpr bool approximatelyEqualAbsRel(double x, double y, double absEps, double relEps)
{
	//Check if the numbers are really close , needed when comparing near zero 
	if (std::abs(x - y) <= absEps)
	{
		return true;
	}

	// Otherwise use the Knuth's algorithm (the second function that uses relEpsilon)
	return approximatelyEqualRel(x, y, relEps);
}

int main()
{
	// We have six relational operators that return boolean value true (1) or false (0) depending if the realtion is true e.g <,>,>=,<=,== and !=+
#if 0
	//By default conditions in an if statement or conditional operator evaluate as boolean values e.g
	int b1{ 9 };
	if (b1 == true) // == true is not needed and doesnt add anything
		if (b1)         // do this instead bc its the exact same and also will return true so the if statement will run on that

			if (b1 == false) // == false is also has a a better way to write it down
				if (b1 != true)  // or this is also a bad way to write it down
					if (!b1)         // do this instead its the exact same and returns the same as the two above this
						// so dont use == or != if it doesnt add anything bc it makes them harder to read without any benefits
#endif

	// Comparison of calculated floating point value can be problematic e.g

	constexpr double d1{ 100.0 - 99.99 }; // should be equal to 0.01
	constexpr double d2{ 10.0 - 9.99 };   // should be equal to 0.01
	
	if (d1 == d2)       // to run those if statements lower the warning level 
	{
		std::cout << "d1 == d2" << '\n';
	}
	else if (d1 > d2)
	{
		std::cout << "d1 > d2" << '\n';
	}
	else if (d1 < d2)
	{
		std::cout << "d1 < d2" << '\n';
	}
	/* 
	Even tho we expect it to output "d1 == d2" bc 0.01 == 0.01 it does not, it ouputs d1 > d2 instead, if you take a close look in the debugger you  can see that 
	d1 = 0.010000000000005116 and d2 = 0.0099999999999997868 both numbers are close to 0.01 but d1 is greater than and d2 is less than.
	As we discussed comparing floating point numbers can be dangerous bc floating point values are not precise and small reounding errors in the floating operand may cause it to be
	smalller or slightly larger than expected and this throws off the relational operators


	In some case using < or > on floating points is fine e.g if the two numbers are far apart thats where its reliable but if its very close to each other it becomes unreliable
	but in some cases its still fine as long as you get an answer like in a game where if its close to each other and it returns false instead of true it just looks like you barely 
	missed it so using relational operator <or > isnt recommended when reliabelity is important but it can be used in specific situations and can be useful

	Unlike < and > on floatin point values, == and != are much more problematic and should be avoided bc even the smallest rounding error can decide if its true or false making it much
	more likely to return false then true e.g
	*/
	std::cout << std::boolalpha << (0.3 == 0.2 + 0.1) << '\n'; // should print true but bc of rounding error it prints false / std::boolalpha is here so the bool that is returned from (0.3 == 0.2 + 0.1) is in words instead of 1 or 0
	// so generally avoid using  == or != to compare floating point value if there is any chance those values have been callculated 
	// in some cases its okey if its not calculated and compared to the same type and the literal also has the same type and it doesnt exceed the significand digits of the type e.g
#if 0
	if (someFcn() == 0.0) // of if someFcn() returns 0.0 as a literal only
	{ }

	constexpr double gravity{ 9.8 };
	if (gravity == 9.8) // okay if gravity is initialized with a literal value
#endif
	// Its mostly not safe to compare floating point literals with other diffrent type e.g 9.8f to 9.8 will reutrn false



	// There is a way tho to do floating point equality more reliable, for that some beginneres use a variable commonly called epsilon with the value of 0.00000001 or 1e-8 and the std::abs() function
	// In this case we just check if they are close enough std::abs(x - y) is used to the get the diffrence and make it positive and then its compared to <= Epsilon e.g approximatelyEqualAbs() function at the top
	// The main problem with the approximatelyEqualAbs() function is that comparing it to Epsilon might be good comparing inputs around 1.0 but is too big for inputs around 0.0000001 or very high numbers it would be too small so we need another way 


	constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };  // should be close to 1.0 but it has rounding errors

	constexpr double relEps{ 1e-8 };  //0.00000001
	constexpr double absEps{ 1e-12 }; //0.000000000001 / recommended to be put to a very low number helps with calculations near zero

	std::cout << std::boolalpha; // prints true or false instead of 1 and 0

	//compare almost 1.0 to 1.0
	std::cout << approximatelyEqualRel(a, 1.0, relEps) << '\n';  // returns true
	//compare almost 0.0 to 0.0
	std::cout << approximatelyEqualRel(a - 1.0, 0.0, relEps) << '\n'; // returns false bc the math close to 0 broke down 

	// To circumvent the issue of the second call we can combine the first function that uses absEpsilon and the scond function that uses relEpsilon

	std::cout << approximatelyEqualAbsRel(a, 1.0, absEps, relEps) << '\n';  // returns true 
	std::cout << approximatelyEqualAbsRel(a - 1.0, 0.0, absEps, relEps) << '\n'; // returns true now with this function

	/* 
	In conclusion, comapring floating point numbers is a difficult topic and there is no "one size fits all" algorithm  that works for every case but the approximatelyEqualAbsRel()
	with relEps at 1e-8 and absEps at 1e-12 should be good enough to handle most cases you encounter
	*/
	
	/*
	Small Addition since C++23 we can make our functions approximatelyEqualAbsRel() and approximatelyEqualRel() be constexpr, the reason why it is only possible since C++23
	bc prior to that the std::abs function that is called in it became constexpr itself, so if you tried to call it prior to that after making you function constexpr it would fail
	bc constexpr function can only call other constexpr functions
	*/


	// small note that would work if the compiler used C++23 but apparently it doesnt or maybe it does but not fully as far as we can tell or at least the new addition of std::add being constexpr isnt added yet so we gotta wait for that
	constexpr bool same { approximatelyEqualAbsRel(a,1.0,absEps,relEps) };
	std::cout << same << '\n';
	std::cout << "C++ standard version: " << __cplusplus << std::endl; // i checked the version with that and it tells me its C++20 so not sure whats up with that 
	//There is a fix for that if we rly want to make it constexpr and we dont have full C++23 support we can use a custom abs function and make it constexpr e.g
#if 0
	template <typename T>  // we will learn about tmeplates in a later lesson
	constexpr T constAbs(T x) // can handle diffrent types of values
	{
		return (x < 0 ? -x : x);
	}
#endif 



	return 0;
}