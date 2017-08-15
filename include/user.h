#ifndef _USER_H__

#include <stdbool.h>
#include "llist.h"

#define	_USER_H__

typedef struct userT {
	char* name;
	char* password;
	long cookie;
	long timestamp;		//if exceeded too long, user is logged out
	Node* messages;		//Linked list
	int messageCount;
} User;

User *createUser(char* name, char* password);
bool isLoggedIn(User* user);
void addMessage(User* user, Node* message);
Node *findMessage(User *user, long id);
long getTimeout();

#endif