#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct BinaryTree{
    Node* root;
    int size;
}BinaryTree;

typedef struct Q_Node{
    Node* data;
    struct Q_Node* next;
}Q_Node;

typedef struct Queue{
    Q_Node* head;
    int size;
}Queue;

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    return n;
}

Q_Node* createQNode(Node* node) {
    Q_Node* q = (Q_Node*)malloc(sizeof(Q_Node));
    q->data = node;
    return q;
}

Q_Node* findLast(Q_Node* q) {
    Q_Node* temp = q;
    while(temp->next != NULL) temp = temp->next;
    return temp;
}

void append(Q_Node* q, Node* n) {
    Q_Node* last = findLast(q);
    last->next = createQNode(n);
}

void enqueue(Queue* q, Node* n) {
    if(n == NULL) return;

    if(q->head == NULL) {
        q->head = createQNode(n);
    } else {
        append(q->head, n);
    }
    
    q->size = q->size + 1;
}

Q_Node* removeFirst(Q_Node* q) {
    Q_Node* next = q->next;

    return next;
}

Node* dequeue(Queue* q) {
    Q_Node* head = q->head;
    Node* node = head->data;
    q->head = removeFirst(head);
    q->size = q->size - 1;
    free(head);
    return node;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = 0;
    return q;
}

bool algo(BinaryTree* tree, int data) {
    Queue* q = createQueue();
    enqueue(q, tree->root);
    
    bool result = false;

    while(q->size > 0){
        Node* n = dequeue(q);
        if(n->data == data) {
            result = true;
            break;
        }
        enqueue(q, n->left);
        enqueue(q, n->right);
    }
    
    free(q);
    return result;
}

void freeNodes(Node* n) {
    if(n == NULL) {
        return;
    }
    freeNodes(n->left);
    freeNodes(n->right);
    free(n);
}

void freeTree(BinaryTree* t) {
    freeNodes(t->root);
    free(t);
}

int main() {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    Node* n1 = createNode(1);
    Node* n2 = createNode(20);
    Node* n3 = createNode(4);

    n1->left = n2;
    n1->right = n3;
    tree->root = n1;
    tree->size = 3;

    bool result = algo(tree, 29);
    printf("result: %d\n", result);
    freeTree(tree);
    return 1;
}


