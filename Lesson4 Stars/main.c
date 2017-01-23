// Чистяков Дмитрий. ДЗ 4 со звёздочками!
// Вопрос по заданию такой:
// мы читаем из файла в массив при помощи метода  fscanf(),
// который выполняет форматированное чтение чисел,
// опираясь на разделитель \n.
// Каким методом читать из файла по четыре байта (int)
// без разделителя?
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// для простоты размер массива всегда 100
#define MaxArr 100

// читаем из файла в массив 100 чисел
short readFile(int *_arr);

// записываем в файл 100 случайных чисел
short writeFile();

// вывод массива на экран
void showArray(int *_arr);

// ищем все наибольшие отклонения от среднего и кладём их
// в массив arrResult
void getAllMaxDev(int *_arr);

double getMean(int _arr[]);

void menu();

int main() {
    int arr[MaxArr];
    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                readFile(arr);
                break;
            case 2:
                writeFile();
                break;
            case 3:
                showArray(arr);
                break;
            case 4:
                getAllMaxDev(arr);
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

// считываем из файла 100 чисел прямо в массив
short readFile(int _arr[]) {
    FILE *in;
    int length = 0, nextInt, i;
    in = fopen("d:\\temp\\data01.txt", "r");
    if (in == NULL) {
        puts("Can't read file! \n");
        system("pause");
        return 1;
    }
    // читаем заголовок-размер массива
    if (!feof(in)) {
        fscanf(in, "%d", &length);
    }
    // затем заполняем массив
    for (i = 0; i < MaxArr; i++) {
        if (!feof(in)) {
            // прямо в массив не хочет читать,
            // поэтому имеем промежуточную переменную nextInt
            fscanf(in, "%d", &nextInt);
            _arr[i] = nextInt;
        }
    }
    fclose(in);
    printf("Grade %d\n", i);
    puts("Done! \n");
    system("pause");
    return 0;
}

// заполняем файл 100 случайными числами
short writeFile() {
    FILE *out;
    out = fopen("D:\\temp\\data01.txt", "w");
    if (out == NULL) {
        puts("Can't write file! \n");
        system("pause");
        return 1;
    }
    fprintf(out, "%d\n", MaxArr);
    srand(time(NULL));
    for (int i = 0; i < MaxArr; i++)
        fprintf(out, "%d\n", (rand() % 100));
    fclose(out);
    puts("Done! \n");
    system("pause");
    return 0;
}

void showArray(int *_arr) {
    for (int i = 0; i < MaxArr; i++) {
        printf("%10i%10i\n", i, _arr[i]);
    }
    system("pause");
}

void getAllMaxDev(int *_arr) {
    // первым делом получаем среднее
    double mean;
    mean = getMean(_arr);
    int arrResult[MaxArr];
    int j;
    // изначально нулевой элемент имеет самое большое отклонение
    arrResult[0] = 0;
    double maxDev = fabs((_arr[0] - mean));
    int countResult = 1;
    for (j = 0; j < MaxArr; j++) {
        if (fabs((_arr[j] - mean)) == maxDev) {
            arrResult[countResult] = j;
            countResult++;
        };
        if (fabs((_arr[j] - mean)) > maxDev) {
            maxDev = fabs((_arr[j] - mean));
            arrResult[0] = j;
            countResult = 1;
        };
    }
    puts("Max deviant from mean indexes:\n");
    for (j = 0; j < countResult; j++) {
        printf("%i\n", arrResult[j]);
    }
    system("pause");
    return;
}

void menu() {
    printf("\n1-task1 read file 100 int \n");
    printf("2-task2 write file 100 random \n");
    printf("3-task3 show array\n");
    printf("4-task4 get all Max Deviant from mean \n");
    printf("0-exit\n");
}

// подсчёт суммы 100 элементов массива
int getSum(int _arr[]) {
    int n = 100, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += _arr[i];
    }
    return sum;
}
// среднее арифметическое 100 элементов массива
double getMean(int _arr[]) {
    double _mean = 0;
    int length = 100;
    _mean = getSum(_arr) / length;
    return _mean;
}