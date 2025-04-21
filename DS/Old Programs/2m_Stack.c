#include<stdio.h>
#define SIZE 10 //MACRO

	typedef struct {
		
		 int item[SIZE];
		 int top;
		
		}stack;
	
	void init(stack *);
	void push(stack *,int);
	int pop(stack *);
	
	void push(stack *sp, int value)
	{
		if(sp->top==SIZE -1)
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
	
	void init(stack *sp)
	{
		sp->top=-1;
	
	}
	
	int main()
	{
		stack s1,s2;
		s1.top=-1; // or you ccan call init(&s1)
		init(&s2);
		
		push(&s2,100);
		push(&s2,2000);
		
		printf("deleted from s1 %d\n",pop(&s2));
		return 0;
		

	
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
