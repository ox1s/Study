/*
Problem CF -- непрерывные дроби

Вам на вход приходят числитель и знаменатель дроби.
Ваша задача: написать программу выдающую на стандартный вывод представление цепной дробью.
*/

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

long long iabs(long long x)
{
	return (x > 0) ? x : -x;
}
long long eu_mod(long long m, long long n)
{
	int r;
	assert( n!=0 );
	r = m % n;
	if ( r<0 ) r+=iabs(n);
	return r;
}
unsigned long long rec(long long m, long long n)
{
	unsigned long long q;
#if 0
	q = eumod(m,n);
	if ( q==0 )
		return n;
	printf("%llu",m/n);
	return rec(n,q);
#endif
	q = eu_mod(m,n);
        for (; q != 0;)
        {
		printf("%llu ",m/n);
                m = n;
                n = q;
                q = eu_mod(m,n);
        }
	printf("%llu\n",m/n);
	return n;
}


int main()
{
	// Цепная дробь
	unsigned long long a,b;
	int user_input = scanf("%llu%llu", &a,&b);
	if ( user_input != 2 ) 
	{
		printf("Ты должен был ввести 2 числа");
		abort();
	}
	rec(a,b);
	return 0;
}

