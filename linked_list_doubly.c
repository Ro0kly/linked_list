#include <stdio.h>
#include "linked_list.h"

int main() {

    DNode *head = createNodeD(0);

    remove_last_D(&head);

    printListD(head);
    // DNode *one = createNodeD(1);
    // DNode *two = createNodeD(2);
    // DNode *three = createNodeD(3);
    // DNode *four = createNodeD(4);
    // DNode *five = createNodeD(5);

    // pushD(head, one);
    // pushD(head, two);
    // pushD(head, three);
    // pushD(head, four);
    // pushD(head, five);

    // remove_last_D(head);
    // head = remove_first_D(head);
    // head = insert_to_start_D(head, -1);
    // insert_at_position_D(head, 4, 6);
    // remove_with_id_D(head, 2);
    // printListD(head);
    
    return 0;
}