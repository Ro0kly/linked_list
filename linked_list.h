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
Node *insert_at_position(Node *node, int position, int id);
Node *insert_after_value(Node *node, int after_id, int id);
Node *remove_first(Node *node);
void remove_last(Node *node);
Node *remove_with_id(Node *node, int id);

// Additional methods

//void printListReverse(Node *head); //COMPILE ERROR
void printListRecursion(Node *head);