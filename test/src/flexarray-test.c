#include <stdio.h>
#include <stdlib.h>
#include "../../mylib.h"
#include "../../flexarray.h"

int main() {
	char *word = emalloc(255 * sizeof(word[0]));;
	flexarray f = flexarray_new();
	
	while (1 == scanf("%255s", word)) {
		flexarray_append(f, word);
	}
		
    flexarray_sort(f);
	flexarray_print(f);
    flexarray_free(f);
    
    free(word);

	return EXIT_SUCCESS;
}
