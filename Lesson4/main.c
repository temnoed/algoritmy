// Чистяков Дмитрий. ДЗ 4.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MaxArr 100 // компилятору размер массива

void solution1(int _arr[]);
// a.	ввод массива с клавиатуры;

void solution2(int _arr[]);
// b.	заполняет массив случайными числами;

int getSum(int _arr[]);
// c.	подсчет суммы элементов;

double getMean(int _arr[]);
// d. подсчет среднего арифметического элементов;

void showMaxDev(int _arr[]);
//  e.	нахождения номера первого элемента,
// который максимально отличается от среднего арифметического;

int getMax(int _arr[]);
// f. находит максимальное число в массиве;

//void solution7();
//
//void solution8();
//
//void solution9();
//
//void solution10();
//
void menu();

int main() {
    int arr[MaxArr]; // создали массив на 100 интов
    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                solution1(arr);
                break;
            case 2:
                solution2(arr);
                break;
            case 3:
                getSum(arr);
                break;
            case 4:
                getMean(arr);
                break;
            case 5:
                showMaxDev(arr);
                break;
            case 6:
                getMax(arr);
                break;
//            case 7:
//                solution7();
//                break;
//            case 8:
//                solution8();
//                break;
//            case 9:
//                solution9();
//                break;
//            case 10:
//                solution10();
//                break;
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

void solution1(int *_arr) { // ввод массива с клавиатуры

    int n;
    do {
        printf("Input grade numbers for KEY(1..%i):", MaxArr);
        scanf("%i", &n);
    } while (n < 1 || n > MaxArr);
    int i;
    for (i = 0; i < n; i++) {
        printf("Input grade %i\n", i);
        scanf("%i", &_arr[i]);
    }
    printf("%10s%10s\n", "Number", "Grade");
    for (i = 0; i < n; i++) {
        printf("%10i%10i\n", i, _arr[i]);
    }
    return;
}

void solution2(int _arr[]) { // заполняем массив случайными числами
    //  Как, всё таки, лучше инициализировать массив при помощи *arr или arr[] ?
    int n;
    do {
        printf("Input grade numbers for RANDOM(1..%i):", MaxArr);
        scanf("%i", &n);
    } while (n < 1 || n > MaxArr);
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        _arr[i] = (rand() % 100);
    }
    printf("%10s%10s\n", "Number", "Grade");
    for (i = 0; i < n; i++) {
        printf("%10i%10i\n", i, _arr[i]);
    }
    return;
}

int getSum(int _arr[]) { // подсчёт суммы элементов массива
    int n, sum = 0;
    do {
        printf("Input grade numbers for SUM(1..%i):", MaxArr);
        scanf("%i", &n);
    } while (n < 1 || n > MaxArr);
    printf("%10s%10s\n", "Number", "Grade");
    for (int i = 0; i < n; i++) {
        sum += _arr[i];
        printf("%10i%10i\n", i, _arr[i]);
    }
    printf("Sum = %i\n", sum);
    system("pause");
    return sum;
}

double getMean(int _arr[]) { // среднее арифметическое элементов массива
    double mean;
    int length;
    do {
        printf("Input grade numbers for MEAN(1..%i):", MaxArr);
        scanf("%i", &length);
    } while (length < 1 || length > MaxArr);
    mean = getSum(_arr) / length;
    printf("Mean = %f\n", mean);
    system("pause");
    return mean;
}

void showMaxDev(int *_arr) {
// нахождения номера первого элемента,
// который максимально отличается от среднего арифметического;
    int i = 0, length;
    double mean;
    mean = getMean(_arr);
    do {
        printf("\n Input grade numbers for show index MaxDev(1..%i):", MaxArr);
        scanf("%i", &length);
    } while (length < 1 || length > MaxArr);
    for (int j = 0; j < length; j++) {
        if (fabs((_arr[j] - mean)) > fabs((_arr[i] - mean))) {
            i = j;
        }
    }
    printf("Max deviation index = %d\n", i);
    system("pause");
    return;
}

int getMax (int *_arr) { // ищем наибольшее число в массиве
    int length;
    do {
        printf("\n Input grade numbers for show MAX(1..%i):", MaxArr);
        scanf("%i", &length);
    } while (length < 1 || length > MaxArr);
    int max = _arr[0];
    for (int i = 1; i < length; i++)
        if (_arr[i] > max)
            max = _arr [i];
    printf("Max = %d\n", max);
    system("pause");
    return max;
}

void menu() {

    printf("\n1-task1 keyboard\n");
    printf("2-task2 random\n");
    printf("3-task3 sum\n");
    printf("4-task4 mean\n");
    printf("5-task5 max deviation index\n");
    printf("6-task6 max num\n");
    printf("0-exit\n");
}

