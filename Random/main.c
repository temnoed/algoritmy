#include <stdio.h>
#include <stdlib.h>      // ��� ������������� ���������� ��������� �����
int main(int argc, char *argv[])
{
   srand(time(NULL));// ������������� �������� ��������� �����. ��� ���� ������� ����� ����� ������ � ���� ��
   printf("%d\n",rand());// ���������� ��������������� ����� ����� � ��������� �� 0 �� RAND_MAX.
   printf("%d\n",rand()%100);        //... �� 0 �� 99
   printf("%d\n",rand()%100+1);    //... �� 1 �� 100
   printf("%d\n",rand()%10+100);  //... �� 100 �� 109
}
