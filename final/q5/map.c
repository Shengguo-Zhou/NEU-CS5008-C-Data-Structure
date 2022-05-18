#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

const int SIZE = 26;
const char LETTERS[] = "abcdefghijklmnopqrstuvwxyz";
const char LETTERS_UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef struct Pair {
    char* key;
    int* value;
}Pair;

typedef struct Node {
    Pair* pair;
    struct Node* next;
}Node;

typedef struct Map {
    Node** data;
    int size;
}Map;


int hash(const char* key) {
    char c = key[0];
    return 0;
}

Map* createMap(char* key, int* value, int size) {


    Node* n = (Node*)malloc(sizeof(Node));
    Pair* p = (Pair*)malloc(sizeof(Pair));
    p->key = key;
    p->value = value;
    n->pair = p;
    n->next = NULL;
    Map* m = (Map*)malloc(sizeof(Map));
    Node** d = (Node**)malloc(sizeof(Node*) * size);
    int index = hash(key);
    d[index] = n;

    m->data = d;
    m->size = 1;
    printf("%d\n", *(m->data[0]->pair->value));
    return m;
}

int getIndex(char c) {
    int i = 0;
    while (i < 26 && c != LETTERS[i] || c != LETTERS_UPPER[i]) {
        i++;
    }

    return i;
}



Node* get(Map* map, const char* key) {
    int index = hash(key);

    Node* temp = (Node*)malloc(sizeof(Node));
    temp = map->data[index];
    while (temp != NULL) {
        Pair* pair = temp->pair;
        const char* k = pair->key;
        printf("key is %s\n", pair->key);

        if (strcmp(key, k) == 0) {
            break;
        }

        temp = temp->next;
    }
    printf("temp is %s\n", temp->pair->key);
    return temp;
}

void put(Map* map, char* key, int* value) {
    //Implement logic here
        // 1. create the key - value pair

    int index = hash(key);

    Pair* thisPair = (Pair*)malloc(sizeof(Pair));
    Node* thisNode = (Node*)malloc(sizeof(Node));

    thisPair->key = key;
    thisPair->value = value;
    thisNode->pair = thisPair;
    thisNode->next = NULL;

    Node* pairNodePosition = (Node*)malloc(sizeof(Node));
    pairNodePosition = map->data[index];
    printf("this value is %d\n", *pairNodePosition->pair->value);

    if (pairNodePosition->pair != NULL) { // key exits
        Node* firstNode = map->data[index];

        while (firstNode->next != NULL) {
            firstNode = firstNode->next;
        }
        // printf("here is ok\n");
        firstNode->next = thisNode;
    }
    else map->data[index] = thisNode; // insert directly
}

int isEmpty(Map* map) {
    return map->size == 0;
}

int main() {
    srand(time(NULL));

    printf("starting list operation\n");
    printf("size of pair is %lu\n", sizeof(Pair));
    char* k1 = (char*)malloc(sizeof(char));
    k1 = "alpha";

    int* v1 = (int*)malloc(sizeof(int));
    *v1 = 10;

    char* k2 = (char*)malloc(sizeof(char));
    k2 = "beta";

    int* v2 = (int*)malloc(sizeof(int));
    *v2 = 20;


    Map* m = createMap(k1, v1, SIZE);
    printf("the value in m is : %d\n", *(m->data[0]->pair->value));


    Node** data = m->data;
    Node* n1 = data[0];
    Pair* p1 = n1->pair;
    printf("p1 the value is %d\n", *p1->value);

    put(m, k2, v2);

    Node* n2 = get(m, k2);
    Pair* p2 = n2->pair;
    printf("p2 the value is %d\n", *p2->value);

    Node* gNode = get(m, k1);
    Pair* gPair = gNode->pair;

    printf("testing get %d\n", *(gPair->value));
    return 0;
}
