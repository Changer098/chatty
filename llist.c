#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "llist.h"

Node *createNode(char* message, char* sender, long timestamp, long id) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->message = message;
	newNode->sender = sender;
	newNode->timestamp = timestamp;;
	newNode->id = id;
	newNode->next = NULL;
	return newNode;
}

//Returns false if error
bool freeNode(Node* node) {
	if (node == NULL) {
		puts("llist::freeNode() recieved a NULL argument");
		return false;
	}
	else {
		if (node->message != NULL) {
			free(node->message);
		}
		if (node->sender != NULL) {
			free(node->sender);
		}
		free(node);
		return true;
	}
}

List *createList() {
	List *newList = (List*)malloc(sizeof(List));
	newList->head = NULL;
	newList->tail = NULL;
	newList->nodeArr = (Node**)malloc(sizeof(Node) * 10);
	newList->arrCount = 0;
	newList->arrSize = 10;
	newList->lastId = -1;
	newList->listLength = 0;
	return newList;
}

//Returns false if an error occurred
bool freeList(List* list) {
	/* 
		TODO
	*/
	return false;
}

bool quickFreeList(List* list) {
	/*
		TODO
	*/
	return false;
}

//return true if Contains || false if not
bool ContainsId(List *list, long id) {
	if (list == NULL) { 
		return false;
	}
	if (list->head == NULL) {
		return false;
	}
	if (list->tail == NULL) {
		return false;
	}
	if (list->listLength == 0) {
		return false;
	}
	if (id < 0) { 
		return false;
	}
	bool doLoop = true, firstRun = true;
	int indexLeft = 0, indexRight = list->arrCount;
	do {
		//do left then right
		//RULES
		
		/*
			TODO
		*/
	}
	while (doLoop);
	return false;
}

Node *add(Node *node, List *list) {
	if (node == NULL) {
		puts("llist::add() Tried to add a NULL node");
	}
	else if (list == NULL) {
		puts("llist::add() Tried to add a node to a NULL list");
	}
	else {
		list->tail->next = node;
		list->tail = node;
		
		/*
			TODO:
		*/
	}
}

//Auxilary function to search through a node to find a matching id
Node * __search(Node *node, long id) {
	Node *currNode = node;
	Node *nextNode = node;
	while (nextNode != NULL && currNode != NULL) {
		if (currNode->id == id) {
			return currNode;
		}
		nextNode = currNode->next;
	}
	return NULL;
}
