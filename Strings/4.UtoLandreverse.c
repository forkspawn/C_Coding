#include<stdio.h>
void changeCase(char *p)
{   
    
    if(*p>=65 && *p<=90)
    {  
        for(;*p!='\0';p++)
        { 
            if(*p==' ')
            *p=' ';
            else
            *p=*p+32;
        }
    }
   else if(*p>=97 && *p<=122)
        for(;*p!='\0';p++)
        { 
            if(*p==' ')
            *p=' ';
            else
            *p=*p-32;
        }
   else
        printf("Not in the range\n");

}

void main()
{
    char arr[]="-hat the fuck is going n ";
    changeCase(arr);
    printf("%s \n",arr);
}
