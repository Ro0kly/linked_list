#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int id;
  struct node *next;
} Node;

// Main method
Node *createNode(int id);
void printList(Node *head);
void push(Node *node, Node *next);
Node *insert_to_start(Node *node, int id);
Node *remove_first(Node *node);
void remove_last(Node *node);

// Additional methods
void printListRecursion(Node *head);
Node *insert_at_position(Node *node, int position, int id);
void append(Node *node, int after_id, int id);
Node *remove_with_id(Node *node, int id);
Node *find(Node *node, int id);
int contains(Node *node, int id);
Node *swap_ids(Node *node, int id1, int id2);
void bubble_sort(Node *node);
//void printListReverse(Node *head); //COMPILE ERROR