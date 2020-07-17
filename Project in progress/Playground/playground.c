#include <stdio.h>
#include <string.h>
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

//int main(void) {
//    remainder();
//    //printf("1 % 0: %d \n", 1 % 0);
//}



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