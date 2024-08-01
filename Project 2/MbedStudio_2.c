#include "mbed.h" 
InterruptIn button1(BUTTON1); 
InterruptIn button2(PB_5); 
DigitalOut led1(LED1); 
DigitalOut led2(PA_0); 
DigitalOut led3(PA_1); 
Timeout timeout; 
Ticker ticker; 
volatile int counter1 = 0; 
volatile int counter2 = 0; 

void updateLed3() { 
  led3 = !led3; 
} 
void button1Pressed() { 
  counter1++; 
} 
void button2Pressed() { 
  counter2++; 
} 

void check() { 
  if (counter1 > 3) { 
    led1 = !led1; 
  } 
  if (counter2 > 5) { 
    led2 = !led2; 
  } 
  counter1 = 0; 
  counter2 = 0; 
  timeout.attach(&check, 10000ms); 
} 

int main() { 
  button1.mode(PullUp); 
  button2.mode(PullUp); 
  button1.fall(&button1Pressed); 
  button2.fall(&button2Pressed); 
  led1 = 0; 
  led2 = 0; 
  led3 = 0; 
  timeout.attach(&check, 10000ms); 
  ticker.attach(&updateLed3, 20000ms); 
  while(1); 
}
