#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;

} node;

typedef struct Dblist {
    struct node *head;
    struct node *tail;
    int nodeCount;

}Dblist;

void initlist(Dblist *listptr);
void addFirst(Dblist *listptr, int data);
void addLast(Dblist *listptr, int data);
int loadFromFile(Dblist *listptr, char *filename); 
void createlistRandom(Dblist *listptr, int n);
void printListDetail(Dblist *listptr);
void printForward(Dblist *listpr);
void printReverse(Dblist *listptr);
node *find(Dblist *listptr, int target);
int insertAfter(Dblist *listptr, int target, int data);
int insertBefore(Dblist *listpr);
int deleteFirst(Dblist *listptr);
int deleteTarget(Dblist *listptr, int target);
void menu();

void initlist(Dblist *listptr){
    listptr->head=NULL;
    listptr->tail=NULL;
    listptr->nodeCount=0;
}

int createListRandom(Dblist *listptr,char *filename){

    FILE *inputfile= fopen(filename, "r");
    if(inputfile==NULL){
    return 0;
    }
    int data;
    fscanf(inputfile,"%d",&data);
    while(!feof(inputfile)){
    addlast(listptr,data);
    fscanf(inputfile,"%d",&data);
    }
    fclose(inputfile);
    return 1;
}

void createlistRandom(Dblist *listptr, int n){
    int i,k;
    srand(time(NULL));

    for(i=1;i<=n;i++)
        k=rand() % 1000;
    addLast(listptr,k);
}


void menu()
{
  printf("Doubly Linked List Operations \n");  
  printf("----------------------------- \n");
  printf("1.  Load from file \n"); 
  printf("2.  Create list with random numbers \n");
  printf("3.  Add first \n");
  printf("4.  Add last \n");
  printf("5.  Print list detail \n");
  printf("6.  Print list first to last data \n");
  printf("7.  Print list last to first data \n");
  printf("8.  Find \n");
  printf("9.  Delete first \n");
  printf("10. Delete last \n");
  printf("11. Detete a target \n");
  printf("12. Quit \n");
}

int main()
{
    
}
void addFirst(Dblist *listptr, int data)
{
    //create a new node dynamicall using malloc
    //assign the node content with data
    //initialize the prev and next pointer with NULL
    // if the nodecount=0 then 
    // head = tail = assign the address of the new node
    // else
    // p->next=head;
    // head->prev=p;
    // head=p;

    node *p = (node *)malloc(sizeof(node));
    if(p==NULL);
    {
    printf("Unable to create a node \n");
    return;
    }
    p->data=data;
    p->next=p->prev=NULL;
    if(listptr->nodeCount==0)
    {
        listptr->head=listptr->tail=p;
    }
    else
    {
    p->next=listptr->head;
    listptr->head->prev=p;
    listptr->head=p;
    }
    listptr->nodeCount++;
}

void addLast(Dblist *lstptr, int data){
    {
    node *p = (node *)malloc(sizeof(node));
    if(p==NULL);
    {
    printf("Unable to create a node \n");
    return;
    }
    p->data=data;
    p->next=p->prev=NULL;
    if(listptr->nodeCount==0)
    {
        listptr->head=listptr->tail=p;
    }
    else
    {
     listptr->tail->next=p;
     p->prev = listptr->tail;
    listptr-> tail=p;    
    } 
  listptr->nodeCount++;
}

void printForward(Dblist *listptr){
    node *p=listptr->head;
    if(p==NULL)
    {
        printf("Linkedlist is empty\n");
        return;
    }
   printf("Content of the double linkedlist\n"); 
    while(p!=NULL)
    {
       printf("%4d \n",p->data);
       p=p->next;
}
   printf("\n--End--\n");
   

}
