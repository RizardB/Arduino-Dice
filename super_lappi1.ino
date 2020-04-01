int ledPins[]={13,12,11,10,9,8,7};
int i=0;
int button=2;
int delayRandom=50;
int delayTime=1000;
int diceNumbers[6][7]={
  {0,0,0,10,0,0,0},
  {13,0,0,0,0,0,7},
  {13,0,0,10,0,0,7},
  {13,0,11,0,9,0,7},
  {13,0,11,10,9,0,7},
  {13,12,11,0,9,8,7}
};
void setup(){
  for(i=0;i<7;i++){
    pinMode(ledPins[i], OUTPUT);
    Serial.begin(9600);
  }
  pinMode(button,INPUT);
}
void loop(){
  /*for(i=0;i<7;i++){
    digitalWrite(ledPins[i], HIGH);
  }*/
  if(digitalRead(button)==HIGH){
  	randomAnimation();
  }
}
void randomAnimation(){
  for(int j=0;j<5;j++){
  	int randomNumber=random(7,14);
    digitalWrite(randomNumber,HIGH);
    delay(delayRandom);
    digitalWrite(randomNumber,LOW);
  }
  delay(delayTime);
  randomNumber();
}
void randomNumber(){
  int randomNumber=random(1,7);
  Serial.println(randomNumber);
  for(int j=0;j<=6;j++){
    if(diceNumbers[randomNumber-1][j]>0){
      digitalWrite(diceNumbers[randomNumber-1][j],HIGH);
      //Serial.println(diceNumbers[randomNumber-1][j]);
    }
  }
  delay(delayTime);
  clearAll();
}
void clearAll(){
  for(i=0;i<7;i++){
    digitalWrite(ledPins[i], LOW);
  }
}
