#include <iostream>
#include <bitset>
#include <cstdint>


void printBit(int x, int pow)
{
	std::cout << ((x / pow) % 2);
}

void print8BitBinary(int x)
{
	printBit(x, 128);
	printBit(x, 64);
	printBit(x, 32);
	printBit(x, 16);
	std::cout << ' ';
	printBit(x, 8);
	printBit(x, 4);
	printBit(x, 2);
	printBit(x, 1);
}

int main()
{
	/*
	Converting binary to decimal:

	You start from the right and make a table
	0  1  1  0   0  1  1  1   binary
   128 64 32 16  8  4  2  1   decimal counterpart (start from the farmost right start with 1 and go to left while doubling the number this one is for 8 bit but ofc it can go up to 16 or 32 bit too there isnt a limit)

   if the number is 0 above the decimal counterpart then 0 * decimal counterpart and if the number 1 is above 1 * decimal counterpart and then add them all together e.g

   (0 * 128) + (1 * 64) + (1 * 32) + (0 * 16) + (0 * 8) + (1 * 4) + (1 * 2) + (1 * 1) = 103  so binary 0110 0111 is 103 in decimal

	*/


	/*
	Converting decimal to binary:

	You keep dividing the number through 2 until the result is 0, and you always note down the remainder bc those are the binary digits and the beginning of the binary is the 
	first remainder (keep in mind binary begins from the right not the left so the firs digit is the farmost right one)(this one isnt in the correct order the result needs to be flipped:

	103 / 2 = 51 | 1    // the 1 here is the remainder
	51 / 2 = 25  | 1
	25 / 2 = 12  | 1
	12 / 2 = 6   | 0
	6 / 2 = 3    | 0
	3 / 2 = 1    | 1 
	1 / 2 = 0    | 1   // as you can see we reached 0 but we only got 7 digits now it depends if we get told that its only 7 Bits long then thats the answer but we know in this case 
	                      its 8 bits long so we just add another 0 to the leftmost digit until we have 8 digits representing 8 bits




	This method is best for humans bc it only involves dividing by 2 but not so good for machines because it requires storing all of the bits as they are calculated and then printed
	in reverse. But there is a method that is more efficient for machines and gives us the answer in the correct order already:

	Lets look at 103 and at the table with the binary and counterparts and lets find the closest power of 2  decimal  thats smaller then 103 is 64 and 64 fits in so the spot of 64
	gets a 1 and we subtract 103 - 64 = 39 so lets continue with that lets look what is the closest power of 2 decimal that is smaller then 39 , its 32 so we put a 1 on the 32 spot
	and subtract 39 - 32 = 7 now we repeat, 16 is bigger so we cant use that and 8 is bigger then 7 too so we cant use that either so the next big thing thats smaller is 4 so 7 - 4 = 3,
	then we repeat the next one is 2 which is smaller so 3 - 2 = 1 and then we go to 1 which is the same size which is also okey so 1 -1 = 0 and the rest that didnt get a 1 are getting 
	zeroes so 103 = 0110 0111




	Now there is one more Method that isnt efficient for humans (bc a lot of division) or machines (division is  an inefficient operation)
	but is efficient if it comes to coding it bc the first one needs you to save the bits in progress and the second needs you to use if statements throughout the process
	so here is another way:

	Basically its the same as Method 2 where you search for the biggest power of 2 decimal to your number thats smaller or the same but in this one you keep dividing your
	decimal number (the decimal number stays the same you divide it through all decimal counterparts until you reach 1 which is the last division) beginning with the biggest one and 
	going until you reach 1 which is the last devision, if the result of the the division is even then this bit is a 0 if its odd its a 1 but keep in mind we wont look at the remainder
	just the main number so for example if the number is 6 with remainder 3 its still even (this method also gives the result incorrect order) e.g:

	103 / 64 = 1,1.609375  | odd  1 
	103 / 32 = 3.21875     | odd  1
	103 / 16 = 6.4375      | even 0
	103 / 8  = 12.875      | even 0
	103 / 4  = 25.75       | odd  1
	103 / 2  = 51.5        | odd  1
	103 / 1  = 103         | odd  1

	so the answer is  110 0111 if its 7 bits but if its 8 bits its 0110 0111

	*/

	/*
	Adding in binary:
	(11   ) // carried over digits by 1 + 1
     0110 (6 in decimal)  // if both digits that are added these rules apply : 1 + 0 = 1, 0 + 1 = 1, 0 + 0 = 0, 1 + 1 = 0 /but in this last case the 1 is carried on to the next collumn so if the next collumn is 0 + 0 its gonna be 1 + 0 + 0;
	+0111 (7 in decimal)  // btw as usual start from right to left
	--------------------
	=1101 (13 in decimal)

	Another small example :
	lets say you want to 1 to and binary number like 1011 0011 its basically the same but first you need to convert 1 to binary
	(      11 ) / carried over
	 1011 0011 (original binary number)
	+0000 0001 (binary number for 1)
	----------
	=1011 0100
	*/




	/*
	So far we converted binary to decimal and decimal to binary with unsigned numbers (positive) but have a look at signed binary/decimal that could be positive or negative.
	So the way it works it depends on the type of the variable where the binary is stored if its unsigned it just saves it normally but if its signed it saves it in the 
	two complement method, which basically means its saves the binary as one complement and the left most bit which will be the sign bit as another complement. So when the leftmost
	bit is a 1 then the binary is negativ and if its a 0 its positve or zero, the general rule is Positive signed numbers are in binary just like positive unsigned numbers but with the 
	sign bit set to 0 and Negative signed numbers are in binary as the bitwise inverse of the positive number BUT you do + 1 (we are not talking about the sign bit you literally 
	do an addition operation + 1) e.g

	Converting decimal to binary (two complements):

	- 5 // first we need to convert 5 to binary 
	0000 0101 //5 in binary then after that we do the inverse
	 1111 1010 // inverse of binary 5 and then we do + 1
    +0000 0001 // 1 in binary 
	----------
	 1111 1011 // now we have -5 in binary

	 another example -76 
	  0100 1100 // 76 in binary
	 1011 0011 // inverse
    +0000 0001 // + 1
	----------
	 1011 0100 // - 76 in binary

	 // One important reason why we add +1 when we convert negative numbers is lets take -0 if we just inversed the decimal we would get 1111 1111 and that isnt correct bc that clearly
	 isnt 0 but if we add + 1  this overflows and becomes 0000 0000 so this way we get the correct binary representation




	 Converting binary (two complements) to decimal:

	 If the sign bit is 0 then convert it as usual as you would do with unsigned binary e.g 0000 0101 = 5
	 BUT if the sign bit is 1 then you need to take some steps before converting, first you invert the bits and then add + 1 and then you convert that, when you got the result
	 you add a negative sign to it that should give you the right decimal e.g:

	  1011 1101 // negative binary as we can see from 1 being the sign bit (ofc thats only the case if its signed )
	 0100 0010 // firs you make the inverse
    +0000 0001 // add 1
	----------
	 0100 0011 // now convert that to decimal
	 - 67 // and dont forget to add the - 
	 
	 There is also a easier method to calculate it by hand:
	 Lets take the same number 1011 1101 we do the normal conversion as we would do with unsigned binary BUT the the sign bit is gonna be negative e.g
	 only 128 is negative bc its the sign bit   (1* -128) + (0 * 64) * (1 * 32) + (1 * 16) + (1 * 8) + (1 * 4) + (0 * 2) + (1 * 1) = -67
	 


	 // So prob one Question you have is how does the compiler know in general if the binary is negative or positive ? It depends on the type its saved as, if its unsigned it
	    automatically knows that the the binary number is positive but if its saved in a signed type it first checks the sign bit to determine if its positive or negative and then 
		does the conversion accordingly and in case of literals the default is signed int like 0b1011 but you can specify it to be unsigned by using u at the end like 0b1011u ;
	 */

     /* Small Quiz Question 1:
     0100 1101 = 77
	    
        Question 2:
		93 = 0101 1101
		first Method:
		93/2 = 46 | 1
		46/2 = 23 | 0
		23/2 = 11 | 1
		11/2 = 5  | 1
		5 /2 = 2  | 1
		2 /2 = 1  | 0
		1 /2 = 0  | 1
		= 0101 1101  // added a 0 to the left bc its 8 bit
		second Method: 128 is too big so its 0 the next one is 64 which is good so its 1 93 - 64 = 29 , next one is 32 which is too big so 0 , so then 16 which is good so 1  29 - 16 = 13
		next one is 8 which also fits so its 1  13 - 8 = 5, the next one is 4 which also fits so 1 5 - 4 = 1, then 2 is too big so 0 and then 1 fits so also 1  1 - 1 = 0
		= 0101 1101

		Question 3:
		-93 =
		 0101 1101 // 93
		1010 0010
       +0000 0001
	   ----------
	    1010 0011

		Question 4:
		1010 0010 = 162  // unsigned decimal

		Question 5: 
		1010 0010 = -94     // signed decimal
		-128 + 34 = -94


		Question 6: 
	 */
	std::cout << "Input a number between 0 and 255: ";
	int x{};
	std::cin >> x;
	print8BitBinary(x);

	std::cout << '\n';

	return 0;
}