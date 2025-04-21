#include<stdio.h>
void minMax(int arr[],int len, int *min, int *max)
{
	*min=*max=arr[0];
	int i;
	for(i=1;i<len;i++)
	{
		if(arr[i]> *max)
			*max=arr[i];
		
		if(arr[i]< *min)
			*min=arr[i];
	}

}

	int main()
	{
	
		
		int min,max,i;
		int len;
		int a[100];
		
		//int a[]={34,3435,353,3432,64,76,7,45,343,5};
		
		// len=sizeof(a)/sizeof(a[0]);
		printf("Enter the size of the array\n");
		scanf("%d",&len);
		
		printf("Enter the values of Array\n");
		for(i=0;i<len;i++)
			{scanf("%d",&a[i]);}
		
		minMax(a,len,&min,&max);
		
		printf("The values of Array are\n");
		for(i=0;i<len;i++)
		{	printf("%d ",a[i]);}
		
		printf("\nThe min value is %d \nThe max value is %d\n",min,max);
		return 0;
	
	
	}
