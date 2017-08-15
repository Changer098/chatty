#include "helpers.h"
#include <stdio.h>

int main() {
	printf("substring of 'hello'(1,3) is %s\n", substring("hello", 1,3));
	printf("substring of 'world'(0,4) is %s\n", substring("world", 0,4));
	if (substring("blah", 5, 4) == NULL) puts("pass 3");
	if (substring("blah", 4, 4) == NULL) puts("pass 4");
	if (substring(NULL, 1,2) == NULL) puts("pass 5");
	return 0;
}