#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "ht.h"
// #include "ht.c"
// #include "ll.h"
// #include "ll.c"

#include <stdio.h>
#include <assert.h>
#include "hashtable_final.h"
#include "hashtable_final.c"

char* sort(char* s) {
    char* string = s;
    int i, j;
    char temp;
    int n = strlen(string);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (string[i] > string[j]) {
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    return string;
}

int main() {

    HashTable d;
    // char buf[512];
    // int i;

    d = HashTableCreate();

    // HashTableInsert(d, "foo", "hello world");
    // puts(HashTableSearch(d, "foo"));

    // HashTableInsert(d, "foo", "hello world2");
    // puts(HashTableSearch(d, "foo"));

    // HashTableDelete(d, "foo");
    // puts(HashTableSearch(d, "foo"));

    // HashTableDelete(d, "foo");
    // assert(HashTableSearch(d, "foo") == 0);

    // HashTableDelete(d, "foo");

    // for (i = 0; i < 10000; i++) {
    //     sprintf(buf, "%d", i);
    //     HashTableInsert(d, buf, buf);
    // }

#define SIZE 128

    FILE* ptr;

    char ch[SIZE];
    char ch_o[SIZE];
    char* ch_order;

    ptr = fopen("words.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    while (fgets(ch, SIZE, ptr) != NULL) {

        strcpy(ch_o, ch); // value
        ch_order = sort(ch); // key

        if (HashTableSearch(d, ch_order) != 0)
            printf("The %s string's anagram is %s\n", ch_o, HashTableSearch(d, ch_order));
        else 
            printf("The original string is %s\n", ch_o);
        
        HashTableInsert(d, ch_order, ch_o);
    }

    fclose(ptr);

    HashTableDestroy(d);

    return 0;
}



// #define FNV_OFFSET 14695981039346656037UL
// #define FNV_PRIME 1099511628211UL

// // Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// // https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
// uint64_t hash_key(char* key) {
//     uint64_t hash = FNV_OFFSET;
//     for (const char* p = key; *p; p++) {
//         hash ^= (uint64_t)(unsigned char)(*p);
//         hash *= FNV_PRIME;
//     }
//     return hash;
// }

// #define SIZE 1024

// int main(void) {

//     // ht* counts = ht_create();
//     // printf("%zu", counts->capacity);
//     // if (counts == NULL) {
//     //     exit_nomem();
//     // }
//     uint64_t hash = hash_key(key);
//     size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

//     FILE* ptr;

//     char ch[SIZE];
//     char ch_o[SIZE];
//     char* ch_order;

//     ptr = fopen("testword.txt", "r");

//     if (NULL == ptr) {
//         printf("file can't be opened \n");
//     }

//     // printf("content of this file are \n");

//     // fgets(ch, SIZE, ptr);

//     LinkedListPtr link[INITIAL_CAPACITY];
//     for(int q = 0; q < INITIAL_CAPACITY; q++) {
//         link[q] = malloc(sizeof(ht_entry));
//         link[q] = NULL;
//     }

//     while (fgets(ch, SIZE, ptr) != NULL) {


//         strcpy(ch_o, ch);
//         ch_order = sort(ch);
//         index = 
//         // get the index
//         if(same index ){
//             append the 
//         }
//         counts = ht_set(counts, ch_order, ch_o);


//         // printf("char original is %s, %s\n", ch_o, ch_order);
//         // fgets(ch, SIZE, ptr);

//         // printf("%zu\n", counts->capacity);
//         // uint64_t hash = hash_key(ch);
//         // size_t index = (size_t)(hash & (uint64_t)(counts->capacity - 1));

//         // if (counts->entries[index].value != NULL) {
//         //     // Already exists, increment int that value points to.
//         //     // int* pcount = (int*)value;
//         //     // (*pcount)++;
//         //     // continue;
//         //     counts->entries[index].value = CreateLinkedList();
//         // }
//         // AppendLinkedList(counts->entries[index].value, ch);

//         // Word not found, allocate space for new int and set to 1.
//         // char* pcount = malloc(sizeof(char));
//         // if (pcount == NULL) {
//         //     exit_nomem();
//         // }
//         // *pcount = '1';
//         // if (ht_set(counts, ch, pcount) == NULL) {
//         //     exit_nomem();
//         // }
//     }

//     fclose(ptr);

//     // Print out words and frequencies, freeing values as we go.
//     // hti it = ht_iterator(counts);
//     // while (ht_next(&it)) {
//     //     printf("%s ", it.key);
//     //     // free(it.value);
//     //     ht_get(it._table, it.value);
//     // }

//     // // Show the number of unique words.
//     // printf("%d\n", (int)ht_length(counts));
//     printf("capacity is %zu\n", counts->capacity);

//     int l;
//     for (l = 0; l < counts->capacity - 1; l++) {
//         if (counts->entries[l].key != NULL) {
//             ht_get(counts, l);
//             // printf("inside \n");
//             // PrintAllLinkedList(counts->entries[l].value);
//         }
//     }


//     // ht_get(counts, counts->entries[197].key);
//     // ht_destroy(counts);
//     return 0;
// }
