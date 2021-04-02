#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_TYPE int

typedef struct List {
    ELEMENT_TYPE data;
    struct List *next;
    int size;
} List, Node, *PList, *PNode;

PList init() {
    PList head = (PList)malloc(sizeof(List));
    head->next = NULL;
    head->size = 0;
    return head;
}

int insert(PList list, ELEMENT_TYPE element) {
    PNode node = (PNode)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;
    PNode rear = list;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    rear->next = node;
    list->size++;
    return 1;
}

int insertAt(PList list, ELEMENT_TYPE elment, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    PNode node = (PNode)malloc(sizeof(Node));
    node->data = elment;
    PNode lastNode = list;
    PNode nextNode = lastNode->next;
    for (int i = 0; i < index; i++) {
        if (nextNode != NULL) {
            nextNode = nextNode->next;
        }
        lastNode = lastNode->next;
    }
    lastNode->next = node;
    node->next = nextNode;
    list->size++;
    return 1;
}

ELEMENT_TYPE getElement(PList list, int index) {
    PNode node = list->next;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->data;
}

int removeElement(PList list, int index) {
    if (index < 0 || index >= list->size) {
        return -1;
    }
    PNode last = list;
    for (int i = 0; i < index; i++) {
        last = last->next;
    }
    PNode current = last->next;
    last->next = last->next->next;
    free(current);
    return 0;
}

int main(int argc, char const *argv[]) {
    PList list = init();
    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 5);
    insert(list, 123);
    insert(list, 23);
    insert(list, 333);
    insertAt(list, 102, 3);
    PNode node = list->next;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    return 0;
}
