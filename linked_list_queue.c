#include "linked_list.h"
#include <stdio.h>

int main() {
	Queue *queue = NULL;
	queue = (Queue *)malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;

	Node *head = createNode(0);

    queue->head = head;
    queue->tail = head->next;

	Node *minus_one = createNode(-1);
    Node *minus_two = createNode(-2);

    in(queue, minus_one);
    in(queue, minus_two);

    out(queue);
    printList(queue->head);
	return 0;
}