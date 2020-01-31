const int digitalpin0 = 0;
const int digitalpin1 = 1;
const int digitalpin2 = 2;
const int digitalpin3 = 3;
const int digitalpin4 = 4;
const int digitalpin5 = 5;
const int digitalpin6 = 6;
const int digitalpin7 = 7;
const int interrupt = 8;
const int wr = 9;
const int rd = 10;
const int cs = 11;
float value;
float voltage_value;
float original_value;


void setup() {
  // put your setup code here, to run once:
pinMode(digitalpin0, INPUT);
pinMode(digitalpin1, INPUT);
pinMode(digitalpin2, INPUT);
pinMode(digitalpin3, INPUT);
pinMode(digitalpin4, INPUT);
pinMode(digitalpin5, INPUT);
pinMode(digitalpin6, INPUT);
pinMode(digitalpin7, INPUT);
pinMode(interrupt, INPUT);
pinMode(wr, OUTPUT);
pinMode(rd, OUTPUT);
pinmode(cs, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
intt = digitalRead(interrupt);  
if(intt == 0){
a0=analogRead(digitalpin0);
a1=analogRead(digitalpin1);
a2=analogRead(digitalpin2);
a3=analogRead(digitalpin3);
a4=analogRead(digitalpin4);
a5=analogRead(digitalpin5);
a6=analogRead(digitalpin6);
a7=analogRead(digitalpin7);
value=(a0*128)+(a1*64)+(a2*32)+(a3*16)+(a4*8)+*a5*4)+(a6*2)+(a7);
voltage_value = (value/5)*255;
original_value = (2*voltage_value) - 5;}

}
