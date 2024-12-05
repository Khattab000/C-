#include <iostream>
#include <iomanip> // for std::setw (which sets the width of a subsequent output)
// VOID

void writeValue(int x)  // void here means no return value / void is an incomplete type intetnionally bc it represents the lack of type and thus cannot be defined
{
	std::cout << "The value of x is: " << x << '\n';
	// no return statement, because this function doesn't return a value / if you added smth like return 5; you would get a compile error
}

int getValue()   // you could put void into the brackets to say that the function doesnt take any parameterts but it being empty is basically the same and more preferable 
{
	int x{};
	std::cin >> x;
    return x;
}

// Object sizes and sizeof operator

/*
An object with n bits(where n is an integer) can hold 2 ^ n e.g 8Bit Byte can hold 2 ^ 8 (256) diffrent Values and an object that uses 2Bytes can hold 2 ^ 16 (65536) diffrent Values

In order to determine the size of a type on a particualar machine we use the the sizeof operator, it takes a variable or type and returns it size in bytes

For Advanced Lessons: sizeof doesnt include dynamically allocated memory used by an object
*/


int main()
{
    int x{};

    std::cout << std::left; // left justify output bsically makes the coming output left alligned and is needed if std::setw is used bc std::setw defaults to making the ouput right alligned, using std::left affects all subsequent ouputs unless you change it back   /fun fact if you want right alligned for smth else you can use std::right
    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";    //std::setw() decides at what space the output after the output the std::setw() is used on is and you put a number in to decide what space it is but it only affects the direct output after std::setw() not the full print statement e.g used in bool: makes the output after bool appear in space 16 but the ouput after that is normal
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";    //sizeof operator gives us the byte size when given a variable or a type
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";  //using sizeof on type void gives us a compilation error
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";
    std::cout << std::setw(16) << "x:" << sizeof(x) << " bytes\n";          // e.g for variable
	return 0;
}

// Fun Fact: A Type that use more memories doesnt mean always that its slower the once that usem memories certain CPUs are often optimized to process data of a certain type