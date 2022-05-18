#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

typedef struct Tree {
    int* value;
    struct Tree* left;
    struct Tree* right;
    int size;
}Tree;

void printAllValues(Tree* t) {
    if (t == NULL) return;

    printAllValues(t->left);
    printf("value is %d\n", *(t->value));
    printAllValues(t->right);
}

Tree* construct(int i) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    int* v = (int*)malloc(sizeof(int));
    *v = i;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    t->size = 1;
    return t;
}

int preOrder(Tree* t, int i) {
    if (t == NULL) return 0;

    int ret = *(t->value) == i;
    int left = preOrder(t->left, i);
    int right = preOrder(t->right, i);

    return ret || left || right;
}

void add(Tree* t, int i) {
    int* val = (int*)malloc(sizeof(int));
    *val = i;

    if (t->left == NULL && t->right == NULL) {
        Tree* nt = construct(i);
        if (i <= *(t->value)) t->left = nt;
        else t->right = nt;
    }

    else if (i <= *(t->value)) {
        if (t->left == NULL) {
            Tree* nt = construct(i);
            t->left = nt;
        }
        else add(t->left, i);
    }

    else {
        if (t->right == NULL) {
            Tree* nt = construct(i);
            t->right = nt;
        }
        else add(t->right, i);
    }
    t->size++;
}

bool isBST(Tree* t, int min, int max) {
    if (t == NULL) return true;
    int val = *(t->value);
    if (val <= min || val >= max) return false;
    return isBST(t->left, min, val) && isBST(t->right, val, max);
}

bool isValidBST(Tree* t) {
    return isBST(t, INT16_MIN, INT16_MAX);
}

void sizeOfTree(Tree* t) {
    printf("size is %d\n", t->size);
}

int main() {
    Tree* t1 = construct(1);

    add(t1, 2);
    add(t1, 3);
    add(t1, 0);
    add(t1, -1);
    add(t1, -2);
    add(t1, -3);

    printAllValues(t1);
    sizeOfTree(t1);

    if (isValidBST(t1)) printf("It is a valid BST.\n");
    else printf("It is not a valid BST.\n");

    return 0;
}

