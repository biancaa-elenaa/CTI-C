#include <stdio.h>
#include <stdlib.h>
#define ST_SZ 100

int st[ST_SZ]={0};

int nr_to_vector(int nr[],int n)
{
    int i=0;

    while(n){
        nr[i++]=n%10;
        n=n/10;
    }

    return i;
}

int vector_to_nr(int st[],int count,int vec[])
{
    int n=0;

    for(int i=1;i<=count;i++)
        n=n*10+vec[st[i]-1];

    return n;
}

int valid(int st[], int k,int vec[])
{
    if(k==1 && vec[st[k]-1]==0)
        return 0;

    for (int i=1;i<k;i++)
        if(st[i] == st[k])
            return 0;

    return 1;
}

int solutie(int st[], int k, int count)
{
    return (k==count);
}

void tipar(int st[], int count,int vec[]){

    for (int i=1; i<=count; i++)
    {
        printf("%d", vec[st[i]-1]);
    }
    printf("\n");
}

int succesor(int st[], int k, int count){
	if (st[k]<count){
		st[k]++;
		return 1;
	}
	return 0;
}

int back(int count,int *vec){
    int sum=0;
	int k=1;
	st[k]=0;
	while (k>0){
		
	    if (succesor(st,k,count)){
		
	        if (valid(st, k,vec)){
	            if (solutie(st, k, count)){
	                //tipar(st,count,vec);
                    sum =sum + vector_to_nr(st,count,vec);
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
    return sum;

}

int main(int argc,char *argv[])
{
    int n=atoi(argv[1]);
    int vec[ST_SZ];

    int count = nr_to_vector(vec,n);

    int sum=back(count,vec);
    printf("%d\n",sum);  
    return 0;
}
