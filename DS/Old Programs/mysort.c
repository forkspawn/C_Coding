#include <stdio.h>
#define n 5

void main()
{
    int a[n],i,j,temp;

    printf("Enter 5 values \n");

   for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=1;i<n;i++)
        for(j=0;a[i]<a[j];j++)
        {
           printf("for %d < %d \n",a[i],a[j]);
           
            temp=a[i];
           a[i]=a[j];
           a[j]=temp; 
        }
      
   for(i=0;i<n;i++)
        printf("%d\n",a[i]);


}
