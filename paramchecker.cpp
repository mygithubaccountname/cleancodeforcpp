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


void initializeLimits(parameter*);
void setReading(parameter*, vitals*);
bool checkVitals(parameter*);

bool vitalsAreOk(vitals* vitalReadings) {
   bool testResult;
   parameter parameterList[3];
   
   initializeLimits(parameterList);
   setReading(parameterList, vitalReadings);
   testResult = checkVitals(parameterList);    
   
   return testResult;
}

void initializeLimits(parameter* list){
  list[0].setLimits(70, 150);
  list[1].setLimits(80, 100);
  list[2].setLimits(30, 60);
}

void setReading(parameter* list, vitals* vitalReadings){
  list[0].setValue(vitalReadings->bpm);
  list[1].setValue(vitalReadings->spo2);
  list[2].setValue(vitalReadings->respRate);
}

bool checkVitals(parameter* list){
  bool vitalStatus = true; 

  for (int loopvariable = 0; loopvariable < 3 ; loopvariable++) {
     vitalStatus &= list[loopvariable].isWithinLimits();
  }

   return vitalStatus;
}
