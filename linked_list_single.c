#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Node *head = createNode(1);
	Node *two = createNode(2);
	Node *three = createNode(3);
	Node *four = createNode(4);
	Node *five = createNode(5);

	push(head, two);
	push(two, three);
	push(three, four);
	push(four, five);

	printList(head);
	return 0;
}
