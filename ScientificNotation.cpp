#include <iostream>

int main()
{
	// scientific notation 1.2 x 10^4 = 12.000 / the 1.2 is the signigicand and the exponent is 4 basically deciding the amount of zeroes in the number after the 1 e.g 10^4 = 10000
	// 5972200000000000000000000 kg is a rly big number and cant be read properly so we use scientific notation 5.9722 x 10^24 which is much easier to read
	// in C++ we use a alternative e.g 1.2 x 10^4 becomes 1.2e4 and 5.9722 x 10^24 is 5.9722e24 / e being the exponent on top of the 10
	// the alternative also can be used on numbers smaller then 1 e.g 5e-2 = 5 x 10^-2 = 0.05 other e.g 9.1093837e-31 kg = 9.1093837 x 10^-31 kg = 0,0000000000000000000000091093837 kg / btw the mass of an electron
	// for decimal numbers you need to slide the decimal to the left or right so there is only one non zero number on the left of the decimal /moving the decimal once to the left increases the exponent by one moving it to the right decreases the exponent by 1
	// e.g 12.23423 you move the decimal once to the left so the exponent increases from 0 to 1 so its now 1.223423e1 other e.g 0.00234 to have only one non zero number on the left of decimal you need to move right 3 times decreasing the exponent from 0 to -3 so it is 2.34e-3 last e.g 42030 move decimal 4 times to the left increasing exponent from 0 to 4 making it 4.2030e4 (if we assume that trailing zero is significant otherwise its 4.203e4 which is basically the same
	// if a trailing zero is important is to case to case base e.g meassuring to make sure its not  a approximately / basically the significand part should also show how many and which digits are important
	return 0;
}