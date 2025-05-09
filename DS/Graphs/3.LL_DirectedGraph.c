#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct EdgeNode;

struct VertexNode
{
    char name[50];
    struct VertexNode *nextVertex;
    struct EdgeNode *firstEdge;
};

struct VertexNode *start=NULL;

struct EdgeNode
{
    struct VertexNode *endVertex;
    struct EdgeNode *nextEdge;
};

struct VertexNode *findVertex(char s[]);
void insertVertex(char s[]);
void insertEdge(char s1[], char s2[]);
void deleteEdge(char s1[], char s2[]);
void deletefromEdgeLists(char s[]);
void deletefromVertexLists(char s[]);
void deleteVertex(char s[]);
void display();
int isAdjacent(char s1[], char s2[]);
int outdegree(char s[]);
int indegree(char s[]);

void main()
{
     int choice,x;
    char s1[50],s2[50];

    insertVertex("AA");
    insertVertex("BB");
    insertVertex("CC");
    insertVertex("DD");
    insertVertex("EE");

    insertEdge("AA","BB");
    insertEdge("AA","CC");
    insertEdge("CC","DD");
    insertEdge("DD","AA");
    insertEdge("CC","AA");
    insertEdge("BB","EE");

    while(1)
    {
        printf("1. Display Adjacency Matrix \n");
        printf("2. Insert a vertex \n");
        printf("3. Remove a vertex\n");
        printf("4. Insert an edge \n");
        printf("5. Delete an edge \n");
        printf("6. Display Indegree and outdegree of a vertex \n");
        printf("7. Check if there is an edge between two vertices \n");
        printf("8. Exit \n");
        printf("Enter your Choice \n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                display();
                break;
            
            case 2:
                printf("Enter Vertex name: \n");
                scanf("%s",s1);
                insertVertex(s1);
                break;
            case 3:
                printf("Enter vertex name: \n");
                scanf("%s",s1);
                deleteVertex(s1);
                break;
            case 4:
                printf("Enter start and end vertices \n");
                scanf("%s",s1);
                scanf("%s",s2);
                insertEdge(s1,s2);
                break;
            case 5:
                printf("Enter start and end vertices");
                scanf("%s",s1);
                scanf("%s",s2);
                deleteEdge(s1,s2);
                break;
            case 6:
                printf("Enter vertex name \n");
                scanf("%s",s1);
                x=indegree(s1);
                if(x==-1)
                    printf("Vertex name not present in the graph \n \n");
                else
                {
                    printf("Indegree is: %d \n",x);
                    printf("outdegree is : %d \n",outdegree(s1));
                }
                break;
            case 7:
                printf("Enter hte name of the vertrex \n");
                scanf("%s",s1);
                printf("Enter the name of the second vertex \n");
                scanf("%s",s2);
                x=isAdjacent(s1,s2);
                if(x==-1) 
                  printf("Vertex name not present in the graph \n");
                else if(x==0)
                   printf("There is no edge from %s to %s \n",s1,s2);
                else
                   printf("There is an edge from %s to %s \n",s1,s2);
                break;
            case 8:
                exit(1);
            default:
                printf("Wrong choice\n");
                break;

        }


    }
    


}
  

void insertVertex(char s[])
{
    struct VertexNode *temp,*p;
    if(start==NULL)
    {
        temp=(struct VertexNode*)malloc(sizeof(struct VertexNode));
        strcpy(temp->name,s);
        temp->nextVertex=NULL;
        temp->firstEdge=NULL;
        start=temp;
        return;
    }
    p=start;
    while(p->nextVertex!=NULL)
    {
        if(strcmp(p->name,s)==0)
        {
            printf("Vertex already present \n\n");
            return;
        }
        p=p->nextVertex;
    }
    if(strcmp(p->name,s)==0)
    {
        printf("Vertex already present \n");
        return;
    }

    temp=(struct VertexNode*)malloc(sizeof(struct VertexNode));
    strcpy(temp->name,s);
    temp->nextVertex=NULL;
    temp->firstEdge=NULL;
    p->nextVertex=temp;
}

struct VertexNode *findVertex(char s[])
{
    struct VertexNode *p=start;
    while(p!=NULL)
    {
        if(strcmp(p->name,s)==0)
            return p;
        p=p->nextVertex;
    }
    return NULL;
}

void deleteVertex(char s[])
{
    deletefromEdgeLists(s);
    deletefromVertexLists(s);
}

void deletefromVertexLists(char s[])
{
    struct VertexNode *temp,*p;
    struct EdgeNode *ptr,*temporary;
    if(start==NULL)
    {
        printf("No vertices to be deleted\n");
        return;
    }
    if(strcmp(start->name,s)==0) //vertex to be deleted is first vertex of the list
    {
        temp=start;
        start=start->nextVertex;
    }
    else
    {
        p=start;
        while(p->nextVertex!=NULL)
        {
            if(strcmp(p->nextVertex->name,s)==0) //searching for the node
                break;
            p=p->nextVertex;
        }
        if(p->nextVertex==NULL)
        {
            printf("Vertex Not found\n");
            return;
        }
        else
        {
            temp=p->nextVertex; // this is deleting part which replaces the p.next=p.next.next
            p->nextVertex=temp->nextVertex;
        }
    }
    ptr=temp->firstEdge; //before freeing the node temp, free all edges going from this vertex
        while(ptr!=NULL)
        {
            temporary=ptr;
            ptr=ptr->nextEdge;
            free(temporary);
        }
    free(temp);

}

