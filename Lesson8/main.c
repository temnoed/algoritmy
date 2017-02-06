// Чистяков Дмитрий. ДЗ 8.
#include <stdio.h>
#include <malloc.h>

#define T int
#define MaxN 1000

//----------------Опишем структуру узла списка:

struct TNode {
    T value;
    struct TNode *next;
};
typedef struct TNode Node;

//------------------------опишем стек:

struct Stack {
    Node *head;
    int size;
    int maxSize;
};
struct Stack stack; // создадим экземпляр для стека:


//--------------------------------------------

void printStack();

//------ push and pop для простого стека-------------------

void push(T value) {
    if (stack.size >= stack.maxSize) {
        puts("Error stack size.\n");
        return;
    }
    // При запихивании нового элемента, создадим временный указатель на узел,
    // выделим под узел памяти и направим указатель на него:
    Node *tmp;

    // 1.	Добавить в программу “реализация стека на основе односвязного списка”
    // проверку на выделение памяти (посмотрите в Интернете, как это сделать).
    // Если память не выделяется, то выводится соответствующее сообщение.
    // Постарайтесь создать ситуацию, когда память не будет выделятся.
    // чтобы "вырубить" память откусываем очень большой кусок:
    // if (!(tmp = (Node *) malloc(1024*1024*1024))) {

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

//------------------------------------



//-------------------------------------------------

void solution1() {

    stack.size = 0;
    stack.maxSize = MaxN;
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

//------------------------------------------------
// 2.	Написать программу, которая определяет, является ли введённая
// скобочная структура правильной.
// Примеры правильных скобочных выражений: (), (())(), ()(), ((())),
// неправильных — )(, ())((), (, )))), ((()):


void solution2() {

    stack.size = 0;
    stack.maxSize = MaxN;
    stack.head = NULL;

    char isBreketsGood(char *str) {

        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{') push(str[i]);
            if (str[i] == ')')
                if (pop() != '(') return '0';
            if (str[i] == ']')
                if (pop() != '[') return '0';
            if (str[i] == '}')
                if (pop() != '{') return '0';

            i++;
        }
        if (pop() == '\0') return '1'; // флаг 1 - корректно, 0 - скобки стоят неправильно.
        else return '0';
    }


    char strGood[] = "([] Miru Mir ! []) {}[]{{({})}}()";
    char strBad[] = "([)]{(})";
    printf("String: %s has flag: %c\n", strGood, isBreketsGood(strGood));
    printf("String: %s has flag: %c\n", strBad, isBreketsGood(strBad));
    return; // solution2.
}




//-------------------------------------------
// 3.	Создать стек на основе закольцованного списка.
// описание узла и стека будут такие же как у линейного списка.
// различие в push, pop и print:

void solution3() {
    struct Stack ringStack; // экземпляр стека для кольца
    ringStack.size = 0;
    ringStack.head = NULL;
    ringStack.maxSize = MaxN;

    //-------------------------push для кольцевого стека:

    void pushRing(T _value) {

        if (ringStack.size >= ringStack.maxSize) {
            puts("Error stack size.\n");
            return;
        }

        // При запихивании нового элемента, создадим временный указатель на узел,
        // выделим под узел памяти:
        Node *tmp;
        if (!(tmp = (Node *) malloc(sizeof(Node)))) {
            puts("Allocation error.");
            system("pause");
            exit(1);
        }

        // когда добавляем первый элемент:
        if (ringStack.head == NULL) {
            tmp->value = _value;
            tmp->next = tmp;
            ringStack.head = tmp;

            // когда вставляем следующий элемент в кольцо:
        } else {
            tmp->value = _value;
            tmp->next = ringStack.head->next;
            ringStack.head->next = tmp;
            ringStack.size++;
        }
    }

    //--------------печать кольцевого стека:

    void printRingStack() {

        if (ringStack.head) {
            Node *current = ringStack.head->next;
            do {
                printf("%c ", current->value);
                current = current->next;
            } while (current != ringStack.head->next);

        } else puts("stack is empty");
    }

    //-----------------------------------------

    pushRing('0');
    pushRing('1');
    pushRing('2');
    pushRing('3');
    pushRing('4');
    printRingStack();
    free(ringStack.head);
    return; //solution 3.
}






//------------------------------------
// 4.	***Создать функцию SortPush, которая вставляет узел в односвязный список таким образом,
// чтобы список был отсортирован. Продемонстрировать работу программы.

void solution4() {

    stack.size = 0; // готовим пустой список
    stack.maxSize = MaxN;
    stack.head = NULL;


    void sortPush(T _value) {

        if (stack.size >= stack.maxSize) { // проверяем список на заполненность
            puts("List overflow!");
            system("pause");
            return;
        }


        Node *newNode; // создаём новый узел и выделяем под него память:
        if (!(newNode = (Node *) malloc(sizeof(Node)))) {
            puts("Memory allocation error.");
            system("pause");
            exit(1);
        }
        newNode->value = _value;
        stack.size++;


        //    если список ещё пуст, ставим узел первым
        if (stack.head == NULL) {
            newNode->next = NULL;
            stack.head = newNode;
            return;
        }


        //    сортируем-находим нужное место при помощи временного указателя
        Node *temp;
        temp = stack.head;
        while (temp->next != NULL && temp->next->value < _value) {
            temp = temp->next;
        }


        //    и вставляем элемент
        newNode->next = temp->next;
        temp->next = newNode;
    }   //          end sortPush()


    sortPush(65);
    sortPush(67);
    sortPush(66);
    sortPush(69);
    sortPush(68);
    sortPush(68);
    sortPush(68);
    sortPush(65);
    printStack();

    return; //solution4.
}




//-------------------------- стек на основе простого массива:

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

//------------------------

void menu() {
    printf("\n1 - stack and memory error \n");
    printf("2 - brackets \n");
    printf("3 - ring stack \n");
    printf("4 - sortPush \n");
    printf("7 - stack by simple array \n");
    printf("0 -exit\n");
}


//------------------------------


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


//------------------------------вывод на экран стека:


void printStack() {
    Node *current;
    current = stack.head;
    if (stack.head == NULL) puts("Stack is empty.");
    else
        while (current != NULL) {
            printf("%c ", current->value);
            current = current->next;
        }
    free(current);
    puts("");
    return;
}


//-----------------------------------