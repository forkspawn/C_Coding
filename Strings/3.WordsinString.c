#include<stdio.h>
#include<string.h>
void main()
{
    char str[50]="what is going on you know what";
    int i;
    int count=0;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
            count++;
    }
    printf("%d",count+1);
}
