// Рекурсия с возвратом. Обход доски конём.
// Готовое решение с опечатками оформлено и подправлено из
// "Язык Си: шаг за шагом (автоматизация и применение)" Романов Е.Л.
// А также "Алгоритмы и структуры данных" Вирт Н.
#include <stdio.h>
#include <stdlib.h>

// Используем глобальные переменные как в оригинале решения
// размер доски 5*5 для ускорения:
#define deskX 5
#define deskY 5
int desk[deskY][deskX];
int maxMove = deskX * deskY;

// счётчик ходов:
int stepCount;
int result = 0;

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
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%4d", desk[i][j]);
        }
        puts("\n");
    }
    printf("%d - move mumber.\n", stepCount);
    //system("pause");
}

// поиск хода:
// на вход подаются текущие координаты коня
int getStep(int x, int y) {



    int i;
    if (x < 0 || x > 4 || y < 0 || y > 4)
        return (0);
    if (desk[x][y] != 0)
        return (0);

    //отметить свободное поле
    desk[x][y] = ++stepCount;
    drawDesk();

    if (stepCount == 25)
        return (1);
    for (i = 0; i < 8; i++)
        if (getStep(x + vektorXY[i][0], y + vektorXY[i][1]))
            return 1;
    stepCount--;
    desk[x][y] = 0;
    return 0;
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
    // стартуем из этой координаты, потому что
    // из неё точно есть решение:
    path(2, 2);
    drawDesk();
    system("pause");
    return 0;
}