#include <stdio.h>

/* подсчет вводимых символов; 2-й версия */
int main()
{
    double nc;
    for (nc = 0; getchar() != EOF; ++nc);
    printf("%.0f\n", nc);
}
