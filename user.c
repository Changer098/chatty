#include <time.h>
#include "user.h"
#include "llist.h"
#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>

User *createUser(char* name, char* password) {
	if (name == NULL) {
		puts("createUser() recieved a NULL name parameter");
		return NULL;
	}
	if (password == NULL) {
		puts("createUser() recieved a NULL password parameter");
		return NULL;
	}
	User *user = (User*)malloc(sizeof(User));
	user->name = name;
	user->password = password;
	user->timestamp - (long)time(NULL);
	user->messages = NULL;
	user->messageCount = 0;
	user->cookie = randomLong();
	
	return user;
}
bool isLoggedIn(User* user){
	if (user == NULL) {
		puts("User::isLoggedIn() User oarameter is NULL");
		return false;
	}
	long currentTime = (long)time(NULL);
	long difference = currentTime - user->timestamp;
	if (difference < 0) {
		printf("User::isLoggedIn had a negative time difference!\n");
		printf("Then: %ld, Now: %ld, Difference: %ld\n", user->timestamp, currentTime, difference);
		return false;
	}
	else if (difference == 0 || difference < getTimeout()) {
		return true;
	}
	else if (difference > getTimeout()) {
		return false;
	}
	return false;
}
void addMessage(User* user, Node* message){
	
}
Node *findMessage(User *user, long id){
	if (user == NULL) {
		puts("user::findMessage() user parameter is NULL");
		return NULL;
	}
	if (user->messageCount == 0) {
		puts("user::findMessage() has no messages");
		return NULL;
	}
	if (id < 0) {
		puts("user::findMessage() was given an invalid id parameter (<0)");
		return NULL;
	}
	
	Node *currentNode = user->messages;
	while (currentNode != NULL) {
		if(currentNode->id == id) {
			return currentNode;
		}
		currentNode = currentNode->next;
	}
	
	puts("user::findMessage() couldn't find the message");
	return NULL;
}
long getTimeout() {
	//like a static field
	return 1800; //30 seconds
}