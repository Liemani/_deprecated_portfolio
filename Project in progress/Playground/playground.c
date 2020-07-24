#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "book.h"

#pragma warning(disable:4996)





// bookList
// 1. getListFromFile
// 2. print
// 3. search
// 4. insertBook
// 5. removeBook
// 데이터 영역ㅁ20ㅁㅁㅁㅁㅁㅁㅁㅁㅁㅁ
//              2020-07-03
void test00() {
    char* date = "2020-07-03"; // 시작 주소값 의미
    printf("*date: %c \n", *date);
    printf("*(date + 1): %c \n", *(date + 1));
    printf("sizeof(date): %d \n", sizeof(date));
    printf("sizeof(*date): %d \n", sizeof(*date));
}
void test01() {
    printf("%d \n", -1 / 5);
}

void devision() {
    int a;
    int b;

    while (1) {
        printf("Input a: ");
        scanf("%d", &a);
        while (getchar() != '\n');
        putchar('\n');

        printf("Input b: ");
        scanf("%d", &b);
        while (getchar() != '\n');
        putchar('\n');

        if (b == 0) break;

        printf("%d / %d = %d \n", a, b, a / b);
        putchar('\n');
    }

    printf("Closing program \n");
}

void remainder() {
    int a;
    int b;

    while (1) {
        printf("Input a: ");
        scanf("%d", &a);
        while (getchar() != '\n');
        putchar('\n');

        printf("Input b: ");
        scanf("%d", &b);
        while (getchar() != '\n');
        putchar('\n');

        if (b == 0) break;

        printf("%d %% %d = %d \n", a, b, a % b);
        putchar('\n');
    }

    printf("Closing program \n");
}

void test02() {
    printf("sizeof(int): %d \n", sizeof(int));
    printf("sizeof(int*): %d \n", sizeof(int*));
}

void test03() {
    int number = 0;
    scanf("%d", &number);

    printf("1 \t");

    for (int i = 2; i <= number / 2; ++i) {
        if (number % i == 0) {
            printf("%d \t", i);
        }
    }

    printf("%d", number);
}

typedef struct Test01 {
    int first;
    int second;
} Test01;

void test04() {
    if (-1) {
        printf("-1 is true");
    }
}

void test05() {
    char i = 1;
    while (i) {
        printf("%d: %c \n", i, i);
        ++i;
    }
}

void test06() {
    assert(1 == 0);
}

typedef struct TestStructure00 TestStructure00;

typedef struct TestStructure01 {
    TestStructure00* pTest00;
} TestStructure01;

typedef struct TestStructure00 {
    int test00;
} TestStructure00;

void test07() {
    TestStructure01 test01 = { 0 };
    TestStructure00 test00 = { 1 };
    test01.pTest00 = &test00;

    printf("%d", test01.pTest00->test00);
}

int main(void) {
    test07();
}



int main2(void)
{
    Book bookList[10];
    int count = 0;

    FILE* fin;
    fin = fopen("bookList.dat", "r");

    char* delimiter = "@\n";
    char buf[1024];
    while (fgets(buf, 1024, fin) != NULL) {
        char* token = strtok(buf, delimiter);
        strcpy(bookList[count].title, token);
        fprintf(stderr, "%s \n", bookList[count].title);

        token = strtok(NULL, delimiter);
        strcpy(bookList[count].author, token);

        token = strtok(NULL, delimiter);
        strcpy(bookList[count].publisher, token);

        token = strtok(NULL, delimiter);
        strcpy(bookList[count].date, token);

        token = strtok(NULL, delimiter);
        strcpy(bookList[count].isbn, token);

        ++count;
    }

    for (int i = 0; i < count; ++i)
        printf("%s %s %s %s %s \n", bookList[i].title, bookList[i].author, bookList[i].publisher, bookList[i].date, bookList[i].isbn);

    fclose(fin);
    return 0;
}