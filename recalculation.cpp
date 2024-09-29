#include "enterAll.h"
#include "exitFromLoopFunc.h"
#include "MonthlyBudget.h"
#include <vector>



void recalculation(int& i,std::vector<MonthlyBudget> &month){
 std::cout<<i;
 for(int y=0;y<i;y++){
  std::cout<<i;
      MonthlyBudget monthly=month[y];
       monthly.recalculation();
       month[y]=monthly;
    }
    return;
}
