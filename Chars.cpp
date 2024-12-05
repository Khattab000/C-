#include <iostream>
#include <string>  // if you want to use type std::string to make a string

// char has always the size of 1 Byte and in most cases its signed / can store small int but not recommended but if you do specify if its signed or unsigned
int main()
{
	std::cout << "Do you like Burritos please answer with y or n: ";
	char answer{}; // that can onnly save a signle character that includes : letter,number symbol or even whitespace / char type is an intgral type so the underlying value is stored as an integer so ever character has an ASCII value which you can look up in the ASCII Table
	std::cin >> answer; // bc the character can only take a single character it only takes the first character even tho the command promp lets you write more
	                    // if you write more it gets queued and if that happens the next std::cin wont wait for your input bc the additional inputs from your first input are still in the buffer
	std::cout << "Your Answer is: " << answer << '\n'; // '\n' newline escape sequence / can be written in the string or standalon with single quotes
	std::cout << "You like doritos: ";
	char answer2{};
	std::cin >> answer2;    // if you put multiple characters in the first input, then those that werent used are in the buffer and will be used for this input and subsequent inputs depending on how many char you typed in
	std::cout << "Your Answer is: " << answer2 << '\n'; // if you input ab in the first input it should say a in the first one and b in the second one


	char ch1{ 'a' }; // Initialized with the letter 'a' and is stored as integer 97
	char ch2{ 97 };  // Initialized with integer 97 the code of ('a') so ch1 and ch2 are the same but ch2 is not preferred / btw if you want to store a number you can also just use '' but it can only be one digit two digits would need a string 

	std::cout << ch1 <<" " << ch2 << ' ' << 'a' << '\n'; // Output : a a a

	if (answer == 'y') // Characters unlike strings are always placed in single quotes 
	{
		std::cout << "Muchas Gracias\n";
	}
	else if (answer == 'n')
	{
		std::cout << "Ayeeee Caramba\n";
	}
	else
	{
		std::cout << "OK\n";
	}

	std::cout << "First Part\tSecond Part\n";  // similar to \n , \t is a also an escape sequence but you should/can put in the middle of the string to have a tab between the two halfs (6 Spaces to be exact) that would be a horiziontal tab but if you want a vertical one use \v
	                                           // but there are many more escape sequences (btw alwasy make sure its a \ not a /) which you can look up on the table but notable ones are : \'  prints a single quote, \" prints a double quote, \\ prints a backslash
	// some examples of escape sequences 

	std::cout << "\"This is quoted Text\"\n";
	std::cout << "This string conatains a single backslash \\\n";
	std::cout << "6F in hex is char '\x6F'\n"; // \x(number) translates into char represented by hex number


	// single quote char and escape sequences (unless they are imbedded in the string) and double quote strings / but for output you can use double quote on char too for consistency sake#
	// avoid multicharacter literals even when they are possible e.g '56' bc they are not part of the C++ standart and may cause íssues 
	//One last thing diffrent character types exist e.g char32_t but arent recommended or useful for the current time doing the tutorial its mostly used unless you plan to make your  code Unicode compatible

	
	return 0;
}