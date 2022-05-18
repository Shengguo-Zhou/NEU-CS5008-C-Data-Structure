Question 4

===========

Problem Statement: Problem solve with familiar concepts on an unfamiliar data type

============

We briefly discussed heaps this semester, but did not go into depth. For this problem, you don't need to necessarily
know what a heap is, you only need to worry about a specific piece of logic. The task for this problem is to implement
logic which determines if a given heap is valid, or not.

The heap property: For every tree in the heap, it's children must either be greater than (if a min heap) or smaller than
(if a max heap) than itself. For example, consider the heap: [1,2,3,4,5]. The tree representation of this heap is:

          1
         / \
        2   3
       / \
      4   5

This IS a valid min heap, but an invalid max heap.

The function to get the left child for given node is 2i+1 and 2i+2 for the right, where i is the index of the current
node.

Using the above information, complete the function `isValidMaxHeap`.

============

Rubric:
Code compiles: 3
Code correct: 3
Leaks plugged: 3
Code style and structure for any helpers: 3 
Readability: 5
isValidMaxHeap implemented: 8

Total: 25
