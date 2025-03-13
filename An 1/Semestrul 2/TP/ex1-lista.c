#include <stdio.h>
#include <stdlib.h>

typedef unsigned Payload_t;

typedef struct Nod{
    Payload_t info;
    struct Nod *urm;
}Nod_t;

typedef Nod_t* Lista_t;

Lista_t makeLista()
{
    return NULL;
}

Nod_t* makeNod(Payload_t info){
    Nod_t* nod=malloc(sizeof(Nod_t));
    if (!nod){
        return NULL;
    } 
    nod->info=info;
    nod->urm=NULL;
    return nod;
}


Lista_t  addback(Lista_t L,Nod_t *c)
{
    if(L==NULL)
    {
        return c;
    }
    else
    {
        Nod_t * iterator = L;
        while(iterator->urm != NULL)
            iterator = iterator->urm;
        iterator -> urm = c;
        return L;
    } 
}

Lista_t makeArrayLista(Payload_t *v,int n)
{
    Lista_t L=makeLista();
    for(int i=0;i<n;i++)
    {
        L=addback(L,makeNod(v[i]));
    }
    return L;
}

void printLista(Lista_t L){
    for (Nod_t*c =L; c!=NULL; c=c->urm){
        printf("%u, ", c->info);
    }
    printf("\n");
}

int main()
{
    Lista_t L=makeLista();
    int n=6;
    Payload_t v[7];
    for(int i=0;i<n;i++)
        v[i]=i*2;
    L=makeArrayLista(v,6);
    printLista(L);
    return 0;
}