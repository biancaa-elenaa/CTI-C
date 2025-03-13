#include <stdio.h>
#include <stdlib.h>

typedef enum StackCodes{Q_OK, Q_EMPTY,Q_FULL} OpCode_t;

typedef unsigned Element_t;

typedef struct Queue{
    Element_t *data;
    int cap;
    int tail;
}Queue_t;

Queue_t makeQ(int cap)
{
    Queue_t q;
    q.tail=0;
    q.data=malloc(cap*sizeof(Element_t));
    if(q.data == NULL)
    {
        q.cap=0;
        return q;
    }
    q.cap=cap;
    return q;
}

OpCode_t enque(Queue_t *q,Element_t el) //adaugarea unui element
{
    if(q->tail<q->cap)
    {
        q->data[q->tail]=el;
        q->tail++;
        return Q_OK;
    }
    return Q_FULL;
}

OpCode_t dequeue(Queue_t* q, Element_t* result){
    if(q->tail > 0){
        *result=q->data[0];
        for(int i=0; i<q->tail-1; i++){
        	q->data[i]=q->data[i+1];
        }
        q->tail--;
        return Q_OK;
    }
    return Q_EMPTY;
}

int main()
{
    Queue_t q=makeQ(10);
    OpCode_t status;
    for(int i=1;i<=5;i++)
        if((status=enque(&q,100*i)) != Q_OK)
            printf("Eroare la adaugare la pasul %d %d\n",i,status);
        else
            printf("ok la %d\n",i);
    printf("%d\n",q.tail);
    Element_t value;
    for (int i=1; i<=7; i++){
        if ((status=dequeue(&q, &value))==Q_OK){
            printf("Am reusit sa scor %u\n", value);
        }
        else{
            printf("A aparut eroarea %d\n", status);
        }
    }
    return 0;
}