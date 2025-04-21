#include<stdio.h>

void main()
{
	
	int seen[10]={0}; // this intializes all the values with zeroes
	int i; //to store the user value
	int rem; // to store the remainder
	printf("Enter the number to check any digit is repeated\n");
	scanf("%d",&i);
	
	while(i>0)
	{
		rem=i%10; // this give the last digit of the number
		if(seen[rem]==1) // to check if the digit has been repeated if it is then it breaks fr
				 // the loop
			break;
		seen[rem]=1;
		i=i/10; // this gives the first numbers leaving the last 
		}
	if(i>0)
		printf("Yes\n");
	else
		printf("No\n");

}
