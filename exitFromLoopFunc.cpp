
#include <iostream>
#include <string>
bool exitFromLoopFunc(std::string text){
    char exitFromLoop;
    std::cout<<text;
    std::cin>>exitFromLoop;
   if(exitFromLoop=='y'||exitFromLoop=='Y')
   return true;
   if(exitFromLoop=='n'||exitFromLoop=='N')
   return false;
   else
   return exitFromLoopFunc("Do you want to enter another period? (y/n)");
}
