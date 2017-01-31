// Чистяков Дмитрий. ДЗ 5.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MaxArr 20 // компилятору размер массива

// пузырьковая
int* solution1(int arr[]);

// оптимизированная пузырьковая
int* solution2(int arr[]);

// шейкерная
void solution3(int *arr);

// 3.	Реализовать бинарный алгоритм поиска в виде функции,
// которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или -1,
// если элемент не найден.
void solution4(int arr[]);

void swap(int *a, int *b);

void print(int N, int *a);

void init(int *arr, int *array);

void menu();

int main() {
    int array[MaxArr] = {2, 5, 17, 8, 90, 0, 13, 45, 67, 56, 6, 98, 45, 88, 34, 67, 45, 7, 71, 34}; // создали массив
    // передавать на обработку будем arr, чтобы "оригинал" не менялся
    int arr[MaxArr];

    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                init(arr, array);
                solution1(arr);

                break;
            case 2:
                init(arr, array);
                solution2(arr);
                break;
            case 3:
                init(arr, array);
                solution3(arr);
                break;
            case 4:
                init(arr, array);
                // передаём отсортированный массив
                solution4(solution2(arr));
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

// bubble sort
int* solution1(int *arr) {
    int n = MaxArr;
    int i;
    int j = 0;
    // вводим счётчик
    int count = 0;

    puts("\nArray before sort: ");
    print(n, arr);
    for (i = 0; i < n; i++)
        for (j = 0; j < n - 1; j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                count++;
                swap(&arr[j], &arr[j + 1]);
            }
        }
    puts("\nArray after sort: ");
    print(n, arr);
    printf("\ncount= %d\n", count);
    system("pause");
    return arr;
}

// опитимизированная пузырьковая
int* solution2(int *arr) {
    int n = MaxArr;
    int i;
    int j = 0;
    // вводим счётчик
    int count = 0;
    short flag = 1;
    puts("\nArray before sort: ");
    print(n, arr);
    // во первых, уменьшаем внешний цикл до n - 1
    for (i = 0; ((i < n - 1) & (flag = 1)); i++) {
        flag = 0;
        // во вторых, внутренний цикл до n-i-1
        for (j = 0; (j < n - 1 - i); j++) {
            count++;
            if (arr[j] > arr[j + 1]) {
                count++;
                swap(&arr[j], &arr[j + 1]);
                // в третьих, используем flag для уменьшения лишних итераций
                flag = 1;
            }
        }
    }
    puts("\nArray after sort: ");
    print(n, arr);
    printf("\ncount= %d\n", count);
    system("pause");
    return arr;
}

// шейкерная:
void solution3(int *arr) {
    int size = MaxArr;
    int left_idx = 0;
    int right_idx = size - 1;
    int i = 0;
    int count = 0;
    puts("\nArray before sort: ");
    print(size, arr);
    do {
        for (i = left_idx; i < right_idx; i++) {
            count++;
            if (arr[i + 1] < arr[i]) {
                count++;
                swap(&arr[i], &arr[i + 1]);
            }
        }
        right_idx--;

        for (i = right_idx; i > left_idx; i--) {
            count++;
            if (arr[i - 1] > arr[i]) {
                count++;
                swap(&arr[i], &arr[i - 1]);
            }
        }
        left_idx++;
    } while (left_idx <= right_idx);
    puts("\nArray after sort: ");
    print(size, arr);
    printf("\ncount= %d\n", count);
    system("pause");
    return;
}
// бинарный поиск индекса в отсортированном массиве
int searchBinIdx(int arr[], int value) {
    print(MaxArr, arr);
    int result;
    int m = MaxArr;
    int l = 0, r = m - 1;
    m = l + (r - l) / 2;
    while (l <= r && arr[m] != value) {
        if (arr[m] < value) l = m + 1;
        else r = m - 1;
        m = l + (r - l) / 2;
    }
    if (arr[m] == value) result = m;
      else result = -1;
    return result;
}

// 3.	Реализовать бинарный алгоритм поиска в виде функции,
// которой передается отсортированный массив.
// Функция возвращает индекс найденного элемента или -1,
// если элемент не найден.
void solution4(int *_arr) {
    print(MaxArr, _arr);
    int x;
    puts("Vvedite element X dlya poiska: ");
    scanf("%i", &x);
    printf("Naiden index: %d \n", searchBinIdx(_arr, x));
    system("pause");
    return;
}

void menu() {

    printf("\n1-task1 bubble sort\n");
    printf("2-task2 bubble optimised\n");
    printf("3-task3 cocktail \n");
    printf("4-task4 search binary\n");
    printf("0-exit\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void print(int N, int *a) {
    int i;
    for (i = 0; i < N; i++)
        printf("%6i", a[i]);
    printf("\n");
}

void init(int *arr, int *array) {
    for (int i = 0; i < MaxArr; i++) {
        arr[i] = array[i];
    }
}