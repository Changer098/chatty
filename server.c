#include <stdlib.h>
#include <stdio.h>
#include <jansson.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

const int PORT = 8181;
int8_t verbose = -1;

void help() {
	puts("CHATTY");
	puts("-h,--h \t \t \t Displays this help page");
	puts("-v,--v \t \t \t Turns on verbose mode");
	puts("");
}

int main(int argc, char** argv) {
	if (argc > 1) {
		int i = 1;
		for (i = 1; i < argc; i++) {
			//printf("%d = %s\n", i, argv[i]);
			if (strcmp(argv[i], "-h") || strcmp(argv[i], "-h")) {
				help();
			}
			if (strcmp(argv[i], "-v") || strcmp(argv[i], "-v")) {
				verbose = 1;
			}
		}
	}
	puts("Chatty starting up!");
	
}