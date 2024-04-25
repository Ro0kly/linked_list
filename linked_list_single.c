#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Node *head = createNode(0);
	Node *one = createNode(1);
	Node *two = createNode(2);

	push(head, one);
	push(head, two);

	pop(head);

	printList(head);
	return 0;
}
