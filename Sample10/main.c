#include <stdio.h>
// ���������� ������� ������ ����������� ����������, ����������� ���������
int main(int argc, char *argv[])
{
   unsigned int counter;   // ���������� ������
   int grade;                     // �������� ������
   int sum;                       // ����� ������
   double average;          // ������� ������
// ���� �������������
   sum=0;
   counter=1;
   while(counter<=10)
   {
       printf("%s","Enter grade:");
       scanf("%d",&grade);
       sum=sum+grade;
       counter++;
   }
   average=sum/10.0;
   printf("Class average is %g\n",average);
   return 0;
}
