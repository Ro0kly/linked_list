#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
	int id;
	char *second_name;
	char *short_name;
	int account_number;
	int deposit;
	struct person *prev;
	struct person *next;
} Person;

int separate_on_words(char *text, char **words) {
	//char delim[1] = " ";
	char *ptr = strtok(text, " ");
	int j = 0;

	while (ptr != NULL) {
		int len = strlen(ptr);
        //printf("len:%d, ", len);
		words[j] = malloc(sizeof(char) * len);
		words[j] = ptr;
        //printf("words_p: %s\n", words[j]);
        //strcpy(words[j], ptr);
		ptr = strtok(NULL, " ");
		j++;
	}
    return j;
}

Person *create_person(char **person_details, int details_count) {
    if (details_count < 5) {
        return NULL;
    }
	Person *person = malloc(sizeof(Person));
	person->id = atoi(person_details[0]);
	person->second_name = person_details[1];
	person->short_name = person_details[2];
	person->account_number = atoi(person_details[3]);
	person->deposit = atoi(person_details[4]);
	person->prev = NULL;
	person->next = NULL;
	return person;
}

void pushD(Person *head, Person *next) {
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

void print_person(Person *person) {
    printf("per: %d, %s, %s, %d, %d\n", person->id, person->second_name, person->short_name, person->account_number, person->deposit);
}

void print_persons(Person *head) {
    Person *current = head;
    while (current != NULL) {
        print_person(current);
        current = current->next;
    }
}

int main() {
	//Person *head = create_person(0, "Smetanin", "M.V.", 12314, 1000);
    Person *head = NULL;
	FILE *fptr = NULL;
	fptr = fopen("persons.txt", "r");
	if (fptr == NULL) {
		printf("There is no such file.\n");
	} else {
		printf("File is open to read.\n");
		const int str_length = 1000;
		char str[str_length];
		while (fgets(str, str_length, fptr) != NULL) {
            printf("str: %s\n", str);
            if (head) {
                printf("real head: %s\n", head->second_name);
            }
			char **person_details = malloc(sizeof(char *) * 5);
			int words_count = separate_on_words(str, person_details);
            //separate_on_words(str, person_details);
			//printf("person: %s, %s, %s, %s, %s\n", person_details[0],person_details[1],person_details[2],person_details[3],person_details[4]);
            if (head == NULL) {
                head = create_person(person_details, words_count);
                print_person(head);
                printf("one time head: %s\n", head->second_name);
            } else {
                Person *person = create_person(person_details, words_count);
                print_person(person);
                printf("head: %s, new person: %s\n", head->second_name, person->second_name);
                //pushD(head, person);
            }
            printf("head at the end of loop: %s\n", head->second_name);
            free(person_details);
		}
        fclose(fptr);
	}
    printf("\n");
    print_persons(head);
	return 0;
}