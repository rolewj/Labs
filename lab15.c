#include <stdio.h>
#include <malloc.h>

typedef struct list{
	int data;
	struct list* next;
} List;

List* addFirst(List* head, List* new_el){
	new_el -> next = head;
	return new_el;
}

List* addLast(List* head, List* new_el){
	if (head == NULL){
		return new_el;
	}
	while(head -> next != NULL){ // пока не встретим последний элемент
		head = head -> next; // переходим к следующему элементу
	}
	head -> next = new_el; // добавляем в конец новый элемент
	return head;
}

List* addByIncreasing(List* head, List* new_el){
	List* prev = NULL;
	List* next = head;
	while(next != NULL){ // пока следующий элемент не пустой 
		if (new_el -> data == next -> data){ // если новый равен следующему элементу
			free(new_el); // освобождаем новый элемент
			return head;
		}
		if (new_el -> data < next -> data){ // если выполняется, то элемент находится в нужном месте 
			break;
		}
		prev = next;
		next = next -> next;
	}
	new_el -> next = next; // новый элемент указывает следующему 
	if (prev != NULL){ // если прошлого элемента не существует
		prev -> next = new_el;
		return head;
	} 
	else{
		return new_el;
	}
}

void printList(List* head){
	while(head != NULL){
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

void freeList(List* head){
	while(head != NULL) {
		List* n = head; // запоминает текущий элемент
		head = head -> next;
		free(n);
	}
}

int main(int argc, char** argv){
	List* head = NULL;
	for(;;){
		int input;
		scanf("%d", &input);
		if(input == 0){
			break;
		}
		List* num = (List*) malloc(sizeof(List)); // создает новый элемент
		num -> data = input;
		head = addByIncreasing(head, num); // добавляем в список новый элемент
		printf("List: ");
		printList(head);
	}
	printf("List: ");
	printList(head);
	freeList(head);
	return 0;
}
