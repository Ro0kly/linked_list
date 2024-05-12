#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Двунаправленный кольцевой список (вариант данных 3).
Упорядочить список в порядке возрастания номеров счетов.
Подсчитать количество вкладчиков и общую сумму их вкладов для вкладов,
превышающих заданную величину.
*/

// Comment: Данная структура Person является нодой двунаправленного списка.
typedef struct person {
	int id;
	char *second_name;
	char *short_name;
	int account_number;
	int deposit;
	struct person *prev;
	struct person *next;
} Person;

/*
Comment: Данная функция разбивает строку на массив слов (матрица).
Возвращает количество полученных слов.
*/
int separate_words(char *text, char **words) {
	char *ptr = strtok(text, " ");
	int j = 0;
	while (ptr != NULL) {
		int len = strlen(ptr);
		words[j] = malloc(sizeof(char) * len);
		words[j] = ptr;
		ptr = strtok(NULL, " ");
		j++;
	}
	return j;
}

// Comment: Данная функция создает ноду Person и возвращает ее.
Person *create_person(char **person_details, int details_count) {
	if (details_count < 5) {
		return NULL;
	}
	Person *person = malloc(sizeof(Person));
	person->id = atoi(person_details[0]);
	person->second_name = strdup(person_details[1]);
	person->short_name = strdup(person_details[2]);
	person->account_number = atoi(person_details[3]);
	person->deposit = atoi(person_details[4]);
	person->prev = NULL;
	person->next = NULL;
	return person;
}

// Comment: Данная функция пушит ноду в список (делает хвостовой).
void push(Person *head, Person *next) {
	if (head == NULL) {
		printf("Head is NULL");
		return;
	}
	Person *current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = next;
	next->prev = current;
}

// Comment: Данная функция печатает одну ноду.
void print_person(Person *person) {
	printf("person: %d, %s, %s, %d, %d\n", person->id, person->second_name, person->short_name, person->account_number,
	       person->deposit);
}

/*
Comment: Данная функция печатает список. 
Поскольку список кольцевой, ожидаем когда current дойдет до head.
*/
void print_persons(Person *head) {
	Person *current = head;
	do {
		print_person(current);
		current = current->next;
		if (current == head) {
			break;
		}
	} while (1);
}

/*
Comment: Данная функция читает файл persons.txt по строкам
и создает из вкладчиков (данные строк) ноду, а затем пушит в лист.
*/
void create_list_from_file(FILE *fptr, Person **head, Person **tail, int *count) {
	const int str_length = 1000;
	char str[str_length];
	while (fgets(str, str_length, fptr) != NULL) {
		char str_copy[1000];
		strcpy(str_copy, str);
		char **person_details = malloc(sizeof(char *) * 5);
		int words_count = separate_words(str, person_details);
		if (*head == NULL) {
			*head = create_person(person_details, words_count);
			(*count)++;
		} else {
			Person *person = create_person(person_details, words_count);
			push(*head, person);
			(*count)++;
			int len = strlen(str_copy);
			if (str_copy[len - 1] != '\n') {
				(*tail) = person;
				person->next = *head;
				(*head)->prev = person;
			}
		}
		free(person_details);
	}
}

//Comment: Данная функция меняет местами данные вкладчиков.
void swap_info(Person **current) {
	int tmp_id = (*current)->id;
	char *tmp_second_name = (*current)->second_name;
	char *tmp_short_name = (*current)->short_name;
	int tmp_account_number = (*current)->account_number;
	int tmp_deposit = (*current)->deposit;

	(*current)->id = (*current)->next->id;
	(*current)->second_name = (*current)->next->second_name;
	(*current)->short_name = (*current)->next->short_name;
	(*current)->account_number = (*current)->next->account_number;
	(*current)->deposit = (*current)->next->deposit;

	(*current)->next->id = tmp_id;
	(*current)->next->second_name = tmp_second_name;
	(*current)->next->short_name = tmp_short_name;
	(*current)->next->account_number = tmp_account_number;
	(*current)->next->deposit = tmp_deposit;
}

//Данная функция сортирует вкладчиков (ноды) по номеру счета (account_number).
void sort_by_account_number(Person **head, Person **tail) {
	int swap = 0;
	(*head)->prev = NULL;
	(*tail)->next = NULL;
	Person *current = *head;

	while (current != NULL) {
		swap = 0;
		Person *current_2 = current;
		while (current_2->next != NULL) {
			if (current_2->account_number > current_2->next->account_number) {
				swap = 1;
				swap_info(&current_2);
			}
			current_2 = current_2->next;
		}
		if (swap == 0) {
			(*head) = current;
			(*tail) = current_2;
			(*tail)->next = *head;
			(*head)->prev = *tail;
			break;
		}
	}
	printf("\n");
}

/*
Comment: Данная функция принимает опорное значение
и считает сумму депозитов выше этого значения.
*/
void get_sum_by_pivot(Person *head, int pivot) {
	int sum = 0;
	Person *current = head;
	do {
		if (current->deposit > pivot) {
			sum += current->deposit;
		}
		current = current->next;
	} while (current != head);
	printf("Опорная сумма: %d, сумма депозитов счетов выше опорный суммы: %d\n", pivot, sum);
}

/*
Comment: Это функция main, здесь программа начинает свое выполнение,
открываем файл для чтения.
*/
int main() {
	Person *head = NULL;
	Person *tail = NULL;
	int person_count = 0;
	int pivot = 10000;

	FILE *fptr = NULL;
	fptr = fopen("persons.txt", "r");
	if (fptr == NULL) {
		printf("Такого файла не существует.\n");
	} else {
		printf("Файл готов к чтению.\n");
		create_list_from_file(fptr, &head, &tail, &person_count);
		printf("--------------------------\n");
		printf("Начальный список вкладчиков (до изменений):\n");
		print_persons(head);
		printf("--------------------------\n");
		printf("Количество вкладчиков: %d\n\n", person_count);
		printf("Список вкладчиков остортированный по возрастанию номеров счетов:\n");
		sort_by_account_number(&head, &tail);
		print_persons(head);
		printf("\n");
		get_sum_by_pivot(head, pivot);
		printf("--------------------------\n");
		fclose(fptr);
	}
	return 0;
}