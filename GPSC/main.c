#include <stdio.h>
int main(int argc, char *argv[])
{
   int x,a,b,m;
                // Произвольно выбираем a,b,m и x
   m=100; // Вершина последовательности
   b=3;
   a=2;
   x=1;
   int i,N=100;
               // Сгенерируем N случайных чисел
   for(i=0;i<N;i++)
   {
       x=(a*x+b)%m;
       printf("%d ",x);
   }
   return 0;
}
