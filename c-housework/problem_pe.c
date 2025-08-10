#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
Problem PE -- побитовое решето

Вам заранее задан тип данных решета

struct sieve_t {
  int n;
  unsigned char *s;
};

Ваша задача написать функции fill_sieve и is_prime с наперёд заданными прототипами

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

Функция fill_sieve заполняет решето, при этом признак хранится в каждом бите, и 1 обозначает, что число составное

То есть после работы этой функции s[0] == 0x53 (01010011), s[1] = 0xD7 (11010111) и т.д.

Считайте, что на входе sv->n уже выставлено и sv->s уже аллоцировано не менее, чем в sv->n байт и инициализировано нулями. Выделения памяти в этой функции не происходит

Обратите внимание: sv->n это размер решета в байтах. Вы должны заполнить его полностью, каждый бит. До какого числа при этом идти это ваше решение, но это точно не число sv->n

Функция is_prime проверяет число n на простоту с использованием решета sv

Посылка должна состоять из этих двух функций (допустимо также любое количество вспомогательных), и не должна содержать функцию main
*/

struct sieve_t {
    int n;
    char *s;
};

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20 * CHAR_BIT)
        return 100 * CHAR_BIT;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres) + 1;
}

void fill_sieve(struct sieve_t *sv)
{
    for (int i = 0; i * i < sv->n * CHAR_BIT; ++i) {
        if (i <= 1)
            sv->s[i / 8] = sv->s[i / 8] | (1 << i % 8);

        if (((sv->s[i / 8] >> i % 8) & 1) != 1)
            for (int j = i * i; j < sv->n * CHAR_BIT; j += i)
                sv->s[j / 8] = sv->s[j / 8] | (1 << j % 8);
    }

}

int is_prime(struct sieve_t *sv, unsigned n)
{
    return !((sv->s[n / 8] >> n % 8) & 1);
}

int nth_prime(struct sieve_t *s, int N)
{
    int cnt, p;
    if (N == 1)
        return 2;
    if (N == 2)
        return 3;

    cnt = 2;
    p = 5;

    for (;;) {
        if (is_prime(s, p)) {
            cnt += 1;
            if (cnt == N)
                break;
        }
        p += 2;
        if (is_prime(s, p)) {
            cnt += 1;
            if (cnt == N)
                break;
        }
        p += 4;
    }
    return p;
}

int main()
{
    int n, outp;
    int res;
    struct sieve_t *s;

    res = scanf("%d", &n);
    assert(res == 1);

    s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    assert(s);

    s->n = (sieve_bound(n) / CHAR_BIT) + CHAR_BIT;
    s->s = (char *) calloc(s->n, sizeof(char));
    assert(s->s);

    fill_sieve(s);

    outp = nth_prime(s, n);
    printf("%d\n", outp);

    free(s->s);
    free(s);
}
