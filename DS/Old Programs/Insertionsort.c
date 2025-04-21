#include<stdio.h>
#define n 10
void main()
{
	int a[10];
	int i,j,temp,value,hole;
	printf("Enter 10 elements \n");
	for(i=0;i<n-1;i++)
		scanf("%d",&a[i]);

	for(i=1;i<n-1;i++)
	{
		value = a[i]; // The value of second element is stored in the value
		hole=i;	// hole is a place holder where the element will be compared
		
		while(hole>0 && a[hole-1]>value) // here hole greater than zero and the first element 
						 // is compared with the second element of the array,
						 // if its greater than its shifted to the right and 
						 // hole is updated so that it could check next elements
		{
			a[hole]=a[hole-1];
			hole = hole-1;
		
		}
		
		a[hole]=value; // the value is replaced over here
		
		}
	
	

	printf("The new elements are \n");
	for(i=0;i<n-1;i++)
		printf("%d\n",a[i]);	
	

}
