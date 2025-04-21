#include<stdio.h>
#include<stdlib.h>

	typedef struct {
		
		 int *item; // to store the base address
		 int top;
		 int size;
		
		}stack;
	
	void init(stack *,int);
	void push(stack *,int);
	int pop(stack *);
	void deallocate(stack *);
	
	void push(stack *sp, int value)
	{
		if(sp->top==sp->size -1)
		{
			printf("Stack overflow \n");
			return;
		}
 	 
	sp->top++;
	sp->item[sp->top]=value;
	
	}
	
	int pop(stack *sp)
	{
	
		if(sp->top==-1)
		{
			printf("Stack underflow\n");
		
		}
	int value;
	value=sp->item[sp->top];
	sp->top--;
	return value;
	}
	
	void init(stack *sp,int size)
	{
		sp->top=-1;
		sp->item=(int *)malloc(sizeof(int)*size);	
		if(sp->item==NULL)
		 {
			printf("Unable to allocate the memory \n");		
			exit(1);
			}
		sp->size=size;
	}
	
	void deallocate(stack *sp)
	{
	 if(sp->item!=NULL)
	 	free(sp->item);
	 sp->top=-1;
	 sp->size=0;
	
	}
	
	
	
	int main()
	{
		stack s1,s2;
		init(&s1,4); // or you ccan call init(&s1)
		init(&s2,3);
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		int choice,value;
		
		while(1)
		{
			printf("Enter choice\n");
			scanf("%d",&choice);
			
			switch(choice)
			{
				case 1: 
					printf("Enter value\n");
					scanf("%d",&value);
					push(&s1,value);
					break;
				case 2:
					value=pop(&s1);
					if(value!=9999)
					{
						printf("Popped data %d  \n",value);
					} 
					break;
				case 3:
					exit(0);
					deallocate(&s1);
				
				default:
					printf("Invalid choice \n");
			}
		
		
		
		}

	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
