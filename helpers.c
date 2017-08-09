#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include "helpers.h"

//https://stackoverflow.com/questions/2572366/how-to-use-dev-random-or-urandom-in-c
long randomSeed() {
	int randomFD = open("/dev/random", O_RDONLY);
	char randomData[100];
	memset(randomData, 0, sizeof(randomData));
	long randomValue = 0;
	for (int i = 0;i < 100;i++) {
		read(randomFD, &randomData, 100);
		for (int i = 0; i < 100; i++) {
			//printf("%d: %d\n", i, randomData[i]);
			randomValue += randomData[i];
		}
	}
		
	close(randomFD);
	//printf("Read %d from urandom\n", (int)readLen);
	/*for (int i = 0; i < 50; i++) {
		printf("%d: %d\n", i, randomData[i]);
	}*/
	return randomValue;
}
long randomLong() {
	long seeds[10];
	for (int i = 0; i < 10; i++) {
		seeds[i] = randomSeed();
	}
	srand(time(NULL));
	int seedIndex = rand() % 10;
	srand(seeds[seedIndex]);
	return (long)rand();
}
char** getLines(char* message, int *len) {
	if (message == NULL) {
		puts("getLines() recieved a null message");
		return NULL;
	}
	if (len == NULL) {
		puts("Len is null");
		len = (int*)malloc(sizeof(int));
		*len = 0;
	}
	int index = 0, size = 1, leftIndex = 0, arrIndex = 0;
	char** arr = (char**)malloc(sizeof(char*));
	while (message[index] != 0) {
		if (message[index] == '\n') {
			//get substring, add to array
			char* sub = substring(message, leftIndex, index);
			if (arrIndex == size) {
				//resize array
				char** tmpArr = (char**)malloc(sizeof(char*) * (size * 2));
				for (int i = 0; i < size; i++) {
					tmpArr[i] = arr[i];
				}
				size = size * 2;
				arr = tmpArr;
			}
			arr[arrIndex] = sub;
			arrIndex++;
			leftIndex = index + 1;
		}
		index++;
	}
	if (message[index - 1] != '\n') {
		//when the message doesn't end in a new line
		char* sub = substring(message, leftIndex, index);
		if (arrIndex == size) {
			//resize array
			char** tmpArr = (char**)malloc(sizeof(char*) * (size * 2));
			for (int i = 0; i < size; i++) {
				tmpArr[i] = arr[i];
			}
			size = size * 2;
			arr = tmpArr;
		}
		arr[arrIndex] = sub;
		arrIndex++;
	}
	*len = arrIndex;
	return arr;
}
//Start and End are index specific, E.G. message[start] where start = 0 is the same as message[0]
//Similar to js substring()
char* substring(char* message, int start, int end) {
	if (message == NULL) {
		puts("substring() was given a null message!");
		return NULL;
	}
	//check if start and end are incorrect
	if (start == end || start > end) {
		return NULL;
	}
	
	int messIndex = 0, strIndex = 0, size = 1;
	char* string = (char*)malloc(sizeof(char));
	while(message[messIndex] != 0) {
		if (messIndex >= end) {
			if (strIndex == size) {
				//add another spot to string
				char* tmpString = (char*)malloc(sizeof(char) * (size) + 1);
				for (int i = 0; i < size; i++) {
					tmpString[i] = string[i];
				}
				size = size + 1;
				free(string);
				string = tmpString;
			}
			string[strIndex] = 0;
			break;
		}
		else if (messIndex >= start) {
			//add to string
			if (strIndex == size) {
				//double the string
				char* tmpString = (char*)malloc(sizeof(char) * (size * 2));
				for (int i = 0; i < size; i++) {
					tmpString[i] = string[i];
				}
				size = size * 2;
				free(string);
				string = tmpString;
			}
			string[strIndex] = message[messIndex];
			strIndex++;
		}
		messIndex++;
	}
	if (messIndex < start) {
		printf("%s has a length of %d but was given a start index of %d\n", message, messIndex + 1, start);
		return NULL;
	}
	return string;
}