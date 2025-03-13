#include <stdio.h>
#include <stdint.h>

uint16_t set(uint16_t n,int p)
{
  n= n | (1 << p);
  return n;
  
}
int main()
{
  uint16_t n;
  int p;
  scanf("%hX", &n);
  scanf("%d", &p);
  n=set(n,p);
  printf("%X\n", n);
  return 0;
}
