// Used with InlineFunctionsAndVariables.cpp and math.cpp so include it in the project

#pragma once  // you can also use  #ifndef PI_H
                                // #define PI_H

inline double pi()
{
    return 3.14159;
}

// use #endif at the end if #ifndef and #define was used instead if #pragma once / but tbh just use #pragma once 