#include <stdio.h>
#include <afxres.h>
#include <sys/time.h>

// Используем массив 100*100 для простоты и  заполняем
// его рандомами сначала классическим методом, а
// потом указателями.
#define MaxArr 100

// ----Запоминаем в глобальных переменных текущее время
struct timeval tv1, tv2, dtv;
struct timezone tz;

void time_start();

long time_stop();

//-----------------------------
void main() {
    int n = MaxArr;
    int i, j;
    int *b;
    int a[n][n];
    b = &a[0][0];
// заполняем двумерный случайными интами
    time_start();

    srand(time(NULL));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            a[i][j] = (rand() % 100);
        }
    // выводим двумерный
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10d", a[i][j]);
        printf("\n");
    }
    printf("\nTime: %ld millisecond\n", time_stop());
    system("pause");
    //------------------
    // --- заполняем указателями:
    time_start();

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            *(b + i * n + j) = rand() % 100;
        }
    }
// -------------выводим указателями
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10d", *(b + i * n + j));// Получаем значение из рассчитанного адреса
        printf("\n");
    }
    printf("\nTime: %ld millisecond\n", time_stop());
    system("pause");
    //---------------------
    return;
}
//----------------------------------
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