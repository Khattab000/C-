#include <iostream>

int add (int x,int y)   // this funtion is supposed to perform addition
{
    return x - y;      // but it doesnt due to the wrong operator being used
}

int main()
{
    std::cout << "5 + 3 = "<<add(5,3) << '\n'; // should produce 8, but produces 2 bc we mistakingly did x - y in the add funtion
    return 0;
}
/* the code will run but it has a logic error we need to find out 
   out what the problem is (debug)

 1. The root of cause which  is the '-' in the add funtion which should be '+' instead to do addition
 2. Understand the problem which is easy to understand bc - does subtraction and + does addition and the functuion is supposed to do addition
 3. Determine a fix , we simply change the - operator to +
 4. Repair the issue, now we just actually change the - to a + and then ensure that the program recompiles
 5. Retest make sure you get the correct answer and maybe try other numbers too to make sure its not only works with those two numbers only and make sure no new problems have emerged 
 Thats how the correct version of add() : 

 #include <iostream>

int add (int x,int y)
{
    return x + y;      
}

If you cant find the issue try to reproduce the error so you can diagnose it and then if you are able to do that it shoul be easier to find the error
 */
