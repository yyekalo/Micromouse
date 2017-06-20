void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0,OUTPUT);
  pinMode(A0,INPUT);

  

}

void loop() {
  // put your main code here, to run repeatedly:

   int current = analogRead(A0);
  digitalWrite(0,HIGH);
  delay(2);
  Serial.print(analogRead(A0));
  Serial.print(" ");
  Serial.println(analogRead(A0)-current);
  digitalWrite(0,LOW);
  delay(100);

}
