/*
Problem RL -- рекурсия в цикл
Ниже приведён исходный код программы для рекурсивного алгоритма Евклида.
Ваша задача: переписать его так, чтобы вместо рекурсии использовался цикл
Посылка должна состоять из программы, считывающей со стандартного ввода два числа x и y и выводящей на стандартный вывод одно число g
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int x)
{
	return (x < 0) ? -x : x;
}
int eu_mod(int x, int y)
{
	int r;
	assert(y!=0);
	r = x%y;
	if (r<0) r+= iabs(y);
	return r;
}
unsigned long long gcd(unsigned long long x,
			unsigned long long y) {
	unsigned long long q;

	if (y > x)
		return gcd(y, x);
	assert(y > 0);
	
	q = eu_mod(x,y);
	for (; q != 0;)
	{
		x = y;
	        y = q;
		q = eu_mod(x,y);
	}
	return y;

}

int main() {
	unsigned long long x = 0, y = 0, g;
	int res;

	res = scanf("%llu %llu", &x, &y);
	assert(res == 2);
	g = gcd(x, y);
	printf("%llu\n",g);
	return 0;
}

