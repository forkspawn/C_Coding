#include<stdio.h>
int n,a[100],i,ele,pos;
 
 void insert()
 {
	for(i=n;i<=pos;i--)
	{
		a[i]=a[i-1];
	}		
	a[pos-1]=ele;
 } 
 
  void main()
  {
  	printf("Enter the size of Array \n");
  	scanf("%d",&n);
  	
  	printf("Enter the Array elements\n");
  	for(i=0;i<n;i++)
  	{
  		scanf("%d",&a[i]);
  	}	   
	
  	
  	printf("Enter the element to be inserted \n");
  	scanf("%d",&ele);
  	printf("Enter the position \n");
  	scanf("%d",&pos);		
	
	
	for(i=n;i>=pos;i--)
	{
	   a[i]=a[i-1]; // or a[i+!]=a[i] this doesnt work as in the fifth position there is
	   		// no element as the array is size n when you put i+1, meaning we need to change from
	   		// n to n+1 as we know array starts from 0 to n-1, at n there is no element 
	   printf("*\n");
	   printf("\n %d \n",a[i]);
	   printf("\n value of i %d \n",i);
           printf("\n value of pos %d \n",pos);
           printf("\n value of n %d \n",n);	
		
		
		}
	   
	   
	    pos=pos-1;
	    a[pos]=ele; // a[i+1] 
	
	    printf("\n value of i %d \n",i);
            printf("\n value of pos %d \n",pos);
            printf("\n value of n %d \n",n);
			
 	
 	printf("The elements in new array are\n ");
  	for(i=0;i<=n;i++)
  	{
  		printf("%d \n",a[i]);
  	}
  
  
  }
