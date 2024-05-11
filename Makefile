single:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_single.c
	./a.out
doubly:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_doubly.c
	./a.out
cycle:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_cycle.c
	./a.out
queue:
	gcc -Wall -Werror -Wextra linked_list.c linked_list_queue.c
	./a.out
ht:
	gcc -Wall -Werror -Wextra home_task_2.c
	./a.out
hts:
	gcc home_task_2.c
	./a.out