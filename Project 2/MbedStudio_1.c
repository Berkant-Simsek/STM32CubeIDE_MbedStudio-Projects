#include "mbed.h" 
#include "chrono" 
#include <cstdint> 
#include <cstdio> 
InterruptIn button(BUTTON1); 
DigitalOut led1(LED1); 
DigitalOut led2(PB_5); 
volatile int counter = 0; 
uint32_t elapsedTime; 
Timer timer; 
void buttonRise(){ 
counter++; 
} 
int main() { 
led1 = 1; 
led2 = 1; 
button.rise(&buttonRise); 
t
 imer.start(); 
while(1) { 
elapsedTime = 
chrono::duration_cast<chrono::milliseconds>(timer.elapsed_time()).count(); 
if (elapsedTime > 2000) { 
printf("Timer: %d\n",elapsedTime); 
t
 imer.reset(); 
            if (counter == 3) { 
                printf("3 kere basildi\n"); 
                 
                for (int i = 0; i < 2; i++) { 
                    led1 = !led1; 
                    thread_sleep_for(500); 
                    led1 = !led1; 
                    thread_sleep_for(500); 
                } 
                counter = 0; 
            }  
 
            else if (counter == 5) { 
                printf("5 kere basildi\n"); 
 
                for (int i = 0; i < 4; i++) { 
                    led2 = !led2; 
                    thread_sleep_for(500); 
                    led2 = !led2; 
                    thread_sleep_for(500); 
                } 
                counter = 0; 
            } 
            counter = 0; 
        } 
 
        else { 
            counter = 0; 
        } 
    } 
} 
