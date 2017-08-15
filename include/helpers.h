#ifndef _HELPERS_H__
#include <stdbool.h>
#define	_HELPERS_H__

long randomSeed();
long randomLong();
char** getLines(char* message, int* len);
char* substring(char* message, int start, int end);
bool isLenZero(char *message); //returns true for a string of length zero
unsigned long checksum(char *string);
#endif