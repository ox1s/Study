#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

unsigned long long fibonachi[62] = { 0, 1 };

int print_converted(unsigned n, int limit)
{	
	int idx = limit;
	while ( idx >= 2)
	{
		if (n >= fibonachi[idx]) {
			printf("10");
			n = n - fibonachi[idx];
			idx = idx - 2;
		}
		else {
			printf("0");
			idx = idx - 1;
		}
	}	
	
	if (n != 0)
		printf("1");
	else if (idx == 1 && n == 0)
		printf("0");
	printf("\t n = %u idx = %d", n, idx);
	return 0;
}
int main()
{
	unsigned a;
	int res = scanf("%u",&a);
	if (res != 1)
		abort();
	if (a == 0) {printf("0"); return 0;}

	for (int i = 2;  i<62 ; ++i) {
		long long tmp = fibonachi[i-1];
		fibonachi[i] = (fibonachi[i-1] + fibonachi[i-2]);
		fibonachi[i-2] = tmp;
	}	
	
	int limit = 0;
	for (int i = 2; i<62; i++) {
		if (a >= fibonachi[i])
			limit = i;
	}
	printf("limit %d\n", limit);
	print_converted(a,limit);
}

