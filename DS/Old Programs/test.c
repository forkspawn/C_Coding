#include<stdio.h>
void main()
{
      int a[10]={1,6,7,21,35,56,81,121,201,330};
      int val,i;
      
      
     printf("The array is ");
      for(i=0;i<10;i++)
      {
      	printf("%d ",a[i]);
      }
      
      printf("Enter the value to be searched\n");
      scanf("%d",&val);
      
      for(i=0;i<10;i++)
      {
      	if(val==a[i])
      	{printf("\nThe value is at %d \n",i+1);
      	}
      
      }

}

