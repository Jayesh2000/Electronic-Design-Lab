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
const int out_en = 11;
float value;
float voltage_value;
float original_value;
int intt;
int a0, a1, a2, a3, a4, a5, a6, a7;
boolean toggle0 = 0;
boolean toggle1 = 0;
boolean toggle2 = 0;
int start_counter = 0, start_pulse = 50;
int end_pulse = 40;
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
//pinMode(e0, INPUT);
pinMode(8, OUTPUT); //timer 0
pinMode(9, OUTPUT); //timer 2
pinMode(13, OUTPUT); //timer 1



cli();
TCCR0A = 0;// set entire TCCR0A register to 0
TCCR0B = 0;// same for TCCR0B
TCNT0  = 0;//initialize counter value to 0
  // set compare match register for 500khz increments
OCR0A = 0;// = (16*10^6) / 500000 - 1 (must be <256)
  // turn on CTC mode
TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 1 prescaler
TCCR0B |= (0 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
TIMSK0 |= (1 << OCIE0A);
//analogWrite(11,20);
  TCNT1 = 0;
  TCCR1A= 0;
  TCCR1B= 7;
  TCCR1B |= (1 << WGM12);
  sei();
Serial.begin(115200);
}

ISR(TIMER0_COMPA_vect){//timer0 interrupt 2kHz toggles pin 8
//generates pulse wave of frequency 2kHz/2 = 1kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle0){
    digitalWrite(8,HIGH);
    if(toggle1 == 1)
    {
      digitalWrite(13, HIGH);
      toggle1 = 0;
    }
    toggle0 = 0;
  }
  else{
    digitalWrite(8,LOW);
    toggle0 = 1;
  }
  if (start_counter == start_pulse)
  {digitalWrite(13, HIGH);
   start_counter = 0;
  }
  else if (start_counter == end_pulse)
  {
    digitalWrite(9, HIGH);
    ++start_counter;
     
  }
 else if (start_counter == 0)
  {digitalWrite(13, LOW);
   ++start_counter;
  }
 else
  {start_counter++;
  digitalWrite(9, LOW);
  }

  
}

ISR(TIMER1_COMPA_vect){//timer1 interrupt 1Hz toggles pin 13 (LED)
//generates pulse wave of frequency 1Hz/2 = 0.5kHz (takes two cycles for full wave- toggle high then toggle low)

  
}
  
ISR(TIMER2_COMPA_vect){//timer1 interrupt 8kHz toggles pin 9
//generates pulse wave of frequency 8kHz/2 = 4kHz (takes two cycles for full wave- toggle high then toggle low)
  if (toggle2){
    digitalWrite(9,HIGH);
    toggle2 = 0;
  }
  else{
    digitalWrite(9,LOW);
    toggle2 = 1;
  }
}

void loop() {
 
}

