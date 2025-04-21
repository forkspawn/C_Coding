#include<stdio.h>
#include<stdlib.h>

#define False 0
#define True 1

struct node
{
    int info;
    short int balance;
    struct node *lchild;
    struct node *rchild;
};

void display(struct node *p, int level);
void inorder(struct node *p);

struct node *rotateLeft(struct node * p);
struct node *rotateRight(struct node *p);

struct node *getNode(int x);
struct node *insertNode(struct node *p, int x);
struct node *insertionLeftSubtreeCheck(struct node *p, int *taller);
struct node *insertionRightSubtreeCheck(struct node *p, int *taller);
struct node *insertionLeftBalance(struct node *p);
struct node *insertionRightBalance(struct node *p);

struct node *deleteNode(struct node *p, int x);
struct node *deletionLeftSubtreeCheck(struct node *p, int *shorter);
struct node *deletionRightSubtreeCheck(struct node *p, int *shorter);

void main()
{
    int choice,key;
    struct node *root =NULL;
    while(1)
    {
        printf(" \n");
        printf("1.Display Tree \n");
        printf("2.Insert a new node \n");
        printf("3.Delete a node \n");
        printf("4.Inorder Traversal \n");
        printf("5.Quit \n");
        printf("Enter Your Choice \n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                display(root,0);
                break;

            case 2:
                printf(" \n");
                scanf("%d",&key);
                root = insertNode(root,key);
                break;

            case 3:
                printf("Enter the key to be deleted \n");
                scanf("%d",&key);
                root = deleteNode(root,key);
                break;
 
            case 4:
                inorder(root);
                break;

            case 5:
                exit(1);

            default:
                printf("Wrong Choice \n");
        
        }
    }
}

void display(struct node *p, int level)
{
    int i;
    if(p==NULL)
        return;
   
    display(p->rchild,level+1);
    printf("\n");

    for(i=0; i<level;i++)
        printf("    ");

    printf("%d",p->info);
    display(p->lchild, level+1);
    
   
}

void inorder(struct node *p)
{
    if(p==NULL)
        return;
    inorder(p->lchild);
    printf("%d",p->info);
    inorder(p->rchild);
}

struct node *rotateLeft(struct node *p)
{
    struct node *a;
    a=p->rchild;
    p->rchild = a->lchild;
    a->lchild = p;
    return a;
}

struct node *rotateRight(struct node *p)
{
    struct node *a;
    a=p->lchild;
    p->lchild = a->rchild;
    a->rchild = p;
    return a;
}

struct node *getNode(int x)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->info=x;
    p->lchild=NULL;
    p->rchild=NULL;
    p->balance =0;
    return p;
}

struct node *insertNode(struct node *p, int x)
{
    static int taller;
    if(p==NULL)        
    {
        p=getNode(x);
        taller=True;
    } 
    else if(x < p->info)
            {
                p->rchild=insertNode(p->rchild,x);
                
                if(taller== True)
                {
                    p=insertionLeftSubtreeCheck(p,&taller);
                }
            }
    else if(x>p->info)
    {
        p->rchild=insertNode(p->rchild,x);
        if(taller==True)
        {
            p=insertionRightSubtreeCheck(p,&taller);
            
        }
    }
    else
    {
        printf("%d already present in tree \n",p->info);
        taller = False;
    }
    return p;
} 
      
struct node *insertionLeftSubtreeCheck(struct node *p, int *taller)
{
    switch(p->balance)
    {
        case 0: // case L1: was balanced
            p->balance=1;
            break;
        case -1:
            p->balance=0;
            *taller=False;
            break;
        case 1:
            p=insertionLeftBalance(p);
            *taller=False;
    }
    return p;
}

struct node *insertionRightSubtreeCheck(struct node *p, int *taller)
{
    switch(p->balance)
    {
        case 0: 
            p->balance = -1;
            break;
        case 1:
            p->balance = 0;
            *taller=False;
            break;
        case -1:
            p=insertionRightBalance(p);
            *taller=False;
            break;
    }
   return p; 
}

struct node *insertionLeftBalance(struct node *p)
{
    struct node *a, *b;
    a=p->lchild;
    if(a->balance==1)
            {
                p->balance=0;
                a->balance=0;
                p= rotateRight(p);
            }
    else
    {
        b=a->rchild;
        switch(b->balance)
        {
            case 1:
                p->balance =-1;
                a->balance =0;
                break;
            case -1:
                p->balance =0;
                a->balance =1;
                break;
            case 0:
                p->balance=0;
                a->balance=0;
        }
        b->balance=0;
        p->lchild=rotateLeft(a);
        p= rotateRight(p);
    }
    return p;
}

