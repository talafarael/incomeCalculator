#include <iostream>
#include <vector>
#include <string>
#include "displayAll.h"
#include "enterAll.h"
#include "MonthlyBudget.h"
#include "recalculation.h"


int main(){
  int i=0;
  bool exitInEventLoop=false;
  std::vector<MonthlyBudget> month;
  while(!exitInEventLoop){//   enterAll( i, month);
    
     
   int action;
   std::cout<<"if you want enter budget enter : 1"<<std::endl;
   std::cout<<"if you want see budget enter : 2"<<std::endl;
   std::cout<<"if you want recalculation budget enter : 3"<<std::endl;
   std::cout<<"if you want exit enter : 4"<<std::endl;
   std::cin>>action;

  
   switch(action) {
      case 1: 
      enterAll(i, month);
    break;
    case 2:
     displayAll(i,month);
    break;
    case 3:
          recalculation(i, month);
    break;
    case 4:
       exitInEventLoop=true;
    break;
    

   }
   std::cout<<i;
       
}

return 0;
}


