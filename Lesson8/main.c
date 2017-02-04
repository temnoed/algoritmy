// Чистяков Дмитрий. ДЗ 8.
#include <stdio.h>
#include <malloc.h>

#define T char
#define MaxN 1000


// 1.	Добавить в программу “реализация стека на основе односвязного списка”
// проверку на выделение памяти (посмотрите в Интернете, как это сделать).
// Если память не выделяется, то выводится соответствующее сообщение.
// Постарайтесь создать ситуацию, когда память не будет выделятся.
void solution1();

//
void solution2();

//
void solution3();

//
void solution4();

// стэк на основе простого массива:
void solution7();

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
            case 7:
                solution7();
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

// 1.	Добавить в программу “реализация стека на основе односвязного списка”
// проверку на выделение памяти (посмотрите в Интернете, как это сделать).
// Если память не выделяется, то выводится соответствующее сообщение.
// Постарайтесь создать ситуацию, когда память не будет выделятся.
void solution1() {

    // Опишем структуру узла списка:
    struct TNode {
        T value;
        struct TNode *next;
    };

// Чтобы не писать везде struct TNode дадим этой структуре имя Node:
    typedef struct TNode Node;
    struct Stack {
        Node *head;
        int size;
        int maxSize;
    };

    struct Stack stack;
    stack.size = 0;

    void push(T value) {
        if (stack.size >= stack.maxSize) {
            puts("Error stack size.\n");
            //return;
        }
        // При запихивании нового элемента, создадим временный указатель на узел,
        // выделим под узел памяти и направим указатель на него:
        Node *tmp;
        if (!(tmp = (Node *) malloc(sizeof(Node)))) {
            puts("Allocation error.");
            system("pause");
            exit(1);
        }
        tmp->value = value;
        tmp->next = stack.head;
        stack.head = tmp;
        stack.size++;
    }
// Выталкиваем из списка
    T pop() {
        if (stack.size == 0) {
            puts("Stack is empty.\n");
            return '\0';
        }
// Временный указатель
        Node *next = NULL;
// Значение "наверху" списка
        T value;
        value = stack.head->value;
        next = stack.head;
        stack.head = stack.head->next;
// Запись, на которую указывала голова удаляем, освобождая память
        free(next);
// Возвращаем значение, которое было в голове
        stack.size--;
        return value;
    }
    void printStack() {
        Node *current = stack.head;
        while (current != NULL) {
            printf("%c ", current->value);
            current = current->next;
        }
    }
    stack.maxSize = 3;

    stack.head = NULL;
    push('1');
    push('2');
    push('3');
    push('4');
    push('5');
    push('6');
    printStack();
    free(stack.head);
    return; // solution1.
}

void solution2() {
    return;
}

void solution3() {
    return;
}

void solution4() {
    return;
}

// стек на основе простого массива:
void solution7() {
    int n = -1;
    T stackArr[MaxN];
    void push(T _char) {
        if (n < MaxN) {
            n++;
            stackArr[n] = _char;
        } else printf("Stack overflow");
    }

    T pop() {
        if (n != -1) return stackArr[n--];
        else {
            printf("Stack is empty");
            return 0;
        }
    }
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    push('f');
    while (n != -1) printf("%c", pop());
    return;
}

void menu() {
    printf("\n1- stack and memory error \n");
    printf("2-task2 \n");
    printf("3-task3 \n");
    printf("4-task4 \n");
    printf("7- stack by array \n");
    printf("0-exit\n");
}