#include <iostream>


int main()
{

	// Unary operator only take one operand there are two + and - e.g
	int x{ 3 };
	-x;  // makes it - 3
	int y{ 4 };
	+y;  // doesnt do anything even if y was -4 bc + or - are basically y * +1 or y * -1 so the + operator is redundant
	x = 5 - -3; // the first - is the binary subtraction operator and the second - is the unary minus operator 


	//Binary arithmetic operators take two operands a left and right. We have 5 operands: + , - , * , / , and %


	// Integr and floating point division division basically has to modes if the devision includes a float (number with fraction) it will perform a floating point devision e.g
	7.0 / 4;   // = 1.75 always returns a float /keep in mind rounding errors always may occur with floating poin arithmetic
	7.0 / 4.0; // = 1.75
	7 / 4.0;   // = 1.75
	//But if there arent any floats and only integers the division operator performs a intgeger division and drops any fractions when returning the solution e.g
	7 / 4;   // = 1  even tho the correct answer is 1.75 but bc that is a integer division the fraction is dropped
	-7 / 4;  // = -1 / correct answer is -1.75
	// to make sure that the fraction isnt dropped in an integer division we can use static_cast<> to convert the integer to float e.g
	constexpr int a{ 7 };
	constexpr int b{ 4 };

	std::cout << a / b << '\n';   // = 1
	// use double instead of float for more accuracy 
	std::cout << static_cast<double>(a) / b << '\n';   // = 1.75
	std::cout << a / static_cast<double>(b) << '\n';   // = 1.75
	std::cout << static_cast<float>(a) / static_cast<double>(b) << '\n';  // = 1.75 / as long as one of the operands is a floating point variable that is enough to make the result a float so only one needs to be float


	// Dividing by 0 or 0.0, you can divide 0 e.g 0/1 = 1 but 1/0 = error but floating point number 0.0 may lead to undefined behaviour or NaN or Inf depending on the compiler
	std::cout << 0.0 / 5 << '\n' << 5 / 0.0 << '\n'; // the first one is 0 bc .0 fraction is dropped most of the time even if answer is float and the second is an error (another compiler gave Inf as result)



	// Arithmetic assignment operators we have six of those: =, +=, -=, *=, /= and %=  e.g
	x = x + 4;
	x += 4;   //use that instead of x = x + 4; to make it much shorter bc the first one takes two operator + and = and this one only uses += and its the exact same
	y = y * 4;
	y *= 4;   // shorter and still the same, preffered way


	return 0;
}