/*

2. Algoritmul de sortare prin interclasare 

Implementati o functie cu antetul void mergeSort(int v[], unsigned stg, unsigned dr); 
care implementeaza algoritmul de sortare prin interclasare, prezentat in cadrul cursului din 
saptamana 7. Alternativ va puteti folosi de modelul de implementare disponibil 
la https://www.pbinfo.ro/articole/7667/sortarea-prin-interclasare . 

Determinati experimental dependenta timpului de executie de dimensiunea tabloului si 
incercati sa deduceti un ordin de complexitate. Comparati cu valoarea de referinta din 
literatura, O(n*log(n)) [cf. Knuth]

*/

#include <stdio.h>

int tmp[100];

void MergeSort(int v[], unsigned stg, unsigned dr)
{
    if(stg < dr)
    {
        int mijloc = (stg + dr)/2;
        MergeSort(v,stg,mijloc);
        MergeSort(v, mijloc + 1 , dr);
		//Interclasare
		int i = stg, j = mijloc + 1, k = 0;
		while( i <= mijloc && j <= dr )
			if( v[i] < v[j])
				tmp[++k] = v[i++];
			else
				tmp[++k] = v[j++];
		while(i <= mijloc)
			tmp[++k] = v[i++];
		while(j <= dr)
			tmp[++k] = v[j++];
		for(i = stg , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
    }
}

int main()
{
    int v[]={12,3,40,1,25,6,100};
    int n=sizeof(v)/sizeof(v[0]);
    MergeSort(v,0,n-1);
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
    }
    printf("\n");


    
    
    
}

