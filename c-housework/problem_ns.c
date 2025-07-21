#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int print_converted(unsigned n, unsigned base)
{
		unsigned arr[31];
		int count = 0;
		for (int i = 0 ; n>=base ; i++)
		{
			arr[i] = n%base;
			n = n/base;
			count+=1;
		}
		arr[count] = n;
		int l = count,p = 0;
		while(p<l)
		{
			int temp = arr[p];
			arr[p] = arr[l];
			arr[l] = temp;
			p += 1;
			l -= 1;
        	}
		for (int i = 0; i <= count;i++)
			printf("%d", arr[i]);
		printf("\n");
}
int main()
{
	unsigned a,b;
	int res = scanf("%u%u",&a,&b);
	if (res != 2)
		abort();
	print_converted(a,b);
}

