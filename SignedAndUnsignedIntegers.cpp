#include <iostream>

void doSomething(unsigned int x)
{
	std::cout << "x is " << x << '\n';
}

// Signed integers are integers that can hold positive int , negative int and 0
int main()
{

	[[maybe_unused]] short s;          // short int
	[[maybe_unused]] int i;            // int 
	[[maybe_unused]] long l;           // long int 
	[[maybe_unused]] long long ll;     // long long int 
	// you can ofc use the names that are commented out instead but the shorter versions are the same and preferred
	// you can also put "signed" as a prefix to the types but that would be redundant bc they are signed by default
	// the range of an 8-Bit signed integer can hold 256 possible values these values are -128  -  127  (7 bits used for the magnitude of the number and one bit used to hold the sign so its positive number : 0 to 2^7 (0 to 127) and negative number -2^7 to -1 (-128 to -1)
	// so in general the range of a n-bit signed variable has a range of -(2^n-1) to 2^n-1 - 1
	// so an unsigned would hold from 0 - 255 (bc the 0 is also counted so the total is 256 diffrent values and it doesnt use a bit to hold the sign making it 2^8)

	// OVERFLOW is when you you try to assign a number that is too big for the type to hold and in the process of that you get undefined behaviour and information getting lost 
	// e.g assigning value 140 to an 8-bit signed integer will result in undefined behaviour bc the number 140 rquires 9-bits to represent (8 magnitude bits and 1 sign bit) and we only 8-Bits in total

	int x{ 2'147'483'647 }; // assume 4 byte integer / the maximum value of a 4 byte singed integer / btw you can use ' between numbers to make it easier to read / if you want to write decimal numbers use . instead
	std::cout << x << '\n';

	x = x + 1; // integer Overflow bc it goes above the max which results in undefined behaviour / might go to the negative instead then bc output for this code was -2147483648 (which is the lowest point it can go)
	std::cout << x << '\n';
	// in general if you suspect that the value might be to big for the type then try using a bigger type to make sure it fits

	//INTEGER DIVISION

	std::cout << 20 / 4 << '\n'; // dividing whole numbers works as expected the output is 5 
	std::cout << 8 / 5 << '\n'; // but dividing these numbers gives us the output 1
	// when dividing two integers the result will always be an integer for that reason dividing 8/5 gets you 1 even tho the value is 1.6 but the fractional part (0.6) is dropped bc an integer doesnt hold decimal numbers the same holds ture with -8/5 which is -1 after dropping the -0.6
	// so keep that in mind when doing integer division

// Unsigned Integers are integers that can hold positive integers and 0 BUT not negative integers
// unsigned integers can be useful when working with small memory networking and systems 

	[[maybe_unused]] unsigned short us;
	[[maybe_unused]] unsigned int ui;
	[[maybe_unused]] unsigned long ul;
	[[maybe_unused]] unsigned long long ull;

	// the range of an unsigned int is 0 to (2^n)-1 (0 - 255)  / unlike the signed which has a n-1 as the power bc of its one bit usage for the sign so if you need smth that only stores big positve numbers unsigned integers might be a good idea
	// Unsigned Integer Overflow is technically speaking incorrect bc the behaviour of adding to an unsigned int over its max capacity is well documented and is defined so it doesnt give you and undefined behaviour but it is similar sometimes to a signed integer overflow 
	// you need to turn off or put treat warning as error level down to 1 or 0 to compile the below code
	// so basically how a Unsigned Integer "Overflow" works is e.g if you put 280 in a 1-byte range int which has a range of 0 - 255 it will overflow and the calculation goes like this : 280/256(the max amount of the range + 1) and the remainder of this calculation is the number stored in this case it would be 280/256 = 1 remainder 24  só the 24 is the number stored / an easier way to think about it is imagining it wrapping around basically everything above 255 goes back to 0 e.g 256 would store the value 0 , 257 would store the value 1 and 258 would store the value 2

	unsigned short foo { 65535 }; // largest 16-bit unsigned value possible
	std::cout << "foo was: " << foo << '\n';
	foo = 65536;                  // 65536 is out of range, so we get the modulo wrap- around
	std::cout << "foo is now: " << foo << '\n'; // output is 0
	foo = 65537;                  // 65537 is out of range, so we get the modulo wrap- around
	std::cout << "foo is now: " << foo << '\n'; // ouput is 1 
	foo = 0;                                  // the wrap around can also occur on the other side e.g if we put -1 and the lowest it can go is 0 then it wraps around to 65535
	std::cout << "foo was: " << foo << '\n';
	foo = -1; 
	std::cout << "foo is: " << foo << '\n';   // output 65535
	foo = -2;
	std::cout << "foo is: " << foo << '\n';   // output 65534


	// but in general you want to try to avoid using unsigned integers bc it can easily lead to overflows or bugs in general when you dont keep in mind what numbers it can take and especially in the 0 range causing wrap arounds easily 
	// also a big reason to avoid unsigned integers is for arithmatic purposes bc normally if you calculate a singed int with an unsigned int the result and both sides will be unsigned e.g below code
	
	unsigned int roo{ 2 };
	signed int goo{ 3 };
	std::cout << roo - goo << '\n'; // 2 - 3 = 4294967295 / normally its -1 but bc the solution is unsigned it wraps around 

	// another example for unsigned arithmatic:

	signed int dee{ -1 };
	unsigned int dre{ 1 };
	
	if (dee < dre)  // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false / bc even if < or > is used it still counts as an arithmatic calculation making the solution and both sides of the operation unsigned
		std::cout << "-1 is less than 1\n"; 
	else
		std::cout << "1 is less than -1\n";

	// another small example using the function doSomething()

	doSomething(-1);  // the author of the function didnt expect anyone to pass on a negative number and that lead to it be wrapping around bc the function was expecting an unsigned number

	// even tho its generally favored to use signed int instead of unsigned, there are some use cases e.g Bit Manipulation, Usage of the well defined wrap around behaviour for algorithms like encryption and random number generation, Array Indexing, development on embedded systems like arduino or some other process/memory limited context for performance reasonsSsSsSSss

	return 0;
}