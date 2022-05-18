#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "sort.c"
#include "linkedlist.h"
#include "linkedlist.c"
#include "QuickSort_General.h"
#include "QuickSort_General.c"
#include "QuickSort_MedianPivot.h"
#include "QuickSort_MedianPivot.c"
#include "sort2.h"
#include "sort2.c"
#include <time.h>

int main()
{

    ///////////// generate random number /////////////////////////

    int min_val = 1;
    int max_val = 100;
    int MAX = 50;
    time_t t;
    srand(time(&t));
    LinkedListPtr list = CreateLinkedList();
    int randomNumberCount = 0;

    while (randomNumberCount++ < 50)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        printf("This number will always be between 1 and 100: %d\n", randomNumber);
        AppendLinkedList(list, randomNumber);
    }
    printf("before sorting\n");
    PrintAllLinkedList(list);
    printf("\n");
    Sort(list);
    printf("after sorting\n");
    PrintAllLinkedList(list);
    printf("\n");
    DestroyLinkedList(list);
    printf("--------- ^ part 1 finished   -------\n");

    LinkedListPtr list2 = CreateLinkedList();
    randomNumberCount = 0;

    while (randomNumberCount++ < 50)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        printf("This list2 number will always be between 1 and 100: %d\n", randomNumber);
        AppendLinkedList(list2, randomNumber);
    }
    printf("quick sorting before sorting\n");
    PrintAllLinkedList(list2);
    printf("\n");
    QuickSortGeneral(list2);
    printf("quick sorting after sorting\n");
    PrintAllLinkedList(list2);
    printf("\n");
    DestroyLinkedList(list2);
    printf("---------  part 2 quick sorting general finished   -------\n");

    LinkedListPtr list3 = CreateLinkedList();
    randomNumberCount = 0;

    while (randomNumberCount++ < 50)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        printf("This list3 number will always be between 1 and 100: %d\n", randomNumber);
        AppendLinkedList(list3, randomNumber);
    }
    printf("quick sorting medium pivot before sorting\n");
    PrintAllLinkedList(list3);
    printf("\n");
    QuickSortMedianPivot(list3);
    printf("quick sorting medium pivot after sorting\n");
    PrintAllLinkedList(list3);
    printf("\n");
    DestroyLinkedList(list3);
    printf("---------  part 2 quick sorting medium pivot finished   -------\n");

    LinkedListPtr list4 = CreateLinkedList();
    randomNumberCount = 0;

    while (randomNumberCount++ < 50)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        printf("This list4 number will always be between 1 and 100: %d\n", randomNumber);
        AppendLinkedList(list4, randomNumber);
    }
    printf("sort2 before sorting\n");
    PrintAllLinkedList(list4);
    printf("\n");
    Sort2(list4);
    printf("qsort2 after sorting\n");
    PrintAllLinkedList(list4);
    printf("\n");
    DestroyLinkedList(list4);
    printf("---------  part 2 sort2 finished   -------\n");

    //////////////////// compare insetion sort //////////////////////////
    LinkedListPtr comparelist1 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 16)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist1, randomNumber);
    }
    clock_t t_sort_16;
    t_sort_16 = clock();
    Sort(comparelist1);
    t_sort_16 = clock() - t_sort_16;
    double t1 = ((double)t_sort_16) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist1);

    LinkedListPtr comparelist2 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 64)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist2, randomNumber);
    }
    clock_t t_sort;
    t_sort = clock();
    Sort(comparelist2);
    t_sort = clock() - t_sort;
    double t2 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist2);

    LinkedListPtr comparelist3 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 128)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist3, randomNumber);
    }
    t_sort = clock();
    Sort(comparelist3);
    t_sort = clock() - t_sort;
    double t3 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist3);

    LinkedListPtr comparelist4 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 512)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist4, randomNumber);
    }
    t_sort = clock();
    Sort(comparelist4);
    t_sort = clock() - t_sort;
    double t4 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist4);

    LinkedListPtr comparelist5 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 1024)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist5, randomNumber);
    }
    t_sort = clock();
    Sort(comparelist5);
    t_sort = clock() - t_sort;
    double t5 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist5);

    LinkedListPtr comparelist6 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 2048)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist6, randomNumber);
    }
    t_sort = clock();
    Sort(comparelist6);
    t_sort = clock() - t_sort;
    double t6 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist6);

    printf("16       64        128      512      1024      2048\n");
    printf("----------------------------------------------------------\n");
    printf("algo1 selection sort:\n");
    printf("%f %f %f %f %f %f\n", t1, t2, t3, t4, t5, t6);

    //////////////////// compare quick sort general pivot//////////////////////////
    LinkedListPtr comparelist11 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 16)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist11, randomNumber);
    }
    t_sort_16 = clock();
    QuickSortGeneral(comparelist11);
    t_sort_16 = clock() - t_sort_16;
    double t11 = ((double)t_sort_16) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist11);

    LinkedListPtr comparelist12 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 64)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist12, randomNumber);
    }
    t_sort = clock();
    QuickSortGeneral(comparelist12);
    t_sort = clock() - t_sort;
    double t12 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist12);

    LinkedListPtr comparelist13 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 128)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist13, randomNumber);
    }
    t_sort = clock();
    QuickSortGeneral(comparelist13);
    t_sort = clock() - t_sort;
    double t13 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist13);

    LinkedListPtr comparelist14 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 512)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist14, randomNumber);
    }
    t_sort = clock();
    QuickSortGeneral(comparelist14);
    t_sort = clock() - t_sort;
    double t14 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist14);

    LinkedListPtr comparelist15 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 1024)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist15, randomNumber);
    }
    t_sort = clock();
    QuickSortGeneral(comparelist15);
    t_sort = clock() - t_sort;
    double t15 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist15);

    LinkedListPtr comparelist16 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 2048)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist16, randomNumber);
    }
    t_sort = clock();
    QuickSortGeneral(comparelist16);
    t_sort = clock() - t_sort;
    double t16 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist16);

    printf("algo2 quick general pivot sort:\n");
    printf("%f %f %f %f %f %f\n", t11, t12, t13, t14, t15, t16);

    //////////////////// compare quick sort median pivot//////////////////////////
    LinkedListPtr comparelist21 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 16)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist21, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist21);
    t_sort = clock() - t_sort;
    double t21 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist21);

    LinkedListPtr comparelist22 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 64)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist22, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist22);
    t_sort = clock() - t_sort;
    double t22 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist22);

    LinkedListPtr comparelist23 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 128)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist23, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist23);
    t_sort = clock() - t_sort;
    double t23 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist23);

    LinkedListPtr comparelist24 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 512)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist24, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist24);
    t_sort = clock() - t_sort;
    double t24 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist24);

    LinkedListPtr comparelist25 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 1024)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist25, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist25);
    t_sort = clock() - t_sort;
    double t25 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist25);

    LinkedListPtr comparelist26 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 2048)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist26, randomNumber);
    }
    t_sort = clock();
    QuickSortMedianPivot(comparelist26);
    t_sort = clock() - t_sort;
    double t26 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist26);

    printf("algo3 quick median pivot sort:\n");
    printf("%f %f %f %f %f %f\n", t21, t22, t23, t24, t25, t26);

    //////////////////// compare sort2 //////////////////////////
    LinkedListPtr comparelist31 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 16)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist31, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist31);
    t_sort = clock() - t_sort;
    double t31 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist31);

    LinkedListPtr comparelist32 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 64)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist32, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist32);
    t_sort = clock() - t_sort;
    double t32 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist32);

    LinkedListPtr comparelist33 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 128)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist33, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist33);
    t_sort = clock() - t_sort;
    double t33 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist33);

    LinkedListPtr comparelist34 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 512)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist34, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist34);
    t_sort = clock() - t_sort;
    double t34 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist34);

    LinkedListPtr comparelist35 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 1024)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist35, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist35);
    t_sort = clock() - t_sort;
    double t35 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist35);

    LinkedListPtr comparelist36 = CreateLinkedList();
    randomNumberCount = 0;
    while (randomNumberCount++ < 2048)
    {
        int randomNumber = min_val + (rand() % (max_val - min_val));
        AppendLinkedList(comparelist36, randomNumber);
    }
    t_sort = clock();
    Sort2(comparelist36);
    t_sort = clock() - t_sort;
    double t36 = ((double)t_sort) / CLOCKS_PER_SEC;
    DestroyLinkedList(comparelist36);

    printf("algo4 sort2 bubble sort:\n");
    printf("%f %f %f %f %f %f\n", t31, t32, t33, t34, t35, t36);

    printf("---------  compare algorithm completed  -------\n");

    // //////////////// test sort /////////////
    // LinkedListPtr list = CreateLinkedList();
    // AppendLinkedList(list, 10);
    // AppendLinkedList(list, 7);
    // AppendLinkedList(list, 4);
    // AppendLinkedList(list, 11);
    // AppendLinkedList(list, -12);

    // InsertLinkedList(list, 0);
    // InsertLinkedList(list, -1);
    // InsertLinkedList(list, 100);

    // /// the list should be 100, -1, 0, 10 , 7, 4, 11, -12

    // printf("before sorting\n");
    // PrintAllLinkedList(list);
    // printf("\n");
    // Sort(list);
    // printf("after sorting\n");
    // PrintAllLinkedList(list);
    // printf("\n");

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
