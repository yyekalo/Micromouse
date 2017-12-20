
volatile unsigned int temp = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(A0,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),increment,RISING);
  attachInterrupt(digitalPinToInterrupt(3),increment,RISING);
  Serial.begin(9600);

  
delay(2000);
Serial.println("begin printing");
analogWrite(A0 ,128);
 
}

void loop() {

  //Serial.println(temp);
 


//  for(int x=0 ; x < 255 ; x++){
//
//    analogWrite(A0, x);
//    Serial.print("**********************");
//    Serial.println(x);
//    delay(500);
//  }

 Serial.println(temp);
  

}


void increment() {

if(temp >= 4294967296){

  return;
}
  temp++;
}

