#pragma once
#include <iostream>

class MonthlyBudget {
public:
    void recalculation();
    void enterAll();
    void displayAll();
private:
  int income;
  long  int costs;
  long  int additionalExpenses;
   long int investment;
   int investementArr[5]={-1};
  long  int clearProfit;
  long  int recalculationTimes=0; 

   void clearProfitfunc();
    int tax();
   void taxReductionCalculation();
     int  allcost();
     int preTaxProfit();
};