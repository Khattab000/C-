#include <iostream>
#include <bitset> // for std::bitset
#include<format> // printing binary C++20 variant
#include<print>  // printing binary C++23 variant

int main()
{
	//Important regardless what Numeral System is used to initialize the Output/Print is always in Decimal (default)
	/*
	// original Numbers in Bracket 
	Decimal: (0, 1, 2, 3, 4, 5, 6, 7, 8, 9,) 10, 11, 12
	Binary: (0, 1,) 10, 11,
	Octal: (0, 1, 2, 3, 4, 5, 6, 7,) 10 , 11 ,12        // hardly used and not recommended to be used 
	Hexa Decimal: (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F,) 10, 11, 12,  // you can also use lowercase letters but the convention is uppercase letters
	*/
	int x{ 012 }; //0 before the number means this is octal
	std::cout << x << '\n'; // prints 10 bc 12 in octal is 10

	int y{ 0xF }; //0x before the number means this is hexadecimal
	std::cout << y << '\n';

	//Because there are 16 diffrent values in hexadecimal digit we can say that a single hexadecimal digit encompasses 4bits so a pair of Hexadecimal digits need one byte
	/*	
Hexadecimal	0	    1	    2	    3	    4	    5	    6	    7	    8	    9	    A	    B	    C	    D	    E	    F
Binary	    0000	0001	0010	0011	0100	0101	0110	0111	1000	1001	1010	1011	1100	1101	1110	1111

e.g  0011 1010 0111 1111 1001 1000 0010 0110 = 3A7F 9826
	*/
	
#if 0
	//in prior version of C++ there were no binary literal support so you had to use hexadecimal to help you out:
	int bin{};
	bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
	bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable 
	// but nowadays we have support for it and use smth diffrent:
	int bin{};  // assume 16bit int
	bin = 0b1; // using 0b before the number means this is binary / assigns binary 0000 0000 0000 0001 to the variable
	bin = 0b100011111010; // assigns binary 0000 1000 1111 1010

	int bin{ 0b1011'0010 }; // ' in between can be used as a seperator to make it more readable but doesnt change the ouput and is just ignored / assign binary 1011 0010 to the variable / btw its the same as 0000 0000 1011 0010
	long value{ 2'132'673'462 }; // much easier to read than 2132673462 / important dont use ' before the first digit e.g int bin { 0b'1011'0010 }; / bc 0b dont count as digits
#endif

	int z{ 12 };
	std::cout << z << '\n'; // prints in decimal by default
	std::cout << std::hex << z << '\n'; // prints in hexadecimal
	std::cout << z << '\n'; // still in hexadecimal bc I/O manipulators stay active until changed or turned off
	std::cout << std::oct << z << '\n'; // prints in octal
	std::cout << std::dec << z << '\n'; // prints in decimal and stays like this used to go back to default (prob turn off version is also applicable) /preferred bc its the default 

	// printing binary is a bit more complicated we will show the old and newer version 
	// for old version we use std::bitset :

	// std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{ 0b1000'0101 }; // binary litera of binary 1100 0101
	std::bitset<8> bin2{ 0xC5 }; // hexadecimal literal for binary 1100 0101
	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{0b1010} << '\n'; // create a temporary std::bitset and print it

	// for the new version we also have two varient C++20 variant and C++23 varient:

	std::cout << std::format("{:b}\n", 0b1010);  // C++20 variant, {:b} formats the argument as binary digits / exclude the 0b from output
	std::cout << std::format("{:#b}\n", 0b1010); // C++20 variant, {:#b} formats the argument as 0b-prefixed binary digits / includes the 0b from output

	std::println("{:b} {:#b}", 0b1010, 0b1010);  // C++23 variant, format/print two arguments (same as above) and a newline / and for each 4bits you need to add one more {:b} or {:#b}



	return 0;
}