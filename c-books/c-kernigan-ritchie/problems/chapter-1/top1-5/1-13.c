#include <stdio.h>
#include <ctype.h>
/*
Упражнение 1.13. Напишите программу, печатающую гистограммы длин вводимых слов. Гистограмму легко
рисовать горизонтальными полосами. Рисование вертикальными полосами — более трудная задача.
*/
#define MAX_WORDS 10

int main()
{
    int c;
    int maxlength = 0, count = 0, len = 0;
    int words[MAX_WORDS];
    while ((c = getchar()) != EOF) {
        if (isalpha(c))
            ++len;
        else if (len > 0) {
            if (count < MAX_WORDS)
                words[count++] = len;
            len = 0;
        }
    }
    if (len > 0 && count < MAX_WORDS)
        words[count++] = len;

    printf
        ("\nГистограмма длин вводимых слов:\n");

    for (int i = 0; i < count; ++i)
        if (words[i] > maxlength)
            maxlength = words[i];

    for (int i = 0; i < count; ++i) {
        printf("\n%3d |", i + 1);
        for (int j = 0; j < maxlength; ++j) {
            if (words[i] > j)
                printf("#");
            else
                printf(" ");
        }
        printf(" | %d", words[i]);
    }
    printf("\n>");

}
