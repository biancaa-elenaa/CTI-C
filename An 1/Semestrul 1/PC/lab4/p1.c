#include <stdio.h>

void container(int lg,int lat,char c)
{
  for(int i=1;i<=lat;i++)
    {
      for(int j=1;j<=lg*2;j++)
      {
	if(i==1 || i==lat || j==1 || j==lg || j==lg*2 || j==lg+lg/2+1)
	  {
	    putchar(c);
	    printf(" ");
	  }
	else
	  printf("  ");
      }
      printf("\n");
    }
}
void etaj(int lg,int lat,char c)
{
  for(int i=1;i<=lat;i++)
    {
      for(int j=1;j<=lg;j++)
      {
	if(i==1 || j==1 || j==lg)
	  {
	    putchar(c);
	    printf(" ");
	  }
	else
	  printf("  ");
      }
      printf("\n");
    }
}
void acoperis(int lg,int inaltime)
{
  int jdr=lg/2+1;
  int jst=lg/2+1;
  for(int i=1;i<=inaltime;i++)
    {
      for(int j=1;j<=lg;j++)
	{
	  if(j==jdr)
	    printf("* ");
	  if(j==jst && i!=1)
	    printf("* ");
	  if((j!=jst) && (j!=jdr))
	    printf("  ");
	}
      jdr=jdr+1;
      jst=jst-1;
      printf("\n");
    }
}
void gradina(int lung)
{
  for(int i=1;i<=lung;i++)
    printf("# ");
  printf("\n");
}
void gard(int lung)
{
  for(int i=1;i<=lung;i++)
    printf("|-");
}
int main()
{
  acoperis(7,4);
  etaj(7,4,'@');
  container(7,4,'*');
  gradina(15);
  gard(15);
  return 0;
}
