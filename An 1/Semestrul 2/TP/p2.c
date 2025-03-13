##include <stdio.h>
#include <stdlib.h>
#define ST_SZ 100

int st[ST_SZ]={-1};

int valid(int st[], int k){
    if(k>1)
    {
        if(st[k]==1 && st[k-1]==1)
        return 0;
    }
    return 1;
}

int solutie(int st[], int k, int n){
    return (k==n);
}

void tipar(int st[], int k){
    for (int i=1; i<=k; i++){
        printf("%d ", st[i]);
    }
    printf("\n");
}

int succesor(int st[], int k, int n){
	if (st[k]<1){
		st[k]++;
		return 1;
	}
	return 0;
}

void back(int n){

	int k=1;
	st[k]=-1;
	while (k>0){
		
	    if (succesor(st,k, n)){
		
	        if (valid(st, k)){
	            if (solutie(st, k, n)){
	                tipar(st, k);
	            }
	            else{
	               k=k+1;	//trecem pe nivelul urmator;
	               st[k]=-1;
	            }
	        }
		}
		else{
			k--;	//cobram pe nivelul anterior si continuam de la ultima valoare atinsa
		}
	}

}

int main(void){
    back(3);
    return 0;
}
