#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "deque.h"

LinkedListPtrd CreateLinkedListd()
{
    LinkedListPtrd newLinkedList =
        (LinkedListPtrd)malloc(sizeof(LinkedListPtrd));
    if (newLinkedList == NULL)
        return NULL;

    newLinkedList->num_elements = 0;

    newLinkedList->head = CreateLinkedListNoded(0);
    newLinkedList->head->prev = NULL;
    newLinkedList->head->next = newLinkedList->tail;

    newLinkedList->tail = CreateLinkedListNoded(0);
    newLinkedList->tail->prev = newLinkedList->head;
    newLinkedList->tail->next = NULL;

    return newLinkedList;
}

void DestroyLinkedListd(LinkedListPtrd list)
{
    int count = list->num_elements;
    LinkedListNodePtrd node = list->head->next;
    if (count == 0)
    {
        free(list);
        return;
    }
    while (node->next != NULL)
    {
        node = node->next;
        DestroyLinkedListNoded(node->prev);
    }
    free(list); 
    return;
}

int NumElementsInLinkedListd(LinkedListPtrd list)
{
    return list->num_elements;
}

int InsertLinkedListd(LinkedListPtrd list, int newData)
{
    LinkedListNodePtrd newNode;
    newNode = CreateLinkedListNoded(newData);
    if (newNode == NULL)
        return -1;
    else {
        newNode->next = list->head->next;
        list->head->next->prev = newNode;
        list->head->next = newNode;
        newNode->prev = list->head;

        list->num_elements += 1;
        return 0;
    }
}

int AppendLinkedListd(LinkedListPtrd list, int newData)
{
    LinkedListNodePtrd newNode;
    newNode = CreateLinkedListNoded(newData);
    if (newNode == NULL)
        return -1;
    else {
        list->tail->prev->next = newNode;
        newNode->prev = list->tail->prev;
        newNode->next = list->tail;
        list->tail->prev = newNode;

        list->num_elements += 1;
        return 0;
    }

}

void PrintLinkedListd(LinkedListPtrd list)
{
    if (list->num_elements == 0)
        printf("The list is empty\n");
    else printf("%p", list);
}

int PrintAllLinkedListd(LinkedListPtrd list)
{
    if (list->num_elements == 0)
        return -1;

    int count = list->num_elements;
    LinkedListNodePtrd temp = list->head->next;
    while (count > 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count--;
    }
    return 0;
}

LinkedListNoded* CreateLinkedListNoded(int data)
{
    LinkedListNoded* newNode = (LinkedListNoded*)malloc(sizeof(LinkedListNoded));

    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

int DestroyLinkedListNoded(LinkedListNoded* node)
{
    free(node);
    return 0;
}

int RemoveLLElemd(LinkedListPtrd list, LinkedListNodePtrd ptr)
{
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    list->num_elements--;
    free(ptr);
    return 0;
}


////////////////////// queue ////////////////////////

void pushLeft(LinkedListPtrd list, int value) {
    LinkedListNodePtrd newnode;
    newnode = CreateLinkedListNoded(value);
    if (newnode == NULL) return;
    newnode->next = list->head->next;
    list->head->next->prev = newnode;
    newnode->prev = list->head;
    list->head->next = newnode;

    list->num_elements += 1;
    return;
}

void popLeft(LinkedListPtrd list){
    if(list->num_elements == 0) return;
    LinkedListNodePtrd node = list->head->next;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);

    list->num_elements -= 1;
    return;
}

int peekLeft(LinkedListPtrd list){
    if(list->num_elements == 0) return -1;
    LinkedListNodePtrd node = list->head->next;
    return node->data;
}

void pushRight(LinkedListPtrd list, int value){
    LinkedListNodePtrd newnode;
    newnode = CreateLinkedListNoded(value);
    if (newnode == NULL) return;
    newnode->prev = list->tail->prev;
    list->tail->prev->next = newnode;
    newnode->next = list->tail;
    list->tail->prev = newnode;

    list->num_elements += 1;
    return;
}

void popRight(LinkedListPtrd list){
    if(list->num_elements == 0) return;
    LinkedListNodePtrd node = list->tail->prev;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);

    list->num_elements -= 1;
    return;
}

int peekRight(LinkedListPtrd list){
    if(list->num_elements == 0) return -1;
    LinkedListNodePtrd node = list->tail->prev;
    return node->data;
}
