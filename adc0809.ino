const int digitalpin0 = 0;
const int digitalpin1 = 1;
const int digitalpin2 = 2;
const int digitalpin3 = 3;
const int digitalpin4 = 4;
const int digitalpin5 = 5;
const int digitalpin6 = 6;
const int digitalpin7 = 7;
const int eoc = 9;
const int wr = 10;
const int start = 8;
const int cs = 11;
float value;
float voltage_value;
float original_value;
int start_count = 0, wr_flag = 0;
int start_limit = 100, wr_limit = 20, wr_done;
//storage variables
boolean toggle0 = 0;
boolean toggle1 = 0;
boolean toggle2 = 0;
boolean wr_count = 0, wr_ready = 0;
boolean a0, a1, a2, a3, a4, a5, a6, a7;

void setup(){
  pinMode(digitalpin0, INPUT);
pinMode(digitalpin1, INPUT);
pinMode(digitalpin2, INPUT);
pinMode(digitalpin3, INPUT);
pinMode(digitalpin4, INPUT);
pinMode(digitalpin5, INPUT);
pinMode(digitalpin6, INPUT);
pinMode(digitalpin7, INPUT);
pinMode(eoc, INPUT);
pinMode(wr, OUTPUT);
pinMode(start, OUTPUT);
pinMode(cs, OUTPUT);
Serial.begin(115200);

cli();//stop interrupts

//set timer0 interrupt at 2kHz
  TCCR0A = 0;// set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 2khz increments
  OCR0A = 199;// = (16*10^6) / (1M*16) - 1 (must be <256)  -- 5k output
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler
  TCCR0B |= (1 << CS01) | (0 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);

////set timer1 interrupt at 1Hz
//  TCCR1A = 0;// set entire TCCR1A register to 0
//  TCCR1B = 0;// same for TCCR1B
//  TCNT1  = 0;//initialize counter value to 0
//  // set compare match register for 1hz increments
//  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
//  // turn on CTC mode
//  TCCR1B |= (1 << WGM12);
//  // Set CS12 and CS10 bits for 1024 prescaler
//  TCCR1B |= (1 << CS12) | (1 << CS10);  
//  // enable timer compare interrupt
//  TIMSK1 |= (1 << OCIE1A);
//
////set timer2 interrupt at 8kHz
//  TCCR2A = 0;// set entire TCCR2A register to 0
//  TCCR2B = 0;// same for TCCR2B
//  TCNT2  = 0;//initialize counter value to 0
//  // set compare match register for 8khz increments
//  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
//  // turn on CTC mode
//  TCCR2A |= (1 << WGM21);
//  // Set CS21 bit for 8 prescaler
//  TCCR2B |= (1 << CS21);   
//  // enable timer compare interrupt
//  TIMSK2 |= (1 << OCIE2A);


sei();//allow interrupts

}//end setup

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle0){
    digitalWrite(cs,HIGH);
    toggle0 = 0;
    if(start_count == start_limit)
    {digitalWrite(start, HIGH);
     start_count = 0;
    }
    if(digitalRead(eoc) == LOW)
     {wr_done = 0;
      wr_flag = 0;
     }
    if(digitalRead(eoc) == HIGH && wr_flag != wr_limit && wr_done == 0)
    { digitalWrite(wr, HIGH);
      wr_ready = 1;
      ++wr_flag;      
    }
    else
     { wr_done = 1;
      digitalWrite(wr, LOW);
     }
  }
  else{
    digitalWrite(cs,LOW);
    toggle0 = 1;
    if(start_count == 0)
     digitalWrite(start, LOW);
    ++start_count;
   
  }
}
//
//ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
////generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)
//  if (toggle1){
//    digitalWrite(13,HIGH);
//    toggle1 = 0;
//  }
//  else{
//    digitalWrite(13,LOW);
//    toggle1 = 1;
//  }
//}
//  
//ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz toggles pin 9
////generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
//  if (toggle2){
//    digitalWrite(9,HIGH);
//    toggle2 = 0;
//  }
//  else{
//    digitalWrite(9,LOW);
//    toggle2 = 1;
//  }
//}
void loop() {
  // put your main code here, to run repeatedly:
if(wr_ready == 1)
{
if(digitalRead(digitalpin0) == HIGH)
a0 = 1;
else
a0 = 0;

if(digitalRead(digitalpin1) == HIGH)
a1 = 1;
else
a1 = 0;


if(digitalRead(digitalpin2) == HIGH)
a2 = 1;
else
a2 = 0;


if(digitalRead(digitalpin3) == HIGH)
a3 = 1;
else
a3 = 0;


if(digitalRead(digitalpin4) == HIGH)
a4 = 1;
else
a4 = 0;


if(digitalRead(digitalpin5) == HIGH)
a5 = 1;
else
a5 = 0;


if(digitalRead(digitalpin6) == HIGH)
a6 = 1;
else
a6 = 0;


if(digitalRead(digitalpin7) == HIGH)
a7 = 1;
else
a7 = 0;


value=(a7*128)+(a6*64)+(a5*32)+(a4*16)+(a3*8)+(a2*4)+(a1*2)+(a0);
voltage_value = (value*2);
Serial.println(voltage_value);
wr_ready = 0;
}
}
