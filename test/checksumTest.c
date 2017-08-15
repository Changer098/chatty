#include <stdio.h>
#include "helpers.h"

int main() {
	printf("checksum of 'hello' is %lu\n", checksum("hello"));
	printf("checksum of 'world' is %lu\n", checksum("world"));
	printf("checsum of 'hello world' is %lu\n'", checksum("hello world"));
	return 0;
}