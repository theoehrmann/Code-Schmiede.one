//LEDs
const byte red1 = 2;
const byte red2 = 3;
const byte red3 = 4;
const byte red4 = 5;

//Button
int inPin = 6;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

//Motor
#define ENABLE 12
#define DIRA 10
#define DIRB 11
#define ENABLE2 9
#define DIRA2 7
#define DIRB2 8

//Counter
#include <TimerOne.h>
int a = 38;
int b = 30;
int c = 35;
int d = 37; //decimal 
int e = 41;
int f = 36;
int g = 33;
int h = 39; 
int d1 = 40; 
int d2 = 34;
int d3 = 32;
int d4 = 31;
long m = 0; 
int n = 100;
int del = 5;  
int count = 0; 

//ISR
//volatile int output = HIGH;                      
int stopDC = 25  ;
int val2 = 0;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(red3, OUTPUT);
  pinMode(red4, OUTPUT);
  
  //Button
  pinMode(inPin, INPUT);    // declare pushbutton as input
  
  //Motor
    //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(ENABLE2,OUTPUT);
  pinMode(DIRA2,OUTPUT);
  pinMode(DIRB2,OUTPUT);

  //Counter
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
  Timer1.initialize(100000); 
  Timer1.attachInterrupt(Stopwatch);

  //ISR            
  //attachInterrupt(digitalPinToInterrupt(20), stopMotor, RISING);
  pinMode(stopDC, INPUT);

  Serial.begin(9600);
}



void DigitP(int n) 
{
  digitalWrite(d1, HIGH);
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);

  switch(n)
  {
    case 0: 
    digitalWrite(d1, LOW); 
    break;
    case 1: 
    digitalWrite(d2, LOW); 
    break;
    case 2: 
    digitalWrite(d3, LOW);
    break;
    default: 
    digitalWrite(d4, LOW); 
    break;
  }
}

void NumberP(int n)
{
  switch(n)
  {
    default: 
    Numberzero(); 
    break;
    case 1: 
    Numberone(); 
    break;
    case 2: 
    Numbertwo(); 
    break;
    case 3: 
    Numberthree(); 
    break;
    case 4: 
    Numberfour(); 
    break;
    case 5: 
    Numberfive(); 
    break;
    case 6: 
    Numbersix(); 
    break;
    case 7: 
    Numberseven(); 
    break;
    case 8: 
    Numbereight(); 
    break;
    case 9: 
    Numbernine(); 
    break;
  }
} 

//The same code as 7 segment display, used to create each number by lighting up sections of each digit. 

void clearLEDs() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(h, LOW);
}

void Numberzero()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void Numberone() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void Numbertwo()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void Numberthree()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void Numberfour() 
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Numberfive() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Numbersix() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Numberseven() 
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void Numbereight()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void Numbernine()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

//code to add every second to create the stopwatch effect. 

void Stopwatch()
{
  count ++;
  if(count == 10)
  {
    count = 0;
    m++;
    if(m == 10000)
    {
      m = 0;
    }
  }
}


void loop() {
  val = digitalRead(inPin);  // read input value
  if (val == HIGH) {        
    digitalWrite(red1, LOW);  // turn LED OFF
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
  } else {
    //run start led pattern
    digitalWrite(red1, HIGH);
    delay(500);
    digitalWrite(red1, LOW);
    delay(500);
    digitalWrite(red2, HIGH);
    delay(500);
    digitalWrite(red2, LOW);
    delay(500);
    digitalWrite(red3, HIGH);
    delay(500);
    digitalWrite(red3, LOW);
    delay(500);
    digitalWrite(red4, HIGH);
    delay(500);
    digitalWrite(red4, LOW);
    delay(500);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    delay(500);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
      
    //start motor
    digitalWrite(ENABLE, HIGH); // enable on
    digitalWrite(DIRA,HIGH); //one way
    digitalWrite(DIRB,LOW);
    digitalWrite(ENABLE2, HIGH); // enable on
    digitalWrite(DIRA2,HIGH); //one way
    digitalWrite(DIRB2,LOW);

    //start counter
    delay(3000);
    val2 = digitalRead(stopDC);  // read input value
    Serial.print(val2);
    while (val2 == HIGH) {
      clearLEDs();
      DigitP(0);
      NumberP((m/1000));
      delay(del);
    
      clearLEDs();
      DigitP(1);
      NumberP((m%1000)/100);
      delay(del);
    
      clearLEDs();
      DigitP(2);
      NumberP(m%100/10);
      delay(del);
    
      clearLEDs();
      DigitP(3);
      NumberP(m%10);
      delay(del);
      
      
      val2 = digitalRead(stopDC);
      Serial.print(val2);
   }

     
    digitalWrite(DIRA,LOW); //one way
    digitalWrite(DIRB,LOW);
    digitalWrite(DIRA2,LOW); //one way
    digitalWrite(DIRB2,LOW);
    
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    delay(200);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
    delay(200); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    delay(200);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
    delay(200);
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    delay(200);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
    delay(200);   
     digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);
    digitalWrite(red3, HIGH);
    digitalWrite(red4, HIGH);
    delay(200);
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(red3, LOW);
    digitalWrite(red4, LOW);
    delay(200);
    digitalWrite(red1, HIGH);       

    clearLEDs();
    DigitP(0);
    clearLEDs();
    DigitP(1);
    clearLEDs();
    DigitP(2);
    clearLEDs();
    DigitP(3);
    val = 0;
  }
} 
