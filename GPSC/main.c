#include <stdio.h>
int main(int argc, char *argv[])
{
   int x,a,b,m;
                // ����������� �������� a,b,m � x
   m=100; // ������� ������������������
   b=3;
   a=2;
   x=1;
   int i,N=100;
               // ����������� N ��������� �����
   for(i=0;i<N;i++)
   {
       x=(a*x+b)%m;
       printf("%d ",x);
   }
   return 0;
}
