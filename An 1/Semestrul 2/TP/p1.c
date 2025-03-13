#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 4
#define ST_SZ 100

int st[ST_SZ]={0};

int eVoc(char s)
{
    if(strchr("aeiou",s) == 0)
        return 0; // nu e vocala
    return 1;
}

int eCons(char s)
{
    if((s>='a' && s<='z') && eVoc(s)==0)
        return 1;
    return 0;
}

int valid(int st[], int k,char *cuv)
{
    if(k>1)
    {
        if ( (eVoc(cuv[st[k]-1])==1 && eVoc(cuv[st[k-1]-1])==1) || (eCons(cuv[st[k]-1]) ==1 && eCons(cuv[st[k-1]-1]) ==1)) 
        {
            return 0;
        }
    }
    for (int i=1; i<k; i++){
        if (st[i]==st[k]){
            return 0;
        }
    }
    return 1;
}

int solutie(int st[], int k, int n)
{
    return (k==n);
}

void tipar(int st[], int n,char *cuv){

    for (int i=1; i<=n; i++)
    {
        printf("%c", cuv[st[i]-1]);
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

void back(int n,char *cuv){

	int k=1;
	st[k]=0;
	while (k>0){
		
	    if (succesor(st,k, n)){
		
	        if (valid(st, k,cuv)){
	            if (solutie(st, k, n)){
	                tipar(st, k,cuv);
	            }
	            else{
	               k=k+1;	
	               st[k]=0;
	            }
	        }
		}
		else{
			k--;	
		}
	}

}

int main(int argc, char* argv[])
{
    char* s=strdup(argv[1]);
    int n=strlen(s);
    int voc=0,cons=0;
    for(int i=0; i<n;i++)
    {
        if(eVoc(s[i]))
            voc++;
        else
            cons++;
    }
    if(abs(voc-cons)>1)
        printf("Imposibil\n");
    else
        back(n,s);

    return 0;
}
