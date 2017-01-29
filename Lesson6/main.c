// Чистяков Дмитрий. ДЗ 6.
#include <stdio.h>
#include <stdlib.h>

// 1. вводим строку символов
void solution1(char *ptrStr);

// 1-a. сколько раз символ входит в строку
void solution2(char *ptrStr);

//
void solution3();

//
void solution4();

void menu();


int main() {
    //Строка, которая используется
    char ptrString[128] = "";
    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                solution1(ptrString);
                printf("Was entered: %s\n", ptrString);
                break;
            case 2:
                solution2(ptrString);
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

// вводим строку символов
void solution1(char *ptrStr) {
    puts("Enter original string: ");
    // почему не работает метод gets?
    //gets(ptrStr);
    scanf("%127s", ptrStr);
    return;
}

// считаем сколько раз символ присутствует в строке
int countSymbols(char *ptrStr, char symbol) {
    int result = 0, i = 0;
    while (*(ptrStr + i) != '\0') {
        if (*(ptrStr + i) == symbol) result++;
        i++;
    }
    return result;
}

// Задание 1-a. сколько раз символ входит в строку
void solution2(char *ptrStr) {
    int result = 0;
    char sym = 0;
    puts("Enter the symbol: ");
    scanf("%s", &sym);
    printf("Was entered symbol: %c\n\n", sym);
    result = countSymbols(ptrStr, sym);
    printf("Count symbols in original string: %d\n", result);
    system("pause");
    return;
}


void solution3() {
    return;
}

void solution4() {
    return;
}

void menu() {
    printf("\n1-task1 enter string \n");
    printf("2-task 1-a count symbols in string\n");
    printf("3-task3 \n");
    printf("4-task4 \n");

    printf("0-exit\n");
}