#include "main.h" 
int main(void) 
{ 
/* Initialize HAL */ 
HAL_Init(); 
/* Initialize GPIOs */ 
MX_GPIO_Init(); 
int button_press_count = 0; 
uint32_t last_button_press_time = 0; 
uint32_t debounce_delay = 50; 
while (1) 
{ 
uint32_t current_time = HAL_GetTick(); 
if (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin) == GPIO_PIN_RESET && current_time - last_button_press_time > debounce_delay) 
    { 
      // Button is pressed 
      last_button_press_time = current_time; 
      button_press_count++; 
      if (button_press_count == 3) 
      { 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET); 
        HAL_Delay(100); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET); 
        HAL_Delay(100); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET); 
        HAL_Delay(100); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET); 
        button_press_count = 0; 
      } 
      else if (button_press_count == 7) 
      { 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET); 
        HAL_Delay(300); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET); 
        HAL_Delay(300); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET); 
        HAL_Delay(300); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET); 
        HAL_Delay(300); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_SET); 
        HAL_Delay(300); 
        HAL_GPIO_WritePin(USER_LED_GPIO_Port, USER_LED_Pin, GPIO_PIN_RESET); 
        button_press_count = 0; 
      } 
    } 
  } 
} 
