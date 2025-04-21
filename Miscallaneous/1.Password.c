#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
//#include<windows.h>
main()
{
  char st[40],ch;
  /*const char *exe;*/

  int i=0;
  clrscr();
  gotoxy(20,12);
  printf("Enter Password  :");
  while(1)
  {
    ch=getch();
    if(ch==13)
     break;
    else
    {
      if(ch==8)
      {
       if(i>0)
       {
	printf("\b");
	printf("%c",32);
	printf("\b");
	i--;
       }
      }
     else
     {
       st[i]=ch;
       i++;
       printf("*");
      }
    }
   }
   s
 st[i]='\0';
  if(strcmp(st,"kiran")==0)
  {
      gotoxy(35,20);
      printf("Please Wait....");
      system("c:\\prj.exe");
   }
 else
  {
     gotoxy(35,20);
    printf("Invalid Password");
    getch();
  }
}
