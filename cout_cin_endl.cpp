#include <iostream>                            // io stands for input/output

int main() 
{
	std::cout << "Hello World";                // simple print statement which prints Hello World to the console cout = character output 
	std::cout << 9;                            // << called insertion operator
	int x{ 17 };
	std::cout << x;
	std::cout << "Hello World: " << x;        // to print multiple(link them together )just add << to the end and then you can put in another string, number or variable 
	
	std::cout << "MIKE" << std::endl;         //use std::endl for a new line after the what you printed so that the next thing is printed below it on not in the same line /std::endl = end line
	std::cout << "EHRMENTRAUT" << std::endl;  // even tho its not end line isnt needed at the last line of code its still useful to leave it there just in case if you wanna add smth or other things are displayed
	
	std::cout << "Drey" << x << '\n';        // just like std::endl '\n' does basically the same it indicates end of the line and puts the cursor on the newline, but '\n' is preferred
	std::cout << "Dreyfuss\n";               // diffrence of endl and '\n' is basically endl flushes the buffer everytime when invoked but '\n' does not making the latter more efficient bc it doesnt need to be flushed everytime
	
	std::cout << "Please change the value of x to your fav number: "; // no need for '/n' bc we gonna ask for input so its fine being in the same line bc the user presses enter so it will move the cursor down
	std::cin >> x;                                                    // is an input statement / cin = character input >> = extraction operator/ you need to specify a variable beforehand to save the input in / no need for '\n' it does it automatically 
	std::cout << "new x: " << x << '\n';

	std::cout << "Please input three numbers ";
	int y{}, z{};
	std::cin >> x >> y >> z;
	std::cout << "You entered " << x << ", " << y << " and " << z << ".\n";
	return 0;          
	// buffer is basically the waiting area for requests before reachign their destination and is periodically flushed when the request reach their destination
	// Each line of input data in the input buffer is terminated by a '\n' character. 
	/*std::cin is buffered because it allows us to separate the entering of input from the extract of input.We can enter input once and then perform multiple extraction requests on it.
      basically if someone inputs 4 5 6 the 4 is used first and the 5 and 6 buffered for later extraction requests and is used on the next cin statement / but numbers need to be seperated by space	
	*/
	// if someone enters 5a in an input statement that asks for a number the 5 is put in the buffer and then is getting extracted and 'a' is put in the buffer for later use (even tho it would prop fail if it doesnt ask for a string)
	// but if the user only puts in 'b' even tho we asked for an int , then b also goes to the buffer and then it fails and puts 0 instead and the future extractions also fail bc the invalid input is in the buffer defaulting it to 0 too  
}