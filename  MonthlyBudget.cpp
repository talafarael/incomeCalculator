#include <iostream>
#include "MonthlyBudget.h"
#include "exitFromLoopFunc.h"

void MonthlyBudget::recalculation(){
   
   int profit =income-allcost()-tax();
    int profitPercentage = profit * 100 /  income;
  
    if(profitPercentage<=10&&recalculationTimes!=5){
      displayAll();
      clearProfitfunc();
    }
  
}
void MonthlyBudget::displayAll(){
        std::cout<<"income:";
        std::cout<<income<<std::endl;
        std::cout<<"additionalExpenses:";
        std::cout<<additionalExpenses<<std::endl;
        std::cout<<"costs:";
        std::cout<<costs<<std::endl;
        std::cout<<"investment:";
        std::cout<<investment<<std::endl;
        std::cout<<"tax:";
        std::cout<<tax()<<std::endl;
        std::cout<<"preTaxProfit";
        std::cout<<preTaxProfit()<<std::endl;
        std::cout<<"clear profit";
        std::cout<<clearProfit<<std::endl;
        std::cout<<"reschedule the budget"<<std::endl;
         if(recalculationTimes!=0){
        for(int y=0;y<recalculationTimes;y++){
            std::cout<<"     reschedule in"<<y<<":"<<investementArr[y]<<std::endl;
          }}
        std::cout << "___________________________________________"<<std::endl;
       

}
void  MonthlyBudget::enterAll(){
        std::cout<<"enter income";
        std::cin>>income;
        std::cout<<"enter additionalExpenses";
        std::cin>>additionalExpenses;
        std::cout<<"enter costs";
        std::cin>>costs;
        std::cout<<"enter investment";
        std::cin>>investment;
        
        clearProfitfunc();
  }
void  MonthlyBudget::clearProfitfunc(){
  long   int profit =income-allcost()-tax();
   long  int profitPercentage = profit * 100 /  income;
   std::cout<<"profit"<<profit<<std::endl;
    if(profitPercentage<=10 && recalculationTimes!=5){
      taxReductionCalculation();
     }
     clearProfit= preTaxProfit()-tax();  
}
void MonthlyBudget::taxReductionCalculation(){
   if(exitFromLoopFunc("Do you want to reschedule the budget by changing additional funds? (y/n)")){
    
  long int sumadditionalExpenses=additionalExpenses*10/100;
   investementArr[recalculationTimes]=additionalExpenses;
    ++recalculationTimes;
     additionalExpenses=additionalExpenses-sumadditionalExpenses;
    std::cout<<"additionalExpenses:  "<<additionalExpenses<<std::endl;
     clearProfitfunc();
   }
   clearProfit= preTaxProfit()-tax();
}
int  MonthlyBudget::preTaxProfit(){

    return income-allcost();
   }
int   MonthlyBudget::allcost(){
    return costs+additionalExpenses+investment;
   }
int  MonthlyBudget::tax(){
   long  int interest =income-allcost();
    if(interest<=20000){
        return income*5/100;
    }else if(interest<=100000){
    return income*10/100;
   }else{
     return income*20/100;
   }
   }
