#include "paramchecker.h"
#include <gtest/gtest.h>
vitals vitalReading;

TEST(VitalsTest, BPM) { 
    vitalReading.vital[0] = 60; //bpm
    vitalReading.vital[1] = 100; //spo2
    vitalReading.vital[2] = 50; //respRate
    vitalReading.numberOfParmeters = 3;
    ASSERT_EQ(true, vitalsAreOk(&vitalReading));
}
 
TEST(VitalsTest, SPO2) {
    vitalReading.vital[0] = 100; //bpm
    vitalReading.vital[1] = 40; //spo2
    vitalReading.vital[2] = 50; //respRate
    vitalReading.numberOfParmeters = 3;
    ASSERT_EQ(false, vitalsAreOk(&vitalReading));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
