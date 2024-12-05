#include <iostream>
#include <string>
#include <string_view>

/* Question #1

a) Why are named constants often a better choice than literal constants?

b) Why are const/constexpr variables usually a better choice than #defined symbolic constants?

Answer : a)Using literal constants (magic numbers) in your program makes your program harder to understand and to modify, named constants make these process much easier.
         b) They are a better choice bc #define dont show up on the debugger and may cause naming confliction more often

*/

/*  Question #5

Write a program that asks for the name and age of two people, then prints which person is older.

Here is the sample output from one run of the program:

*/
#if 0
std::string getName(int num)
{
	std::cout << "Enter the name of person #" << num << ": ";
	std::string name{};
	std::getline(std::cin >> std::ws, name);
	return name;
}

int getAge(std::string name)
{
	std::cout << "Enter the age of " << name << ": ";
	int age{};
	std::cin >> age;
	return age;
}

void printOlder(std::string name, std::string name2, int age, int age2)
{
	if (age > age2)
	{
		std::cout << name << " (age " << age << ") is older than " << name2 << " (age " << age2 << ").\n";
	}
	else
	{
		std::cout << name2 << " (age " << age2 << ") is older than " << name << " (age " << age << ").\n";
	}
}

int main()
{
	std::string name{getName(1)};
	int age{getAge(name)};
	
	std::string name2{getName(2)};
	int age2{getAge(name2)};

	printOlder(name, name2, age, age2);

	

	return 0;
}
#endif

constexpr std::string_view getQuantityPhrase(int x)  // we use constexpr bc ín marys case we can make it run in compile time so its more efficient so if its a constant that is returned try using constexpr  /opens up for optimization
{                                                    // in this case we can return std::string_view bc it points to a constant literal saved in static memory so it works even outside of the function ad that is more efficient to do so
	if (x < 0)
	{
		return "negative";
	}
	else if (x == 0)
	{
		return "no";
	}
	else if (x == 1)
	{
		return "a single";
	}
	else if (x == 2)
	{
		return "a couple of";
	}
	else if (x == 3)
	{
		return "a few";
	}
	else
	{
		return "many";
	}
}

constexpr std::string_view getApplesPluralized(int y)
{
	if (y == 1)
	{
		return "apple";
	}
	else
	{
		return "apples";
	}
}

// Write the function getQuantityPhrase() here

// Write the function getApplesPluralized() here

int main()
{
	constexpr int maryApples{ 3 };
	std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

	std::cout << "How many apples do you have? ";
	int numApples{};
	std::cin >> numApples;

	std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

	return 0;
}