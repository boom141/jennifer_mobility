 

#define A1 9
#define A2 8
#define B1 7
#define B2 6

const int TrigPin = 11;
const int EchoPin = 12;

float Calculated_Distance = 0;
int input_action = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);       //the trigger pin will output pulses of electricity
  pinMode(EchoPin, INPUT); 
  
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(B1,OUTPUT);
  pinMode(B2,OUTPUT);

  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(B1,LOW);
  digitalWrite(B2,LOW);
  
}

void loop() {

  Calculated_Distance = Get_Distance();
  Serial.print(Calculated_Distance);
  Serial.println("in");
  
////  Serial.println("Enter Action: ");
//  while (Serial.available()==0){}             // wait for user input
    input_action = Serial.parseInt();
//
//     switch(input_action){
//      case 1:
//        forward();
//      break;
//      case 2:
//        backward();
//      break;
//      case 3:
//        rotate();
//      break;
//      case 4:
//        standby();
//      break;
//     }
}

void forward(){
  analogWrite(A1,255);
  analogWrite(A2,0);
  analogWrite(B1,255);
  analogWrite(B2,0);
}
void backward(){
  analogWrite(A1,0);
  analogWrite(A2,255);
  analogWrite(B1,0);
  analogWrite(B2,255);
}
void rotate(){
  analogWrite(A1,255);
  analogWrite(A2,0);
  analogWrite(B1,0);
  analogWrite(B2,255);
}
void standby(){
  digitalWrite(A1,LOW);
  digitalWrite(A2,LOW);
  digitalWrite(B1,LOW);
  digitalWrite(B2,LOW);
}

float Get_Distance()
{ 
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object   
  float calculatedDistance;         //variable to store the distance calculated from the echo time

  //send out an ultrasonic pulse that's 10ms long   
  digitalWrite(TrigPin, HIGH);   
  delayMicroseconds(10);   
  digitalWrite(TrigPin, LOW);

  echoTime = pulseIn(EchoPin, HIGH);      //use the pulsein command to see how long it takes for the
  //pulse to bounce back to the sensor

  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)

  return calculatedDistance;              //send back the distance that was calculated
}
