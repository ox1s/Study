#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int is_prime(unsigned n) {
	if (n < 2) return 0;

	for (int j = 2; j*j <= n; ++j)
		if ((n%j) == 0)
			return 0;
	return 1;
}

unsigned find_prime(unsigned n) {
	unsigned i = 0,j = 0;
	while (i < n) {
		j++;
		if(is_prime(j) == 1) {
			i++;
#if 0
			printf("Простое i = %u, j = %u\n", i,j);
#endif
		}
#if 0
		printf("\tj = %u\n\ti = %u\n", j,i);
#endif
	}
	return j;

}

int main() 
{
	unsigned n;

	int res = scanf("%u", &n);
	if (res != 1) {
		printf("Wrong input!");
		abort();
	}
	unsigned f = find_prime(n);
	printf("%u", f);
}
