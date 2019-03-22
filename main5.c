#include "lm4f120h5qr.h"          // To use the defined marcos in lm4f120h5qr.h, ow i had to define macros in .c

int main()
{
  SYSCTL_RCGCGPIO_R = 0x20U;     // Clock gating register for GPIOF
  GPIO_PORTF_DIR_R     = 0x0EU;  // Data direction register of PORTF
  GPIO_PORTF_DEN_R   = 0x0EU;    // So enable register, not much sure about it
  
  

  while(1)     
  {
    int volatile counter = 0;   // Why volatile and not int? proccessor skips the loop instructions in the machine code when the optimiztion settings
                                // are high because the final value of the var counter is overwritten. In overwritten and erasing cases, compiler 
                                // ignores the loops thinking they are irrelavant. 
    
    GPIO_PORTF_DATA_R  = 0x02U;
    while(counter < 1000)
    {
     ++counter; 
    }
    
    GPIO_PORTF_DATA_R  = 0x00U;
    counter = 0;
    
    while(counter < 1000)
    {
    ++counter; 
    }
    
  }
 
  return 0;             //Great JOB!
}
