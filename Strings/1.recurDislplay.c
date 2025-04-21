#include<stdio.h>
#include<string.h>
void display(char *ptr)
        {
            printf("\n %s",ptr);
            if(*ptr)
                display(ptr+1);
            printf("\n %s",ptr);
        }

void main()
{
    char str[10]="Hello";
    char s[]="rendezvous!";
    display(str);
    printf("%ld\n",sizeof(str));
    printf("%ld\n",sizeof("abc"));
    printf("\n%d",*(s+strlen(s)));
}
        
