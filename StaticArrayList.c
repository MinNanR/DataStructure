#include <stdio.h>

#define ELEMENT_TYPE int
#define MAX_SIZE 100

typedef struct ArrayList {
    ELEMENT_TYPE data[MAX_SIZE];
    int size;
} ArrayList;

ArrayList init() {
    ArrayList list;
    list.size = 0;
    return list;
}

int insert(ArrayList *list, ELEMENT_TYPE element) {
    if (list->size == MAX_SIZE) {
        return 0;
    }
    list->data[list->size++] = element;
    return 1;
}

int inserAt(ArrayList *list, ELEMENT_TYPE element, int index) {
    if (list->size == MAX_SIZE) {
        return 0;
    }
    if (index < 0 && index >= MAX_SIZE) {
        return 0;
    }
    for (int i = list->size; i >= index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = element;
    list->size++;
    return 1;
}

ELEMENT_TYPE getElement(ArrayList *list, int index) {
    if (index >= 0 && index < list->size) {
        return list->data[index];
    }
    return NULL;
}

int findElementIndex(ArrayList *list, ELEMENT_TYPE element) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == element) {
            return i;
        }
    }
    return -1;
}

int removeElement(ArrayList *list, ELEMENT_TYPE element) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == element) {
            for (int j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            list->size--;
            return 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    ArrayList list = init();
    for (int i = 0; i < 100; i++) {
        insert(&list, i);
    }
    printf("\n");
}
