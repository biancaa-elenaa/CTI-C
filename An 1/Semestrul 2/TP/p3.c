#include <stdio.h>
#include <stdlib.h>
#define ST_SZ 100

int st[ST_SZ]={0};

int valid(int st[], int k){
    if(k>1)
    {
        if(abs(st[k]-st[k-1])!=1)
            return 0;
    }
    return 1;
}

int solutie(int st[], int k, int n){
    if(k!=n)
        return 0; 
    if(st[n]!=0)
        return 0;
    if(st[1]==0)
        return 0;
    return 1;
}

void tipar(int st[], int k){
    for (int i=1; i<=k; i++)
    {
        printf("%d ", st[i]);
    }
    printf("\n");
}

int succesor(int st[], int k, int n){
	if (st[k]<n){
		st[k]++;
		return 1;
	}
	return 0;
}

void back(int n)
{
	int k=1;
	st[k]=0;
	while (k>0){
		
	    if (succesor(st,k, n)){
	        if (valid(st, k)){
	            if (solutie(st, k, n)){
                    printf("a");
	                tipar(st, k);
	            }
	            else{
	               k=k+1;	//trecem pe nivelul urmator;
	               st[k]=0;
	            }
	        }
		}
		else{
			k--;	//cobram pe nivelul anterior si continuam de la ultima valoare atinsa
		}
	}

}
int main(int argc, char* argv[])
{
    int n=atoi(argv[1]);
    back(n);
    return 0;
}
                                                                                                             