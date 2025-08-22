#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void pow_mod(unsigned *arr, unsigned k, unsigned m)
{
    unsigned mult[4], prod[4] = {1,0,0,1};
    for (int i = 0; i < 4; ++i)
        mult[i] = arr[i] % m;


    while (k > 0) {
        if (k % 2 == 1) {
            unsigned tmp[4] = { 0 };

            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    for (int q = 0; q < 2; ++q) 
                        tmp[i * 2 + j] = (tmp[i * 2 + j] + prod[i * 2 + q] * mult[q * 2 + j]) % m;

            for (int i = 0; i < 4; ++i)
                prod[i] = tmp[i];

            k -= 1;
        }

        unsigned tmp[4] = { 0 };

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int q = 0; q < 2; ++q)
                    tmp[i * 2 + j] = (tmp[i * 2 + j] + mult[i * 2 + q] * mult[q * 2 + j]) % m;

        for (int i = 0; i < 4; ++i)
            mult[i] = tmp[i];

        k /= 2;
    }
    for (int i = 0; i < 4; ++i)
	    arr[i] = prod[i];
}

void fib_mod(unsigned long long n, unsigned m, unsigned *arr)
{
    assert(m > 0);
    if (n != 0) {

        if ((arr[0] == arr[1] == arr[2]) && arr[3] == 0) {
            for (int i = 2; i <= n; ++i) {
                arr[3] = arr[1];        // F_{n-1} (new) = F_{n} (old)
                arr[2] = arr[0];        // F_{n} (new) = F_{n+1} (old)
                arr[0] = (arr[3] + arr[2]) % m; // F_{n+1} = (F_{n} + F_{n-1}) mod m
                arr[1] = arr[2];        // F_{n} = F_{n}
            }
        } else
            pow_mod(arr, n, m);
    } 
    else {
	    arr[0] = 1; arr[1] = 0; arr[2] = 0; arr[3] = 1;
    }
}

int main()
{
    unsigned x00, x01, x10, x11, n, m;
    int res = scanf("%u%u%u%u%u%u", &x00, &x01, &x10, &x11, &n, &m);
    if (res != 6) {
        printf("Wrong input!");
        abort();
    }
    unsigned arr[] = { x00, x01, x10, x11 };
    fib_mod(n, m, arr);
    for (int i = 0; i < 4; i++)
        printf("%u ", arr[i]);
}
