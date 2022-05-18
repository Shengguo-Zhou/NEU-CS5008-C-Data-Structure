#include <stdio.h>

#include "linkedlist.h"


LinkedListNodePtr SelectSmallest(LinkedListNodePtr curNode, int count){
    LinkedListNodePtr smallest;
    smallest = curNode;
    while(count > 0){
        if(curNode->data < smallest->data)
            smallest = curNode;
        curNode = curNode->next;
        count--;
    }
    return smallest;
}

void Swap(LinkedListNodePtr curNode, LinkedListNodePtr smallestValNode){
    int tempVal = curNode->data;
    curNode->data = smallestValNode->data;
    smallestValNode->data = tempVal;
    return;
}

void Sort(LinkedListPtr list) {
    //implement your sort here
    // Selection sort
    
    int count = list->num_elements;
    if(count == 0 || count == 1) return; 
    
    LinkedListNodePtr curNode = list->head->next;
    

    while(count > 0){
        LinkedListNodePtr smallestValNode = SelectSmallest(curNode, count);
        Swap(curNode, smallestValNode);
        count--;
        curNode = curNode->next;
    }

    return;
    
}

