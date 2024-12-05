#include <iostream>

/* Question 2 (Question 1 was on the learncpp.com website)

Write the following program: The user is asked to enter 2 floating point numbers (use doubles). The user is then asked to enter one of the following mathematical symbols: +, -, *, or /.
The program computes the answer on the two numbers the user entered and prints the results. If the user enters an invalid symbol, the program should print nothing.

*/
#if 0
double calculator(double x, double y, char z)
{
	if (z == '+')
	{
		return x + y;
	}

	else if (z == '-')
	{
		return x - y;
	}

	else if (z == '*')                  // General improvement could be Hint: Write three functions: one to get a double value, one to get the arithmetic symbol, and one to calculate and print the answer.
	{
		return x * y;
	}

	else if (z == '/')
	{
		return x / y;
	}
	else {
		return -1;                  // find another way not -1
	}


}



int main()
{
	std::cout << "Enter a double Value: ";
	double x{};
	std::cin >> x;
	std::cout << "Enter another double Value: ";  // You should get a function for getting input instead of writing it twice 
	double y{};
	std::cin >> y;
	std::cout << "Enter + , - , * or /: ";
	char z{};
	std::cin >> z;
	std::cout << x << ' ' << z << ' ' << y << ' ' << " is " << calculator(x, y, z);

	return 0;
}
#endif

/*
Question 3

Extra credit : This one is a little more challenging.

Write a short program to simulate a ball being dropped off of a tower.To start, the user should be asked for the height of the tower in meters.Assume normal gravity(9.8 m/s^2),
and that the ball has no initial velocity(the ball is not moving to start).Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
The ball should not go underneath the ground(height 0).
Use a function to calculate the height of the ball after x seconds.The function can calculate how far the ball has fallen after x seconds using the following formula :
distance fallen = gravity_constant * x_seconds^2 / 2
*/
double distance_fallen (double time, double height)
{
	return height - (9.8 * ((time * time) / 2));
}

void printUpdate(double time, double height)
{
	if (height > 0) 
	{
		std::cout << "At " << time << " seconds, the ball is at height: " << height << " meters\n";
	}

	else
	{
		std::cout << "At " << time << " seconds, the ball is on the ground.\n";
	}
}

void fallingBallUpdate5s(double height)
{
	printUpdate(0, distance_fallen(0, height));   // you can change and improve that with a while loop but we will be learning about those later on
	printUpdate(1, distance_fallen(1, height));
	printUpdate(2, distance_fallen(2, height));
	printUpdate(3, distance_fallen(3, height));
	printUpdate(4, distance_fallen(4, height));
	printUpdate(5, distance_fallen(5, height));

}


int main()
{
	std::cout << "Enter the height of the tower in meters: ";
	double tower{};
	std::cin >> tower;

	fallingBallUpdate5s(tower);       // you should have put the code of fallingBallUpdate5s code in main and instead made a function to get input bc the other functions can be reused but fallingUpdate5s is tooo specific just keep that in mind



	return 0;
}