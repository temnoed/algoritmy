#include <stdio.h>
// ����������� ��������� ���������� ������� ������ �� ������ ��� ������������� ���������� ��������
int main()
{
   unsigned int counter;  // ���������� ������
   int grade;                    // �������� ������
   int sum;                      // ����� ������
   double average;        //������� ������
// ���� �������������
   sum=0;
   counter=0;
   printf("%s","Enter grade(-1-end):");
   scanf("%d",&grade);
   while(grade!=-1)
   {
       sum=sum+grade;
       counter++;
       printf("%s","Enter grade(-1-end):");
       scanf("%d",&grade);
   }
   if (counter!=0)
   {
       average=(double)sum/counter;
       printf("Class average is %g\n",average);
   }
   else
   {
       puts("No grades were entered");
   }
   return 0;
}
