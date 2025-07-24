#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


unsigned pow_mod(unsigned[] arr, unsigned k, unsigned m){
	for (int i = 0; i<3; ++i)
		arr[i] = arr[i]%m;
	unsigned prod = 1; // произведение
	
	while (k > 0)
	{	
		for (int i = 0; i<3; ++i) {
	 		if(k%2 == 1) 
			{

				prod = (mult * prod)%m; k-=1;
			}
			mult = (mult*mult) % m; k/=2;
		}
	}
	
	return prod;
}
int fib_mod(unsigned long long  n, unsigned m, unsigned[] arr)
{
		
	assert(m > 0);
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
	unsigned x00, x01, x10, x11, n, m;
	int res = scanf("%u%u%u%u%u%u", &x00, &x01, &x10, &x11, &n, &m);
	if (res != 6) {
		printf("Wrong input!");
       		abort();
 	}
	unsigned[] arr = { x00, x01, x10, x11 };
	fib_mod(n, m, arr);
}	

	
