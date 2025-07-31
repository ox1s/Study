#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

int main() {
    unsigned n;
    int res = scanf("%u", &n);
    if (res != 1) {
	    printf("Wrong input!");
	    abort();
    }
    unsigned *sieve = calloc(n + 1, sizeof(int));
    for (int i = 2; i <= n; ++i) {
	    if(sieve[i] != 1) {
	    	for (long j = (long)i * i ; j <= n; j += i) {
		sieve[j] = 1;
#if 0
		printf("\nsieve[%d] = 1\n", j);
#endif
		}
	    }
    }
    unsigned count = 0;
    for (int i = 2; i<=n; ++i)
	    if (sieve[i] == 0)
		    count+=1;
     printf("%u", count);

}

