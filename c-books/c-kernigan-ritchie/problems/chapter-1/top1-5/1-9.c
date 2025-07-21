#include <stdio.h>

int main() {
	int isLastCharSpace = 0;
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (!isLastCharSpace) {
				isLastCharSpace = 1;
				putchar(c);
			}
		}
		else {
			putchar(c);
			isLastCharSpace = 0;
		}

			
	}
}
