#include "paramchecker.h"
#include <gtest/gtest.h>
vitals vitalReading;

TEST(VitalsTest, BPM) { 
    vitalReading.bpm = 100;
    vitalReading.spo2 = 100;
    vitalReading.respRate = 50;
    ASSERT_EQ(true, vitalsAreOk(&vitalReading));
}
 
TEST(VitalsTest, SPO2) {
     vitalReading.bpm = 100;
    vitalReading.spo2 = 40;
    vitalReading.respRate = 50;
    ASSERT_EQ(false, vitalsAreOk(&vitalReading));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
