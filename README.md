# STM32CubeIDE_MbedStudio-Projects

## Project 1
Hardware: User button and user LED on the board will be used.
Software: 
- A. StmCube
- B. Keil Cloud / MbedStudio

Part 1: (no switch bouncing precaution added)
- Initially LED is off.
- After 3 button press LED will blink twice with 100 ms on-off times.
- After 7 button press LED will blink thrice with 300 ms on-off times.
- This procedure goes indefinitely.

Part 2: Repeat part1 by adding a delay to avoid switch bouncing. 

Report: Code listings for part1 and part2 – both in Stm and Keil Comments, explanations and observations.

## Project 2
Part 1:
- Usea single push button as an interrupt input, and two LEDs as outputs. 
- Initially both LEDs are on.
- Count button press in a definite time interval (e.g. 2s).
- If count is 3, LED1 blinks 2 times.
- If count is 5, LED2 blinks 4 times.
- This procedure goes indefinitely.

Part 2:
- Use3 LEDsand2 pushbuttons (as external interrupts (e.g. pins B13,B14).) will be used. 
- Initially both LEDs are off.
- Withina 10 second period;
  - If button 1 is pressed >3 times, led 1 toggles.
  - If button 2 is pressed >5 times, led 2 toggles.
  - Third LED can be used to indicate 20s period.
- This procedure goes indefinitely.

## Project 3
Part 1:
- Use a push button as interrupt input and two LEDs as outputs.
- Use a single ticker function. Ticker counts 1-2-3-4-5-1-2-3-4-5 indefinitely in a period of 1500 ms. Show this counting in serial output and toggle LED1 in every 1500 ms.

Part 2:
- Count button press within a 1500ms period. Show press count in serial output.

Part 3:
- If button press counter is greater than 3 within a 1500ms interval, LED2 turns off for 1 sec.   
- LED2 is initially on. Turn off period (1 sec) should be determined by a timeout function.

## Project 4
- 2 LEDs and1 adjustable resistor (potentiometer) will be used. 
- Potentiometer will be connected to an analog input.
- Read values (from potentiometer) will be fed through serial output.
- Take care of data representation.
- Led1 will turn on when read voltage values are less than 1.6 volts
- Led2 will turn on when read voltage values are more than 1.6 volts
- This procedure goes indefinitely.
