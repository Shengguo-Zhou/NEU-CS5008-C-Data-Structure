#include <stdio.h>
#include <math.h>
#include "QuickSort_MedianPivot.h"

/////////////////// helper method ////////////////////////////

int getValueM(LinkedListNodePtr list, int number)
{
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number)
    {
        cur = cur->next;
    }
    return cur->data;
}

LinkedListNodePtr getNodeM(LinkedListNodePtr list, int number)
{
    int count = 0;
    LinkedListNodePtr cur = list;
    while (count++ != number)
    {
        cur = cur->next;
    }
    return cur;
}

void swapM(LinkedListNodePtr list, int start, int end)
{
    int temp = getValueM(list, start);
    LinkedListNodePtr startNode = getNodeM(list, start);
    LinkedListNodePtr endNode = getNodeM(list, end);
    startNode->data = endNode->data;
    endNode->data = temp;
    return;
}

int getmax(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getmin(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int getMedium(int one, int two, int three)
{
    int max = getmax(one, getmax(two, three));
    int min = getmin(one, getmin(two, three));
    return one + two + three - max - min;
}

//////////////// quick sort ////////////////////////////

int partitionM(LinkedListNodePtr list, int start, int end)
{
    /// choose take the first, last and middle element from the array.
    /// Use the median value of those as the pivot.
    int medium = start + (end - start) / 2;
    int mid = getMedium(getValueM(list, start), getValueM(list, medium), getValueM(list, end));
    if (getValueM(list, start) == mid)
        swapM(list, start, end);
    else if (getValueM(list, medium) == mid)
        swapM(list, medium, end);
    else
        swapM(list, end, end);
    int pivot = getValueM(list, end);
    int wall = start;
    int i;
    for (i = start; i < end; i++)
    {
        int val = getValueM(list, i);
        if (val > pivot)
            continue;
        swapM(list, i, wall);
        wall++;
    }
    swapM(list, wall, end);
    return wall;
}

void QuickSortM(LinkedListNodePtr list, int start, int end)
{
    if (start >= end)
        return;
    else
    {
        int mid = partitionM(list, start, end);
        QuickSortM(list, start, mid - 1);
        QuickSortM(list, mid + 1, end);
    }
    return;
}

void QuickSortMedianPivot(LinkedListPtr ll_list)
{
    int len = ll_list->num_elements;
    if (len == 0 || len == 1)
        return;
    else
    {
        LinkedListNodePtr list = ll_list->head->next;
        QuickSortM(list, 0, len - 1);
        return;
    }
}
