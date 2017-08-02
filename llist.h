#ifndef _LLIST_H__

#include <stdbool.h>

#define _LLIST_H__

//Singly Linked Node
typedef struct nodeT {
	struct nodeT *next;
	char *message;
	char *sender;
	long timestamp;
	long id;
} Node;

typedef struct listT {
	Node *head;
	Node *tail;
	//Array of Steps within LL
	Node **nodeArr;
	//Count of in Array
	long arrCount;
	//Count of Allocated Locations
	long arrSize;
	//The last node's ID
	long lastId;
	//Length of the List
	long listLength;
	//Distance between each node in the Array
	int stepCount;
} List;


Node *createNode(char* message, char* sender, long timestamp, long id);
bool freeNode(Node* node);

List *createList();
bool freeList(List* list);
Node *add(Node *node, List* list);

#endif