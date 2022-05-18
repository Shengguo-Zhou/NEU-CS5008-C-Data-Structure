#include <stdio.h>
#include "QuickSort_General.h"

/////////////////// helper method ////////////////////////////

int getValue(LinkedListNodePtr list, int number)
{
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number)
    {
        cur = cur->next;
    }
    return cur->data;
}

LinkedListNodePtr getNode(LinkedListNodePtr list, int number)
{
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number)
    {
        cur = cur->next;
    }
    return cur;
}

void swap(LinkedListNodePtr list, int start, int end)
{
    int temp = getValue(list, start);
    LinkedListNodePtr startNode = getNode(list, start);
    LinkedListNodePtr endNode = getNode(list, end);
    startNode->data = endNode->data;
    endNode->data = temp;
    return;
}

//////////////// quick sort ////////////////////////////

int partition(LinkedListNodePtr list, int start, int end)
{
    int pivot = getValue(list, end);
    int wall = start;
    int i;
    for (i = start; i < end; i++)
    {
        int val = getValue(list, i);
        if (val > pivot)
            continue;
        swap(list, i, wall);
        wall++;
    }
    swap(list, wall, end);
    return wall;
}

void QuickSort1(LinkedListNodePtr list, int start, int end)
{
    if (start >= end)
        return;
    else
    {
        int mid = partition(list, start, end);
        QuickSort1(list, start, mid - 1);
        QuickSort1(list, mid + 1, end);
    }
    return;
}

void QuickSortGeneral(LinkedListPtr ll_list)
{
    int len = ll_list->num_elements;
    if (len == 0 || len == 1)
        return;
    else
    {
        LinkedListNodePtr list = ll_list->head->next;
        QuickSort1(list, 0, len - 1);
        return;
    }
}
