#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() { 
    
    Node *head = createNode(1);
    Node *two = createNode(2);
    Node *three = createNode(3);
    Node *four = createNode(4);

    push(head, two);
    push(two, three);
    push(three, four);

    remove_with_id(head, 2);
    printList(head);
    
    return 0;
}
