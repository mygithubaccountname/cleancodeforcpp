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
void setReading(parameter*, float, float, float);
bool checkVitals(parameter*);

bool vitalsAreOk(vitals* vitalReadings) {
   bool result;
   parameter parameterList[3];
   
   initializeLimits(parameterList);
   parameterList[0].setValue(vitalReadings->bpm);
   parameterList[1].setValue(vitalReadings->spo2);
   parameterList[2].setValue(vitalReadings->respRate);
   //setReading(parameterList, bpm, spo2, respRate);
   
   result = checkVitals(parameterList);    
   
   return result;
}

void initializeLimits(parameter* list){
  list[0].setLimits(70, 150);
  list[1].setLimits(80, 100);
  list[2].setLimits(30, 60);
}
/*
void setReading(parameter* list, float bpm, float spo2, float respRate){
  list[0].setValue(bpm);
  list[1].setValue(spo2);
  list[2].setValue(respRate);
}
*/
bool checkVitals(parameter* list){
  bool vitalStatus = true; 

  for (int loopvariable = 0; loopvariable < 3 ; loopvariable++) {
     vitalStatus &= list[loopvariable].isWithinLimits();
  }

   return vitalStatus;
}
