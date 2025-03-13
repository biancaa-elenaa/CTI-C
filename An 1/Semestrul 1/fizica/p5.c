#include <stdio.h>
#include <stdint.h>

uint32_t invers(uint32_t n)
{
  uint32_t m=0;
  for(int i=0;i<32;i++)
    {
      m=m*2+n%2;
      n=n/2;
    }
  return m;
}
int main()
{
  uint32_t n=2;
  n=invers(n);
  printf("%X\n", n);
  return 0;
}