void deletefromEdgeLists(char s[])
{
    struct VertexNode *p;
    struct EdgeNode *q,*temp;

    for(p=start;p!=NULL;p=p->nextVertex)
    {
        if(p->firstEdge==NULL)
            continue;
        if(strcmp(p->firstEdge->endVertex->name,s)==0)
        {
            temp=p->firstEdge;
            p->firstEdge=p->firstEdge->nextEdge;
            free(temp);
        }
        else
        {
            q=p->firstEdge;
            while(q->nextEdge!=NULL)
            {
                if(strcmp(q->nextEdge->endVertex->name,s)==0)
                {
                    temp=q->nextEdge;
                    q->nextEdge=temp->nextEdge;
                    free(temp);
                    break;
                }
                q=q->nextEdge;
            }
        }
    }
}
//learn from here
void insertEdge(char s1[],char s2[])
{
    struct VertexNode *u,*v;
    struct EdgeNode *p,*temp;

    if(strcmp(s1,s2)==0)
    {
        printf("Invalid Edge: start and end verices are same\n");
        return;
    }

    u=findVertex(s1);
    v=findVertex(s2);
    if(u==NULL)
    {
        printf("Start vertex not present, first insert vertex %s \n\n",s1);
        return;
    }
    if(v==NULL)
    {
        printf("End vertex not present, first insert vertex %s\n \n",s2);
        return;
    }
    temp=(struct EdgeNode*)malloc(sizeof(struct EdgeNode));
    temp->endVertex=v;
    temp->nextEdge=NULL;

    if(u->firstEdge==NULL)
        u->firstEdge=temp;
    else
    {
        p=u->firstEdge;
        while(p->nextEdge!=NULL)
        {
            if(strcmp(p->endVertex->name,s2)==0)
            {
                printf("Edge Present \n\n");
                return;
            }
            p=p->nextEdge;
        }
        if(strcmp(p->endVertex->name,s2)==0)
        {
            printf("Edge present \n");
            return;
        }
        p->nextEdge=temp;
    }

}


void deleteEdge(char s1[], char s2[])
{
    struct VertexNode *u;
    struct EdgeNode *temp, *q;

    u=findVertex(s1);
    if(u==NULL)
    {
        printf("Start Vertex not present\n\n");
        return;
    }
    
    if(u->firstEdge==NULL)
    {
        printf("Edge not present\n");
        return;
    }

    if(strcmp(u->firstEdge->endVertex->name,s2)==0)
    {
        temp=u->firstEdge;
        u->firstEdge=u->firstEdge->nextEdge;
        free(temp);
        return;
    }

    q=u->firstEdge;
    while(q->nextEdge!=NULL)
    {
        if(strcmp(q->nextEdge->endVertex->name,s2)==0)
        {
            temp=q->nextEdge;
            q->nextEdge=temp->nextEdge;
            free(temp);
            return;
        }
        q=q->nextEdge;
    }
    printf("Edge not present in the graph \n\n");
}

void display()
{
    struct VertexNode *p;
    struct EdgeNode *q;

    for(p=start;p!=NULL;p=p->nextVertex)
    {
        printf("%s-> ",p->name);

        for(q=p->firstEdge;q!=NULL;q=q->nextEdge)
            printf("%s ",q->endVertex->name);
        
        printf("\n");
    }
}

// if edge(s1,s2) exists
int isAdjacent(char s1[], char s2[])
{
    struct VertexNode *u=findVertex(s1);
    struct EdgeNode *q;
    if(u==NULL)
    {
        printf("Vertex not present\n");
        return 0;
    }
    for(q=u->firstEdge;q!=NULL;q=q->nextEdge)
        if(strcmp(q->endVertex->name,s2)==0)
            return 1;
    return 0;
}

//returns number of edges going out from vertex
int outdegree(char s[])
{
    int outd;
    struct VertexNode *u=findVertex(s);
    struct EdgeNode *q;

    if(u==NULL)
    {
        printf("Vertex not present\n\n");
        return -1;
    }
    outd=0;
    for(q=u->firstEdge;q!=NULL;q=q->nextEdge)
        outd++;
    return outd;
}

//returns number of edges coming to vertex
int indegree(char s[])
{
    int ind;
    struct VertexNode *p;
    struct EdgeNode *q;
    struct VertexNode *u=findVertex(s);

    if(u==NULL)
    {
        printf("Vertex not present\n");
        return -1;
    }
    ind=0;
    for(p=start;p!=NULL;p=p->nextVertex)
    {
        for(q=p->firstEdge;q!=NULL;q=q->nextEdge)
            if(q->endVertex==u)
                ind++;
    }
    return ind;
}










