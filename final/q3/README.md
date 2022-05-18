Question 3

===========

Problem Statement: Identify the algorithm 

============

Using what you know about specific data structures and their related algorithms, identify the algorithm in the code. In
your own words, describe what this algorithm does and how it's different to other variations. If you're not able to
identify the algorithm, describe the algorithm you're most familiar with from this class.
============

Rubric:
Identified: 8
Description: 12
Comparison with similar algorithms: 5
Total: 25

====================================================================================

MY ANSWER

Search a certain data in a tree level by level, by using a queue.

This whole mystery.c implements two main data structure, ---- tree and queue.

And in the main function, the function traverse the tree level by level. Fistly, the function put the same level's root of the tree in a queue. And it pops the node from the queue one by one, and if it is the same with the data which we want to find, the function stops and return true. And if we don't find the data, we continue the loop. This function checks whether the node's left and right child is empty, if they are not empty, this funcion put it into the queue. And the left child nodes and the right child nodes are belong to the next level. This loop will end until either we find the data or all the node is traversed. At last, if we get the data, we return true, otherwise we return false.

And it is a little bit different with BST, BST - Binary Search Tree is a node-based binary tree data structure which has the following properties:
1. The left subtree of a node contains only nodes with keys lesser than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. The left and right subtree each must also be a binary search tree.