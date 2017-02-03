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
int *ptrDesk;

// длина маршрута всего ходов:
int maxMove = deskX * deskY;

// счётчики ходов:
int stepCount;
unsigned int stepCountGlobal;

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
static int *ptrVektorXY;

//----------------рисуем доску методом []
void drawDesk() {
    int i, j;
    system("cls");
    for (i = 0; i < deskY; i++) {
        for (j = 0; j < deskX; j++) {
            printf("%4d", desk[i][j]);
        }
        puts("\n");
    }
    stepCountGlobal++;
    printf("Move mumber %d\n", stepCountGlobal);
    printf("Time: %ld millisecond\n", time_stop());
    //system("pause");
}
//----------------рисуем доску методом pointer
void drawDeskPointer() {
    int i, j;
    system("cls");
    for (i = 0; i < deskY; i++) {
        for (j = 0; j < deskX; j++) {
            //printf("%4d", desk[i][j]);
            printf("%4d", *(ptrDesk + i * deskY + j));
        }
        puts("\n");
    }
    stepCountGlobal++;
    printf("Move mumber %d\n", stepCountGlobal);
    printf("Time: %ld millisecond\n", time_stop());
    //system("pause");
}
//---------------start menu
void menu() {
    printf("\n1 - array [] method \n");
    printf("2 - array pointer method \n");
    printf("0 - exit\n");
}
//------------------------
// поиск хода методом []
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
//------------------------
// поиск хода методом pointer
// на выходе функции будет 0, если в данную клетку нельзя встать конём,
// на вход подаются текущие координаты коня:
int getStepPointer(int x, int y) {
    int i = 0;
    int result = 0;
    // проверяем на выход за пределы поля:
    if (x < 0 || x > 4 || y < 0 || y > 4) result = 0;
    else {
        // проверяем был ли конь тут раньше:
        if (*(ptrDesk + y * deskX + x) != 0) result = 0;
        else {
            // считаем номер хода:
            *(ptrDesk + y * deskX + x) = ++stepCount;
            drawDeskPointer();
            // проверяем на конец маршрута:
            if (stepCount == maxMove) result = 1;
            else {
                // перебираем возможные ходы из данной точки дальше
                while (i < 8 & result != 1) {
                    // рекурсивное ветвление с проверкой на возможность ходить дальше и на конец маршрута
                    if (getStep(x + *(ptrVektorXY + i * 2 ), y + *(ptrVektorXY + i * 2 + 1 ))) result = 1;
                    i++;
                }
                // если следующий ход невозможен,
                if (result == 0) {
                    // уменьшаем счётчик ходов
                    stepCount--;
                    // отходим с данной клетки
                    *(ptrDesk + y * deskX + x) = 0;
                }
            }
        }
    }
    return result;
}
//----------------------обнуляем доску и запускаем поиск хода методом []
void path(int x0, int y0) {
    int i, j;
    for (i = 0; i < deskY; i++)
        for (j = 0; j < deskX; j++)
            desk[i][j] = 0;
    // обнуляем счётчик ходов
    stepCount = 0;
    getStep(x0, y0);
}
//----------------------обнуляем доску и запускаем поиск хода методом pointer
void pathPointer(int x0, int y0) {
    int i, j;
    for (i = 0; i < deskY; i++)
        for (j = 0; j < deskX; j++)
            // desk[i][j] = 0;
            *(ptrDesk + i * deskX + j) = 0;
    // обнуляем счётчик ходов
    stepCount = 0;
    getStepPointer(x0, y0);
}
//-------------------------method []
void solution1() {
    stepCountGlobal = 0;
    time_start();
    // стартуем из этой координаты, потому что
    // из неё точно есть решение:
    path(2, 2);
    system("pause");
    return;
}
//-------------------------method pointer
void solution2() {
    stepCountGlobal = 0;
    time_start();
    // стартуем из этой координаты, потому что
    // из неё точно есть решение:
    pathPointer(2, 2);
    system("pause");
    return;
}
//------------------------------main
int main() {
    // указатель определяет начало массива доски и ходов:
    ptrDesk = &desk[0][0];
    ptrVektorXY = & vektorXY[0][0];
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

//---------------------- Работа со временем
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
//--------------------------