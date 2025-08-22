#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
Домашнее задание HWE — решето с радикальной экономией памяти

Вам заранее задан тип данных решета

struct sieve_t {
  int n;
  unsigned char *mod1;
  unsigned char *mod5;  
};

Здесь n это размер обоих частей решета в байтах, то есть каждый из массивов mod1 и mod5 содержит n байт

Ваша задача написать функции fill_sieve и is_prime с наперёд заданными прототипами

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

Функция fill_sieve заполняет решето, при этом признак хранится в каждом бите, при этом s.mod1 хранит только биты для чисел вида 6k + 1 (1 7 13 19, ...), а s.mod5 для чисел вида 6k + 5 (5, 11, 17, ...)

То есть после работы этой функции s.mod1[0] == 0x11 (00010001), s.mod5[0] = 0x20 (00100000) и т.д.

Выделения памяти в этой функции не происходит

Функция is_prime возвращает 1 если число n простое или 0 если оно составное

Посылка должна состоять из этих двух функций (допустимо также любое количество вспомогательных), и не должна содержать функции main
*/


struct sieve_t {
    int n;
    unsigned char *mod1;
    unsigned char *mod5;
};

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20)
        return 100;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres);
}

void fill_sieve(struct sieve_t *s);
int is_prime(struct sieve_t *sv, unsigned n);

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
    s->n = ((sieve_bound(n) / CHAR_BIT) / 6) + 1;
    s->mod1 = (unsigned char *) calloc(s->n, sizeof(char));
    s->mod5 = (unsigned char *) calloc(s->n, sizeof(char));

    fill_sieve(s);

#if 0
    {
        int i = 0, k = 0;
        printf("primes:\n");
        while (k < n) {
            if (is_prime(s, i)) {
                printf("%d ", i);
                k += 1;
            }
            i += 1;
        }
        printf("\n");
    }
#endif

    outp = nth_prime(s, n);
    printf("%d\n", outp);

    free(s->mod1);
    free(s->mod5);
    free(s);
}

#line 10000


void fill_sieve(struct sieve_t *sv)
{

    sv->mod1[0] = sv->mod1[0] | 1;

    for (int i = 5; i * i < sv->6 * (n * CHAR_BIT);) {

        int mod = i % 6;       
        int k = i / 6; // находит байт
	if (k >= 8)


        if (mod == 5) {
            if (((sv->mod5[k / 8] >> k % 8) & 1) != 1)
                for (int j = i * i; j < 6 * (sv->n * CHAR_BIT); j += i) {
                    mod = j % 6;
                
                    if (mod == 1)
                        sv->mod1[k / 8] = sv->mod1[k / 8] | (1 << k  % 8);
                    else if (mod == 5)
                        sv->mod5[k / 8] = sv->mod5[k / 8] | (1 << k % 8);
                }
            i = i + 2;

        }

        else if (mod == 1) {
            if (((sv->mod1[k / 8] >> k % 8) & 1) != 1)
                for (int j = i * i; j < 6 * (n * CHAR_BIT); j += i) {
                    mod = j % 6;
                    k = j / 6;
                    if (mod == 1)
                        sv->mod1[k / 8] = sv->mod1[k / 8] | (1 << k % 8);
                    else if (mod == 5)
                        sv->mod5[k / 8] = sv->mod5[k / 8] | (1 << k % 8);
                }
            i = i + 4;

        }
    }


#if 1
    printf("\nПолучились следующие массивы:\n");
    printf("\nmod 1:\n");
    for (int i = 0; i < 2; ++i) {
        printf("байт = %d: \n", i);
        for (int j = 0; j < 8; ++j)
            printf("\tбит = %d, %d\n", j, (sv->mod1[i] >> j) & 1);
    }
    printf("\nmod 5:\n");
    for (int i = 0; i < 2; ++i) {
        printf("байт = %d: \n", i);
        for (int j = 0; j < 8; ++j)
            printf("\tбит = %d, %d\n", j, (sv->mod1[i] >> j) & 1);
    }
#endif

}


int is_prime(struct sieve_t *sv, unsigned n)
{
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0 || n < 2)
        return 0;

    int mod = n % 6;
    int k = n / 6;

    if (mod == 5) {
        return !((sv->mod5[k / 8] >> (k % 8)) & 1);
    } else if (mod == 1) {
        return !((sv->mod1[k / 8] >> (k % 8)) & 1);
    } else {
        return 0;
    }

}
