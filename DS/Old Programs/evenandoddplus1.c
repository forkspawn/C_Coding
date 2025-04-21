#include<stdio.h>
int odd(int );
int even(int );
int i=1;

int n;
int odd(int n)
{
	if(i<=n)
	{
		printf("%d ",i+1);
		i++;
		even(n);
	
	}

}

int even(int n)
{
	if(i<=n)
	{
		printf("%d ",i-1);
		i++;
		odd(n); 
        }

}

int main()
{	int n;
	printf("Enter number of digits that you want print \nwhere odd number gets plus 1 and even number gets minus 1\n");
	scanf("%d",&n);
	odd(n);
	printf("\n");


}
