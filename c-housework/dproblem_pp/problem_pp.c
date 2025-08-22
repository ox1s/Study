#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int get_pisano_period(unsigned m)
{
	long long first = 0, second = 1;
	unsigned long long limit = (unsigned long long)m*m;
	for (unsigned long long i = 2;  i <  limit; ++i) {
		long long tmp = second;
		second = (first + second)%m;
		first = tmp;
		if (first == 0 && second == 1)
		{
			return i - 1;
		}
	} 
}
int fib_mod(unsigned long long  n, unsigned m)
{
	assert(m > 0);
	n = n % get_pisano_period(m);
	if (n == 0) {
		return 0;
	}
	long long first = 0, second = 1;
	for (int i = 2;  i <= n ; ++i) {
		long long tmp = second;
		second = (first + second)%m;
		first = tmp;
	}
	return second;
}
int main() 
{
	unsigned long long n;
	unsigned m;
	int res = scanf("%llu%u", &n, &m);
        if (res != 2)
		abort();
	printf("%d %d", fib_mod(n,m), get_pisano_period(m));
	return 0;
}	
