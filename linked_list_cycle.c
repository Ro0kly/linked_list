#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	DNode *head = createNodeD(0);
	DNode *one = createNodeD(1);
	DNode *two = createNodeD(2);
	DNode *three = createNodeD(3);
	DNode *four = createNodeD(4);
	DNode *five = createNodeD(5);

	pushD(head, one);
	pushD(head, two);
	pushD(head, three);
	pushD(head, four);
	pushD(head, five);
    five->next = head;
    head->prev = five;
    printListDCycle(head);
	return 0;
}