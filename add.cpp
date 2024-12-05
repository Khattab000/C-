#include "add.h"        // thats the header files containing the forward declaration for this function below the #inlcude is mainly here to make sure everything works and stays consistent in case anything changes and so the compiler can catch the error while compiling instead of at the linking process // Insert contents of add.h at this point.  Note use of double quotes here.
// best practice is to always to #include the corresponding header files to the source file
#include <iostream>

// this is just made in connection to MultipleFiles.cpp to showcase the usage of functions from diffrent files

int add(int x, int y)
{
	return x + y;
}