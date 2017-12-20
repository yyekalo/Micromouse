 // MPU-6050 Short Example Sketch
// By Arduino User JohnChi
// August 17, 2014
// Public Domain
#include<Wire.h>
const int MPU_addr=0x68;  // I2C address of the MPU-6050
int16_t GyZ;
#define Min -32676
#define Max 32740
int z;
double angle=0;

IntervalTimer timer;



void setup(){
  Wire.begin();
  Wire.setSCL(19);
  Wire.setSDA(18);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x1B);  // scale and self test register
  Wire.write(0);     // set to 250o/second
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x38);  //enable interupt on data ready
  Wire.write(0x1);     
  Wire.endTransmission(true);
  Serial.begin(9600);
  timer.priority(0);
  timer.begin(gZ,10000);
}




void loop(){
  delay(15000);
}



void gZ(){

cli();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x47);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,2,true);
  GyZ = Wire.read() << 8 | Wire.read();
  GyZ+=93;
  
  z = map(GyZ,Min,Max,-250,250);
  angle+=double(z*0.01);
  Serial.print(z);Serial.print("  ");Serial.println(angle);
  sei();

}


