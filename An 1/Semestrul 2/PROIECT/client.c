#include <stdio.h>
#include "proiect.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10
#define LOWER_LIMIT 1
#define UPPER_LIMIT 100

int main()
{
    srand(time(0));
    
    //Aplicatia 3.1
    int *array1=NULL;
    array1=makeRandArray(SIZE);
    print_array(array1,SIZE);
    printf("--------------\n");
    free(array1);

    //Aplicatia 3.2
    int *array2=NULL;
    array2=makeRandLimitArray(SIZE,LOWER_LIMIT,UPPER_LIMIT);
    print_array(array2,SIZE);
    printf("--------------\n");
    free(array2);

    //Aplicatia 3.3
    int *array3=NULL;
    array3=makeRandFlexiArray(SIZE,getNewElem_asc);
    print_array(array3,SIZE);
    printf("--------------\n");
    free(array3);
    
    double *gauss=distributia_Gauss(100,0,1);
    print_double_array_csv(gauss,100,"gauss.csv");
    
    int *poisson=distributia_Poisson(100,2);
    print_array_csv(poisson,100,"poisson.csv");
    
    free(gauss);
    free(poisson);
    
    
    return 0;
}