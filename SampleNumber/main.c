#include <stdio.h>
int main()
{
 int number;
 printf("Input number:");
 scanf("%d",&number);
 int d=0;

 for(int i=2;i<=sqrt(number) && d==0;i++)
     if (number%i==0) d=1;

 if (d==0) printf("Number %d is simple",number);
 else printf("Number %d is not simple",number);
 return 0;
}

