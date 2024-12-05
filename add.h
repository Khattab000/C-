#pragma once                           /* that is a header guard , its task is basically checking if the header is already included bc for example other header files might include that header file
                                          so to avoid an error but its mainly used when we include a definition in our header file which is generally discouraged,we include that header guard so it can
                                          prevent it from being included multiple times we use #pragma once   for that but the traditional header guard looks like this:
                                          add.h
                                          #ifndef ADD.H                  // name doesnt matter but the convention is using the name of the file in all caps / but be careful that it doesnt use the same name as another header file does 
                                          #define ADD.H

                                         int add(int,int);

                                         #endif
                                         
                                         wave.h:
                                         #ifndef WAVE_H
                                         #define WAVE_H

                                         #include "add.h"

                                         #endif

                                         main.cpp:
                                         #include "add.h"
                                         #include "wave.h"

                                         int main()
                                         {
                                          return 0;

                                         }

                                         basically how it works is first when this header file is first called it checks if ADD.H is defined if it isnt it defines it and then proceeds as 
                                         usual, BUT if its already defined it just stops at its tracks and doesnt add anything to the source file bc it only proceeds when it is not defined, preventing
                                         the funtion of ever being defined twice (but it wont stop it from being defined in two diffrent files which is fine)
                                         but pragma once basically does the same but in a much shorter way 
                                          */                

int add(int, int);                     // that is the content of our header file and a forward declaration to the function found in add.cpp
                                       // this is a header file where we put all our forward declarations in of other files in example add.cpp this saves us writing the forward declaration for every function
                                       // also the file extension is .h for header files and you want to name it after the file that its taking the funtions from
                                       // important the header file is only for forward declaration of a funtion NOT defining it again that would violate the one definition rule so be careful for now
                                       // header files can also #include other header file

// generally speaking always include a header guard for safety