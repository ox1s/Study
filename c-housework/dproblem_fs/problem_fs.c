#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/* 1. Узнаем сколько будет цифр в переводе
	с помощью цикла k! <= n

	Например: 1! = 1 < 17; 2! = 2 < 17; 3! = 6 < 17; 4! = 24 > 17;

	2. Узнали какая же цифра в fact_num (напр. 3)
	теперь выводим первый символ, это будет 17/3! = 2;
	
	3. Углубляемся в стек:
	n = n%fact_num!; fact_num--

	Например: n = 17%3! = 17%6 = 5

	4. Повторяемся со следующими значениями до
	момента когда fact_num не будет равен нулю
*/
unsigned fact(unsigned n)
{
	if (n == 0)
		return 1;
	else
		return n*fact(n-1);
}
unsigned print_converted(unsigned n, unsigned fact_num)
{
	
	if (fact_num == 0) {
		return 0;
	}
	printf("%u.", n/fact(fact_num));
	print_converted(n%fact(fact_num), fact_num-1);

}
int main()
{
	unsigned a;
	int res = scanf("%u",&a);
	if (res != 1)
		abort();
	unsigned k = 1;

	while (fact(k + 1) <= a) {
		k++;
	}
	print_converted(a, k);
}

