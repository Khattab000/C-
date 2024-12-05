#include <iostream>
#include <cstdint> // for std::int8_t 

void print(double x) // print takes a double input
{
	std::cout << x << '\n';
}

void print2(int x)
{
	std::cout << x << '\n';
}

void returnNumberASCII (int x)
{
	std::cout << " has the ASCII Code: " << x << '\n';
}
int main()
{
	
	print(5); // we are passing an int even tho it requires a double but it still works bc the compiler does type conversions for fundemental same types so the 5 turns to 5.0 /printing it doesnt change anything bc floats drop the zero after the decimal anyways if there is only zero
	// we call that conversion that happened without explicitly asking : implicit type conversion
	// typed conversion uses direct initialization to produce a new value for the traget typ from a value of a diffrent typer e.g double x from int 5  but the int variable itself isnt changed it just uses its int to create an output for double x
#if 0
	print2(5.5); // be careful in the first instance with print(5) we didnt mind the conversion bc at the end the number basically stayed the same but in print2(5.5) the number is gonna get conversed to an int changing the number from 5.5 to 5 which is not the same
#endif	             // for this you need to turn off treat warning as error (warning level) bc it warns you for possible data loss that happens when you try to do conversion from a floating type to a integral type

	// Conclusion int to double conversion is safe but double to int isnt and may lead to a data loss / And always use brace initialization bc it makes sure no data loss occurs e.g double d { 5 }; // okay: int to double is safe   int x { 5.5 }; // error: double to int not safe

	print2(static_cast<int>(5.5)); // static_cast can be used if we explicitly want to do a type conversion and we tell the compiler that we take the risk of a data loss , so even when you do a conversion from double to int the compiler wont warn you or wont give you an error
	                               // explicity convert  double value 5.5 to an int
	                               // syntax for static cast : static_cast<new_type>(expression) // <> is mostly used for types or for preprocessor

	char ch{'a'}; // 97 is ASCII code for 'a' / so you can put 97 instead of 'a' and it would be the same
	std::cout << ch << '\n';
	std::cout << ch << " has value " << static_cast <int>(ch) << '\n';  // you can use static_cast to convert char to int the int is gonna be the ASCII value of the char but thats just the the output being chonverted the original ch is still a char 

	unsigned int u1{ 5 };
	//Convert value of u1 to a signed int
	int s1{ static_cast<int>(u1) };      // the opposite is also possible converting signed int to unsigned int as long as its in the range of both which 5 is 
	std::cout << s1 << '\n'; // prints 5

	// if the value is not in range of both , it will cause some issues :
	// destination value is unsigned : unsigned Overflow /modulo Wrap around
	// destination Value is signed : signed Overflow /undefined behaviour/ since C++20 it outputs -1
	//e.g

	int s{ -1 };
	std::cout << static_cast<unsigned int>(s) << '\n'; // prints 4294967295

	unsigned int u{ 4294967295 };
	std::cout << static_cast<int>(u) << '\n';  // prints -1

	// We talked in an earlier lesson about fixed width integers and size_t and how weirdly enough , that the compiler defines and treats std::int8_t (and the unsigned ,fast and least) identically to signed and unsigned chars (this applies only to the 8 bit version not the 16 , 32 and others)
	// Now we show you why that is problematic and why you should avoid that

	std::int8_t myInt{ 65 };  // initializing myInt with 65
	std::cout << myInt << '\n'; // even tho you are expecting it to print 65 bc its an int initialized with 65, thats not the case and it prints 'A' instead bc of that weird behaviour (65 is the ASCII code for A)
	std::cout << static_cast<int>(myInt) << '\n'; // if you wanna make sure that it prints 65 instead of 'A' use static cast but tbh just avoid it and use other types instead

	std::cout << "Enter a number between 0 and 127: ";
	std::int8_t myInt2{};
	std::cin >> myInt2;
	std::cout << "Your number is: " << static_cast<int>(myInt2) << '\n';  // even with stat_cast there will be issues bc if a user inputs a number that has two digits the first digit is used and the second is dropped so only the ASCII value of the first number is printed

	// Conclusion AVOID std::int8_t as much as possible use other bit versions like 16 bit instead

	// Small Quiz
	// Quiz 1 and 2:

	std::cout << "Type in a single character: ";
	char input{};
	std::cin >> input;
	std::cout << "Your input " << "\'" << input << "\'" << " has the ASCII Code: " << static_cast<int>(input) << '\n';
	std::cout << "Your input " << "\'" << input << "\'";
	returnNumberASCII(input);  // we used the function instead (you can also use a function just returning an int or taking an int or just a int variable which you initialize with input variable like int ASCII{input} )to emulate an implicit type conversion, but always try to prefer explicit type conversion

	return 0;
}