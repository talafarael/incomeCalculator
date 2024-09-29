#include "enterAll.h"
#include "exitFromLoopFunc.h"
#include "MonthlyBudget.h"
#include <vector>

void enterAll(int& i,std::vector<MonthlyBudget>& month){
  
    for(;;){
        MonthlyBudget monthly;
        monthly.enterAll();
        month.push_back(monthly);
        ++i;
        if(!exitFromLoopFunc("Do you want to enter another period? (y/n)")){
        break;
        }
}
return;
}