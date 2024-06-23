#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stddef.h>

struct Node {
    void* element;
    struct Node* next;
};

typedef struct {
    struct Node* head;
    size_t dataSize;
} LinkedList;

/**
 * Initializes an empty linked list.
 * @param dataSize The byte size of the list elements type.
 * @return The initialized list.
 */
LinkedList* create_list(size_t dataSize);
int is_empty(const LinkedList* list);
void insert_at_beginning(LinkedList* list, const void* data);
void insert_at_end(LinkedList* list, const void* data);

/**
 * Iterates over all the list elements, executing the given
 * callback for each one.
 */
void traverse_list(const LinkedList* list, void (*callback)(void*));

/**
 * Releases the allocated memory for the list and its elements.
 */
void free_list(LinkedList* list);

#endif //LINKED_LIST_H
