#include "paramchecker.h"

class parameter{
   private:
        float lowerLimit;
        float upperLimit;  
        float paramValue;
   
    public:
       parameter(): lowerLimit(0), upperLimit(100), paramValue(50) { } 
        
        void setValue(float value){
           paramValue = value ;
        }
        
        float getValue(){
           return paramValue;
        }
   
        void setLimits(float lower, float upper){
           lowerLimit = lower;
           upperLimit = upper;
        }
        
        bool isWithinLimits(){
        if ((lowerLimit <= paramValue) && (paramValue <= upperLimit))
          return true;
        else
          return false;
        }
};


void setReading(parameter*, vitals*);
void setLimits(parameter*);
bool checkVitals(parameter*);

bool vitalsAreOk(vitals* vitalReadings) {
   bool testResult;
   parameter parameterList[10];
   
   setReading(parameterList, vitalReadings);
   setLimits(parameterList);
   testResult = checkVitals(parameterList);    
   
   return testResult;
}

void setReading(parameter* list, vitals* vitalReadings){
   for (int loopVariable = 0; loopVariable < vitalReadings.numberOfParmeters; loopVariable++) {
      list[loopVariable].setValue(vitalReadings->vital[loopVariable]);
   }
}

bool checkVitals(parameter* list){
  bool vitalStatus = true; 

  for (int loopvariable = 0; loopvariable < 3 ; loopvariable++) {
     vitalStatus &= list[loopvariable].isWithinLimits();
  }

   return vitalStatus;
}

void setLimits(parameter* list){
  list[0].setLimits(70, 150);
  list[1].setLimits(80, 100);
  list[2].setLimits(30, 60);
}
