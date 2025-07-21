#include <stdio.h>

int main() {
	int c, nt = 0;
	
	while ((c = getchar()) != EOF)
		if (c == '\t')
			++nt;
	printf("количество табуляций %d", nt);
}
