#include <stdio.h>
#include <stdlib.h>

int fib_mod(unsigned n, unsigned m)
{
	long long first = 0, second = 1;
	if (n == 0 || m == 0) {
		return 0;
	}
	for (int i = 2;  i<=n ; ++i) {
		long long tmp = second;
		second = (first + second)%m;
		first = tmp;
	}
	return second;
}
int main() 
{
	unsigned n, m;
	int res = scanf("%u%u", &n, &m);
        if (res != 2)
		abort();
	printf("%d", fib_mod(n,m));
	return 0;
}	
