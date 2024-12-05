#include <iostream>
#include <bitset>  // for std::bitset


/* 
   We use bit manipulation for optimization e.g an object needs to be at least 1 byte but if its a boolean it only needs one bit but it still uses 8 bits (1 bit for true or false and the
   rest are unused) and with bit manipulation we can group multiple boolean in one byte so it only uses 1 bit and each bit of thoes booleans are called bitflags 
*/

int main()
{
	// to define bitflags we either use unsigned int of the appropriate size (8,16 or 32 bits etc, depending on how many flags we have) or we use std::bitset
	[[maybe_unused]]std::bitset<8>mybitset{}; // 8 bits in size means room for 8 flags 
	
	// We number bits from right to left and the first position starts at 0 (we are just talking about the position so the first bit can be 0 or 1)

	/*
	In an earlier lesson we showed that we can use std::bitset to pring values in binary but it has some other functions too that are essential for bit manipulation e.g
	- test() // tells us if a bit is 0 or 1 
	- set() // turn a bit on but if the bit is alread turned on it does nothing, turn on means 1
	- reset() // turn off a bit but if the bit is already turned off , turn off means 0
	- flip() // flips a bit value from 0 to 1 or vice versa
	*/
	std::bitset<8> bits{ 0b0000'0101 };  // we need 8 bits / 0b is used to tell the compiler that its binary digits / the ' is not required but recommended for the programmers readability and doesnt change the output
	bits.set(3); // set bit position 3 to 1 now we have 0000 1101
	bits.flip(4); // flip bit position 4 to 1 now we have 0001 1101
	bits.reset(4); // reset bit position 4 to 0 now we have 0000 1101
	std::cout << "All the bits: " << bits << '\n';
	std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
	std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

	/*
	Giving our bits names can help making the code more readable / we more so give the bit positions the names / dont worry about this using more space bc of all the int variables
	are optimized out in compile time bc they are constexpr type so using std::bitset still will save some space bundeling the boolean values 
	*/

	[[maybe_unused]] constexpr int isHungry{ 0 };
	[[maybe_unused]] constexpr int isSad{ 1 };
	[[maybe_unused]] constexpr int isMad{ 2 };
	[[maybe_unused]] constexpr int isHappy{ 3 };
	[[maybe_unused]] constexpr int isLaughing{ 4 };
	[[maybe_unused]] constexpr int isAsleep{ 5 };
	[[maybe_unused]] constexpr int isDead { 6 };
	[[maybe_unused]] constexpr int isCrying { 7 };

	std::bitset<8> me{ 0b0000'0101 };  // we need 8 bits 
	me.set(isHappy); // set bit position 3 to 1 , now we have 0000 1101
	me.flip(isLaughing); // set bit position 4 to 1, now we have 0001 1101
	me.reset(isLaughing); // set bit position 4 to 0, now we have 0000 1101
	std::cout << "All the bits: " << me << '\n';
	std::cout << std::boolalpha; // turns boolean output from 1 to true and 0 to false
	std::cout << "I am happy: " << me.test(isHappy) << '\n';  // we could also use conditional operator instead of std::cout << std::boolalpha e.g (me.test(isHappy)? "true":"false")
	std::cout << "I am laughing: " << me.test(isLaughing) << '\n';
	std::cout << std::noboolalpha;  // dont forget to deactivate boolalpha otherwise it stays active

	// one disadvantage of std::bitset is that you cant set or reset multiple bits at once  for those cases we use unsigned int which we will cover in later chapters
	
	/*
	  One very important thing is the size of std::bitset which is the bytes needed to hold the bits rounded to the nearest sizeof(size_t) which is 4 Bytes on 32-bit machines and 
	  8 Bytes on 64-bit machines thus a std::bitset<8> will usually use either 4 or 8 Bytes, which might be surprising but the reason for that is that std::bitset isnt made to for memory
	  savings but for speed optimization even tho it only needs 1 Byte to store 8 Bits. Thus we use std::bitset<> when we desire convenience and speed not memory saving

	  For Memory saving we use unsigned integer flags which we cover in a later lesson
	*/

	// Here are some other member functions that can be useful e.g
	std::bitset<8> flags{ 0b0000'0101 };
	std::cout << flags.size() << " bits are in the bitset\n"; // .size() returns the number of bits in the bitset
	std::cout << flags.count() << " bits are set to true\n"; // .count() returns the number of bits that are set to true
	std::cout << std::boolalpha;
	std::cout << "All bits are true: " << flags.all() << '\n'; // .all() returns 1 (true) if all bits are set to true
	std::cout << "Some bits are true: " << flags.any() << '\n'; // .any() returns 1 (true) if any bits are set to true
	std::cout << "No bits are true: " << flags.none() << '\n';  // .none() returns 0 (false) if none of the bits are true 



	return 0;
}