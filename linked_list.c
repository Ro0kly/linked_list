#include "linked_list.h"

// SINGLE LIST METHODS

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
				current->next = current->next->next;
				break;
			} else {
				current = current->next;
			}
		}
		return node;
	}
}

Node *find(Node *node, int id) {
	Node *current = node;
	Node *tmp = NULL;
	while (current != NULL) {
		if (current->id == id) {
			tmp = current;
			break;
		} else {
			current = current->next;
		}
	}
	return tmp;
}

int contains(Node *node, int id) {
	Node *current = node;
	int tmp = 0;
	while (current != NULL) {
		if (current->id == id) {
			tmp = 1;
			break;
		} else {
			current = current->next;
		}
	}
	return tmp;
}

void append(Node *node, int after_id, int id) {
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
}

Node *swap_ids(Node *node, int id1, int id2) {
	Node *current = node;
	Node *pre = NULL;
	Node *pre_buff_1 = NULL;
	Node *pre_buff_2 = NULL;
	Node *buff_1 = NULL;
	Node *buff_2 = NULL;
	Node *hd = node;
	while (current != NULL) {

		if (current->id == id1 && buff_1 == NULL) {
			buff_1 = current;
			pre_buff_1 = pre;
			printf("buff_1: %d\n", buff_1->id);
		} else if (current->id == id2 && buff_2 == NULL) {
			buff_2 = current;
			pre_buff_2 = pre;
			printf("buff_2: %d\n", buff_2->id);
		}

		if (buff_1 == NULL || buff_2 == NULL) {
			pre = current;
		} else {
			break;
		}
		current = current->next;
	}

	if (buff_1 != NULL && buff_2 != NULL) {
		if (pre_buff_1 == NULL) {
			hd = buff_2;
		} else {
			pre_buff_1->next = buff_2;
		}
		if (pre_buff_2 == NULL) {
			hd = buff_1;
		} else {
			pre_buff_2->next = buff_1;
		}

		Node *tmp = buff_2->next;
		buff_2->next = buff_1->next;
		buff_1->next = tmp;
	}
	return hd;
}

void bubble_sort(Node *node) {
	int swap = 0;
	Node *current = node;
	while (current != NULL) {
		swap = 0;
		Node *current_2 = current;
		printf("new current: %d\n", current_2->id);
		while (current_2->next != NULL) {
			if (current_2->id > current_2->next->id) {
				swap = 1;
				printf("swap %d and %d\n", current_2->id, current_2->next->id);
				int tmp = current_2->id;
				current_2->id = current_2->next->id;
				current_2->next->id = tmp;
			}
			current_2 = current_2->next;
		}
		printf("next current: %d\n", current->id);
		if (swap == 0) {
			break;
		}
	}
}

// DOUBLY NODE METHODS

DNode *createNodeD(int id) {
	DNode *dnode = NULL;
	dnode = malloc(sizeof(DNode));
	dnode->id = id;
	dnode->prev = NULL;
	dnode->next = NULL;
	return dnode;
}

void printListD(DNode *head) {
	DNode *current = head;
	while (current != NULL) {
		if (current->next == NULL) {
			printf("%d", current->id);
		} else {
			printf("%d ", current->id);
		}
		current = current->next;
	}
}

void pushD(DNode *head, DNode *next) {
	if (head == NULL) {
		printf("Head is NULL");
		return;
	}
	DNode *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = next;
	next->prev = current;
}

DNode *remove_first_D(DNode *head) {
	if (head == NULL) {
		printf("Head is NULL");
		return NULL;
	}

	head = head->next;
	head->prev = NULL;
	return head;
}

void remove_last_D(DNode *head) {
	if (head == NULL) {
		printf("Head is NULL");
		return;
	}
	DNode *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	DNode *tmp = current->prev;
	tmp->next = NULL;
}

DNode *insert_to_start_D(DNode *head, int id) {
	if (head == NULL) {
		printf("Head is NULL");
		return NULL;
	}
	DNode *new_node = NULL;
	new_node = (DNode *)malloc(sizeof(DNode));
	new_node->id = id;
	new_node->next = head;
	head->prev = new_node;
	return new_node;
}

void insert_at_position_D(DNode *head, int position, int id) {
	if (head == NULL) {
		printf("Head is NULL\n");
		return;
	}
	DNode *current = head;
	int count = 0;
	DNode *new_node = NULL;
	new_node = (DNode *)malloc(sizeof(DNode));
	while (current != NULL) {
		if (count == position) {
			new_node->id = id;
			new_node->next = current;
			new_node->prev = current->prev;
			current->prev->next = new_node;
			current->prev = new_node;
			break;
		} else {
			current = current->next;
			count++;
		}
	}
}

void remove_with_id_D(DNode *head, int id) {
	if (head == NULL) {
		printf("Head is NULL\n");
		return;
	}
	DNode *current = head;
	while (current != NULL) {
		if (current->id == id) {
			current->prev->next = current->next;
			current->next->prev = current->prev;
			break;
		} else {
			current = current->next;
		}
	}
}

DNode *find_D(DNode *head, int id) {
	if (head == NULL) {
		printf("Head is NULL");
		return NULL;
	}
	DNode *current = head;
	DNode *node_to_find = NULL;
	while (current != NULL) {
		if (current->id == id) {
			node_to_find = (DNode *)malloc(sizeof(DNode));
			node_to_find = current;
			break;
		} else {
			current = current->next;
		}
	}
	return node_to_find;
}

// CYCLE LIST METHODS

void printListDCycle(DNode *head) {
	if (head == NULL) {
		printf("Head is NULL\n");
		return;
	}
	DNode *current = head;
	do {
		if (current -> next == head) {
			printf("%d",current->id);
		} else {
			printf("%d ",current->id);
		}
		current = current->next;
	} while(current != head);
}