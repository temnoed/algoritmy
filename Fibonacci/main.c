#include <stdio.h>

int F(int n)
{
    int a=1;
    int b=1;
    int c=1;
    for(int i=2;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main(int argc, char *argv[])
{

    for(int i=0;i<20;i++)
      printf("%5d%10d\n",i,F(i));
    return 0;
}
