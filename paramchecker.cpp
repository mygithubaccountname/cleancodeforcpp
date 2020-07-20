
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  //int i;
  bool bloodPressureIsOk(float);
  bool oxygenationIsOk(float);
  bool respirationIsOk(float);
  
  bool bloodPressureStatus, oxygenationStatus, respiratoryStatus;
  
  bloodPressureStatus = bloodPressureIsOk(bpm);
  oxygenationStatus = oxygenationIsOk(spo2);
  respiratoryStatus = respirationIsOk(respRate);
  
  if (!bloodPressureStatus || !oxygenationStatus || !respiratoryStatus) {
  return false;
  }
  else {
  return true; }
}

bool bloodPressureIsOk(float bpm) {
  if(bpm < 70 || bpm > 150) {
    return false;
  }
  return true;
}

bool oxygenationIsOk(float spo2) {
  if(spo2 < 80) {
    return false;
  }
  return true;
}

bool respirationIsOk(float respRate) {
  if(respRate < 30 || respRate > 60) {
    return false;
  }
  return true;
}
