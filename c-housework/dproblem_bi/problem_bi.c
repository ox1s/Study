#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
Problem BI -- старший и младший бит

Вам предлагается инвертировать N-й по счёту бит в массиве.

На вход приходит количество чисел, каждое не больше одного байта, далее все эти числа и дальше номер бита.

Номер бита отсчитывается от нулевого бита нулевой ячейки массива. Нулевой бит первой ячейки будет иметь номер 8 и т.д.

Посылка должна состоять из программы, считывающей со стандартного ввода массив и число N и выводящей на стандартный вывод массив в котором N-й бит инвертирован.
В случае если номер запрашиваемого бита больше максимального номера в массиве, массив выводится без изменений.

*/


void invert_arr(unsigned n, unsigned *arr, unsigned bit) {
	if (bit >= 8 * n) 
		return;

        int idx = bit/8;
        int bit_idx = bit%8;

        arr[idx] = arr[idx] ^ (1 << bit_idx) ;
}



int main() {
    unsigned n, *arr, bit;

    int res = scanf("%u", &n);
    if (res != 1) {
	    printf("Wrong input!");
	    abort();
    }
    
    arr = (unsigned *)malloc(n * sizeof(unsigned));
    if (arr == NULL) {
	    printf("Memory failed!");
	    abort();
    }

    for(int i = 0; i < n; ++i) {
	    unsigned v;
	    res = scanf("%u", &v);
	    if (res != 1) {
		    printf("Wrong input in array!");
		    abort();
	    }
	    arr[i] = v;
    }

    res = scanf("%u", &bit);
    if (res != 1) {
	    printf("Wrong input!");
	    abort();
    }


    invert_arr(n, arr, bit);
  
    for (int i = 0; i < n; ++i) 
	    printf("%u ", arr[i]);
    

    free(arr);

}
