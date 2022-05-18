#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sort.h"
#include "sort.c"
#include "linkedlist.c"
// #include "operationtest.h"
#include "linkedlist.h"

void printListData(LinkedListPtr list) {
    printf("Number of elements is %d\n", list->num_elements);
}

int main(int argc, char *argv[]) {
    // bool debug = false;

    // // int i;
    // // for(i = 0; i<argc; i++) debug = debug || strcmp(argv[i],"-d") == 0;
    
    // // if(debug) printf("Debug enabled.\n");

    // // LinkedListPtr list = (LinkedListPtr) malloc(sizeof(LinkedListPtr));
    // LinkedListPtr list = CreateLinkedList();
    // // list->head = NULL;
    // // list->tail = NULL;
    // // list->num_elements = 0;

    // // if(debug) 
    // printListData(list);

    // AppendLinkedList(list, 1);
    
    // // if(debug) 
    // printListData(list);
    

    // // testOperations(list, debug);


    //////////////// test sort /////////////
    LinkedListPtr list = CreateLinkedList();
    AppendLinkedList(list, 10);
    AppendLinkedList(list, 7);
    AppendLinkedList(list, 4);
    AppendLinkedList(list, 11);
    AppendLinkedList(list, -12);
    
    InsertLinkedList(list, 0);
    InsertLinkedList(list, -1);
    InsertLinkedList(list, 100);

    /// the list should be 100, -1, 0, 10 , 7, 4, 11, -12

    printf("before sorting\n");
    PrintAllLinkedList(list);
    printf("\n");
    Sort(list);
    printf("after sorting\n");
    PrintAllLinkedList(list);
    printf("\n");



    // ////////// test linkedlist ///////////////////////////
    // LinkedListPtr list = CreateLinkedList();
    // printf("empty linkedlist %d\n", list->num_elements);
    // printf("empty linkedlist %d\n", NumElementsInLinkedList(list));
    // PrintLinkedList(list);
    // int i = PrintAllLinkedList(list);
    // printf("%d\n", i);
    // PrintAllLinkedList(list);
    // printf("---------empty linked list test-------\n");

    // LinkedListNode *node = CreateLinkedListNode(10);
    // DestroyLinkedListNode(node);
    // printf("---------node test-------\n");

    // AppendLinkedList(list, 10);
    // PrintLinkedList(list);
    // printf("\n");
    // PrintAllLinkedList(list);
    // printf("\n");
    // printf("add one element linkedlist: %d\n", NumElementsInLinkedList(list));
    // printf("--------- adding one node test-------\n");

    // AppendLinkedList(list, 20);
    // PrintLinkedList(list);
    // printf("\n");
    // PrintAllLinkedList(list);
    // printf("\n");                                                              // should be 10, 20
    // printf("add two element linkedlist: %d\n", NumElementsInLinkedList(list)); // shoulb be 2
    // printf("--------- adding two node test-------\n");

    // InsertLinkedList(list, 5); // should be 5, 10, 20
    // PrintAllLinkedList(list);
    // printf("\n");
    // InsertLinkedList(list, 111); // should be 111, 5, 10, 20
    // PrintAllLinkedList(list);
    // printf("\n");
    // printf("element linkedlist now should be 4 : %d\n", NumElementsInLinkedList(list));
    // printf("--------- inserting two node test-------\n");
    // // 20, 10 in linkedlist
    // // PrintLinkedList(list);
    // RemoveLLElem(list, list->head->next->next); // delete 5, should be 111, 10, 20
    // PrintAllLinkedList(list);
    // printf("\n");
    // printf("element linkedlist now should be 3 : %d\n", NumElementsInLinkedList(list));

    // DestroyLinkedList(list);

    return 0;
}

