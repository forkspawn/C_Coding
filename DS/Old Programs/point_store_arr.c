#include<stdio.h>

int main()
{
	int a[100];
	int n;
	int *p;
	
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	
	printf("Enter the elements of the array \n");
	
	for(p=a;p<=a+n-1;p++)
		scanf("%d",p);
	
	printf("The elements in reverse order are\n");
	
	for(p=a+n-1; p>=a; p--)
		printf("%d ",*p);
	
	printf("\n");
	
	return 0;
	


}