struct node *insertionRightBalance(struct node *p)
{
    struct node *a, *b;
    a=p->rchild;
    if(a->balance== -1)
            {
                p->balance=0;
                a->balance=0;
                p= rotateLeft(p);
            }
    else
    {
        b=a->lchild;
        switch(b->balance)
        {
            case 1:
                p->balance =1;
                a->balance =0;
                break;
            case -1:
                p->balance =0;
                a->balance =1;
                break;
            case 0:
                p->balance=0;
                a->balance=0;
        }
        
        b->balance=0;
        p->rchild=rotateRight(a);
        p=rotateLeft(p);
    }
    return p;
}

struct node *deleteNode(struct node *p, int x)
{
    struct node *ch, *s;
    static int shorter;

    if(p==NULL)
    {
        printf("%d not found \n",x);
        shorter = False;
        return p;
    }
    if(x< p->info) //delete from left subtree
    {
        p->lchild = deleteNode(p->lchild,x);
            if(shorter == True)
                p= deletionLeftSubtreeCheck(p,&shorter);
    }
    else if(x > p->info)
    {
        p->rchild = deleteNode(p->rchild,x);
        if(shorter==True)
            p=deletionRightSubtreeCheck(p,&shorter);
    }
    else
    {
        if(p->lchild!=NULL && p->rchild!=NULL)
        {
            s=p->rchild;
           
            while(s->lchild)
                s = s->lchild;
            p->info = s->info;
            p->rchild = deleteNode(p->rchild,s->info);
           
            if(shorter==True)
                p=deletionRightSubtreeCheck(p,&shorter);
        }
        else
        {
            if(p->lchild !=NULL)
                ch=p->lchild;
            else
                ch=p->rchild;
            free(p);
            p=ch;
            shorter=True;
                }
    }
    return p;

}

struct node *deletionLeftBalance(struct node *p,int *shorter)
{
     struct node *a, *b;
    a=p->lchild;
    if(a->balance==0)
    {
        p->balance=1;
        a->balance=-1;
        *shorter = False;
        p=rotateRight(p);
    }
    else if(a->balance==1)
    {
        p->balance=0;
        a->balance=0;
        p=rotateRight(p);
    }
    else
    {
        b=a->rchild;
        switch(b->balance)
        {
            case 0:
                p->balance=0;
                a->balance=0;
                break;
            case 1:
                p->balance=0;
                a->balance=1;
                break;
            case -1:
                p->balance=-1;
                a->balance=0;
        }
        b->balance=0;
        p->lchild=rotateLeft(a);
        p=rotateRight(p);
    }
    return p;    
}

struct node *deletionRightBalance(struct node *p,int *shorter)
{
    struct node *a, *b;
    a=p->rchild;
    if(a->balance==0)
    {
        p->balance=-1;
        a->balance=1;
        *shorter = False;
        p=rotateLeft(p);
    }
    else if(a->balance==-1)
    {
        p->balance=0;
        a->balance=0;
        p=rotateLeft(p);
    }
    else
    {
        b=a->lchild;
        switch(b->balance)
        {
            case 0:
                p->balance=0;
                a->balance=-1;
                break;
            case 1:
                p->balance=0;
                a->balance=-1;
                break;
            case -1:
                p->balance=1;
                a->balance=0;
        }
        b->balance=0;
        p->rchild=rotateRight(a);
        p=rotateLeft(p);
    }
    return p;
}

struct node *deletionLeftSubtreeCheck(struct node *p, int *shorter)
{
     switch(p->balance)
    {
        case 0:
            p->balance =-1;
            *shorter =False;
            break;
        case -1:
            p->balance=0;
            break;
        case 1:
            p=deletionRightBalance(p,shorter);
    }
    return p;
 
}
struct node *deletionRightSubtreeCheck(struct node *p, int *shorter)
{
    switch(p->balance)
    {
        case 0:
            p->balance =1;
            *shorter =False;
            break;
        case -1:
            p->balance=0;
            break;
        case 1:
            p=deletionLeftBalance(p,shorter);
    }
    return p;
}

