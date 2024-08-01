#include "mbed.h" 
DigitalIn button(USER_BUTTON); 
DigitalOut led(USER_LED); 
int main() 
{ 
  int button_press_count = 0; 
  uint32_t last_button_press_time = 0; 
  uint32_t debounce_delay = 50; 
  while (true) 
  { 
    uint32_t current_time = Kernel::get_ms(); 
    if (button == 0 && current_time - last_button_press_time > debounce_delay) 
    { 
      // Button is pressed 
      last_button_press_time = current_time; 
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
