#include <iostream>
#include <cstdint> // used for fixed width integers which are basically integers but with a fixed size making sure regardless in which case or where it is used its always the same size, great if you have to make 100 percent sure that smth is a certain size
                   // also used for the fast and least int
#include <cstddef> // when you use specifially use std::size_t / not needed for sizeof() event tho the return type is std::size_t


int main()
{
	std::int16_t i{ 5 }; // using the fixed width integer to make sure that i has 2 Bytes (16bits), ofc you can change the number depending how much you want to have like 8,16 ,32 and 64
	                     // if you want to have a fixed width unsigned integer the same rules as above apply but yóu need to add a 'u' in front of int e.g std::uint16_t i{5};
	std::cout << i << '\n'; // two small issues with fixed widht integers are maybe some systems dont support it and some times it might be slower depending on the typing and situation

	// to counter meassure some of the problems we have two other types :
	// 1. std::int_fast8_t (fastest signed/unsigned integer, it picks the type that is most quickly processed by the CPU)
	// 2. std::int_least8_t (smallest signed/unsigned integer type with the a width of at least of the given bits (give you the smallest int type thats at least the given bits)

	
	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << " bits\n";   // * 8  bc sizeof() gives you the number in byte so we need to conver it to bits 1 byte = 8 bit
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8: " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";  // this one ouputs 32 bc on this system the 32 bit seems to be faster then the 16 bits 
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";

	// small issues with fast and least is : not manyp programmers use them, fast can lead to memory wastage bc sometimes even tho you only need 16 bit the 32 bit is used bc faster, and bc of architectual diffrences certain types might be faster on one system but slower on the other making it hard to make sure what the size is e.g
	std::uint_fast16_t sometype{ 0 };
	sometype = sometype - 1; // intentionally overflow to invoke wraparound behaviour / dont forget to tone down warning level to try out overflow in case it doesnt work

	std::cout << sometype << '\n';
	// result differs depends if you use 16,32 or 64 and you need to test it rigorously to know where it functions and where it doesnt
	

	// IMPORTANT try to avoid std::uint8_t and std::int8_t and their fast and least variants bc there is an issue with 8bit variant where most compiler define and treat them identically as signed/unsigned char and that makes them may or may not behave diffrently in some cases so use the 16bit variant instead just to make sure

	// Conclusion :Prefer Int when sizes doesnt matter,use std::int#_t when storing quantity with a guaranteed range, std::uint_t for bit manipulation and wrap around behaviour
	// Avoid : short and long use fixed width instead, unsigned int for holding quantities, the 8bit fixed width int type, the fast and least fixed width types, compiler specific fixed width int types

	// std::size_t is the return type of the sizeof() operator the number returned is that type / its an unsigned type /at least 16bit (also depending on the application)/ is also a typedef

	std::cout << sizeof(int) << '\n';  // returns a number with the std::size_t type
	int x{ 5 };
	std::size_t s{ sizeof(x) }; // sizeof() retuzrns type std::size_t
	std::cout << s << '\n';
	std::cout << sizeof(std::size_t) << '\n'; // you can also use sizeof() to ask for the size of  std::size_t / the size is 8 bc it compiled on 64 bit console app / type or object cannot be bigger then the max of what std::size_t can hold (in this case 8 Byte) otherwise we couldnt ask for it size with sizeof() but nowadays you dont need to worry about it in the 64 bit and 86bit era

	return 0;
}