#PART 1:

Explanation:

The code initializes the user button and user LED pins as input and output respectively. It then enters an infinite loop that constantly checks the state of the user button. If the button is pressed, the button_press_count variable is incremented by one. If button_press_count equals 3, the LED blinks twice with 100 ms on-off times. If it equals 7, the LED blinks thrice with 300 ms on-off times. After the LED blinks, button_press_count is reset to 0 to start the process again.

Observation:

This code does not implement any switch bouncing precautions, which means that the code may not work properly when the button is pressed due to switch bouncing. Switch bouncing occurs when the electrical contacts of a switch make and break contact rapidly before settling into a stable state, resulting in multiple transitions that may be detected as multiple button presses. To avoid switch bouncing, a debounce algorithm can be implemented. This algorithm waits for a stable state of the button before detecting a button press. There are various debounce algorithms available, such as the simple delay-based debounce and the more advanced state-machine-based debounce. In addition, the code can be improved by using interrupts instead of constantly checking the state of the button in a loop. This would make the code more efficient and less prone to missing button presses.



PART 2:

Explanation: 

The updated code for Part 2 implements switch bouncing precautions by adding a debounce delay to 
avoid multiple button presses due to switch bouncing. In this implementation, we have used a simple 
delay-based debounce algorithm. 
The debounce delay is a variable that defines the duration of the delay required to wait for the button 
to settle into a stable state before detecting a button press. In this implementation, we have set the 
debounce delay to 50 milliseconds. 
The code checks the state of the button using the HAL_GPIO_ReadPin function in STM32CubeIDE and 
DigitalIn object in Mbed Studio. If the button is pressed and the time elapsed since the last button 
press is greater than the debounce delay, the code detects a button press and increments the 
button_press_count variable. 
If button_press_count is equal to 3, the LED blinks twice with a 100-millisecond on-off time. If 
button_press_count is equal to 7, the LED blinks thrice with a 300-millisecond on-off time. The 
HAL_GPIO_WritePin function in STM32CubeIDE and DigitalOut object in Mbed Studio are used to 
control the state of the LED, and the HAL_Delay function in STM32CubeIDE and ThisThread::sleep_for 
function in Mbed Studio are used to introduce the delay between LED state changes. 
 
Observations: 

With the switch bouncing precautions added to the code, the button presses are detected accurately, 
and the LED blinks according to the specified patterns. The debounce delay used in this 
implementation is simple and effective in avoiding multiple button presses due to switch bouncing. 
However, more advanced debounce algorithms may be required for applications that require faster 
button response times or have more complex button interactions.
