// Чистяков Дмитрий. ДЗ 6.
// Сделаны основные задачи и две со звёздочками
// Вопросы: что происходит с памятью если не освобождать её методом free,
// например, если произошёл return и внутри блока была инициализирована *str?
//
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mem.h>

// определяем структуру для хранения строк
struct MyString {
    // сама строка
    char *string;
    // её длина в символах
    size_t sizec;
    // взято под неё байт памяти
    size_t sizeb;
};

// прототип метода вводящего строку с клавиатуры и выделяющего память
struct MyString getMyStr();

// 1. вводим строку символов
char *solution1();

// 1-a. сколько раз символ входит в строку
void solution2(char *ptrStr);

// 1-б. есть ли в строке гласные буквы
void solution3(char *ptrStr);

// 1-c Написать собственную функцию аналог strlen.
size_t MyStrLen(char *ptrStr);

// 1-d which vowel is more repeated
// e.	**Предусмотреть, что некоторые гласные могут встречаться одинаково часто.
// В этом случае вывести сообщение, что нет наиболее часто встречающейся гласной.
void solution5(char *ptrStr);

void menu();

// ищем наибольшее число в массиве
int getMax(int *_arr, unsigned int length);

// ищем индекс наибольшего числа в массиве
int getMaxIdx(int *_arr, unsigned int length);

// поиск индекса первого дубликата
int findDublicateIdx(unsigned int n, int *array);

// проверка есть ли дубликат у данного индекса
int hasDublicates(int idx, int *array, unsigned int length);

// вывод массива на  экран
void showArray(int *_arr, unsigned int length);

int main() {
    //Строка, которая используется
    char *ptrString = NULL;
    int sel;
    do {
        menu();
        scanf("%i", &sel);
        switch (sel) {
            case 1:
                ptrString = solution1();
                printf("Was entered: %s\n", ptrString);
                break;
            case 2:
                solution2(ptrString);
                break;
            case 3:
                solution3(ptrString);
                break;
            case 4:
                printf("%d", strlen(ptrString));
                printf("String has %3d letters.\n", MyStrLen(ptrString));
                break;
            case 5:
                solution5(ptrString);
                break;
            case 0:
                printf("Bye-bye");
                free(ptrString);
                break;
            default:
                printf("Wrong selected\n");
                break;
        }
    } while (sel != 0);
    return 0;
}

