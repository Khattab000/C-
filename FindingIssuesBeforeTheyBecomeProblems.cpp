/*
  A testing function is basically just a function to test
  another function with diffrent inputs or diffrent 
  scenarios to check if the function works properly 

  e.g. testadd() is testing add() to make sure that
  it works with diffrent inputs and if you have an idea
  what the inputs should be you can print that to 
  compare it with the testing outputs,

  this is called unit testing
*/

/* Constraint will be talked about in a later lesson 
   but its basically checking if the input of the 
   user is valid and to catch the error early instead
   of letting it finish and produce some garbage value
   like in a calculation that doesnt work with 
   negative numbers

   But in general you can always keep in mind what 
   input the user could put in to be able to program 
   accordingly ,like giving the user an error or telling
   him that its invalid and he should try again (
   this is called Defensive Programming)
*/

/*
  Introduction to "static analysis tools" also called
  "linters" are bascially software/extension that analyze
  your program for common errors or issues to help you
  to fix them early and catch them as early as 
  possible, ofc your compiler does have one itself but 
  these are more advanced finding even more issues

  Recommended static analysis tools :

   clang-tidy
   cpplint
   cppcheck
   SonarLint (the one you are currently using)

   Also VS comes also with one which you can manually access 
   via Build > Run Code Analysis on Solution (Alt+F11).

Best practice:
Use a static analysis tool on your programs to help 
find areas where your code is non-compliant with 
best practices.
*/

#include <iostream>

int add(int x, int y)
{
    return x + y;
}

void testadd()
{
    std::cout << "This function should print 2 0 0 -2\n";
    std::cout << add(1,1) <<' ';
    std::cout << add(-1,1) <<' ';
    std::cout << add(1,-1) <<' ';
    std::cout << add(-1,-1) <<' ';
}

int main()
{
    testadd();

    return 0;
}
