#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
/*
Problem PF -- простые числа, подобные числам Фибоначчи

Некоторые числа Фибоначчи, например 5 и 13 являются также простыми числами

Поскольку многие числа Фибоначчи довольно велики (например 99194853094755497 и даже 2880067194370816120 вполне входят в 64 бита), проверить их на простоту прямой проверкой может быть нелегко, а памяти на решето не хватит. Поэтому можно использовать статистические тесты из прошлых упражнений (такие как тест Ферма). Но для маленьких чисел простая проверка все ещё эффективней

Разумеется, список простых чисел Фибоначчи не слишком интересен, его легко нагуглить

2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, ....

К счастью, в мире много других интересных последовательностей, похожих на числа Фибоначчи, например такая:

Seq0 = 0

Seq1 = 1

Seqi = k * Seqi - 1 + n * Seqi - 2

Ваша задача, получив на вход числа k и n вычислить самое большое простое число P, такое, что P < 260 и P входит в данную последовательность

Вы можете быть уверены, что k и n целые, положительные и не слишком большие (меньше чем 256 каждое)

Посылка должна состоять из программы, считывающей со стандартного ввода k и n и выводящей на стандартный вывод P

Вполне может быть и так, что в последовательности нет простых чисел. Тогда вы должны вывести на стандартный вывод 0
*/
unsigned long long mult_mod(unsigned long long x, unsigned long long y,
                            unsigned long long m)
{
    unsigned long long res = 0;
    x = x % m;

    while (y > 0) {
        if (y % 2 == 1)
            res = (res + x) % m;
        x = (x * 2) % m;
        y /= 2;
    }
    return res;
}



unsigned long long pow_mod(unsigned long long n, unsigned long long k,
                           unsigned long long m)
{
    unsigned long long mult = n % m;
    unsigned long long prod = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            prod = mult_mod(mult, prod, m);
            k -= 1;
        }
        mult =  mult_mod(mult, mult, m);
        k /= 2;
    }

    return prod;
}

unsigned long long gcd(unsigned long long x, unsigned long long y)
{
    while (y) {
        x = x % y;
        unsigned long long q = x;
        x = y;
        y = q;
    }
    return x;

}

int is_prime_small(unsigned long long n)
{
    if ((n == 2) || (n == 3))
        return 1;
    if ((n < 2) || ((n % 2) == 0) || ((n % 3) == 0))
        return 0;

    for (int j = 5; j * j <= n; j += 6)
        if (((n % j) == 0) || ((n % (j + 2)) == 0))
            return 0;

    return 1;
}

int is_prime(unsigned long long p)
{
    if (p < 1000) {
        int ans = is_prime_small(p);
        return ans;
    }
    for (int i = 0; i < 100; ++i) {
        unsigned long long a = rand() % p;
        if ((gcd(a, p) != 1) || (pow_mod(a, p - 1, p) != (1 % p)))
            return 0;
    }
    return 1;
}


unsigned long long find_max_prime(int k, int n)
{
    unsigned long long first = 0, second = 1;
    unsigned long long found = 0;

    while (1) {
        unsigned long long tmp = second;
        if (is_prime(second) == 1)
            found = second;

        second = n * first + k * second;
        first = tmp;

#if 0
        printf("\n\tsecond = %llu\n\tfirst = %llu\n", second, first);
        printf("\t\tres = %llu \n", n * first + k * second);
#endif

        if (second < first)
            break;
    }

    return found;
}

int main()
{
    int k, n;
    int res = scanf("%d%d", &k, &n);
    if (res != 2) {
        printf("Wrong input!");
        abort();
    }
    unsigned long long p = find_max_prime(k, n);
    printf("%llu", p);
    return 0;
}
