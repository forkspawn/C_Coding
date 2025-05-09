#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
   
}Node;

void menu();
void insert(Node **, int);
void inorder(Node *);
void preorder(Node *);
void postorder(Node *);
Node * bin_search(Node *, int);

void menu()
{
    
 printf("------------BST Operations---------- \n");
 printf("1. Insert \n");
 printf("2. In-order Traversal \n");
 printf("3. Pre-order Traversal \n");
 printf("4. Post-order Traversal \n");
 printf("5. Search \n");
 printf("6. Commands \n");
 printf("7. Quit \n");
 printf("------------------------------------ \n");

}

void insert(Node **rtp, int key)
{
 if(*rtp == NULL)
 {
    *rtp=(Node*)malloc(sizeof(Node));
    if(*rtp==NULL)
    {
           printf("Error--Unable to allocate memory \n"); 
            exit(1);
    }       

    (*rtp)->key=key;
    (*rtp)->left=(*rtp)->right=NULL;
 }
 else if(key > (*rtp)->key){

     insert( &((*rtp)->right), key);
 }

 else if(key < (*rtp)->key){

    insert( &((*rtp)->left), key); 
 }

 else
 {
    printf("Duplicate key found -- Insertion abort");
    return;
 }

}

void inorder(Node *rt)
{
    if(rt != NULL)
    {
    inorder(rt->left);
    printf("%4d",rt->key);
    inorder(rt->right);
    }
    else
        return;
}

void preorder(Node *rt)
{


    if(rt != NULL)
    {
    printf("%4d",rt->key);
    preorder(rt->left);
    preorder(rt->right);
    }
    else
        return;


}

void postorder(Node *rt)
{
   
    if(rt != NULL)
    {
    postorder(rt->left);
    postorder(rt->right);
    printf("%4d",rt->key);
    }
    else
        return;
}

Node* bin_search(Node* rt, int target)
{

    if(rt==NULL)
    {
        return NULL;
}

    else if(rt->key ==target)
    { return rt;
    }

    else if(target>rt->key)
    { 
     return  bin_search(rt->right, target);
    }

    else if(target<rt->key)
    {
        return bin_search(rt->left,target);
    }
}

int main()
{
    int choice;
    int quit=0,key,target;
    Node *root=NULL;
    Node *target_node;
    insert(&root,10);  // hardcoding the keys before the search operation
    insert(&root,5);
    insert(&root,43);
    insert(&root,56);
    insert(&root,136);
    insert(&root,126);
    insert(&root,116);
    insert(&root,176);
    insert(&root,136);
    insert(&root,66);

    menu();
    while(!quit)
    {
        printf("Enter the option \n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1 : 
                    printf("Insert the key: \n");
                    scanf("%d",&key);
                    insert(&root,key);  
                    break;
            case 2 :
                    inorder(root);
                    printf("\n");
                    break;
            case 3 :
                    preorder(root);
                    printf("\n");
                    break;
            case 4 :
                    postorder(root);
                    printf("\n");
                    break;
            case 5:
                    printf("Input target: \n");
                    scanf("%d",&target);
                    target_node = bin_search(root,target);
                    if(target_node==NULL)
                        printf("Target doesn't exist\n");
                    else
                        printf("Target exits \n");
                    break;
            case 6:
                    menu();
                    break;
            case 7:
                    quit=1;
                    break;

       
        }   


    }       


}
