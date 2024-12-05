#include <iostream>

int main() {
	int x;             // define an integer variable named x
	int y = 9, z = 4;  // define two integer variables, named y and z
	x = 3;            //  assignment copies the value on the right-hand side of the = operator to the variable on the left-hand side of the operator
	std::cout << x + y +z<<'\n'; // if you want to start a new line for the next print statement put  <<'\n' after it so its not all in the same line input seems to do that automatically tho
	y = 5;
	std::cout << y << '\n';
	
	// do those initializations instead 
	int width{ 3 }; // instead of having to diffrent statements one to define the variable and one to assign it a value we could just do it in one statement thats is called an initializer
	std::cout << width << '\n';
	
	// and try not to initialize two in the same statement to make sure that there are no mistakes
	int height{}, weight{5};      // value initialization / zero initialization to value 0 / if you intend to use the number 0 then write it in there but if you wanna replace it anyways then dont
	std::cin >> height;           // input statement / for input use >> instead of << that we use for print statements
	std::cout << weight ;
	[[maybe_unused]] int u{ 5 };  // Compiler will complain for any unused variables so if your not sure if you gonna use it you can put [[maybe_unused]] before it 
	return 0; 

}

/* there are many diffrent ways to initialize
int a;  no initializer 
int b = 5; initial value after equals sign (copy initialization)
int c(6);  initial value in parenthesis (direct initialization)
int d {7}; initial value in braces (direct list initialization) also the preferred one for example some of the other initializations would just convert a fraction like 4,5 to 4 but this one just gives an error
int e = {8}; initial value in braces after equals sign (copy list initialization)
int f {}; initializer is empty braces (value initialization) that one preferred too over the no initializer
*/
//Initialize your variables upon creation.
