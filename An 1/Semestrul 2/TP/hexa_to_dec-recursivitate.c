#include <stdio.h>
#include <ctype.h>
#include <string.h>

int hexa_to_dec(char *nr, int index)
{
    if(index == -1)
        return 0;
    if(isdigit(nr[index]))
        return (nr[index] - '0') + 16 * hexa_to_dec(nr,index-1);
    else
        return (toupper(nr[index]) - 'A' + 10) +16 * hexa_to_dec(nr,index-1);
    
}

int main()
{
    char s[10]="1A6F";
   // printf("%d", strlen(s));

    printf("%d",hexa_to_dec(s,strlen(s)-1));
    return 0;
}