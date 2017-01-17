#include <stdio.h>
#include <math.h>


double distance(double x1, double y1, double x2, double y2)
{
   return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(int argc, char *argv[])
{
   double x1,y1,x2,y2;
   printf("Input x1:");
   scanf("%lf",&x1);
   printf("Input y1:");
   scanf("%lf",&y1);
   printf("Input x2:");
   scanf("%lf",&x2);
   printf("Input y2:");
   scanf("%lf",&y2);
   printf("Distance:%lf",distance(x1,y1,x2,y2));
   return 0;
}
