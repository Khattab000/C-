#include <iostream>
#include <string>       // for std::string
#include <string_view>  // for std::string_view


void printString(std::string a)
{
	std::cout << a << '\n';

}


void printStringV(std::string_view a)  //std::string_view is read only so you can use it but not modify it 
{
	std::cout << a << '\n';
}

std::string getName()
{
	std::string s{ "Alex" };
	return s;
}

std::string_view getBoolName(bool b)
{
	std::string t{ "true" };   //local variable
	std::string f{ "false" };  //local variable

	if (b)
	{
		return t;  // return a std::string_view viewing t
	}
	else
	{
		return f; // return a std::string_view viewing f
	} // t and f are destroyed at the end of the function
}

std::string_view getBoolNameC(bool b)
{
	if (b)
	{
		return "true";  // return a std::string_view viewing "true" (C-Style literal)
	}
	else
	{
		return "false"; // return a std::string_view viewing "false" (C-Style literal)
	}
}

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2)
{
	return s1 < s2 ? s1 : s2;  // uses operator ?: (the conditional operator) // return a view to either u or g
} // s1 and s2 are destroyed here but its fine bc s1 and s2 were just viewing u and g so even with them destroyed as long as u and g are in main it shouls still work and not lead to undefined behaviour if called

int main()
{
	int x{ 5 };             // x makes a copy of its initializer into memory / For fundemental types initializing and copying variables is fast
	std::cout << x << '\n';

	std::string s{ "Hello, world!" };  // s makes a copy of its initializer into memory so its saved in static and dynamic memory / For std::string types (not fundemental types) initializing and copying variables is slow
	std::cout << s << '\n';            // in this program all we do with s is print the value and destroy it then so the copy is only made for that which is inefficient
	printString(s);                    // and in this case the string is copied twice , once to for the initialization and twice to copy it to initialize it for the parameter of the function and thats a lot of needless copying to print a string thats why we are introducing std::string_view

	// to solve the issue of std::string being expensive we use std::string_view the main diffrence is that std::string_view is read only so it can be initialized but not modified afterwards but you can still use it 
	/*
	unlike std::string, std::string_view doesnt create a copy of the C - Style string bc it just points to the string so the string is only saved in
	static memory(which happens in compile time so it cant change anymore and allocates its memory automatically) but std::string on the other hand copies it into dynamic memory
	(which happens in run time) so the the string is saved in static memory and dynamic memory (so you can change it and manually can allocate memory) thats why std::string 
	is more expenssive than std::string_view which only saves the string once 
	*/

	std::string_view sv{ "Holy C might be onto smth" };  // std::string_view just points to the string literal which is saved in static memory not copying it in dynamic memory
	printStringV(sv);       // and passing the variable doesnt make a copy either bc we are basically only pointing towards the string literal so no copy needed 
	// so prefer std::string_view instead of std::string if you are not planning to modify the string and only need it in string only especially for function parameters


	std::string_view s1{ "Hello World" }; // Initialized with C-Style string
	std::string_view s2{ s };             // Initialized with std::string
	std::string_view s3{ sv };            // Initialized with std::string_view


	// Even tho the function printStringV() has a std::string_view parameter, it doesnt mind getting a C-Styles string or and std::string bc it just converts them to std::string_view showing how flexible it is
	printStringV("Hello World"); // C-Style
	printStringV(s);             // std::string
	printStringV(s3);            // std::string_view


	// Even tho converting std::string/C-Style to std::string_view isnt a problem or passing it to  a function, the same cant be said about the opposite of converting std::string_view to std::string but there are ways to make it possible bc it doesnt to it implicitly you need to do it manually
	
	// printString(sv);  // compile error: wont implicitly convert std::string_view to std::string

	std::string st{ sv }; // you can initialize std::string with std::string_view and then pass it to the function
	printString(st);

	printString(static_cast<std::string>(sv)); // other way is using static cast to change its type to std::string so we can use it as parameter / btw change is temporary so you gotta use static cast again if needed somewhere else

	// Even tho we said you cant modify std::string_view, you can still change its assignment so basically you change who std::string_view is viewing/pointing to e.g
	// for that reason (you cant modify std::string_view), you cant use std::string_view in std::cin>> ;
	std::string name{ "Alex" };
	std::string_view stv{ name }; //stv is now viewing name 
	std::cout << stv << '\n'; // prints Alex

	stv = "John"; // stv is viewing "John" now /but name is not being changed or modified 
	std::cout << stv << '\n'; // prints John

	std::cout << name << '\n'; // prints Alex bc name didnt change or wasnt modified

	// If you want to manipulate string literal in std::cout you can do that using the std::string_literals and std::string_view_literals namespace

	using namespace std::string_literals;          // access to s suffix
	using namespace std::string_view_literals;     // access to sv suffix

	std::cout << "foo\n";          // no suffix so default C-Style string literal
	std::cout << "foo\n"s;         // s suffix so std::string literal
	std::cout << "foo\n"sv;        // sv suffix so std::string_view literal  / but its fine to initialize a std::string_view object with a C-Style literal

	// unlike std::string, std::string_view has full support of constexpr and is the preffered way if string constants are needed

	constexpr std::string_view jo{ "watch jojo" }; // jo is a string symbolic constant
	std::cout << jo << '\n'; //jo will be replaced with "watch jojo" at compile time


	// Big diffrence of std::string and std::string_view is that std::string is an owner and std::string_view is a viewer 
	// A owner needs to acquire the object, maintain the object and dispose of the object at the end which is an expensive process but you can do whatever you want with the object.
	// A viewer on the other hand just looks at the object but doesnt own or maintain it or disposes of it which is a very cheap process but you cant do whatever you want with the object and the object might dissapear or  is changed so the viewing it might give some unexpectet results

	// An initialized object has no control over what happens to the initialization value after initialization bc its just a copy but that makes it independent from the initializer downside of that is that this what we call an expensive copy

	// std::string_view is recommended when: - you dont modify the string, -dont destroy the string,-or it being changed in an unexpected way / in these cases uses std::string_view instead of std::string bc we dont need an expensive copy then
	/*
	  std::string_view makeas an inexpensive view instead of an expensive copy and when the view is destroyed / changed the object is not affected at all / but unlike std::string,
	  std::string_view is dependent on the initializer throughout its lifetime bc no copy is created so if the the initializer string(which is saved in static memory in compile time) is 
	  destroyed or modified while the view is still beign used unexpected or undefined behavioiur might occur we call that dangling view
	*/
	// Prefer std::string_view function parameters over const std::string& (const std::string& is a reference to a constant std::string so using that as parameter would not make a copy only reference it so it cant modify it either)

	// Now we show some improper ways to use std::string_view :

	std::string_view nok{}; //is available for the whole main function including in nested blocks
	
	{// create a nested block so everything happening only happens locally (local scope in this nested block and will be destroyed outside of it unless you add return to it or passed in or out
		std::string mb{ "shook" }; // created a std::string local to this nested block so not available for the whole main function only for this nested block
		nok = mb;     // nok is viewing mb

	}// mb is destroyed here so nok is now viewing an invalid string

	std::cout << nok << '\n'; // undefined behaviour /in our case it seems to remove the first letter so it prints hook instead of shook / and if you replace shook by s (so one letter only) it prints nothing bc after the first letter there isnt anything left

	//Here is another improper example:

	std::string_view name5{ getName() }; // name initialized with a return value of a function which is destroyed after the expression containing the function call
	std::cout << name5 << '\n'; // undefined behaviour /just like the example above the first letter is removed so it prints "lex" even tho the function returns "Alex"

	// another less obvious example is:
	using namespace std::string_literals;
	std::string_view name6{ "Alex"s }; // using tje s literal suffix (or in general literal suffixes) to creat a string literal only creates it temporarly so we created a temporary std::string literal "Alex" which is destroyed right after the statement#
	std::cout << name6 << '\n'; // undefined behaviour / also prints lex so the first letter was removed yet again


	// We can also get undefined behavior when the string that is being viewed is modified

	std::string lo{ "Heya" };
	std::string_view lv{ lo }; // lv is now viewing lo

	lo = "Hello"; // modifies lo, which invalidates lv (lo is still valid)
	std::cout << lv << '\n';  // undefined behaviour / this time it prints the new string of lo but missing the last letter so it prints "Hell"
	// but there is a way to revalid lv 
	lv = lo; //lv is revalidet and views lo again but this time lv has a valid view again
	std::cout << lv << '\n';  // this time it prints "Hello" bc we revalidated it 



	//also an important topic is returning a std::string_view bc whatever std::string_view was watching is gonna be destroyed after the expression containing the function call so its dangerous using it as a return type and will result in undefined behaviour
	std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // undefined behaviour bc t and f are destroyed at the end of the function /btw your compiler might not warn you about such cases 

	//but there are two main cases where std::string_view can be returned safely case 1 is when std::string_view is viewing a C-Style literal bc those arent destroyed at the end of a function but stored in static memory (during the compile time):
	std::cout << getBoolNameC(true) << ' ' << getBoolNameC(false) << '\n'; // prints "true false"
	
	//second case where its okey is, even tho the variables being viewed are destroyed at the the end (s1 and s2) the originals u and g still exists and we didnt copy them into the function we only passed the view into the function so with the originals initialized in main it still works bc we were watching the same all along
	std::string u{ "World" };  
	std::string g{ "Hello" };
	std::cout << firstAlphabetical(u, g) << '\n'; // prints "Hello" / but keep in mind if u or g where a temporary object which gets destroyed at the end of an expression so does the function call returning std::string_view also happen in the same expression otherwise it would lead to undefined behaviour and left dangling

	// there are two functions that alter our view to an object BUT they dont change the object that is being viewed itself just the view of it like closing part of the curtains so you dont see the full thing

	std::string_view hd{ "Peach" };
	std::cout << hd << '\n';  // prints "Peach"

	hd.remove_prefix(1); // removes 1 character from the left
	std::cout << hd << '\n'; // prints "each"

	hd.remove_suffix(2); // removes 2 characters from the right
	std::cout << hd << '\n'; // prints ea  / dont forget we removed 1 prefix earlier
	
	hd = "Peach";  // reset the view
	std::cout << hd << '\n';
	return 0;

	// with these functions in mind you could use std::string_view to only view a substring of a string e.g string: "snowball"  but we watch only the substring: "ball" by removing 4 of the prefixes from the view
	/*
	one consequence of using std::string_view is it might be not null terminated bc if you have a string "snowball" and your std::string_view is viewing only the substring "now" 
	so in this case std::string_view isnt null terminted so std::string literal and a C - Style literal are always null terminated but a std::string_view might not be, but it doesnt
	matter much bc std::string_view keeps track of the length of the string and even converting it into a std::string isnt a problem but rather not assume that std::string_view just
	to be safe. But if you absolutely need a null terminated string just convert std::string_view into a std::string
	*/
}