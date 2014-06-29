//pins
#define PIN_ZC_SENSE 2
#define PIN_SSR_ENABLE 0
#define PIN_PWM_IN 3

//zero cross sensing... this works for 60hz
#define MAX_DELAY 7300     //max delay possible before voltage disappears
#define OFF_THRESHOLD 7200 //dimmest before turning it completely off
#define ON_THRESHOLD 1100 //lightest before turning it completely on
#define MIN_DELAY 1000     //min delay possible before output equals input
#define ULONG_MAX 4294967295
volatile unsigned long turnOnAt = ULONG_MAX;  
int currentDelay = MIN_DELAY;

//averaging variables
#define SAMPLECOUNT 16
int readings[SAMPLECOUNT];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int avg = 0;

void setup(){
 pinMode(PIN_SSR_ENABLE, OUTPUT);
 pinMode(PIN_ZC_SENSE, INPUT);
 attachInterrupt(0,zc,RISING); 
 digitalWrite(PIN_SSR_ENABLE, LOW);
}

void loop(){
  if(micros() >= turnOnAt){
    if(currentDelay < OFF_THRESHOLD) //if lower than the off threshhold, don't bother turning it on
      digitalWrite(PIN_SSR_ENABLE, HIGH);

    delayMicroseconds(50);
    if(currentDelay > ON_THRESHOLD) //if higher than the on threshold, don't bother turning it off
      digitalWrite(PIN_SSR_ENABLE, LOW);
    turnOnAt = ULONG_MAX;
  }
  else
  {
    total-= readings[index]; 
    readings[index] = analogRead(PIN_PWM_IN);     
  
    total+=readings[index];          
    index++;                        
  
    if (index >= SAMPLECOUNT)              
      index = 0;                          

    currentDelay = map(total/SAMPLECOUNT, 0, 1023, MAX_DELAY, MIN_DELAY);
    delayMicroseconds(750);
  }
}

void zc(){
  turnOnAt = micros() + currentDelay; //currentDelay;
}