// вводим строку символов
char *solution1() {
    char *ptrStr;
    puts("Enter original string: ");
    ptrStr = getMyStr().string;
    return ptrStr;
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

// 1-b. есть ли в строке гласные буквы
void solution3(char *ptrStr) {
    char *strVowel = "AEIOUYaeiouy";
    if (strpbrk(ptrStr, strVowel) == NULL) {
        puts("Vowels -");
    } else {
        puts("Vowels +");
    }
    return;
}

// 1-c. Написать собственную функцию аналог strlen.
size_t MyStrLen(char *ptrStr) {
    size_t result = 0;
    while (*(ptrStr + result) != '\0') result++;
    return result;
}

// 1-d, e. Какая гласная чаще других.
// e.	**Предусмотреть, что некоторые гласные могут встречаться одинаково часто.
// В этом случае вывести сообщение, что нет наиболее часто встречающейся гласной.
void solution5(char *ptrStr) {
    char strVowel[13] = "AEIOUYaeiouy";
    // создадим массив-счётчик гласных по номерам
    int amtVowels[6] = {0, 0, 0, 0, 0, 0};
    char result = 0;
    size_t position = 0;
    int i;
    // проходимся по всем символам в строке
    while (*(ptrStr + position) != '\0') {
        // проходимся по всем гласным
        for (i = 0; i < 6; i++) {
            // если найдена гласная ЗАГЛАВНАЯ
            if (*(ptrStr + position) == (*(strVowel + i))) {
                // увеличиваем её счётчик
                amtVowels[i]++;
            }
            // если найдена маленькая гласная тоже
            if (*(ptrStr + position) == (*(strVowel + i + 6))) {
                // увеличиваем её счётчик
                amtVowels[i]++;
            }
        }
        position++;
    }
    printf("number vow    amt vow\n");
    showArray(amtVowels, 6);

    if (hasDublicates(getMaxIdx(amtVowels, 6), amtVowels, 6) == -1) {
        result = strVowel[getMaxIdx(amtVowels, 6)];
        printf("More repeated vowel: %c\n", result);
    } else puts("There are NO more repeated vowel !\n");

}

void menu() {
    puts("\n1-task1 enter string");
    puts("2-task 1-a count symbols in string");
    puts("3-task 1-b are there vowel letters");
    puts("4-task4 1-c MyStrLen");
    puts("5-task4 1-d,e which vowel is more repeated");
    puts("0-exit");
}

//--------------------------------
// Метод динамически выделяет память для строки кусками по 32 байта
// метод, приведённый в методичке, использует gets(), что, теоретически, может
// записать строку в "неправильное" место памяти.
struct MyString getMyStr() {
    struct MyString myStr;
    myStr.string = NULL;
    // выбираем минимальный размер строки в 32 байта
    myStr.sizeb = 32;
    myStr.sizec = 0;
    short memoryTest = 1;
    // изначально рабочая переменная пустая
    char ch = '\0';
    // проверяем память перед первым выделением
    if ((myStr.string = (char *) malloc(myStr.sizeb)) == NULL) {
        memoryTest = 0;
        printf("Unable to allocate %d bytes of memory for character buffer\n", myStr.sizeb);
    }
    while (1) {
        // если тест памяти 0, то мы сразу выходим и возвращаем 0
        while (memoryTest != 0 && ch != 13 && myStr.sizec < myStr.sizeb - 1) {
            ch = (char) _getch();
            myStr.string[myStr.sizec] = ch;
            myStr.sizec++;
        }
        // если при попытке расширения памяти неудача, то выходим с ошибкой
        if (memoryTest == 1 && (myStr.string = (char *) realloc(myStr.string, myStr.sizeb + 32)) == NULL)
            memoryTest = 0;
        // если нажат ввод или ошибка памяти - выходим
        if ((ch == 13) || memoryTest == 0) {
            if (memoryTest == 0) {
                // будет возвращён 0 - код ошибки
                myStr.string = NULL;
                free(myStr.string);
                myStr.sizeb = 0;
                myStr.sizec = 0;
                printf("Unable to reallocate memory for character buffer.\n");
            }
            if (ch == 13) {
                // вместо enter записываем \0
                myStr.string[myStr.sizec - 1] = '\0';
                // возвратим длину строки без символа окончания
                myStr.sizec--;
            }
            puts(myStr.string);
            return myStr;
        } else {
            myStr.sizeb += 32;
        }
    }
}

// --------------- ищем наибольшее число в массиве
int getMax(int *_arr, unsigned int length) {
    int max = _arr[0];
    for (int i = 1; i < length; i++)
        if (_arr[i] > max)
            max = _arr[i];
    return max;
}
// --------------------ищем индекс наибольшего числа в массиве
int getMaxIdx(int *_arr, unsigned int length) {
    int max = _arr[0];
    int result = 0;
    for (unsigned int i = 1; i < length; i++)
        if (_arr[i] > max) {
            max = _arr[i];
            result = i;
        }
    return result;
}

//----------------------
void showArray(int *_arr, unsigned int length) {
    for (int i = 0; i < length; i++) {
        printf("%10i%10i\n", i, _arr[i]);
    }
    system("pause");
}

// проверка на дубликаты  возвращает индекс первого найденного дубликат или -1.
int findDublicateIdx(unsigned int n, int *array) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (i != j)
                if (array[i] == array[j]) return i;
    return -1;
}

//----------------------------------------
int hasDublicates(int idx, int *array, unsigned int length) {
    int i;
    for (i = 0; i < length; i++)
        if (i != idx)
            if (array[i] == array[idx]) return i;
    return -1;
}