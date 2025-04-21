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
    qp -> front =0;
    qp -> rear=0;
}

void enQue(Que *qp, int v)
{
    if(qp->rear==SIZE)
    {  printf("Queue Overflow\n");
        return;
    }

    qp->item[qp->rear]=v;
    qp->rear = qp->rear+1;
}

int deQue(Que *qp)
{
    if(qp->rear==qp->front)
    {
        return -99999;
    }

    int v = qp->item[qp->front];
    qp->front = qp->front+1;
    return v;
}

int main()
{
    Que q;
    initQue(&q);
    enQue(&q,5);
    enQue(&q,35);
    enQue(&q,54);
    printf("%d \n",deQue(&q));
    printf("%d \n",deQue(&q));
}
    

