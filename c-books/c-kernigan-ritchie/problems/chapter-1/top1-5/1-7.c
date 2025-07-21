#include <stdio.h>

int main() {
	int c;

	while ((c = getchar()) != EOF)
		putchar(c);
	printf("EOF value on my system: %d\n", EOF);
}
