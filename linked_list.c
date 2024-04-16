#include "linked_list.h"

// Main methods

Node *createNode(int id) {
	Node *node = NULL;
	node = malloc(sizeof(Node));
	node->id = id;
	node->next = NULL;
	return node;
}

void printList(Node *head) {
	Node *current = head;
	while (current != NULL) {
		if (current->next == NULL) {
			printf("%d", current->id);
		} else {
			printf("%d ", current->id);
		}
		current = current->next;
	}
}

void push(Node *node, Node *next) { node->next = next; }

Node *insert_to_start(Node *node, int id) {
	Node *new_head = createNode(id);
	new_head->next = node;
	return new_head;
}

Node *insert_at_position(Node *node, int position, int id) {
	Node *current = node;
	int counter = 0;
	Node *new_node = createNode(id);
	if (position == 0) {
		new_node = insert_to_start(node, id);
	} else {
		while (current != NULL) {
			if (counter == position - 1) {
				new_node->next = current->next;
				current->next = new_node;
				break;
			} else {
				current = current->next;
				counter++;
			}
		}
	}
	return new_node;
}

Node *insert_after_value(Node *node, int after_id, int id) {
	Node *current = node;
	Node *new_node = createNode(id);

	while (current != NULL) {
		if (current->id == after_id) {
			new_node->next = current->next;
			current->next = new_node;
			break;
		} else {
			current = current->next;
		}
	}
	return new_node;
}

Node *remove_first(Node *node) {
	node = node->next;
	return node;
}

void remove_last(Node *node) {
	Node *current = node;
	while (current != NULL) {
		if (current->next->next == NULL) {
			Node *tmp = current->next;
			current->next = NULL;
			free(tmp);
			break;
		} else {
			current = current->next;
		}
	}
}

Node *remove_with_id(Node *node, int id) {
	Node *current = node;
	if (current->id == id) {
		current = current->next;
		return current;
	} else {
		while (current != NULL) {
			if (current->next->id == id) {
				Node *tmp = current->next;
				current->next = current->next->next;
				free(tmp);
				break;
			} else {
				current = current->next;
			}
		}
		return node;
	}
}

// Additional methods

void printListRecursion(Node *head) {
	Node *current = head;
	if (current->next != NULL) {
		printf("%d ", current->id);
		current = current->next;
		printListRecursion(current);
	} else {
		printf("%d", current->id);
	}
}

// void printListReverse(Node *head) {
//     Node *current = head;
//     while (current -> next != NULL) {
//         current = current -> next;
//     }
//     printf("%d ", current -> id);
//     free(current);
//     printListReverse(head);
// }