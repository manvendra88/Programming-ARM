int main()
{
  *((unsigned int *)0x400FE608U) = 0x20U;  // Derefrencing the pointer that stores the addresses of variables which are unsigned integer types
  *((unsigned int *)0x40025400U) = 0x0EU;  // Registers of ARM are Unsigned ints and their addresses are as shown and stored in a pointer
  *((unsigned int *)0x4002551CU) = 0x0EU;  // We have thus put outer * to dereference this pointer to assign value to the address of unsigned registers
  
  

  while(1)     
  {
    int counter = 0;
    
    *((unsigned int *)0x400253FCU) = 0x02U;
    while(counter < 1000)
    {
     ++counter; 
    }
    
    *((unsigned int *)0x400253FCU) = 0x00U;
    counter = 0;
    
    while(counter < 1000)
    {
    ++counter; 
    }
    
  }
 
  return 0;             //Great JOB!
}
