#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* new_place = head;
	list_t* new_next;
	if(head->index >= new_element->index){
		new_element->next = head;
		head = new_element;
	}
	else{
		while (new_place->next != NULL && new_element->index >= new_place->next->index){
			new_place = new_place->next;
		}
		new_next = new_place->next;
		new_place->next = new_element;
		new_element->next = new_next;
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* current = head;
	list_t* previous = NULL;
	list_t* next = NULL;
	while (current != NULL){
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
	return head;
}
