#include<stdio.h>
void main()
{
	int a[10];
	int i,j,temp;
	printf("Enter 10 elements \n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			
			}
		}
	
	}

	printf("The new elements are \n");
	for(i=0;i<10;i++)
		printf("%d\n",a[i]);	
	

}
