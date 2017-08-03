#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

//https://stackoverflow.com/questions/2572366/how-to-use-dev-random-or-urandom-in-c
unsigned long randomLong() {
	int randomFD = open("/dev/urandom", O_RDONLY);
	char randomData[50];
	memset(randomData, 0, sizeof(randomData));
	size_t randomDataLen = 0;
	while (randomDataLen < sizeof(randomData)) {
		size_t result = read(randomFD, randomData + randomDataLen,(sizeof (randomData) - randomDataLen);
		if (result < 0) {
			//couldn't read
		}
		randomDataLen += result;
	}
	close(randomFD);
	unsigned long randomValue = 0;
	for (int i = 0; i < 50; i++) {
		randomValue += randomData[i];
	}
	return randomValue;
}