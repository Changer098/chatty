#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main() {
	char* mess1 = "hello1\n1world1\n";
	int *len1 = (int*)malloc(sizeof(int));
	char** lines = getLines(mess1, len1);
	if (lines[0] == "hello1" && lines[1] == "1world1" && *len1 == 2) {
		puts("Passed Test 1");
	}
	else {
		printf("Failed with length: %d\n", *len1);
		printf("%s\n", lines[0]);
		printf("%s\n", lines[1]);
	}
	char* mess2 = "hello\nworld";
	int *len2;
	char** lines2 = getLines(mess2, len2);
	printf("length: %d lines[1]:%s\n", *len2, lines2[1]);
}