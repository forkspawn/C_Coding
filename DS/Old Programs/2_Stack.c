#include<stdio.h>
int stack[100];
int top=-1;
int size,i;

  void push(int elem)
  {
  	if(size==top+1)
  	{
  		printf("\n Stack overflow \n");
  	}
  	else{
  	
  	top++;
  	stack[top]=elem;
  	printf("\n Pushed %d \n",elem);
  	}
  }
  
  void pop()
  {
  	if(top==-1)
  	{
  		printf("Stack Underflow");
  	}
  	else
  	{
  		printf("\nPopped %d \n",stack[top]);
  		top--;
  	}
  }
  
  void display()
  {
  	if(top==-1)
  	{
  		 printf("Stack Underflow no elements!\n");
  		 
  	
  	}
  	else
  	{
  	
  	printf("The elements are\n");
  	for(i=top;i>=0;i--)
  	{ 
  	
  	printf("%d \n",stack[i]) ;
  	
  	}
  
       }
  
  }
  
  int main()
  {
  	int choice,elem,k;
  	printf("\n Enter your stack size \n");
  	scanf("%d",&size);
  	
  	do{
  	
  		printf("\n Enter the choice \n 1.Push \n 2.Pop \n 3.Display \n");
  		scanf("%d",&choice);
  		switch(choice)
  		{
  		case 1:
  		printf("\nEnter the elemnet which you wish to push \n");
  		scanf("%d",&elem);
  		push(elem);
  		break;
  		
  		case 2:
  		pop();
  		break;
  		
  		case 3:
  		display();
  		break;
  		
  		default:
  		printf("Invalid Choice \n");
  		break;  		
  		}
  		printf("\n Do you wish to continue?\n1.Yes \n2.No \n");
  		scanf("%d",&k);
  	}while(k==1);
  }
  
  
  
