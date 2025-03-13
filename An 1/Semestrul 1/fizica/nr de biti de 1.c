#include <stdio.h>
#include <stdint.h>

int contor(uint32_t n)
{
  uint32_t mask= 1 << 31;
  int k=0;
  for(int i = 0; i < 32; i++)
    {
      if((n & mask) != 0)
	{
	  k++;
	}
      mask= mask >> 1;
    }
  return k;
}


int main()
{
  uint32_t n;
  int k=0;
  scanf("%X", &n);
  k=contor(n);
  printf("%d", k);
  return 0;
}
