#ifndef _HANDLER_H__
#include <stdbool.h>
#include <jansson.h>
#define	_HANDLER_H__
typedef struct {
	int checksum;			//MD5 checksum, -1 if not included
	bool UseStrictFormatting;		//False by default
} Headers;
typedef struct {
	
} Exception;
typedef struct {
	Headers *headers;
	Exception *exception; 
	//The exception field will be NULL if no exception is thrown
	//Other fields will be NULL if the exception field is not NULL
	char *method;
	float version;
	json_t *params;
} Message;

Message *parse(char *request)
#endif
