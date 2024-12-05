#include <iostream>



int getValueFromUser()                           // you need to put int as the return type bc otherwise it will get the input and it will print but wont initialize without returning the value
{
	std::cout << "pleas input value: ";
	int value{};
	std::cin >> value;
	return value;                               // return the value the usere entered back to the caller
}



int main() 
{
	int num{ getValueFromUser() };
	std::cout << num << " doubled is: " << num * 2 << '\n';
	
	int num2{ getValueFromUser() };                                       // DO NOT REPEAT YOURSELF use functions instead
	std::cout << num << " + " << num2 << " = " << num + num2 << '\n';
	return 0;
}
/* The program if we added arguments and Parameters
   #include <iostream>

int getValueFromUser()
{
 	std::cout << "Enter an integer: ";
	int input{};
	std::cin >> input;

	return input;
}

void printDouble(int value) // This function now has an integer parameter
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{

	printDouble(getValueFromUser() );

	return 0;
}


*/