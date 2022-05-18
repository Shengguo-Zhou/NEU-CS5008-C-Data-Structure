#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DEQUE_H
#define DEQUE_H

typedef struct ll_noded {
  int           data;       // Data this node holds 
  struct ll_noded *next;     // next node in list, or NULL
  struct ll_noded *prev;     // prev node in list, or NULL
} LinkedListNoded, *LinkedListNodePtrd;

// This struct represents the entire linked list.  We provided a struct
// declaration (but not definition) in LinkedList.h; this is the associated
// definition.  This struct contains metadata about the linked list.
typedef struct ll_headd {
  int          num_elements;  //  # elements in the list
  LinkedListNodePtrd head;  // head of linked list, or NULL if empty
  LinkedListNodePtrd tail;  // tail of linked list, or NULL if empty
} *LinkedListPtrd;


// ======================================================
// LinkedList: A Doubly-Linked List 
// ======================================================

// Creates a LinkedList.
// The customer is responsible for calling DestroyLinkedList()
// to destroy the LinkedList when done.
//
// Returns a LinkedList; NULL if there's an error. 
LinkedListPtrd CreateLinkedListd();

// Destroys a LinkedList.
// All structs associated with a LinkedList will be
// released and freed.
//
// INPUT: A pointer to a LinkedList.
void DestroyLinkedListd(LinkedListPtrd list);


// Returns the number of elements in the linked list. 
// 
// INPUT: A LinkedList 
// 
// Returns the number of elements in the list. 
int NumElementsInLinkedListd(LinkedListPtrd list); 

// Adds an element to the head of a LinkedList, with the given value
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int InsertLinkedListd(LinkedListPtrd, int);


// Adds an element to the tail of a LinkedList, with the given value.
//
// INPUT: A pointer to the LinkedList that will be added to,
// INPUT: A value for a node in the linkedList.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
int AppendLinkedListd(LinkedListPtrd, int);

// Prints out the given LinkedListPtr. 
//
// INPUT: A pointer to the LinkedList that will be printed out.
//
// Returns 0 if the insertion was successful; non-zero for failure. 
void PrintLinkedListd(LinkedListPtrd);

// Creates a LinkedListNode by malloc'ing the space.
//
// INPUT: A pointer that the payload of the returned LLNode will point to.
//
// Returns a pointer to the new LinkedListNode.
LinkedListNoded* CreateLinkedListNoded(int data);

// Destroys and free's a provided LLNode.
//
// INPUT: A pointer to the node to destroy.
//
// Returns 0 if the destroy was successful.
int DestroyLinkedListNoded(LinkedListNoded *node);

// Removes a given element from a linkedList.
//
// INPUT: A pointer to a linked list.
// INPUT: A ListNodePtr that points to a LLNode to be removed from the list.
//
// Returns 0 if the destroy was successful
//   (primarily that the provide Ptr is in the list and could be free'd).
int RemoveLLElemd(LinkedListPtrd list, LinkedListNodePtrd ptr);

// queue

void pushLeft(LinkedListPtrd, int);
void popLeft(LinkedListPtrd);
int peekLeft(LinkedListPtrd);
void pushRight(LinkedListPtrd, int);
void popRight(LinkedListPtrd);
int peekRight(LinkedListPtrd);

#endif
