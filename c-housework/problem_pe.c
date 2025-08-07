#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

void fill_sieve(struct sieve_t *s);
int is_prime(struct sieve_t *sv, unsigned n);

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

    printf("\n");
    outp = is_prime(s, n);
    printf("%d\n", outp);

    free(s->s);
    free(s);
}

#line 10000

void fill_sieve(struct sieve_t *sv)
{
    printf("Заполняем:\n");
    for (int i = 2; i * i < (*sv).n / 32; ++i) {
	int idx = 0;
        printf("i = %d\n", i);
        if (((*sv).s[idx] >> 7) != 1) {
	    printf("Сдвинутый %d", sv->s[idx] >> 7);

            for (int j = i * i; j < 8; j += i) {
                (*sv).s[j] = (*sv).s[j] | (1 << (8 - j));
                printf("j = %d (1 << (8 - j)) = %d\n", j, (1 << (8 - j)));
            }
	    
        }
    }

    for (int i = 0; i < 3; ++i)
	    printf( "%d, ", sv->s[i]);:wq

}

int is_prime(struct sieve_t *sv, unsigned n)
{
    return 23;

}
