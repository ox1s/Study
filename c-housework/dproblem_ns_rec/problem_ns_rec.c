#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void print_converted(unsigned n, unsigned base)
{
	if(n < base) {
		printf("%u", n);
		return;
	}
	
	print_converted(n/base, base);

	printf("%u", n%base);
}
int main()
{
	unsigned a,b;
	int res = scanf("%u%u",&a,&b);
	if (res != 2)
		abort();
	print_converted(a,b);
}

