#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct List {
    Node* head;
    int size;
}List;

List* create(int init) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = init;

    List* l = (List*)malloc(sizeof(List));
    l->head = n;
    l->size = 1;
    return l;
}

List* add(List* list, int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;

    List* l = (List*)malloc(sizeof(List));
    n->next = list->head;

    l->head = n;
    l->size = list->size + 1;
    free(list);

    return l;
}



Node* SelectSmallest(Node* curNode, int count) {
    Node* smallest;
    smallest = curNode;
    while (count > 0) {
        if (curNode->data < smallest->data)
            smallest = curNode;
        curNode = curNode->next;
        count--;
    }
    return smallest;
}

void swap(Node* curNode, Node* smallestValNode) {
    int tempVal = curNode->data;
    curNode->data = smallestValNode->data;
    smallestValNode->data = tempVal;
    return;
}


// I choose the selection sort
void sort(List* head) {
    int count = head->size;
    if (count == 0 || count == 1) return;

    Node* curNode = head->head;
    while (count > 0) {
        Node* smallestNode = SelectSmallest(curNode, count);
        swap(curNode, smallestNode);
        count--;
        curNode = curNode->next;
    }
    return;
}




bool isSorted(List* list) {
    if (list == NULL || list->head == NULL) return false;
    if (list->head->next == NULL) return true;
    Node* curr = list->head;
    Node* temp = list->head->next;
    while (temp != NULL) {
        if (temp->data < curr->data) return false;
        curr = temp;
        temp = temp->next;
    }

    return true;
}

int main() {
    Node* n1 = (Node*)malloc(sizeof(Node));
    Node* n2 = (Node*)malloc(sizeof(Node));

    n1->data = 1;
    n2->data = 2;
    List* l1 = (List*)malloc(sizeof(List));
    l1->head = n2;
    l1->size = 1;

    sort(l1);

    bool r1 = isSorted(l1);
    printf("isSorted1: %d\n", r1);

    n2->next = n1;
    l1->size++;
    // printf("size is %d\n", l1->size);
    sort(l1);

    bool r2 = isSorted(l1);
    printf("isSorted2: %d\n", r2);

    ///////// my test //////////
    l1 = add(l1, -10);
    bool r3 = isSorted(l1);
    printf("isSorted3: %d\n", r3);
}


