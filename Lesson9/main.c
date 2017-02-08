// Чистяков Дмитрий. ДЗ 9.
#include <stdio.h>

#define T char

//
void solution1();

//
void solution2();

//
void solution3();

//
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


//============================================================
// 1.	Реализовать простейшую хеш-функцию.
// На вход функции подается строка, на выходе сумма кодов символов.
//
//
void solution1() {

    unsigned int hash(const char *str) {
        unsigned int hash = 0;
        for (; *str; str++)
            hash = hash + *str;
        return hash;
    }
    char str[80];
    (scanf("%s"), str);
    printf("%d", hash(str));
    return; // solution1
}
//
//=======================================================



//=========================================================
//2.	Переписать программу, реализующее двоичное дерево поиска.
//а) Добавить в него обход дерева различными способами.
//
//
void solution2() {

    typedef struct Node {
        T data;
        struct Node *left;
        struct Node *right;
        struct Node *parent;
    } Node;


    return;
}
//
//========================================================

void solution3() {
    return;
}

void solution4() {
    return;
}

void menu() {
    printf("\n1-hash \n");
    printf("2-task2 \n");
    printf("3-task3 \n");
    printf("4-task4 \n");

    printf("0-exit\n");
}