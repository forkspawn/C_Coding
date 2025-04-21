#include<stdio.h>

/*int *findMid(int a[], int n,int *mid1, int *mid2) // for a pointer function it should return a address 
{				// caution: never try to return the address of the 
				//local variable in the function
	if(n%2!=0)
	 	return &a[n/2];
	 else
	 *mid1 = a[n/2];
	 *mid2 =a[(n/2)+1];
	 	               // as the function returns the variable gets destroyed
	
	

}*/	

void findMid(int a[], int n,int *mid1, int *mid2) // for a pointer function it should return a address 
{				// caution: never try to return the address of the 
				//local variable in the function
	if(n%2!=0)
	 { *mid1 = a[n/2];}	
	 
	 else
	{ *mid2 = a[n/2];
	 *mid1 =a[(n/2)-1]; }
	 	               // as the function returns the variable gets destroyed
	
	

}		


int main()
{
	int a[100];
	int n;
	int i;
	int mid1,mid2;
	
	printf("Enter the size of the array\n");
	scanf("%d",&n);
	
	printf("Enter the elements of the array\n");
	
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	//int *mid= findMid(a,n,&mid1,&mid2);
	findMid(a,n,&mid1,&mid2);
	
	printf("The elements of the array\n");
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	
	if(n%2!=0)
		printf("\nThe middle element is %d\n",mid1);
	
	else
		printf("\nThe two middle elements are %d %d\n",mid1,mid2);
	
}

