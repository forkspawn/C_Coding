#include<stdio.h>

void strcp(char *dest,char *src)
{   
       
    for(;*src;src++,dest++)
        *dest=*src;
    *dest='\0';
    
    /* int i=0
        while(s2[i]!='\0')
        {
            
        }*/
}

/*void strcat(T,S) //either given the position or not given the postion concatenate from the null character
{
    
}

void strrev(T,S)
{
    
}

void strupr()
{
    
}

void strlwr()
{
    
}

int strlen(str)
{
    
}

int strcmp(str1,str2)
{
    
}

int strIcmp(str1,str2) //compares ignoring cases sentives
{
    
}*/

void main()
{
    char str1[50];
    char str2[50]="windows";
    strcp(str2+4,str1+2);
    puts(str1);
    puts(str2);
}
