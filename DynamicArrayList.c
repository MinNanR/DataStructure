#include <stdio.h>
#include <stdlib.h>

#define ELEMENT_TYPE int

typedef struct ArrayList {
    ELEMENT_TYPE *data;
    int size;
    int maxSize;
} ArrayList;

ArrayList *init() {
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->data = (ELEMENT_TYPE *)malloc(sizeof(ELEMENT_TYPE) * 10);
    list->size = 0;
    list->maxSize = 10;
    return list;
}

int insert(ArrayList *list, ELEMENT_TYPE element) {
    if (list->size == list->maxSize) {
        ELEMENT_TYPE *newList =
            (ELEMENT_TYPE *)malloc(sizeof(ELEMENT_TYPE) * (list->maxSize + 10));
        for (int i = 0; i < list->size; i++) {
            newList[i] = list->data[i];
        }
        list->maxSize = list->maxSize + 10;
    }
    list->data[list->size++] = element;
    return 0;
}

int insertAt(ArrayList *list, ELEMENT_TYPE element, int index) {
    if (list->size == list->maxSize) {
        ELEMENT_TYPE *newList =
            (ELEMENT_TYPE *)malloc(sizeof(ELEMENT_TYPE) * (list->maxSize + 10));
        for (int i = 0; i < list->size; i++) {
            newList[i] = list->data[i];
        }
        list->maxSize = list->maxSize + 10;
    }
    for (int i = list->size; i >= index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = element;
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

int removeElement(ArrayList list, ELEMENT_TYPE element) {
    for (int i = 0; i < list.size; i++) {
        if (list.data[i] == element) {
            for (int j = i; j <= list.size - 1; j++) {
                list.data[j] = list.data[j + 1];
            }
            list.size--;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    ArrayList *list = init();
    for (int i = 0; i < 100; i++) {
        insert(list, i);
    }
    return 0;
}
