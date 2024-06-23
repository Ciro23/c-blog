#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static struct Node* create_node(const void* data, const size_t dataSize) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->element = malloc(dataSize);
    newNode->next = NULL;
    memcpy(newNode->element, data, dataSize);
    return newNode;
}

LinkedList* create_list(const size_t dataSize) {
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->dataSize = dataSize;
    return list;
}

int is_empty(const LinkedList* list) {
    return list->head == NULL;
}

void append(LinkedList* list, const void* data) {
    struct Node* newNode = create_node(data, list->dataSize);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    struct Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void traverse_list(const LinkedList* list, void (*callback)(void*)) {
    const struct Node* currentNode = list->head;
    while (currentNode != NULL) {
        callback(currentNode->element);
        currentNode = currentNode->next;
    }
}

void free_list(LinkedList* list) {
    while (list->head != NULL) {
        struct Node* currentNode = list->head;
        list->head = list->head->next;
        free(currentNode->element);
        free(currentNode);
    }
    free(list);
}
