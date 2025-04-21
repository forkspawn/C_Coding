#include<stdio.h>
#include<string.h>

char stack[100];
int top=-1;
int size=100;
char input[40];
char output[40];
int i;

void push(char elem)
{
	if(size==top+1)
	{
		printf("Stack overflow");
	}
	
	else
	{
		
		top++;
		stack[top]==elem;
		printf("Pushed %c \n",elem);
	}


}

char pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
	}
	
	else
	{
		printf("Popped %c \n",stack[top]);
		return stack[top--];
		
	}



} 

void main()
{
	printf("Enter the string \n");
	scanf("%s",input);
	
	for(i=0;i<=strlen(input);i++)
	{
		push(input[i]);
	}

	for(i=0;i<=strlen(input);i++)
	{
		output[i]=pop();
		printf("%c",output[i]);
	
	}
	
	
	printf("The output string is \n");
	for(i=0;i<=strlen(input);i++ )
	{
		printf("%c",input[i]);
	}
	

}
