 int counter = 0 ;
int main()
{
  int *p_int;           //Declaring a variable named p_int that stores the value of the address of integer type variables 
  p_int = &counter;     // & helps getting the address of any variable
  while(*p_int<21)     
  {
    ++(*p_int);
  }
  p_int = (int*)0x20000002U; // Assiging a random unsigned address value to the pointer variable
  *p_int = 0xDEADBEDD;      // Assiging an integer value to that address
  return 0;
}
