#include<stdio.h>
void main()
{
	int i,j,k,n;
	char s = 'A';
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=n;j<=n-i;j++)
		{
		 printf(" ");
		s++;
		
		}
		
		for(j=1;j<=i;j++)
		{
		printf("%c ",s);
		
		
		}
	printf("\n");
	
	}



}
