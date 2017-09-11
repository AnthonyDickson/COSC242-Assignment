#include <stdio.h>
#include <stdlib.h>
#include "../../mylib.h"
#include "../../htable.h"

int main() {
	char *word = emalloc(255 * sizeof(word[0]));;
	htable h = htable_new(20000, 0);
	
	while (1 == scanf("%255s", word)) {
		htable_insert(h, word);
	}
    
	htable_print(h);
    htable_free(h);
    
    free(word);

	return EXIT_SUCCESS;
}
