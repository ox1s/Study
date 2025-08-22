#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
/* 
Малая теорема Ферма

prime p, gcd(a, p) == 1 = > a ^ (p - 1) = 1 (mod p)

Может быть использована для быстрой проверки простоты числа p: если удаётся найти свидетеля, то есть такое число a, что a^(p - 1) != 1 (mod p), это автоматически значит, что число составное

Увы, в качестве свидетеля подходит не каждое число. Например для числа 221, число 38 удовлетворяет условиям теоремы Ферма, тем не менее число 221 составное. Такие числа, как 38 называются лжецами для числа 221

Ваша задача реализовать тест Ферма для чисел, меньших, чем 264 - 1 (unsigned long long)

Посылка должна состоять из программы, считывающей со стандартного ввода число P и выводящей на стандартный вывод 1, если оно простое и 0, если нет

Свидетеля можно искать перебором или пробовать случайные числа. Здесь есть элемент творческой неопределённости. Некоторые числа (т.н. числа Кармайкла), являясь составными, вообще не имеют свидетелей, но шансы натолкнуться на них довольно малы и ответ 1 для этих чисел в этой задаче будет правильным

Все входные числа > 10^8, так что вы можете даже не пробовать решето или проверку в лоб. Все входные числа < 264 и все они положительны, поэтому использовать тип unsigned long long будет хорошей идеей

В примерах указана факторизация, но написать тест Ферма куда проще, чем факторизацию

*/
unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m)
{
    unsigned long long mult = n % m;
    unsigned long long prod = 1;

    while (k > 0) {
        if (k % 2 == 1) {
            prod = (mult * prod) % m;
            k -= 1;
        }
        mult = (mult * mult) % m;
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

int is_prime(unsigned long long p)
{
    for (int i = 0; i < 100; ++i) {
        unsigned long long a = rand() % p;
        if ((gcd(a, p) != 1) || (pow_mod(a, p - 1, p) != (1 % p)))
            return 0;
    }
    return 1;
}

int main()
{
    srand(time(NULL));

    unsigned long long p;
    int res = scanf("%llu", &p);
    if (res != 1) {
        printf("Wrong input!");
        abort();
    }
    int output = is_prime(p);
    printf("%d", output);
}
