#include <iostream>
#include <vector>
#include <string>
bool exitFromLoopFunc(std::string text);
class MonthlyBudget;
void recalculation(int& i,std::vector<MonthlyBudget> &month);
void enterAll(int& i,std::vector<MonthlyBudget> &month);
void displayAll(int& i,std::vector<MonthlyBudget> &month);
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
      displayAll(i, month);
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
class MonthlyBudget{
  public: 
   void recalculation(){
   int profit =income-allcost()-tax();
    int profitPercentage = profit * 100 /  income;
  
    if(profitPercentage<=10&&recalculationTimes!=5){
      displayAll();
      clearProfitfunc();
    }
  }
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
        std::cout<<clearProfit<<std::endl;
        std::cout << "___________________________________________"<<std::endl;

  }
  int income;
  long  int costs;
  long  int additionalExpenses;
   long int investment;
   std::string investementArr[5];
  long  int clearProfit;
  long  int recalculationTimes=0; 
private:
   void clearProfitfunc(){
  long   int profit =income-allcost()-tax();
   long  int profitPercentage = profit * 100 /  income;
  std::cout<<"profit"<<profit<<std::endl;
    if(profitPercentage<=10 && recalculationTimes!=5){
      taxReductionCalculation();
     }
     clearProfit= preTaxProfit()-tax();  
   }

   void taxReductionCalculation(){
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
   int  allcost(){
    return costs+additionalExpenses+investment;
   }
   int tax(){
   long  int interest =income-allcost();
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
void displayAll(int& i,std::vector<MonthlyBudget>& month){
 
    for(int y=0;y<i;y++){
  
      MonthlyBudget monthly=month[y];
       monthly.displayAll();
       
    }
    return;
}
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

