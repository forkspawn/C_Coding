 #include<stdio.h>
 #define ops 4

 float sum(float a, float b)
 {return (a+b);}
 
 float sub(float a, float b)
 {return (a-b);}
 
 float mult(float a, float b)
 {return (a*b);}
 
 float div(float a, float b)
 {return (a/b);}
 
  int main()
  {
  	float(*ptr2func[ops])(float,float)={sum,sub,mult,div};
  	int choice;
  	float a,b;
  	printf("Enter the choice: \n0 for sum\n1 for sub\n2 for mult\n3 for div\n");
  	scanf("%d",&choice);
  	printf("Enter the two numbers\n");
  	scanf("%f %f",&a,&b);
  	printf("%.3f\n",ptr2func[choice](a,b));
  	return 0;
  
  
  
  }
