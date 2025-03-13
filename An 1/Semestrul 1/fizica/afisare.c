#include <stdint.h>
#include <stdio.h>

void printb(uint32_t n)
{
  uint32_t mask= 1 << 31;
  for(int i = 0; i < 32; i++)
    {
      if((n & mask) == 0)
	{
	  printf ("0");
	}
      else
	{
	  printf("1");
	}
      mask= mask >> 1;
    }
  printf("\n");
}

int main()
{
  printb(5);
  return 0;
}
