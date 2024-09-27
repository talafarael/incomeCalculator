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
  public:
  void enterAll(){
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
  void displayAll(){
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
        std::cout<<clearProfit;
        std::cout << "___________________________________________"<<std::endl;

  }
  private:
   int income;
   int costs;
   int additionalExpenses;
   int investment;
   std::string investementArr[5];
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
   investementArr[recalculationTimes]=additionalExpenses;
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
        monthly.enterAll();
        month.push_back(monthly);
        if(!exitFromLoopFunc("Do you want to enter another period? (y/n)")){
        break;
        }
}
switch() {}

   std::cout<<i;
        
    for(int y=0;y<i+1;y++){
      MonthlyBudget monthly=month[y];
       monthly.displayAll();
    }

return 0;
}