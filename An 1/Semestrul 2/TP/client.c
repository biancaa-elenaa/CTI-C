#include <stdio.h>
#include "hs_utils.h"

int main()
{
    printf("Este prim %d\n",estePrim(13));
    printf("Este palindrom? %d\n", ePalindrom(1551));
    int x=3;
    printf("Al %d-lea termen al sirului Fibbonaci este %d\n",x,getFibboTerm(x));
    return 0;
}