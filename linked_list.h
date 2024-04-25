#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int id;
	struct node *next;
} Node;

typedef struct dnode {
	int id;
	struct dnode *prev;
	struct dnode *next;
} DNode;

// TASK:-- Refactor all methods to check if head == NULL;
// TASK:-- Refactor all methods with pointer on pointer;
typedef struct qu {
	Node *head;
	Node *tail;
} Queue;

// SINGLE LIST METHODS
// Main methods
Node *createNode(int id);
void printList(Node *head);
void push(Node *head, Node *next);
Node *insert_to_start(Node *node, int id);
Node *remove_first(Node *node);
void pop(Node *head);

// Additional methods
void printListRecursion(Node *head);
Node *insert_at_position(Node *node, int position, int id);
void append(Node *node, int after_id, int id);
Node *remove_with_id(Node *node, int id);
Node *find(Node *node, int id);
int contains(Node *node, int id);
Node *swap_ids(Node *node, int id1, int id2);
void bubble_sort(Node *node);

// DOUBLY LIST METHODS
// Main methods
DNode *createNodeD(int id);
void printListD(DNode *head);
void pushD(DNode *node, DNode *next);
void remove_last_D(DNode **head);
DNode *remove_first_D(DNode *head);
DNode *insert_to_start_D(DNode *head, int id);

// Additional methods
void insert_at_position_D(DNode *head, int position, int id);
void remove_with_id_D(DNode *head, int id);
DNode *find_D(DNode *head, int id);

// CYCLE LIST METHODS
// Main methods

void printListDCycle(DNode *head);

// QUEUE METHODS
void in(Queue *queue, Node *new_node);
void out(Queue *queue);