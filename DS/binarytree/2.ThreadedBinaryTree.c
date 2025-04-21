#include<stdio.h>
#include<stdlib.h>

typedef enum {False,True} boolean;

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
    boolean leftThread;
    boolean rightThread;
}node;


node *getNode(int key);
node *insertNode(struct node *p,int key);
node *inorderPredecessor(struct node *p);
node *inorderSuccessorr(struct node *p);    
node *deleteNode(struct node *p,int key);
void inorder(node *root);

    void main()
{
    node *root=NULL;
    int key,select;

    while(1)
    {
        printf("1. Insert a new Node\n");
        printf("2. Delete a Node \n");
        printf("3. Inorder Traversal \n");
        printf("4. Exit \n");
        printf("Enter your Choice\n");
        scanf("%d",&select);

        switch(select)
        {
            case 1:
                printf("Enter the key to be inserted\n");
                    scanf("%d",&key);
                root=insertNode(root,key);
                break;
            case 2:
                printf("Enter the key to be deleted \n");
                scanf("%d",&key);
                root = deleteNode(root,key);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                exit(1);
        }
    
    }
}

node *getNode(int key)
{
    node *p=(node*)malloc(sizeof(node));
    p->info=key;
    p->left=NULL;
    p->right=NULL;
    p->leftThread=True;
    p->rightThread=True;
    return p;
}


node *inorderPredecessor(node *p)
{
    if(p->leftThread==True)
        return p->left;
    
    p=p->left;
    while(p->rightThread==False)
        p=p->right;
    return p;
}


node *inorderSuccessorr(node *p)
{
    if(p->rightThread==True)
        return p->right;

    p=p->right;
    while(p->leftThread==False)
        p=p->left;
    return p;
}


void inorder(node *root)
{
    node *p;
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    p=root;
    while(p->leftThread==False)
        p=p->left;
   
    while(p!=NULL)
    {
        printf("%d ",p->info);
        if(p->rightThread == True)
            p=p->right;
        else
        {
            p=p->right;
            while(p->leftThread== False)
                p=p->left;
        }
    }
    printf("\n\n");
}

node *insertNode(node *root, int key)
{
    node *temp,*par,*p;

    p=root;
    par=NULL;

    while(p!=NULL)
    {
        par=p;
        if(key < p->info)
        {
            if(p->leftThread==False)
                p=p->left;
            else
                break;
        }
        else if(key> p->info)
        {
            if(p->rightThread==False)
                p=p->right;
            else
                break;
        }
        else
        {
            printf("%d already present in the tree\n",key);
        }
    }

    temp=getNode(key);
    if(par==NULL)
        root=temp;
    else if(key < par->info)
    {
        temp->left = par->left;
        temp->right=par;
        par->leftThread=False;
        par->left=temp;
    }
    else
    {
        temp->left=par;
        temp->right=par->right;
        par->rightThread=False;
        par->right=temp;

    }
    return root;
}


node *deleteNode(node *root, int key)
{
    node *par,*p,*ch,*s,*ps,*succ,*pred;

    p=root;
    par=NULL;
    while(p!=NULL)
    {
        if(key==p->info)
            break;
        par=p;
       
        if(key<p->info)
        {
           if(p->leftThread==False)
               p=p->left;
           else
               break;
        }
        else
        {   
           if(p->rightThread==False)
               p=p->right;
           else
               break;
        }
    }

    if(p==NULL||p->info!=key)
    {
        printf("%d not found\n",key);
        return root;
    }
    if(p->leftThread!=True && p->rightThread!=True)
    {
        ps=p;
        s=p->left;

        while(s->leftThread==False)
        {
            ps=s;
            s=s->left;
        }
       
        p->info=s->info;
        p=s;
        par=ps;
    }
      
    if(p->leftThread!=True && p->rightThread==True)
    {
        if(par==NULL)
            root==NULL;
        else if(p==par->left)
        {
            par->leftThread=True;
            par->left=p->left;
        }
        else
        {
            par->rightThread=True;
            par->right=p->right;
        }
        free(p);
    }
    
    if(p->leftThread==False)
        ch=p->left;
    else
        ch=p->right;

    if(par==NULL)
        root=ch;
    else if(p==par->left)
        par->left=ch;
    else
        par->right=ch;

    pred=inorderPredecessor(p);
    succ=inorderSuccessorr(p);

    if(p->leftThread==False)
        pred->right=succ;
    else
        succ->left=pred;
    
    free(p);
    return root;

}
