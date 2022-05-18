#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly.c"
#include "doubly.h"
#include "deque.c"
#include "deque.h"


int main()
{

    //////////////// test double linked list /////////////
    LinkedListPtr list = CreateLinkedList();

    AppendLinkedList(list, 10);
    addLeft(list, 1);
    addLeft(list, 2);
    removeLeft(list);
    printf("should be 1, 10 \n");
    PrintAllLinkedList(list);
    printf("\n");


    addRight(list, 1);
    addRight(list, 2);
    removeRight(list);
    printf("should be 1, 10, 1 \n");
    PrintAllLinkedList(list);
    printf("\n");

    insertAt(list, 1, 5);
    printf("should be 1, 5, 10, 1 \n");
    PrintAllLinkedList(list);
    printf("\n");

    removeAt(list, 1);
    printf("should be 5, 10, 1 \n");
    PrintAllLinkedList(list);
    printf("\n");

    if (hasValue(list, 10))
        printf("has value 10 \n");

    DestroyLinkedList(list);



    //////////////// test Deque /////////////

    LinkedListPtrd list2 = CreateLinkedListd();
    AppendLinkedListd(list2, 10);

    pushLeft(list2, 3);
    pushLeft(list2, 2);
    pushLeft(list2, 1);
    popLeft(list2);
    printf("should be 2, 3, 10 \n");
    PrintAllLinkedListd(list2);
    printf("\nshould be 2 \n");
    printf("%d\n", peekLeft(list2));

    pushRight(list2, 3);
    pushRight(list2, 2);
    pushRight(list2, 1);
    popRight(list2);
    printf("should be 2, 3, 10, 3, 2 \n");
    PrintAllLinkedListd(list2);
    printf("\nshould be 2 \n");
    printf("%d\n", peekRight(list2));


    return 0;
}
