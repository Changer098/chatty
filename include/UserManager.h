#ifndef _USERMANAGER_H__
#include <stdbool.h>
#include "user.h"
#define	_USERMANAGER_H__
typedef struct {
	UserArr *users;
	int userCount;
	UserArr *loggedIn;
	int loggedInCount;
	int loggedInSize;
} Manager;
typedef struct {
	User *users;
	int count;
	int size;
} UserArr;
bool login(Manager *manager, User *user);
bool getLoggedIn(Manager *manager, long cookie);
void __addToArr(UserArr *arr, User *user);
void __removeFromArr(UserArr *arr, long cookie);
#endif