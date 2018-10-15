


 
 int trigPin = 2;
 int echoPin = 3;
 int enA=10;
 int in1=9;
 int in2=8;
 int enB=6;
 int in3=5;
 int in4=4;
 int state;
 int oldState;
 int proximite;
 int compteur;
long lecture;
long distance;
int led=11;
int allume;

void setup() {

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW); 
  pinMode(echoPin, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
   state=1;
  //0=reculer
  //1=normal
  
  proximite=0;
  //oldstate=-1: Etat initial
  oldState=-1;
  compteur=0;
  delay (3000);
}

void marche(){
  digitalWrite(led, HIGH);
 // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 250);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 250);
}



void stop1(){
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

void reculer(){
    
  //turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set speed
  analogWrite(enA, 255);
  // turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set speedc
  analogWrite(enB, 0);
  state=0;
  allume=0;
  
}

void loop() {
  if(oldState==-1){
   
    marche();
  }
  
  oldState=state;
 
   if(proximite==1){
    stop1();
    delay(100);
    reculer();
    proximite=0;
  }

 if(state==0){
  Serial.println("test");
  if(compteur %100==0){ 
    if(allume == 1){
      digitalWrite(led, LOW);
      allume=0;
      }
      
      else {
        
        digitalWrite(led, HIGH);
        allume=1;
    }
  }  
  
    if(compteur>=500){
        stop1();
        delay(100);
        compteur=0;
        state=1;
        marche();
    }
    else {
        compteur++;
       // Led ou alarme
    }
 }

 if(state==2){
  Serial.println("je tourne ");
  if(compteur>=500){
        stop1();
        delay(100);
        compteur=0;
        state=1;
        marche();
    }
    else {
        compteur++;
       // Led ou alarme
    }
 }

 

  if(state==1){
  
    // Mesure de la distance
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    //Calcul du temps
    lecture= pulseIn(echoPin, HIGH);
    distance = lecture/58;

    //Ecriture sur le port serial
    Serial.print("Distance: "); 
    Serial.println(distance); 
    delay(1000);

  
    if(distance<=40){
        proximite=1;   
     }
    }
  }
  


 


