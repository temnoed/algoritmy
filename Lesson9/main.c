// Чистяков Дмитрий. ДЗ 9.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define T char


void solution1();

void solution2();

void menu() {
    printf("\n1- hash \n");
    printf("2 - binary tree base \n");
    printf("0-exit\n");
}

int main() {
    solution2();
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
//
//
//=======================================================
// 2.	Переписать программу, реализующее двоичное дерево поиска.
// а) Добавить в него обход дерева различными способами.
// б) *Добавить в программу обработку командной строки
// с помощью которой можно указывать из какого файла считывать данные,
// каким образом обходить дерево.
// 3.	Разработать базу данных студентов из двух полей “Имя”,
// “Возраст”, в которой использовать все знания, полученные на уроках.
// Считайте данные в двоичное дерево поиска.
// Реализуйте поиск по какому-нибудь полю базы данных (возраст).
//
//
void solution2() {

    struct Record_ { // делаем структуру для записи базы данных
        char name[10];
        int age;
    };
    typedef struct Record_ Record;

    struct Node_ { // структура для узла в дереве
        Record* record; // на дереве висят записи
        struct Node_ *left;
        struct Node_ *right;
        struct Node_ *parent;
    };
    typedef struct Node_ Node;


    //Распечатка двоичного дерева в виде скобочной записи
    void printTree(Node *root) {
        if (root) {
            printf("%s %d", root->record->name, root->record->age);
            if (root->left || root->right) {
                printf("(");
                if (root->left) printTree(root->left); else printf("NULL");
                printf(",");
                if (root->right) printTree(root->right); else printf("NULL");
                printf(")");
            }
        }
    }


    //Создание нового узла
    Node *getFreeNode(Record* record_, Node *parent) {
        Node *tmp = (Node *) malloc(sizeof(Node));
        tmp->left = tmp->right = NULL;
        tmp->record = record_;
        tmp->parent = parent;
        return tmp;
    }


    //Вставка узла
    void insertNode(Node **head, Record* newRecord) {
        Node *tmp = NULL;
//   Node *ins = NULL;
        if (*head == NULL) {
            *head = getFreeNode(newRecord, NULL);
            return;
        }
        tmp = *head;
        while (tmp) {
            if (newRecord->age > tmp->record->age) {
                if (tmp->right) {
                    tmp = tmp->right;
                    continue;
                } else {
                    tmp->right = getFreeNode(newRecord, tmp);
                    return;
                }
            } else if (newRecord->age < tmp->record->age) {
                if (tmp->left) {
                    tmp = tmp->left;
                    continue;
                } else {
                    tmp->left = getFreeNode(newRecord, tmp);
                    return;
                }
            } else {
                exit(2);//дерево построено не правильно
            }
        }
    }



    // виды обходов двоичного дерева:
    //- КЛП “корень-левый-правый” (обход в прямом порядке, pre-order):
    void preOrderTravers(Node *root) {
        if (root) {
            printf("%d ", root->record->age);
            preOrderTravers(root->left);
            preOrderTravers(root->right);
        }
    }
    //- ЛКП - “левый - корень - правый” (симметричный обход, in-order):
    void inOrderTravers(Node *root) {
        if (root) {
            inOrderTravers(root->left);
            printf("%d ", root->record->age);
            inOrderTravers(root->right);
        }
    }
    //- ЛПК - “левый - правый - корень” (обход в обратном порядке, post-order):
    void postOrderTravers(Node *root) {
        if (root) {
            postOrderTravers(root->left);
            postOrderTravers(root->right);
            printf("%d ", root->record->age);
        }

    }

    // читаем дерево из файла в указатель
    Node *readFile(const char *fileName) {
        FILE *in = NULL;
        Node *ptrTree_ = NULL;

        in = fopen(fileName, "r");
        if (in == NULL) {
            puts("Can't read file! \n");
            system("pause");
            exit(1);
        }

        char nextName[10];
        int nextAge;
        while (!feof(in)) {
            fscanf(in, "%s %d", nextName, &nextAge);
            printf("%s %d", nextName, nextAge);
            _getch();
        }
        fclose(in);

        return ptrTree_;
    }
//---------------------------------------------------

    // ввод данных из консоли
    system("cls");
    char fileName[80] = "base.txt"; // файл с базой данных
//    puts("Enter file name: ");
//    scanf("%s", fileName);
//    char traversMethod; // способ обхода двоичного древа
//    puts("Enter tree travers method (pre-1, in-2, post-3): ");
//    scanf("%s", &traversMethod);
//    int age; // возраст для поиска фамилии
//    puts("Enter age to looking for: ");
//    scanf("%i", &age);

    // читаем дерево из файла в указатель
    Node *ptrTree;
    readFile(fileName);
    printTree(ptrTree);
    system("pause");
    return;
}
//
//========================================================



