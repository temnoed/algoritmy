#include <stdio.h>
// ����������� ����������� ������ ��������. �������� �������
int main()
{
   int a,b;
   printf("%s","Input a:");
   scanf("%d",&a);
   printf("%s","Input b:");
   scanf("%d",&b);
   while(a!=0 && b!=0)
       if (a>b)
      {
          a=a%b;
       }
  else
     {
        b=b%a;
      }
   printf("GCD:%i",a+b);
   return 0;
}
