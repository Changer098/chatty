#include <stdio.h>
#include <string.h>
#include "handler.h"
#include "helpers.h"

Message *parse(char *request) {
	if (request == NULL) {
		puts("parse() was given a null request!");
		return NULL
	}
	if (isLenZero(request)) {
		puts("parse() was given an empty string to parse!");
		return NULL;
	}
	char ** lines;
	int *len = (int*)malloc(sizeof(int));
	Headers *headers = (Headers*)malloc(sizeof(Headers))
	Message *message = (Message*)malloc(sizeof(Message));
	lines = getLines(request, len);
	
	//parse Headers first
	for (int i = 0; i < *len; i++) {
		if (strcmp(lines[i], "\n") == 0) {
			//escape
		}
		if (lines[i][0] == '{') {
			//we should've escaped the loop by now
		}
}