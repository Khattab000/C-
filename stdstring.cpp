#include <iostream>
#include <string>  // allows use of std::string and std::getline


int main()
{
#if 0
	std::cout << "Hello, world!\n"; //"Hello, world!" is a C-style string literal / but using C-Styles strings in variable can be a bit difficult and lead to some issues maybe in memory managment

	[[maybe_unused]] std::string name{}; //empty string  / so we use std::string for variables instead of the C-Style Initialization of strings : char cString[] = "Hello, World!";
	[[maybe_unused]] std::string name2{ "Alex" };
	name = "John";
	name2 = "Daphne";

	[[maybe_unused]] std::string myID{ "42" };

	std::cout << "My name is: " << name << '\n';

	std::string empty{};
	std::cout <<'[' << empty << ']' << '\n';



	std::string name3{ "Alex" };  // btw dont forget "Alex" is saved in memory as 5 characters even tho the string is only 4 bc of the terminating null character '\0'
	std::cout << name3 << '\n';

	name3 = "Jason";  //change name3 to a longer string (changing the length of an already established string in C sometimes caused issues but not in C++)
	std::cout << name3 << '\n';

	name3 = "Jay"; // change name3 to a shorter string 
	std::cout << name3 << '\n';


	// You can even  change name3 to a very long string without any problems and in case that std::string needs more memory, it will just request more memory in runtime we call that dynamic memory allocation
	// only downside to std::string bc of its power and flexibility with memory its comparatively slow to the C-Style string

	std::cout << "Enter your full name: ";
	std::string name4{};      // This wont work as expected bc if you try to input a name with a whitespace like John Doe it will take the first name John and put Doe in the buffer to be used by the variable color below
	std::cin >> name4;

	std::cout << "Enter your favourite color: ";
	std::string color{};      
	std::cin >> color;


	// to fix the code above and make it so it gets the full line and not just the characters up to the first whitespace leaving the rest in the buffer, we use std::getline():
	std::cout << "Enter your full name: ";
	std::string name4{};     
	std::getline(std::cin>> std::ws, name4);  // std::getline it gets the full line until you press enter including all whitespaces inbetween and puts it in name4 

	std::cout << "Enter your favourite color: ";
	std::string color{};
	std::getline(std::cin>>std::ws, color);     /* read a full line of text into color / btw >> std::ws isnt required but very useful it basically removes any leading whitespaces,
	                                               which can be caused by accident or by pressing enter bc pressing enter basically counts as an second input for std::getline() so 
												   \n is basically put into the buffer and is used instead of the second input and  >>std::ws prevents that
												*/

	std::cout << "Your name is " << name4 << " and your favourite color is " << color << '\n';

	// small example why >>std::ws is important

	std::cout << "Pick 1 or 2: ";
	int choice{};
	std::cin >> choice;

	std::cout << "Now enter your name: ";
	std::string name5{};
	std::getline(std::cin>> std::ws, name5);   // without >>std::ws this input is skipped bc there was a leading whitespace from the enter of the first input of Pick 1 or 2
	                                           // the normal std::cin>> actually ignores lleading whitespaces so no need for >>std::ws but std::getline() doesnt so it needs >>std::ws

	std::cout << "Hello, " << name5 << ", you picked " << choice << '\n';

	// so in conclusion if std::getline() is used always include std::ws

	std::string name6{ "Jafar" };
	std::cout << name6 << " has " << name6.length() << " characters\n"; // .length() will give you the exact lenth of characters of the word EXCLUDING the null terminator even tho std::string is required to be null terminated
	                                                                    // we call .length() a member function bc its part of std::string /Normal Functions function(object)  Member Function object.function()
	// .length() returns an unsigned integral value with the type size_t (the same return type used by sizeof() which returns how big an object is in bytes or how big a type is in bytes) so if you wanna save it in an int use static_cast so there is no conversion issues e.g
	[[maybe_unused]] int length{ static_cast<int>(name6.length()) };

	// since C++20 you can use std::ssize() to get the lenght in a large signed integral with the type std::ptrdiff_t (whatever that even means)

	std::string name7{ "Tooru" };
	std::cout << name7 << " has " << std::ssize(name7) << " characters\n"; 
	// since ptrdiff_t may be larger than int you also want to use static cast to save the result

	[[maybe_unused]] int len{ static_cast<int>(std::ssize(name7)) };


	// Initializing std::string is expensive bc whenever std::string is initialized a copy of the string literal is made and then allocated in memory which is an expensive task for the memory especially for large strings
	// And when passing a std::string by value to a function for example, it also creates a copy andhas to initialize the parameters,  we call that an expensive copy and you should avoid it use std::string_view instead which we will discuss later on
	// Returning a std::string also makes an expensive copy but there are some cases where its okey and not optimized properly : - Returning a local std::string created within the function,-Returning a std::string returned by another function,-Returning a temporary std::string so one created directly in the return statement
	// And if you return a C-Style string literal use std::string_view

	using namespace std::string_literals; // easy access to the s suffix
	std::cout << "foo\n";       // no suffix is a C-Style string literal
	std::cout << "goo\n"s;      // s suffix is a std::string literal / by putting an s behind the string we changed its type from C-Style string to std::string / but dont foget to add   using namespace std::string_literals;  or you could use  using namespace std::literals to import the whole library but its not recommended if you only need the string part

	// You wont need to use std::string literals often bc its fine to initialize std::string objects with C-Style string literal

	constexpr std::string name8{ "Tinah" }; // compile error / bc constexpr std::string isnt supported in most C++ versions and even in the newer ones works only in limited cases / if you want to have a constant std::string use std::string_view instead which we will cover in the next chapter
	std::cout << "My name is: " << name8;
#endif
	// Conclusion: std::string is complex, using many language features we need to still cover but its easy to use and encouraged to use for simple tasks now like basic string and input/output and we will cover additional capabilities later on

	// Question 1:

	std::cout << "Enter your full name: ";
	std::string name9{};
	std::getline(std::cin >> std::ws, name9);

	std::cout << "Enter your age: ";
	int age1{};
	std::cin >> age1;
	int lengthOfString{static_cast<int>(std::ssize(name9))};
	std::cout << "Your age + lenght of name is: " << age1 + lengthOfString << '\n';
	//Btw whitespace was counted to but we will learn in the future how to make it not count it too so rn the std::ssize() counts the amount of letters and whitespaces inbetween

	return 0;
}