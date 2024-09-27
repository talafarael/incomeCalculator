#include <iostream>
#include <vector>
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
class MonthlyBudget{
  public: int income;
   int costs;
   int additionalExpenses;
   int investment;
   int clearProfit;
   int recalculationTimes=0; 
   void clearProfitfunc(){
    int profit =income-allcost()-tax();
    int profitPercentage = profit * 100 /  income;
  
    if(profitPercentage<=10&&recalculationTimes!=5){
      taxReductionCalculation();
     }
     clearProfit= preTaxProfit()-tax();  
   }
   void taxReductionCalculation(){
   if(exitFromLoopFunc("Do you want to reschedule the budget by changing additional funds? (y/n)")){
   int sumadditionalExpenses=additionalExpenses*10/100;
    ++recalculationTimes;
     additionalExpenses=additionalExpenses-sumadditionalExpenses;
    
     clearProfitfunc();
   }
   clearProfit= preTaxProfit()-tax();
       
   }
   int  allcost(){
    return costs+additionalExpenses+investment;
   }
   int tax(){
    int interest =income-allcost();
    if(interest<=20000){
        return income*5/100;
    }else if(interest<=100000){
    return income*10/100;
   }else{
     return income*20/100;
   }
   }
   int preTaxProfit(){

    return income-allcost();
   }
  
};
int main(){
    std::vector<MonthlyBudget> month;
     int i=0;
    for(;;i++){
        MonthlyBudget monthly;
        std::cout<<"enter income";
        std::cin>>monthly.income;
        std::cout<<"enter additionalExpenses";
        std::cin>>monthly.additionalExpenses;
        std::cout<<"enter costs";
        std::cin>>monthly.costs;
        std::cout<<"enter investment";
        std::cin>>monthly.investment;
        
        monthly.clearProfitfunc();
        month.push_back(monthly);
        if(!exitFromLoopFunc("Do you want to enter another period? (y/n)")){
        break;

}
}
   std::cout<<i;
        
    for(int y=0;y<i+1;y++){
      MonthlyBudget monthly=month[y];
        std::cout<<"income:";
        std::cout<<monthly.income<<std::endl;
        std::cout<<"additionalExpenses:";
        std::cout<<monthly.additionalExpenses<<std::endl;
        std::cout<<"costs:";
        std::cout<<monthly.costs<<std::endl;
        std::cout<<"investment:";
        std::cout<<monthly.investment<<std::endl;
        std::cout<<"tax:";
        std::cout<<monthly.tax()<<std::endl;
        std::cout<<"preTaxProfit";
        std::cout<<monthly.preTaxProfit()<<std::endl;
        std::cout<<"clear profit";
        std::cout<<monthly.clearProfit;
        std::cout << "___________________________________________"<<std::endl;
    }

return 0;
}