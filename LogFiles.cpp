/*
    IMPORTANT
   
to use a logger to create log files you first need to include the logger file to the project 
in this cas ist plog-master , AND also important is that you lower the warning level for that case 
for both the general warning level and the header warning level they are initially 4 for general and 3 for header
and also SUPER important add plog-master/include to the directorie in properties of the project

if done correctly the logfile.txt appears in the same place as your cpp files


*/

/*
Just like we discussed in the lesson before there as a way to improve
debugging with prrint statements, by using #define PLACE_HOLDER
with that we can define whatever we want and put a #ifdef PLACE_HOLDER
and a #endif and put the debugging statement inbetween, with that we can
just deactivate all debugging statements when we comment out the 
#define PLACE_HOLDER 
*/
#if 0
#include <iostream>

#define ENABLE_DEBUG  // now when you dont need the debugging statement
                      // you just comment out the #define to disable all of them
                      // in the case of a multiple files project we put the #define in a header file so we can put that in all files so we only need to comment it out once 

int getUserInput()
{
#ifdef ENABLE_DEBUG
std::cerr << "getUserInput() called\n";
#endif
    std::cout<< "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
std::cerr << "main() called\n";
#endif
   int x{getUserInput()};
   std::cout << "You entered: " << x << '\n';
   return 0;
}
#endif
/*
so that is a good improvement for the normal print debugging but it
still creates even more code clutter and in case of mispelling anything
or not including it in the header files its prune for errors so lets see 
an even better approach
*/

/*
The best approach for debugging is using a log. A log is  record
of event that happened and usually time-stamped. The process is called
logging. Typically Logs are written on a file which we call log files
so they can be reviewed later on and most applications and operating
systems write log files that can be used to diagnose issues that occur

Advantages of using log files :
1. Its seperated from the programs output 
2. Log files can easily be send to other people for diagnosis

You could use std::clog which is used for logging but it is just 
send to the error stream just like std::cerr , you could redirect it
tho to  a log file but its too much of a hassle so you better of 
using a third party tool and below we will use that 
*/
#if 1
#include <plog/Log.h>   // Step 1: include the logger headers / this is for the plog logger
#include <plog/Initializers/RollingFileInitializer.h> // *
#include <plog/Initializers/ConsoleInitializer.h>     // *
#include <iostream>

int getUserInput()
{
    PLOGD << "getUserInput() called"; //PLOGD is define by the plog library
    
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger // if you want the log file to be in a certain folder you can write a path before Logfile.txt like "C:/path/to/your/logs/Logfile.txt" //and if you want to temporarily disable the logging you can changge ::debug to ::none e.g plog::init(plog::none , "Logfile.txt"); plog::none eliminates writing of most messages, essentially turning logging off
    
    PLOGD << "main() called"; // Step 3: Output to the lof as if you were writing to the console

    int x{getUserInput()};
    std::cout << "You entered: " << x << '\n';
    
    return 0;
}
#endif
#if 0
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

int getUserInput()
{
    spdlog::info("getUserInput() called"); // Using spdlog for logging instead this time 

    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
    // Initialize spdlog with a file sink
    auto file_logger = spdlog::basic_logger_mt("file_logger", "spdlog_logfile.txt");  // here too the default directory is the one where the compilation happens C:\msys64\ucrt64\bin but if you want to change that you can just write another path before the txt
    spdlog::set_default_logger(file_logger);  // Set the default logger to the file logger
    spdlog::set_level(spdlog::level::debug);  // Set global log level to debug

    spdlog::info("main() called");   // Logging message

    int x{getUserInput()};
    std::cout << "You entered: " << x << '\n';

    return 0;
}
#endif
/* 
   spdlog is more complex and needs more code written but for that
   its faster but for now stick with plog
*/
