#include "paramchecker.h"



class parameters{
   private:
      float limitRange[10][2];

   public:
      parameters(): limitRange(){ }
      
      void setLimits() {
         limitRange[0][0] = 50;
         limitRange[0][1] = 70;
         limitRange[1][0] = 80;
         limitRange[1][1] = 100;
         limitRange[2][0] = 30;
         limitRange[2][1] = 60;
      }
      bool isReadingWithinLimits(float reading, int index){
          if ((limitRange[index][0] <= reading) && (reading <= limitRange[index][1]))
              return true;
          else
              return false;
      }  
};

class reading{
   private:
        float paramValue;
        int paramIndex;
        
    public:
     parameters thresholds; 
     reading(): paramValue(0), paramIndex(0){ }
        void setValue(float value, int index){
           paramValue = value ;
           paramIndex = index ;
        }
        
        float getValue(){
           return paramValue;
        }
        
        bool isWithinLimits(){
            return thresholds.isReadingWithinLimits(paramValue, paramIndex);
        }
};
void setReading(reading*, vitals*);

bool checkVitals(reading*);

void setReading(reading* list, vitals* vitalReadings){
   for (int index = 0; index < vitalReadings->numberOfParmeters; index++) {
      list[index].setValue(vitalReadings->vital[index], index);
      list[index].thresholds.setLimits();
   }
   
}

bool checkVitals(reading* list, int numberOfParams){
  bool vitalStatus = true; 

  for (int loopvariable = 0; loopvariable < numberOfParams ; loopvariable++) {
     vitalStatus &= list[loopvariable].isWithinLimits();
  }

   return vitalStatus;
}


bool vitalsAreOk(vitals* vitalReadings) {
   bool testResult;
   reading chart[10];
   
   setReading(chart, vitalReadings);
  
   testResult = checkVitals(chart, vitalReadings->numberOfParmeters);    
   
   return testResult;
}
