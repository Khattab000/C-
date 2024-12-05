#include <iostream>


void doprint()
{
	std::cout << "In doPrint()\n";
}

void doB()
{
	std::cout << "in doB()\n";              // dont put return statements on a void function its kinda useless bc it will return regardless 
}

void doA()
{
	std::cout << "Starting doA()\n";
	doB();                                   // you can also call another function in a function like doA() calls doB()
	std::cout << "Ending doA()\n";
}

int main()
{
	std::cout << "Starting main()\n";
	doprint();
	std::cout << "Edning main()\n";
	doprint();                             // functions can be called multiple times which is the main usage to make it easier and more readable /DO NOT REPEAT YOURSELF


	doA();                                // main calls doA() and doA() also calls doB()  / BUT you cant write nested Functions (defining a Function in a Funtion) you need to seperate it
	return 0;
}

// Functions should generally do one task and then return the value (if there is value ) the user should then decide if he wants it printed or do smth else with it