#include <stdio.h>
#include "linkedlist.h"

LinkedListPtr CreateLinkedList()
{
    LinkedListPtr newLinkedList =
        (LinkedListPtr)malloc(sizeof(LinkedListPtr));
    if (newLinkedList == NULL)
        return NULL;

    newLinkedList->num_elements = 0;

    newLinkedList->head = CreateLinkedListNode(0);
    newLinkedList->head->prev = NULL;
    newLinkedList->head->next = newLinkedList->tail;

    newLinkedList->tail = CreateLinkedListNode(0);
    newLinkedList->tail->prev = newLinkedList->head;
    newLinkedList->tail->next = NULL;

    return newLinkedList;
}

void DestroyLinkedList(LinkedListPtr list)
{
    int count = list->num_elements;
    LinkedListNodePtr node = list->head->next;
    if (count == 0)
    {
        free(list->head);
        free(list->tail);
        return;
    }
    while (node->next != NULL)
    {
        node = node->next;
        DestroyLinkedListNode(node->prev);
    }
    list->head->next = list->tail;
    list->tail->prev = list->head;
    free(list->head);
    free(list->tail);
    return;
}

int NumElementsInLinkedList(LinkedListPtr list)
{
    return list->num_elements;
}

int InsertLinkedList(LinkedListPtr list, int newData)
{
    LinkedListNodePtr newNode;
    newNode = CreateLinkedListNode(newData);
    if (newNode == NULL) 
        return -1;
    else{
        newNode->next = list->head->next;
        list->head->next->prev = newNode;
        list->head->next = newNode;
        newNode->prev = list->head;

        list->num_elements += 1;
        return 0;
    }
}

int AppendLinkedList(LinkedListPtr list, int newData)
{
    LinkedListNodePtr newNode;
    newNode = CreateLinkedListNode(newData);
    if(newNode == NULL)
        return -1;
    else{
        list->tail->prev->next = newNode;
        newNode->prev = list->tail->prev;
        newNode->next = list->tail;
        list->tail->prev = newNode;

        list->num_elements += 1;
        return 0;
    }
    
}

void PrintLinkedList(LinkedListPtr list)
{
    // printf("hello world\n");
    
    if(list->num_elements == 0)
        printf("The list is empty\n");
    else printf("%p", list);
    // return;
}

int PrintAllLinkedList(LinkedListPtr list)
{
    if (list->num_elements == 0)
        return -1;
    
    int count = list->num_elements;
    LinkedListNodePtr temp = list->head->next;
    while (count > 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count--;
    }
    return 0;
}

LinkedListNode *CreateLinkedListNode(int data)
{
    LinkedListNode *newNode = (LinkedListNode*) malloc(sizeof(LinkedListNode));
    
    if (newNode == NULL)
        return NULL;

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

int DestroyLinkedListNode(LinkedListNode *node)
{
    free(node);
    return 0;
}

int RemoveLLElem(LinkedListPtr list, LinkedListNodePtr ptr)
{
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    list->num_elements--;
    free(ptr);
    return 0;
}