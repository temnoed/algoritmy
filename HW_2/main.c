#include <stdio.h>

int main(int argc, char *argv[])
{
    int N=137;
    int K=15;
    int i=0;
    while (N>=K)
    {
        N-=K;
        i++;
    }
    printf("DIV:%d\n",i);
    printf("MOD:%d\n",N);
    return 0;
}
