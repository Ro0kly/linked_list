#include <stdio.h>
#include "linked_list.h"

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

    remove_last_D(head);
    printListD(head);
    return 0;
}