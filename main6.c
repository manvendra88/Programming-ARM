#include "lm4f120h5qr.h"          // To use the defined marcos in lm4f120h5qr.h, ow i had to define macros in .c

#define LED_RED (1U << 1)
#define LED_BLUE (1U << 2)
#define LED_GREEN (1U << 3)
int main()
{
  
 /* unsigned int a = 0x5A5A5A5A;
  unsigned int b = 0xDEADBEDD;
  unsigned int c ;
  
  c = a | b;                       // This code was meant to understand how bit wise operators in C work                     
  c = a & b;                       
  c = a ^ b;
  c = ~b;
  c = b >> 3;                      // Right shift divides  the first operand with 2^(second operand)
  c = b << 3;                      // Left shifts multiplies the first operand with 2^(first operand)
  
  int x = 000000;
  int y = 000000;
  int z;
  
  z = x >> 3;
  z = y << 3;
  */
  
  SYSCTL_RCGCGPIO_R    = (1U << 5);                         // Clock gating register for GPIOF
  GPIO_PORTF_DIR_R     = (LED_RED | LED_BLUE | LED_GREEN);  // Data direction register of PORTF should be high for 1,2,3
  GPIO_PORTF_DEN_R     = (LED_RED | LED_BLUE | LED_GREEN);  // So enable register, not much sure about it to be high for 1,2,3
  
  GPIO_PORTF_DATA_R    |= LED_BLUE ;                         // GPIO_PORTF_DATA_R = GPIO_PORTF_DATA_R | LED_BLUE

  while(1)     
  {
    int volatile counter = 0;   // Why volatile and not int? proccessor skips the loop instructions in the machine code when the optimiztion settings
                                // are high because the final value of the var counter is overwritten. In overwritten and erasing cases, compiler 
                                // ignores the loops thinking they are irrelavant. 
    
    GPIO_PORTF_DATA_R  |= LED_RED ;     //Embedded Idiom for setting a bit
    
    while(counter < 1000)
    {
     ++counter; 
    }
    
    GPIO_PORTF_DATA_R  &= ~(LED_RED);   // Embedded Idiom for clearing a bit
    counter = 0;
    
    while(counter < 1000)
    {
    ++counter; 
    }
    
  }
 
  return 0;             //Great JOB!
}
