#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // Про шахматную доску и координаты -------------------
    int x1,y1,x2,y2;
    char color1, color2;
    printf("\n Input coord x1 :");
    scanf("%d", &x1);
    printf("\n Input y1 :");
    scanf("%d", &y1);
    if  (((y1 % 2 != 0) & (x1 % 2 != 0)) || ((y1 % 2 == 0) & (x1 % 2 == 0))) {
        color1 = 'w';
    } else {
        color1 = 'b';
    }
    printf("\n Color 1 :%c\n", color1);

    printf("\n Input x2 :");
    scanf("%d", &x2);
    printf("\n Input y2 :");
    scanf("%d", &y2);
    if  (((y2 % 2 != 0) & (x2 % 2 != 0)) || ((y2 % 2 == 0) & (x2 % 2 == 0))) {
        color2 = 'w';
    } else {
        color2 = 'b';
    }
    printf("\n Color 2 :%c\n", color2);

    if (color1 == color2) {
        printf("\n Color the same.");
    } else {
        printf("\n Color NOT same.");
    }
    printf("\n");
    system("pause");

    // Обмен двух чисел a , b без посредников --------------
    int a,b;
    a = 5; b = 123644;
    printf("A = %d, B = %d \n",a,b);
    system("pause");
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Now A = %d, B = %d \n",a,b);

    // Индекс массы тела BMI -------------------------
    float h;
    int m;

    printf("\n Input h (v metrah):");
    scanf("%f", &h);
    printf("Input m :");
    scanf("%d", &m);

    float bmi = m / ( h * h);
    printf("Body mass index = %f\n", bmi);
    system("pause");

        return 0;

    // ввод данных с проверкой--------------
    //
    //        int n,count=0;
    //        metka:
    //        count++;
    //        printf("%d. Input number:",count);
    //        if (scanf("%d",&n)==0)
    //        {
    //            fflush(stdin); //очищаем поток ввода
    //            goto metka;
    //        }
    //        printf("Count %d",count);
    //


}