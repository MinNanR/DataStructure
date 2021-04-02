#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_TYPE int

typedef struct List {
    ELEMENT_TYPE data;
    struct List *next;
    struct List *last;
    int size;
} List, Node, *PList, *PNode;

PList init() {
    PList list = (PList)malloc(sizeof(List));
    list->next = NULL;
    list->last = NULL;
    list->data = NULL;
    list->size = 0;
    return list;
}

int insert(PList list, ELEMENT_TYPE element) {
    PNode node = (Node *)malloc(sizeof(Node));
    node->data = element;
    PNode current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;
    node->next = NULL;
    node->last = current;
    list->size++;
    return 1;
}

int insertAt(PList list, ELEMENT_TYPE element, int index) {
    if (index < 0 || index >= list->size) {
        return 0;
    }
    PNode node = (Node *)malloc(sizeof(Node));
    node->data = element;
    PNode current = list;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    node->next = current;
    node->last = current->last;
    current->last->next = node;
    current->last = node;
    list->size++;
    return 1;
}

int main(int argc, char const *argv[]) {
    PList list = init();
    insert(list, 1);
    insert(list, 2);
    insert(list, 234);
    insert(list, 333);
    insertAt(list, 123, 2);
    PNode node = list->next;
    while (node != NULL) {
        if (node->last->data != NULL) {
            printf("last is %d---", node->last->data);
        }

        printf("current is %d---", node->data);
        if (node->next != NULL) {
            printf("next is %d", node->next->data);
        }
        printf("\n");
        node = node->next;
    }
    return 0;
}
