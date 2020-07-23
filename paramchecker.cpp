#include "paramchecker.h"



class reading{
   private:
      float limitRange[10][2] = {70,50,80,100,30,60};

   public:
      reading(): limitRange(){ }
      bool isReadingWithinLimits(float reading, int index){
      if ((limitRange[index][0] <= reading) && (reading <= limitRange[index][1]))
          return true;
      else
          return false;
      }  
};

class parameter{
   private:
        float paramValue;
        int paramIndex;
        reading chart; 
    public:
     parameter(): paramValue(0), paramIndex(0){ }
        void setValue(float value, int index){
           paramValue = value ;
           paramIndex = index ;
        }
        
        float getValue(){
           return paramValue;
        }
        
        bool isWithinLimits(){
            return chart.isReadingWithinLimits(paramValue, paramIndex);
        }
};
void setReading(parameter*, vitals*);

bool checkVitals(parameter*);

void setReading(parameter* list, vitals* vitalReadings){
   for (int index = 0; index < vitalReadings->numberOfParmeters; index++) {
      list[index].setValue(vitalReadings->vital[index], index);
   }
}

bool checkVitals(parameter* list, int numberOfParams){
  bool vitalStatus = true; 

  for (int loopvariable = 0; loopvariable < numberOfParams ; loopvariable++) {
     vitalStatus &= list[loopvariable].isWithinLimits();
  }

   return vitalStatus;
}


bool vitalsAreOk(vitals* vitalReadings) {
   bool testResult;
   parameter parameterList[10];
   
   setReading(parameterList, vitalReadings);
  
   testResult = checkVitals(parameterList, vitalReadings->numberOfParmeters);    
   
   return testResult;
}
