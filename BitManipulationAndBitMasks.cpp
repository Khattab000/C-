#include <iostream>
#include <bitset>
#include <cstdint>

int main()
{
	/*
	  In order to manipulate single bits in a bitset with bitwise operators we need to use bit masks  bc bitwise operators dont know how to work with single bits, a bitmask is a predefined
	  bitset that is used to select specific bits that will be modefied by the operations. Now we will show how to define them:
	*/
	//We use 0s to mask out bit we dont care about and 1s to highlight the bits we want to modify
	[[maybe_unused]] constexpr std::uint8_t mask0{ 0b0000'0001 }; // represents bit 0 / 0x01 in Hexadecimal (just in case for older C++ Versions) / you could also use (1 << 0) shifting the position of the 1 depending on the bit position
	[[maybe_unused]] constexpr std::uint8_t mask1{ 0b0000'0010 }; // represents bit 1 / 0x02 / (1 << 1)
	[[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2 / 0x04
	[[maybe_unused]] constexpr std::uint8_t mask3{ 0b0000'1000 }; // represents bit 3 / 0x08
	[[maybe_unused]] constexpr std::uint8_t mask4{ 0b0001'0000 }; // represents bit 4 / 0x10
	[[maybe_unused]] constexpr std::uint8_t mask5{ 0b0010'0000 }; // represents bit 5 / 0x20
	[[maybe_unused]] constexpr std::uint8_t mask6{ 0b0100'0000 }; // represents bit 6 / 0x40
	[[maybe_unused]] constexpr std::uint8_t mask7{ 0b1000'0000 }; // represents bit 7 / 0x80

	// Now that we have a bitmask we can use it to check if a single bit is turned on or off (Yes we could have used .test() to do that but that doesnt work on integral types unless we put them in a variable)
	

	// we use the bitmask in conjunction with the bitwise AND (&) operator to check for bit being turned on or off
	
	std::uint8_t flag {0b0000'0101};  // 8 bits in size means room for 8 flags
	std::cout << "bit 0 is " << (static_cast<bool>(flag & mask0) ? "on\n" : "off\n"); // 0000'0101 & 0000'0001 = 0000'0001 and if you convert binary to bool it checks if it has nonzero values so regardless of how many 1s are in there it converts to true if there is at least one 1
	std::cout << "bit 1 is " << (static_cast<bool>(flag & mask1) ? "on\n" : "off\n"); // 0000'0101 & 0000'0010 = 0000'0000 when convertet to bool its false bc there are no nonzero values


	// we use the bitmask in conjunction with bitwise OR equals (|=) to set a bit (turn it on)

	flag |= mask1;  // turn on bit 1 / 0000'0101 | 0000'0010 = 0000'0111 and this is also saved in flags unlike the check for it bein turned on or off
	std::cout << "bit 1 is " << (static_cast<bool>(flag & mask1) ? "on\n" : "off\n");
	flag |= (mask5 | mask7);  // you can also turn on multiple flags at once with OR (|)
	std::cout << "bit 5 is " << (static_cast<bool>(flag & mask5) ? "on\n" : "off\n");
	std::cout << "bit 7 is " << (static_cast<bool>(flag & mask7) ? "on\n" : "off\n");


	// we use bitmask in conjunction with bitwise AND equals (&=) and Bitwise NOT (~) to reset a bit

	flag &= ~mask2; //turns off bit 2  1010'0111 & 1111'1011 (bc of ~) = 1010'0011 and this is saved into flag / also possible with multiple e.g flag &= ~(mask4|mask5) (|) basically fuses the two masks so it becomes 0011'0000
	// if the compiler complains bc of the type conversion you can use flag &= static_cast<std::uint8_t>(~mask2);
	std::cout << "bit 2 is " << (static_cast<bool>(flag & mask2) ? "on\n" : "off\n");


	// we use bitmask in conjunction with bitwise XOR equals (^=) to flip a bit

	flag ^= mask2; // bit 2 is flipped  1010'0011 ^ 0000'0100 = 1010'0111 and is saved in flag / for multiple at once flag ^= (mask2|mask4)
	std::cout << "bit 2 is " << (static_cast<bool>(flag & mask2) ? "on\n" : "off\n");
	flag ^= mask2;
	std::cout << "bit 2 is " << (static_cast<bool>(flag & mask2) ? "on\n" : "off\n");


	// Everything we did up there can be done with std::bitset<8> and with that we can use the functions of std::bitset e.g
	[[maybe_unused]] constexpr std::bitset<8> mask00{ 0b0000'0001 };
	[[maybe_unused]] constexpr std::bitset<8> mask01{ 0b0000'0010 };
	[[maybe_unused]] constexpr std::bitset<8> mask02{ 0b0000'0100 };
	[[maybe_unused]] constexpr std::bitset<8> mask03{ 0b0000'1000 };
	[[maybe_unused]] constexpr std::bitset<8> mask04{ 0b0001'0000 };
	[[maybe_unused]] constexpr std::bitset<8> mask05{ 0b0010'0000 };
	[[maybe_unused]] constexpr std::bitset<8> mask06{ 0b0100'0000 };
	[[maybe_unused]] constexpr std::bitset<8> mask07{ 0b1000'0000 };

	std::bitset<8> flag2{ 0b0000'0101 };
	std::cout << "Bit 1 is " << (flag2.test(1) ? "on\n" : "off\n");
	std::cout << "Bit 2 is " << (flag2.test(2) ? "on\n" : "off\n");

	flag2 |= mask07; // set bit 7
	flag2 &= ~mask07; // reset bit 7
	flag2 ^= mask07;  // flip bit 7
	/* Evene tho its more convenient using the std::bitset functions like .test() .set() .reset() and .flip() you cant manipulate multiple at once and one big disadvantage std::bitset
	   has over std::uint8_t is that its less efficient when workiung with bitwise operators and also not performance and space efficient, so if you need efficiency and manual control
	   use std::uint8_t but if you want to use the additional functions and want more readability and safity with individual bits use std::bitset<8>
	*/


	// Using mask2 or mask3 as identifier tells us what bit is being manipulated but not what the bit is for so its recommended to name them e.g

	[[maybe_unused]] constexpr std::uint8_t isHungry{ 1 << 0 }; 
	[[maybe_unused]] constexpr std::uint8_t isSad{ 1 << 1 };
	[[maybe_unused]] constexpr std::uint8_t isMad{ 1 << 2 };
	[[maybe_unused]] constexpr std::uint8_t isHappy{ 1 << 3 };
	[[maybe_unused]] constexpr std::uint8_t isLaughing{ 1 << 4 };
	[[maybe_unused]] constexpr std::uint8_t isAsleep{ 1 << 5 };
	[[maybe_unused]] constexpr std::uint8_t isDead{ 1 << 6 };
	[[maybe_unused]] constexpr std::uint8_t isCrying{ 1 << 7 };

	std::uint8_t feelings{}; // 0000'0000  all of them turned off from the start
	feelings |= (isHappy|isLaughing); // i am happy and laughing
	feelings &= ~isLaughing;  // not laughing anymore anymore 

	std::cout << std::boolalpha;
	std::cout << "Am I happy: " << static_cast<bool>(feelings & isHappy) << '\n'; 
	// ofc you can use std::bitset too in all of that and take advantage of the .any() function which checks if any of the bits are turned on so instead of static_cast<bool>(feelings & isHappy) you can use (feelings & isHappy).any() this will return 1 if any are turned on and 0 if none are turned on
	std::cout << "Am I laughing: " << static_cast<bool>(feelings & isLaughing) << '\n';
	std::cout << std::noboolalpha;

	/*
	Use cases of bitflags:
	In the above example if we used 8 seperate booleans it would take 8 bytes of memory instead we used bitflags which took 9 Bytse of memory (1 Byte for the flags and 8 Bytes for the masks)
	so we technically did not save any memory, so for smth with just a small amount of objects bitflags arent that efficient, where the efficiency actually starts when we have a lot of 
	objects with identical flags e.g 100 people who have the same flags , with seperate booleans it would take 800 Bytes but with bitflags only 108 Bytes (100 Byte for the flags and still
	only 8 Bytes for the masks) with that we see that bitflags are very useful and reduces memory usage when used with many similar objects by storing multiple flags in a single Byte.
	Conclusion: bitflags with bitmasks are most benefecial when memory usage is critical and can be advantagous when millions of objects are used but sometimes for smaller projects or in
	cases where not many Objects are used its not rly worth using for its added complexity but there is also some useful situations where it can be used e.g 
	
	void someFunction(bool option1, bool option2, bool option3, bool option4, bool option5, bool option6, bool option7, bool option8, bool option9, bool option10, bool option11,
	bool option12, bool option13, bool option14, bool option15, bool option16, bool option17, bool option18, bool option19, bool option20, bool option21, bool option22, bool option23,
	bool option24, bool option25, bool option26, bool option27, bool option28, bool option29, bool option30, bool option31, bool option32);

	as you can see that a lot of writing and when we call the function to pass down the bools it also will be an unreadable mess so instead use that:

	void someFunction(std::bitset<32>flag)
	{}

	//then you create bitmasks for the 32 bools in main

	constexpr std::bitset<32>mask0 {1 << 0};  // Bit 0 first bit
	.....
	constexpr std::bitset<32>mask31 {1 << 31}; // Bit 31 last bit

	std::bitset<32>empty{};  // if you want to pass down everyting being false you can pass down an empty bitset

	//then we pass down the ones we want to set or optionally the empty bitset

	someFunction(mask3|mask6|mask7); // we passed  down that Bit 3, Bit 6 and Bit 7 are true the rest are all false 

	// So that was much more readable then the code  before that

	*/

	constexpr std::uint32_t redBits{ 0xFF000000 };  // FF are 8 Bits set to 1 / 0x for Hexadecimal
	constexpr std::uint32_t greenBits{ 0x00FF0000 };
	constexpr std::uint32_t blueBits{ 0x0000FF00 };
	constexpr std::uint32_t alphaBits{ 0x000000FF };

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g FF7F3300): ";
	std::uint32_t pixel{};
	std::cin >>  std::hex >> pixel;  // std::hex allows us to read in a hex value / dont forget to change std::cin back to default with std::cin >> std::dec; when you dont need it 

	// we use static_cast<std::uint8_t>() bc otherwise the result of the bitwise operation would be std::uint32_t bc that is the size of the pixel we initialized 
	const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };     // The bitwise operation happens in binary e.g pixel is 1111 1111 0111 1111 0011 0011 0000 0000 , 
	const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) }; // redbits is 1111 1111 0000 0000 0000 0000 0000 0000 
	const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };    // AND Result is 1111 1111 0000 0000 0000 0000 0000 0000
	const std::uint8_t alpha{ static_cast<std::uint8_t>((pixel & alphaBits) >> 0) };  // after right shift by 24 (this number depends on the position of the color and how many shifts it needs to be the rightmost position in binary so we can convert it to 8 bit without any problems) is 0000 0000 0000 0000 0000 0000 1111 1111 = 255 in decimal is FF
	                                                                                  // then through static_cast<std::uint8_t>() it becomes 1111 1111 only being 8 bits long
	std::cout << "Your color contains:\n";
	std::cout << std::hex; // print the following values in hex / dont forget to change std::cout back with  std::cin << std::dec;

	// dont forget std::uint8_t will likely act and print as a char so use static_cast<int> to ensure its an integer 
	std::cout << static_cast<int>(red) << " red\n";
	std::cout << static_cast<int>(green) << " green\n";
	std::cout << static_cast<int>(blue) << " blue\n";
	std::cout << static_cast<int>(alpha) << " alpha\n";  // btw most of the time leading 0 in Hex is dropped if not necessary e.g 0 instead of 00 or 1 instead of 01



	// Small Quiz 1:

	[[maybe_unused]] constexpr std::uint8_t option_viewed{ 0x01 };
	[[maybe_unused]] constexpr std::uint8_t option_edited{ 0x02 };
	[[maybe_unused]] constexpr std::uint8_t option_favorited{ 0x04 };
	[[maybe_unused]] constexpr std::uint8_t option_shared{ 0x08 };
	[[maybe_unused]] constexpr std::uint8_t option_deleted{ 0x10 };

	std::uint8_t myArticleFlags{ option_favorited };

	myArticleFlags |= option_viewed;  // Answer a), option_viewed was turned on

	std::cout << std::bitset<8>{myArticleFlags} << '\n';

	std::cout << "Was the article deleted? " << ((myArticleFlags & option_deleted) ? "Its deleted!\n" : "Its not deleted!\n");  // Answer b), checked if option_deleted was on or off

	myArticleFlags &= ~option_favorited;  // Answer c), option_favorited was turned off
	std::cout << std::bitset<8>{myArticleFlags} << '\n';

	/*
	Answer d), The reason they are the same is bc of Demorgans Law and it tells you what happens when you drop the the brackets and how logical operations distribute over negation e.g option 4 is 0001 and option 5 is 0010,
	myflags &= ~(0001 | 0010) = ~(0011) = 1100 and then myflags &=  1100 is gonna deactivate the two bc they both are zero and on other hand myflags &= ~0001 & ~0010 = 1110 & 1101 = 1100
	so its the exact same
	De Morgans Law says if we distribute a NOT (so when the NOT is outside of the bracket and the brackets are removed) we need to flip OR and AND to the other
	*/
	return 0;
}