#include <stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define CHUNK 100

int main()
{
  int x,i=0;
  int *v=NULL;
  int size=CHUNK;
  v=malloc(size*sizeof(int));
  while(scanf("%d",&x) == 1)
    {
      *(v+i)=x;
      i++;
      if(i%CHUNK==0)
	{
	  size=size+CHUNK;
	  v=realloc(v,size*sizeof(int)); 
	}	
    }
  size=i;
  for(int i=0;i<size;i++)
    if((*(v+i))%2 ==0)
      printf("%d ",*(v+i));
  free(v);
  return 0;
}
