#include <iostream>

int main()
{
	// Literals are values that are inserted directly into the code e.g 
	// Literaly are also sometimes called literal constants bc their meaning cannot be redefined
	// literals have also a type but that is derived from the value e.g return 5; type int bc the value is an int /but you can add suffixes like f or F to change the literal type to float
	// suffixes are not case sensitive but s and sv must be lower case and to consecutive l or L must have the same casing /But prefer literal suffic L (upper cae ) over l(lower case)
	
#if 0
	return 5;                      // 5 is a integral Literal
	bool myNameIsAlex{ true };     // true is a boolean literal
	double d{ 3.4 };               // 3.4 is a double literal
	std::cout << "Hello, world!";  // "Hello, world!" is a C-Style string literal
#endif

	std::cout << 5 << '\n';   // 5 (no suffix) is type int by default
	std::cout << 5L << '\n';  // 5L is type long
	std::cout << 5u << '\n';  // 5u is type unsigned int

	// in most cases its fine to use non suffixed int literaly even when initializing non int types
	[[maybe_unused]] unsigned int b{ 6 }; // ok: compiler will convert int value 6 to unsigned int value 6
	[[maybe_unused]] long c{ 7 };         // ok: compiler will convert int value 7 to long value 7

	std::cout << 5.0 << '\n';   // 5.0 (no suffix) is a double literal by default
	std::cout << 5.0f << '\n';  // 5.0f is type float 

#if 0
	[[maybe_unused]] float f{ 4.1 }; // will cause a warning bc 4.1 is a double and not a float you need the f suffix to make it to a float 
#endif
	[[maybe_unused]] float f{ 4.1f }; // works bc the suffix is included 
	[[maybe_unused]] double d{ 4.1 }; // no suffix needed bc double is default type


	[[maybe_unused]] double pi{ 3.14159 }; // 3.14159 is a double literal in standard notation
	[[maybe_unused]] double avogadro{ 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
	[[maybe_unused]] double electronCharge{ 1.6e-19 }; // charge of an electron is 1.6 x 10^-19

	std::cout << "Hello, world!" << '\n';  // the string "Hello, world!" has the type const char[14] rather then const char[13] bc every string is followed by a null terminator '\0' to indicate end of the string thats how its saved in memory the hidden null terminator counts as a character
	// unlike most literals (which are are values) , C-style string literals are const objects which are created at the beginning of the program and stay for the entirety of the program
	// but unlike C-style string literals std::string and std::string_view literals create temporaty objects which have to be used immediatly as they are destroyed at the end of the expression
#if 0
	const int maxStudentsPerSchool{ numClassrooms * 30 };
	setMax(30);
	// thats what we call magic numbers , bc its not quite clear what those variables and numbers do and if we decided to change smth e.g we get more students, then we arent sure what numbers to change and what effect that has
	// so do this instead e.g :
	const int maxStudentsPerClass{ 30 };
	const int totalStudents{ num Classrooms * maxStudentPerClass }; // now obvious what this 30 means

	const int maxNameLenght{ 30 };
	set{ maxNameLenght }; // now obvious this 30 is used in a diffrent context

	// but literals used in obvious context that are unlikely to change arent considere magic mostly used -1, 0, 0.0, 1 e.g:

	int idGenerator{ 0 }; // fine: we're starting our id generator with value 0
	idGenerator += 1;     // fine: we're just incrementing our generator

	int kmtoM(int km) {
		return km * 1000; // fine its obvious 1000 is a conversion factor
	}
#endif
	// Conclusion: try to avoid magic numbers in your code (use constexpr instead see lesson 5.5)
	return 0;
}