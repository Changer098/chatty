//Singly Linked Node
typedef struct node {
	struct node *next;
	char *message;
	char *sender;
	int timestamp;
	long id;
} node;

typedef struct list {
	struct node *head;
	struct node *tail;
	//Array of Steps within LL
	struct node **nodeArr;
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
} list;


node *createNode(char* message, char* sender, int timestamp, long id);
bool freeNode(node* Node);

list *createList();
bool freeList(list* List);
node *add(node *Node, list* List);
