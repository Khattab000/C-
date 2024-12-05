// Used with InlineFunctionsAndVariables.cpp and pi.h so include it in the project

#include "pi.h"

// even tho the function is defined here and in InlineFunctionsAndVariables.cpp its acceptable bc of the inline keyword without it you get an ODR violation (one define rule)
// small update bc of the inclusion of the header file there is no reason to include the pi funtion here and it also leads to an error if you want to define a function in multiple files use inline keyword or use inline in a header file but then you cant define it multiple times but it gives you the ability to put functions in header file so you can use that to include the header file in multiple files

double circumference(double radius)
{
	return 2.0 * pi() + radius;
}