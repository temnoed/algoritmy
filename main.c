// Чистяков Дмитрий. ДЗ 2.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solution1();
//Ввести a и b и вывести
// квадраты и кубы чисел от a до b.

void solution2();
// Даны целые положительные числа N и K.
// Используя только операции сложения и вычитания,
// найти частное от деления нацело N на K,
// а также остаток от этого деления.

void solution3();

//Дано целое число N (> 0). С помощью операций деления
// нацело и взятия остатка от деления
//определить, имеются ли в записи числа N
// нечетные цифры. Если имеются, то вывести True,
// если нет — вывести False.
_Bool checkUneven(int n);

void menu();

int main() {

    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                solution1();
                break;
            case 2:
                solution2();
                break;
            case 3:
                solution3();
                break;
            case 0:
                printf("Bye-bye");
                break;
            default:
                printf("Wrong selected\n");
                break;
        }
    } while (sel != 0);
    return 0;
}

void solution1() {
    printf("Solution 1\n");
    int a, b;
    printf("\n Input a:");
    scanf("%d", &a);
    printf("\n Input b :");
    scanf("%d", &b);
    for (int i = a; i <= b; i++) {
        printf("%10i%10i\n", (i * i), (i * i * i));
    }
}

void solution2() {
    printf("Solution 2\n");
    int n, k, quot;
    n = 17;
    k = 2;
    quot = 0;
    while (n - k >= 0) {
        quot++;
        n -= k;
    }
    printf("Quotient: %3i, modulo: %3i\n", quot, n);
    system("pause");
}

void solution3() {
    printf("Solution 3\n");
    int n;
    printf("\n Input n:");
    scanf("%d", &n);
    if (checkUneven(n)) {
        printf("true \n");
    } else {
        printf("false \n");
    }
    system("pause");
}

_Bool checkUneven(int n) {
    do {
        if (((n % 10) % 2) != 0) return true;
        n = (int) (n / 10);
    } while (n > 0);
    return false;
}

void menu() {
    printf("\n1-task1\n");
    printf("2-task2\n");
    printf("3-task3\n");
    printf("0-exit\n");
}