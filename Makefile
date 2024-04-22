single:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_single.c
	./a.out
doubly:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_doubly.c
	./a.out
cycle:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_cycle.c
	./a.out