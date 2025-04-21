#include<stdio.h>

double fact(int i)
{
	double f=1;
	if(i==2)
	return 2;
	else if(i==2)
	return 1;
	else
	return i*fact(i-1);


}

void main()
{
	int i;
	double res;
	scanf("%d",&i);
	res=fact(i);
	printf("%.1lf\n",res);
	


}
