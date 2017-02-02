// Чистяков Дмитрий. Алгоритмы. ДЗ7.
// Рекурсия с возвратом. Обход доски конём.
// Готовое решение с опечатками оформлено и подправлено из
// "Язык Си: шаг за шагом (автоматизация и применение)" Романов Е.Л.
// Изначально у автора в функции было 5 операторов return.
#include <stdio.h>
#include <stdlib.h>
#include <afxres.h>
#include <sys/time.h>
// подключаем время
struct timeval tv1, tv2, dtv;
struct timezone tz;
void time_start();
long time_stop();

// Используем глобальные переменные как в оригинале решения
// размер доски 5*5 для ускорения:
#define deskX 5
#define deskY 5
int desk[deskY][deskX];

// длина маршрута всего ходов:
int maxMove = deskX * deskY;

// счётчик ходов:
int stepCount;

// описание хода коня в массиве из 8 векторов
static int vektorXY[8][2] = {{1,  -2},
                             {1,  2},
                             {-1, -2},
                             {-1, 2},
                             {2,  -1},
                             {2,  1},
                             {-2, 1},
                             {-2, -1}
};

// рисуем доску
void drawDesk() {
    int i, j;
    system("cls");
    for (i = 0; i < deskY; i++) {
        for (j = 0; j < deskX; j++) {
            printf("%4d", desk[i][j]);
        }
        puts("\n");
    }
    printf("Move mumber %d\n", stepCount);
    printf("Time: %ld millisecond\n", time_stop());
    //system("pause");
}

// поиск хода
// на выходе функции будет 0, если в данную клетку нельзя встать конём,
// на вход подаются текущие координаты коня:
int getStep(int x, int y) {
    int i = 0;
    int result = 0;
    // проверяем на выход за пределы поля:
    if (x < 0 || x > 4 || y < 0 || y > 4) result = 0;
    else {
        // проверяем был ли конь тут раньше:
        if (desk[x][y] != 0) result = 0;
        else {
            // считаем номер хода:
            desk[x][y] = ++stepCount;
            drawDesk();
            // проверяем на конец маршрута:
            if (stepCount == maxMove) result = 1;
            else {
                // перебираем возможные ходы из данной точки дальше
                while (i < 8 & result != 1) {
                    // рекурсивное ветвление с проверкой на возможность ходить дальше и на конец маршрута
                    if (getStep(x + vektorXY[i][0], y + vektorXY[i][1])) result = 1;
                    i++;
                }
                // если следующий ход невозможен,
                if (result == 0) {
                    // уменьшаем счётчик ходов
                    stepCount--;
                    // отходим с данной клетки
                    desk[x][y] = 0;
                }
            }
        }
    }
    return result;
}

// обнуляем доску и запускаем поиск хода
void path(int x0, int y0) {
    int i, j;
    for (i = 0; i < deskY; i++)
        for (j = 0; j < deskX; j++)
            desk[i][j] = 0;
    // обнуляем счётчик ходов
    stepCount = 0;
    getStep(x0, y0);
}

int main() {
    time_start();
    // стартуем из этой координаты, потому что
    // из неё точно есть решение:
    path(2, 2);
    system("pause");
    return 0;
}

// Работа со временем
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
