#include <stdio.h>

#include "linkedlist.h"

int getValue2(LinkedListNodePtr list, int number) {
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number) {
        cur = cur->next;
    }
    return cur->data;
}

LinkedListNodePtr getNode2(LinkedListNodePtr list, int number) {
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number) {
        cur = cur->next;
    }
    return cur;
}

void swap2(LinkedListNodePtr list, int start, int end) {
    int temp = getValue2(list, start);
    LinkedListNodePtr startNode = getNode2(list, start);
    LinkedListNodePtr endNode = getNode2(list, end);
    startNode->data = endNode->data;
    endNode->data = temp;
    return;
}

void Sort2(LinkedListPtr linkedlist) {
    // implement your sort here
    LinkedListNodePtr list = linkedlist->head->next;
    int count = linkedlist->num_elements;
    if (count == 0 || count == 1)
        return;
    int i, j;
    for (i = 0; i < count; i++) {
        for (j = 1; j < count - i; j++) {
            if (getValue2(list, j) > getValue2(list, j - 1))
                continue;
            swap2(list, j - 1, j);
        }
    }

    return;
}
