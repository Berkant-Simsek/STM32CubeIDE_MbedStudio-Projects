#include "mbed.h" 
DigitalIn button(USER_BUTTON); 
DigitalOut led(USER_LED); 
int main() 
{ 
  int button_press_count = 0; 
  while (true) 
  { 
    if (button == 0) 
    { 
      // Button is pressed 
      button_press_count++; 
      if (button_press_count == 3) 
      { 
        led = 1; 
        ThisThread::sleep_for(100); 
        led = 0; 
        ThisThread::sleep_for(100); 
        led = 1; 
        ThisThread::sleep_for(100); 
        led = 0; 
        button_press_count = 0; 
      } 
      else if (button_press_count == 7) 
      { 
        led = 1; 
        ThisThread::sleep_for(300); 
        led = 0; 
        ThisThread::sleep_for(300); 
        led = 1; 
        ThisThread::sleep_for(300); 
        led = 0; 
        ThisThread::sleep_for(300); 
        led = 1; 
        ThisThread::sleep_for(300); 
        led = 0; 
        button_press_count = 0; 
      } 
    } 
  } 
} 
