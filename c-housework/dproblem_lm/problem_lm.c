#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
Problem LM -- наименьшее общее кратное

Число 2520 является наименьшим числом, которое делится без остатка на числа от 2 до 10

Задача состоит в том, чтобы найти наименьшее число, которое делится без остатка на числа от 2 до N

Посылка должна состоять из программы, считывающей со стандартного ввода число N и выводящей на стандартный вывод наименьшее общее кратное чисел от 2 до N включительно

Используйте тот факт, что lcm(a, b) == a * b / gcd(a, b)
			  lcm(a, b, c) == lcm(lcm(a, b), c) 
*/

int iabs(int x)
{
    return (x < 0) ? -x : x;
}

int eu_mod(int x, int y)
{
    int r;
    assert(y != 0);
    r = x % y;
    if (r < 0)
        r += iabs(y);
    return r;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    unsigned long long q;

    if (y > x)
        return gcd(y, x);
    assert(y > 0);

    q = eu_mod(x, y);
    for (; q != 0;) {
        x = y;
        y = q;
        q = eu_mod(x, y);
    }
    return y;

}

unsigned lcm(unsigned long long n)
{
    unsigned long long tmp = 2;
    for (unsigned long long i = 3; i <= n; ++i) {
        tmp = (tmp * i) / gcd(tmp, i);

    }
    return tmp;
}


int main()
{
    unsigned long long N;

    int res = scanf("%llu", &N);
    if (res != 1) {
        printf("Wrong input!");
        abort();
    }
    unsigned l = lcm(N);
    printf("%u", l);

}
