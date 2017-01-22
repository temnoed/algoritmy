// Чистяков Дмитрий. ДЗ 4.
#include <stdio.h>
#include <stdlib.h>


void solution1();


void solution2();


void solution3();


void solution4();


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

    system("pause");
}

void solution2() {

    system("pause");
}

void solution3() {

    system("pause");
}

void solution4() {

    return;
}

void menu() {

    printf("\n1-task1 \n");
    printf("2-task2 \n");
    printf("3-task3 \n");
    printf("4-task4  \n");
    printf("0-exit\n");
}

