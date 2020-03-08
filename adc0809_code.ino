const int digitalpin0 = 0;
const int digitalpin1 = 1;
const int digitalpin2 = 2;
const int digitalpin3 = 3;
const int digitalpin4 = 4;
const int digitalpin5 = 5;
const int digitalpin6 = 6;
const int digitalpin7 = 7;
const int star_ale = 8;
const int clk = 9;
const int eo = 10;
const int out_en = 12;
float value;
float voltage_value;
float original_value;
int intt;
int a0, a1, a2, a3, a4, a5, a6, a7;
  // Timer 1 "A" output: OC1A
void setup ()
{
  
  // put your setup code here, to run once:
pinMode(digitalpin0, INPUT);
pinMode(digitalpin1, INPUT);
pinMode(digitalpin2, INPUT);
pinMode(digitalpin3, INPUT);
pinMode(digitalpin4, INPUT);
pinMode(digitalpin5, INPUT);
pinMode(digitalpin6, INPUT);
pinMode(digitalpin7, INPUT);
pinMode(eo, INPUT);
pinMode(clk, OUTPUT);
pinMode(out_en, OUTPUT);
pinMode(star_ale, OUTPUT);
pinMode(11, OUTPUT);
analogWrite(11,20);
TCCR1A = _BV(COM1A0);              //toggle OC1A on compare match
OCR1A = 1;                     //top value for counter
TCCR1B = _BV(WGM12) | _BV(CS12);   //CTC mode, prescaler clock/256
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
//Serial.print(clk);

digitalWrite(star_ale, HIGH);
delayMicroseconds(1);
digitalWrite(star_ale, LOW);
delayMicroseconds(5000);
intt = digitalRead(eo);  
//while(intt == LOW);
if(intt == HIGH){
digitalWrite(out_en, HIGH);
delayMicroseconds(70);
digitalWrite(out_en, LOW);
//delayMicroseconds(100);

//Serial.print(digitalRead(digitalpin0));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin1));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin2));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin3));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin4));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin5));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin6));
//Serial.print(' ');
//Serial.print(digitalRead(digitalpin7));
//Serial.print('\n');

if(digitalRead(digitalpin0))
a0 = 1;
else 
a0 = 0;
if(digitalRead(digitalpin1))
a1 = 1;
else 
a1 = 0;
if(digitalRead(digitalpin2))
a2 = 1;
else 
a2 = 0;
if(digitalRead(digitalpin3))
a3 = 1;
else 
a3 = 0;
if(digitalRead(digitalpin4))
a4 = 1;
else 
a4 = 0;
if(digitalRead(digitalpin5))
a5 = 1;
else 
a5 = 0;
if(digitalRead(digitalpin6))
a6 = 1;
else 
a6 = 0;
if(digitalRead(digitalpin7))
a7 = 1;
else 
a7 = 0;
value=(a7*256)+(a6*128)+(a5*64)+(a4*32)+(a3*16)+(a2*8)+(a1*4)+(a0*2);
Serial.println(value);
//voltage_value = (value/5)*255;
//original_value = (2*voltage_value) - 5;}
}
}

