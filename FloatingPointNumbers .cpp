#include<iostream>
#include <limits> // to check the IEEE 754 format with numeric_limits
#include <iomanip>// used for std::setprecision() to set the the precision of how many sígnificands are shown and printed out /std::setprecision() this is called an output/input manipulator and when activated once they stay active throughout the whole program exception being std::setw() which needs to be used everytime its needed
int main()
{
	// all three types are part of the floating point types which are always signed , they all hold positive/negative whole  numbers and fractional/decimal numbers
	[[maybe_unused]] float a{};         // 4 bytes / up to 6- 9 significand digits precision / if you store a value with more significand digits then it will be stored inprecisely
	[[maybe_unused]] double b{};        // 8 bytes / up to 15 - 18 significand digits precision
	[[maybe_unused]] long double c{};   // 8,12 or 16 bytes  / recommended to avoid long double bc its not entirely sure when it is which bytes  so in certain cases its 12 and in other its 16 / 5, 18, or 33 significant digits precision depending on the bytes occupied

	// to check which IEEE 754 format  your floating point types are using use this code / its fine if you dont understand it now its too advanced

	std::cout << std::numeric_limits<float>::is_iec559 << '\n';
	std::cout << std::numeric_limits<double>::is_iec559 << '\n';     // prints 1 when true, 0 when false
	std::cout << std::numeric_limits<long double>::is_iec559 << '\n';

	[[maybe_unused]] float d{ 5.0 }; //the number puut in  flloat{ } e.g float d{5.0} is defaulted to be a double and then it gets converted to float risking some inaccuracy during the conversion but if the number is followed by an 'f' e.g float{5.0f} its defaulted to be a float and we are save to go right ?
	[[maybe_unused]] float e{ 5.0f }; // this defaults to a float without any need for conversion bc of the 'f' after the number
	[[maybe_unused]] double f{ 5.0 }; // defaults to double and no need for conversion 
	// 0.0 is also a valid double/float / if you want to use float make sure to not forget to use the f to make sure no conversion needs to be done

	std::cout << 5.0 << '\n';  //output = 5 / so the .0 is removed bc its not significant
	std::cout << 6.7f << '\n'; // output = 6.7 /bc its not .0 its not removed bc the .7 has significant
	std::cout << 6.7 << '\n';  // same as one line above
	std::cout << 9876543.21 << '\n'; //output = 9.87654e+06 /its the same as 9.87654e6  /it changed to scientific notation bc its too long (more then 6 digits on the left of the decimal point) and it is supposed to be 9.87654321e6 but C++ only includes max 6 significand values thats the default precision while printing
	std::cout << 12345678998812393 << '\n'; //output = 12345678998812393 /the scientific notation and significand formation only works with floatring point types

	std::cout << std::setprecision(17); // show 17 digits of precision
	std::cout << 3.33333333333333333333333333333333333333f << '\n'; // Output = 3.3333332538604736  /bc float is less precise it got much more error leading to the 17th digit
	std::cout << 3.33333333333333333333333333333333333333 << '\n';  // Output = 3.3333333333333335  /bc double is much more precise it got much less error leading to the 17th digit only error being the last digit
	
	std::cout << std::setprecision(9);
	std::cout << 123456789.0f << '\n'; // even tho there are only 9 digits (bc 0 is dropped) the ouput is still incorrect (123456792) even tho we put precision to 9 digits thats bc float only are precise for up to 7 digits 

	// CONCLUSION : Favor double over float unless space is at premium as the lack of precision in a float will often lead to inaccuracies

	std::cout << std::setprecision(6); // set precision back to default to 6 
	double g{ 0.1 };
	std::cout << g << '\n'; 
	std::cout << std::setprecision(17);
	std::cout << g << '\n';             //bc the max precision of double is 16 so when we set the precision to 17 the number wasnt quite correct and had a rounding error

	double e1{ 1.0 };            // equals 1.0 bc its a number without a any non zero numbers on the right of the decimal point making it fully representable in a double so there is no riks of rounding errors
	std::cout << e1 << '\n';

	double e2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0 but equals to 0.99999999999999989 bc of rounding errors bc its not fully representable in double bc there are non zero numbers on the right of decimal point AND the precision is set to 17 even tho the max double has accuracy is 15 -16 
	std::cout << e2 << '\n';

	// if you would compare e1 to e2 in a program it probably wont perform as expeceted, in general comparing floating point numbers can be problematic sometimes 
	// and mathimathical operations e.g in e2 is growing the rounding error and makes it more significand then a slight error going from an error in 17th digit to the 16th

	// IN GENERAL : Be careful when using floating point numbers and dont expect them to be accurate so be wary when using them in e.g financial or currency data
	//small note dont forget to reset the setprecision

	std::cout << std::setprecision(6);
	double zero{ 0.0 };
	
	double posinf{ 5.0 / zero }; // positive infinity / inf
	std::cout << posinf << '\n';

	double neginf{ -5.0 / zero }; // negative infinity  /-inf
	std::cout << neginf << '\n';

	double nan{ zero / zero };   // not a number (mathimatically invalid)   / -nan(ind)
	std::cout << nan << '\n';

	//Avoid division by 0.0 all together even when your comipler supports it
	
	return 0;
}