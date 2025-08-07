#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Problem BP -- старший и младший бит

Вам предлагается найти позицию старшего и младшего установленных битов в числе.

Посылка должна состоять из программы, считывающей со стандартного ввода число N и выводящей на стандартный вывод номер его старшего и младшего бита.

В случае если установленных битов в числе нет, вы должны выдать строчку "NO".
*/

int find_msb(unsigned n)
{
    int count = 0;
    for (int i = 0; n >= 2; ++i) {
        n = n >> 1;
        count += 1;
    }
    return count;
}

int find_lsb(unsigned n)
{
    int i = 0;
    int x = n & 1;
    while (x != 1) {
        n = n >> 1;
        x = n & 1;
        ++i;
#if 0
        printf("x = %d\nn = %d\n, i = %d", x, n, i);
#endif
    }
    return i;
}


int main()
{
    unsigned N;
    int res = scanf("%u", &N);
    if (res != 1) {
        printf("Wrong input!");
        abort();
    }
    if (N == 0) {
        printf("NO");
        return 0;
    }
    int msb = find_msb(N);
    int lsb = find_lsb(N);
    printf("%d %d", msb, lsb);

}
