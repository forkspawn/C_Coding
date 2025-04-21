#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct{
    int item[SIZE];
    int rear, front;
}Que;

void initQue(Que*);
void enQue(Que* ,int);
int deQue(Que*);

void initQue(Que *qp)
{
    qp -> front =SIZE-1;
    qp -> rear=SIZE-1;
}
void enQue(Que *qp, int v)
{
    if((qp->rear+1) % SIZE==qp->front)
    {  printf("Queue Overflow\n");
        return;
    }
    
    qp->rear =( qp->rear+1)%SIZE;
    qp->item[qp->rear]=v;
}

int deQue(Que *qp)
{
    if(qp->rear==qp->front)
    {
        return -99999;
    }

    qp->front =( qp->front+1) % SIZE;
    int v = qp->item[qp->front];
    return v;
}

int main()
{
    Que q;
    initQue(&q);
    enQue(&q,5);
    enQue(&q,35);
    enQue(&q,54);
