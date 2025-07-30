/*
Два игрока играют в интересную игру: изначально дано N спичек. 
Первый игрок берёт любое количество, но не все сразу спички. 
Теперь второй может взять не больше, чем вдвое больше чем первый. 
Далее первый берёт не больше чем вдвое больше второго. И так далее. 
Выигрывает тот, кто взял последнюю спичку

Партия 1:

11 спичек. Первый берёт 4, второй может взять до 8 и берёт 7, победа. Запись партии: 11.4,7!

Партия 2:

11.3,3,5!

Партия 3:

11.3.2.1.1.1.1.2!

Ваша посылка должна состоять из функции, которая по общему количеству оставшихся (total) 
и количеству допустимых к взятию (possible) спичек будет возвращать сколько спичек она хочет взять

Разумеется, ваша функция всегда должна делать оптимальный ход

Если оптимальный ход невозможен (все ходы плохи), разумно взять одну спичку
и дать противнику шанс сделать ошибку
*/


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int next_turn(int total, int possible)
{
    int idx = 0;

    int fib[50] = { 1, 2 };
    for (int i = 2; fib[idx] <= total; ++i) {
        assert(i < 50);
        int tmp = fib[i - 1];
        fib[i] = fib[i-1] + fib[i - 2];
        idx = i - 2;
    }
    idx = idx - 1;
#if 1
    for(int i = 0; fib[i] != 0; i++) 
	printf("fib[%d] = %d\n", i, fib[i]);
#endif

    if (fib[idx] != total) {
        while (idx > 0) {
            if (fib[idx] < total) {
		#if 0
                printf
                    ("\n\ttotal = %d - %d\n\tfib[%d] = %d\n\ttotal = %d\n\tpossible and total:\n\t%8d     %5d\n",
                     total, fib[idx], idx, fib[idx], total, possible,
                     total);
		#endif
                total = total - fib[idx];
            }
            if (total == fib[idx] && total <= possible)
                return total;
	    idx = idx - 1;
        }
        if (total > possible)
            return 1;
        else
            return total;
    }

    return 1;

}

int main()
{
    int n, q, res;

    res = scanf("%d%d", &n, &q);
    assert(res == 2);

    n = next_turn(n, q);
    printf("%d\n", n);

    return 0;
}
