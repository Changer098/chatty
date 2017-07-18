#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "llist.h"

node *createNode(char* message, char* sender, int timestamp, long id) {
	node *newNode = (node*)malloc(sizeof(node));
	newNode->message = message;
	newNode->sender = sender;
	newNode->timestamp = timestamp;;
	newNode->id = id;
	newNode->next = NULL;
	return newNode;
}

//Returns false if error
bool freeNode(node* Node) {
	if (Node == NULL) {
		puts("llist::freeNode() recieved a NULL argument");
		return false;
	}
	else {
		if (Node->message != NULL) {
			free(Node->message);
		}
		if (Node->sender != NULL) {
			free(Node->sender);
		}
		free(Node);
		return true;
	}
}

list *createList() {
	list *newList = (list*)malloc(sizeof(list));
	newList->head = NULL;
	newList->tail = NULL;
	newList->nodeArr = (node**)malloc(sizeof(node) * 10);
	newList->arrCount = 0;
	newList->arrSize = 10;
	newList->lastId = -1;
	newList->listLength = 0;
}

//Returns false if an error occurred
bool freeList(list* List) {
	/* 
		TODO
	*/
	return false;
}

bool quickFreeList(list* List) {
	/*
		TODO
	*/
	return false;
}

//return true if Contains || false if not
bool ContainsId(list *List, long id) {
	if (List == NULL) { 
		return false;
	}
	if (List->head == NULL) {
		return false;
	}
	if (List->tail == NULL) {
		return false;
	}
	if (List->listLength == 0) {
		return false;
	}
	if (id < 0) { 
		return false;
	}
	bool doLoop = true, firstRun = true;
	int indexLeft = 0, indexRight = List->arrCount;
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

node *add(node *Node, list *List) {
	if (Node == NULL) {
		puts("llist::add() Tried to add a NULL node");
	}
	else if (List == NULL) {
		puts("llist::add() Tried to add a node to a NULL list");
	}
	else {
		List->tail->next = Node;
		List->tail = Node;
		
		/*
			TODO:
		*/
	}
}

//Auxilary function to search through a node to find a matching id
node * __search(node *Node, long id) {
	node *currNode = Node;
	node *nextNode = Node;
	while (nextNode != NULL && currNode != NULL) {
		if (currNode->id == id) {
			return currNode;
		}
		nextNode = currNode->next;
	}
	return NULL;
}
