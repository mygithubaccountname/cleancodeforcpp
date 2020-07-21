class parameter{
   private:
        float lowerLimit;
        float upperLimit;  

    public:
        parameter(float lower, float upper): lowerLimit(lower), upperLimit(upper){ }
  
        bool isWithinLimits(float param){
        if ((lowerLimit <= param) && (param <= upperLimit))
          return true;
        else
          return false;
        }
};

bool vitalsAreOk(float bpm, float spo2, float respRate) {

  parameter bloodPressure(70, 150);
  parameter oxygenation(80, 100);
  parameter respiration(30, 60);
    
  bool bloodPressureStatus, oxygenationStatus, respiratoryStatus;
  
  bloodPressureStatus = bloodPressure.isWithinLimits(bpm);
  oxygenationStatus = oxygenation.isWithinLimits(spo2);
  respiratoryStatus = respiration.isWithinLimits(respRate);
  
  return (bloodPressureStatus && oxygenationStatus && respiratoryStatus);
}
