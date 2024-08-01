#include "mbed.h" 
 
AnalogIn potentiometer(A5); 
DigitalOut led1(D4); 
DigitalOut led2(D5); 
 
int main() { 
    while(1) { 
        float voltage = potentiometer.read() * 3.3; 
        printf("Voltage: %.4fV\n", voltage); 
 
        if (voltage < 1.6) { 
            led1 = 1; 
            led2 = 0; 
        }  
         
        else { 
            led1 = 0; 
            led2 = 1; 
        } 
 
        thread_sleep_for(100); 
    } 
}
