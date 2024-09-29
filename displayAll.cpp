#include "displayAll.h"
#include "MonthlyBudget.h"
#include <vector>
void displayAll(int& i,std::vector<MonthlyBudget>& month){
 
    for(int y=0;y<i;y++){
  
      MonthlyBudget monthly=month[y];
       monthly.displayAll();
       
    }
    return;
}