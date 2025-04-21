#include<stdio.h>
int main()
{
	int a[100];
	int sum=0;
	int i,n,*p;
	
	printf("Enter the size of the elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements");
	for(i=0;i<n;i++)
			scanf("%d",&a[i]);  
			
	for(p=a;p<=a+4;p++) // alternative for(p=&a[0];p<=&a[4],p++) as a stores the address of first 					element
		sum+= *p;
	
	printf("Sum of the array is %d",sum);
	

}
