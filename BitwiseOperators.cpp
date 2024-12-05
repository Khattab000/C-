#include <iostream>
#include <bitset>
#include <cstdint> // for std::uint8_t

//Question 2 task / rotl stands for rotate left
std::bitset<4> rotl(std::bitset<4> bits)
{
	const bool leftmostbit{ bits.test(3) }; // hold onto the left most bit bc its gonna get removed through the left shift
	bits <<= 1;  // left shift occured so the leftmostbit was pushed out
	if (leftmostbit)
	{
		bits.set(0);      // if the leftmostbit was 1 then the the first bit (rightmostbit) of the bitset is turned on to 1
	}
	// no need for else bc if leftmostbit is 0 it doesnt matter bc the rightmostbit is zero already
	return bits;
}
// Question 3
std::bitset<4> rotl2(std::bitset<4> bits)
{
#if 0
	std::bitset<4> leftmostbit{bits >> 3};  // copy the bitset and do a rightshift by 3 so the leftmostbit is on the rightmost position and the rest is just zeroes
	bits <<= 1;    // left shift on the original bitset so the the rightmost position is zero
	bits ^= leftmostbit;  /* We use XOR operation knowing that other than the rightmost position the rest are zeroes in the copied bitset.,we use XOR bc if a number is 0 in 
							 the original it will remain zero bc the copied one also is full of zero and if ours has a 1 it will remain 1 bc the copied one only has zeroes and when
							 we reach the rightmost position we know for a fact that the original has a 0 there so if the copied one has a 0 there then it stays 0 but if its a 1 then 
							 it changes and becomes a 1 */
	return bits;
#endif
	return (bits << 1) ^ (bits >> 3);
	// There is an even easier way only requiring one line : return (bits <<1)|(bits>>3);  // this shows we could have use OR or XOR and put it in  one return statement / use paranthesis
}

/*
  C++ has  6 bit manipulation operators called bitwise operators:
  - left shift  <<  (x << y  all bits in x shifted left y bits)
  - right shift >>  (x >> y all bits in x shifted right y bits)
  - bitwise NOT  ~  (~x all bits in x are flipped)
  - bitwise AND  &  (x & y each bit in x AND each bit in y)
  - bitwise OR   |  (x | y each bit in x OR each bit in y)
  - bitwise XOR  ^  (x ^ y each bit in x XOR each bit in y) / XOR returns 1 (true) when the bit in x is diffrent from the bit in y otherwise return 0 (false)

  To avoid surprises, use the bitwise operators with unsigned operands or std::bitset
*/

int main()
{
	std::bitset<4> x{ 0b1100 };

	std::cout << x << '\n';
	std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
	std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000  / if you would save that in x the 1 that was pushed out wont return even if you push it to the right again


	/*
	  As you know std::cout uses << and << is used for bitwise operation so how does the operator know which operation to do ? The answer is std::cout has overloaded (provided an
	  alternative deifinition for) operator << that does console output rather than bit shifting. When the compiler sees that the left operand is std::cout it calls the the version of 
	  operator << that does output, if the left operand is an integral type then operator << does usual bit shifting behaviour and btw when using bit shift and cout in the same statement
	  you need to parenthesize otherwise it wont do the bit shift. (all that applies to >> too) (You can do operator overloading yourself too, will be shown in a later chapter)
	  e.g
	*/
	std::bitset<4> y{ 0b0110 };
	std::cout << y << 1 << '\n'; // prints 0110 and then 1 (no bit shift occurs)
	std::cout << (y << 1) << '\n'; // x bit shift left and then prints x (1100)

	// Bitwise NOT (~) just flips every bit from 0 to 1 or 1 to 0 e.g

	std::cout << ~std::bitset<4>{0b0100} << ' ' << ~std::bitset<8>{0b0100} << '\n';  // std::bitset<8>{0b0100} is 0000 0100 bc we put it to 8 digits and we read it from right to left

	// Bitwise OR (|) compares each bit individually with the other operand/s in the same position and returns true if either or any are true otherwise false e.g

	std::bitset<4>a{ 0b1100 };
	std::bitset<4>b{ 0b1010 };
	std::bitset<4>c{ 0b1000 };
	std::cout << (a | b | c) << '\n'; // returns 1110

	// Bitwise AND (&) similar to OR compares bit by bit and returns true only if all are true otherwise returs false

	std::cout << (a & b & c) << '\n'; // returns 1000

	/*
	Bitwise XOR(^) also compares bit to bit and returns false if they are the same and true if they are diffrent
	but if there is more than two operands it compares the first two and the return of that is compared with the next one
	(simple rule if the count of 1 on the position of all operands is even or none then it returns 0
	*/ 

	std::cout << (a ^ b ^ c) << '\n'; // returns 1001

	// Bitwise assignment operators are similar ro assignment operators and this makes it easier to modify the varibales : <<=, >>=, |= , &= , ^=, (but no Bitwise NOT (~) bc only flips the bits and only uses one operand so just do x = ~x) e.g

	std::bitset<4>k{ 0b0101 };
	k <<= 1; // instead of k = k << 1;
	std::cout << k << '\n'; // returns 1010
	k |= a; // instead of k = (k | a)
	std::cout << k << '\n'; // returns 1110


	/*
	If the operands of a bitwise operator are an integral type smaller than an int those operands are converted to int or unsigned int and the return is also gonna be an int or unsigned
	int, for example if the operands are unsigned short the will be converted to unsigned int and the result of the operation will be unsigned int too and in many cases this is fine but
	there are two exceptions.

	Exception 1 is when using operator ~ and operator << both are widh sensitive
	Exception 2 is when you initialize the result to the initial variable it does a narrowing conversion bc it has to be turned back to the smaller type possibly losing data in the process
	e.g
	*/
#if 0
	std::uint8_t l{ 0b0000'1111 };
	std::cout << std::bitset<32>(~l) << '\n'; // incorrect : prints 11111111111111111111111111110000 bc the initial type only had 8 bits and this one has 32 so leading zeros where added
	std::cout << std::bitset<32>(l << 6) << '\n'; // incorrect : prints 0000000000000000001111000000 the same reason as above it should have move some 1 out of the bitset if it wasnt for the type change
	std::uint8_t lneg{~l};                        // error: narrowing conversion from unsigned int to std::uint8_t
	l = ~l;                                       // possible warning: narrowing conversion from unsigned int to std::uint8_t
#endif
	// all that can be fixed if you turn the variable back to its initial type after it is converted by the operator by using static_cast<>() we use that on the operation not the result e.g
	std::uint8_t l{ 0b0000'1111 };
	std::cout << std::bitset<32>(static_cast<std::uint8_t>(~l)) << '\n';  // correct: prints 00000000000000000000000011110000 / the leading zeros stay bc the result type is still std::bitset<32> but the operation happened with std::uint8_t so the result is still correct
	std::cout << std::bitset<32>(static_cast<std::uint8_t>(l << 6)) << '\n'; // correct: prints 0000000000000000000011000000
	std::uint8_t lneg{ static_cast<std::uint8_t>(~l) };                      // compiles
	l = ~l;                                                                  // no warning

	// Small task Question 2:
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';
	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	// Small task Question 3:
	std::bitset<4> bits3{ 0b0001 };
	std::cout << rotl2(bits3) << '\n';
	std::bitset<4> bits4{ 0b1001 };
	std::cout << rotl2(bits4) << '\n';
	return 0;
}