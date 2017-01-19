// Чистяков Дмитрий. ДЗ 3.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void solution1();
//

void solution2();
//

void solution3();

//

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

}

void solution2() {

}

void solution3() {

    system("pause");
}



void menu() {
    printf("\n1-task1\n");
    printf("2-task2\n");
    printf("3-task3\n");
    printf("0-exit\n");
}