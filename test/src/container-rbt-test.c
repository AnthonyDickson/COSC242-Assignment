#include <stdio.h>
#include <stdlib.h>
#include "../../mylib.h"
#include "../../container.h"

int main() {
	char *word = emalloc(255 * sizeof(word[0]));;
	container c = container_new(RED_BLACK_TREE);
	
	while (1 == scanf("%255s", word)) {
		container_add(c, word);
	}
    
    container_sort(c);
	container_print(c);
    container_free(c);
    
    free(word);

	return EXIT_SUCCESS;
}
