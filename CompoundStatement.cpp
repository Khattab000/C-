#include <iostream>


// A compound statement also called a block is a group of zero or more statemens that is treated by the compiler as if it were a single statement blocks begin with { and end with } but no semicolon afterwards

int add(int x, int y)
{ // start block
	return x + y;
} // end block no semicolon needed


int main()
{ // start block (outer block) / Block 1 nesting Level 1
	[[maybe_unused]] int value{}; // this is initialization not a block so semicolon needed

	add(3, 4);

	// you cant nest functions in other functiuons but blocks can be nested inside other blocks e.g
	{// inner nested block  / Block 2 nesting Level 2 (bc its inside of Level 1)
		add(2, 1);
	} // end inner nested block

	// other then function nested blocks are often used for if statements to execute multiple statements instead of one
	if (value != 9000)
	{ //start nested block  / Block 3 nesting Level 2 (bc its inside of Level 1)
		if (value == 0)
		{ //start nested block /Block 4 nesting Level 3 (bc its inside of Level 2)
			value = 5;
			value += 9;
		} // end nested block
		else
		{  //start of another nested block /Block 5 nesting Level 3 (bc its also inside of Level 2)
			value = -5;
			value += 913;
		}  //end of another nested block

	} // end nested block
	


	// There is also smth called Block nesting levels (nesting depth) the deeper you are the higher the level the first block is level 1 and the deeper you go the higher the level
	// even tho the highest levele of nesting is around 256 this however isnt recommended, recommended are about 3 Levels of nesting after that it maybe time to refactor the functions or statements to sub-functions


	return 0;
} // end block (outer block)no semicolon