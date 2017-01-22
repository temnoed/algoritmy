// Чистяков Дмитрий. ДЗ 3.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/time.h>
// include "MyLib.h"

// Запоминаем в глобальных переменных текущее время
struct timeval tv1, tv2, dtv;
struct timezone tz;

void time_start();

long time_stop();

void solution1();

// 1.	Написать функцию возведения целого числа a в степень b.
void solution2();

// 2. 	Реализовать НОД - в виде функции.
void solution3();

// 3.	Написать функцию определения, является ли число простым.
void solution4();

// 4. Написать программу подсчёта количества “Хороших” чисел
// в диапазоне от 1 до 1 000 000. Хорошим называется число,
// которое делится на сумму своих цифр.
// Реализовать подсчёт времени выполнения программы.
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
            case 4:
                solution4();
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
    int a, b;
    printf("\n Input a:");
    scanf("%d", &a);
    printf("\n Input b :");
    scanf("%d", &b);
    int power(int a, int b) {
        int c = 1;
        for (int i = 1; i <= b; i++) {
            c = c * a;
        }
        return c;
    }
    printf("\n%d\n", power(a, b));
    system("pause");
}

void solution2() {
    int gcd(int a, int b) {
        while (a != 0 && b != 0)
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        return (a + b);
    }
    int a, b;
    printf("\n Input a:");
    scanf("%d", &a);
    printf("\n Input b :");
    scanf("%d", &b);
    printf("\n%d\n", gcd(a, b));
    system("pause");
}

void solution3() {
    _Bool isPrime(unsigned int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        double limit = sqrt(n);
        for (unsigned i = 3; i <= limit; i += 2) {
            if ((n % i) == 0) return false;
        }
        return true;
    }
    unsigned int a;
    printf("\n Input a:");
    scanf("%d", &a);
    printf("\nis %d simple? %s \n", a, (isPrime(a)) ? "true" : "false");
    system("pause");
}

void solution4() {
    int sumDigits (long a) {
        int s = 0;
        while (a > 0) {
            s = s + a % 10;
            a = a / 10;
        }
        return s;
    }
    int n = 0;
    time_start();
    for (int i = 1; i <= 1000000; i++) {
        if (i % sumDigits (i) == 0) n += 1;
    }
    printf("\nGood nums %i", n);
    printf("\nTime: %ld millisecond\n", time_stop());
    // pauseMy(); // из "моей" библиотеки
    return;
}

void menu() {

    printf("\n1-task1 power\n");
    printf("2-task2 gcd\n");
    printf("3-task3 prime\n");
    printf("4-task4 time \n");
    printf("0-exit\n");
}

// Работа со временем из Интернета
void time_start() {
    gettimeofday(&tv1, &tz);
}

long time_stop() {
    gettimeofday(&tv2, &tz);
    dtv.tv_sec = tv2.tv_sec - tv1.tv_sec;
    dtv.tv_usec = tv2.tv_usec - tv1.tv_usec;
    if (dtv.tv_usec < 0) {
        dtv.tv_sec--;
        dtv.tv_usec += 1000000;
    }
    return dtv.tv_sec * 1000 + dtv.tv_usec / 1000;
}



