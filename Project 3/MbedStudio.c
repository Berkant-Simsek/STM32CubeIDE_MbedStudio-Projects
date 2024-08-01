#include "mbed.h" 
InterruptIn button(BUTTON1); 
DigitalOut led1(PB_5); 
DigitalOut led2(PB_4); 
volatile int counter_for_button = 0; 
volatile bool press = false; 
volatile int counter_for_ticker = 0; 
Ticker ticker; 
Timeout timeout; 

void change(){ 
  led2 = 1; 
} 

void tickerFunction() { 
  printf("Counter for ticker: %d\r\n", counter_for_ticker); 
  if (counter_for_ticker == 5) { 
    led1 = !led1; 
  } 
  counter_for_ticker = (counter_for_ticker % 5) + 1; 
  if (press) { 
    counter_for_button++; 
    printf("Counter for button: %d\r\n", counter_for_button); 
    press = false; 
  } 
  if (counter_for_button > 3) { 
    led2 = 0; 
    timeout.attach(&change, 1s); 
    counter_for_button = 0; 
  }   
} 

void buttonPressed() { 
  press = true; 
} 

int main() { 
  button.fall(&buttonPressed); 
  ticker.attach(&tickerFunction, 300ms); 
  led1=0; 
  led2=1; 
  while (1) { 
    thread_sleep_for(100); 
  } 
}
