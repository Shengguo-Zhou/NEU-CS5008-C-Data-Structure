#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hashtable_final.h"

struct elt {
    struct elt* next;
    char* key;
    char* value;
};

struct hashtable {
    int size;           /* size of the pointer table */
    int n;              /* number of elements stored */
    struct elt** table;
};

#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)

/* HashTable initialization code used in both HashTableCreate and grow */
HashTable internalHashTableCreate(int size) {
    HashTable d;
    int i;

    d = malloc(sizeof(*d));

    assert(d != 0);

    d->size = size;
    d->n = 0;
    d->table = malloc(sizeof(struct elt*) * d->size);

    assert(d->table != 0);

    for (i = 0; i < d->size; i++) d->table[i] = 0;

    return d;
}

HashTable HashTableCreate(void) {
    return internalHashTableCreate(INITIAL_SIZE);
}

void HashTableDestroy(HashTable d) {
    int i;
    struct elt* e;
    struct elt* next;

    for (i = 0; i < d->size; i++) {
        for (e = d->table[i]; e != 0; e = next) {
            next = e->next;

            free(e->key);
            free(e->value);
            free(e);
        }
    }

    free(d->table);
    free(d);
}

#define FNV_PRIME_64 ((1ULL<<40)+(1<<8)+0xb3)
#define FNV_OFFSET_BASIS_64 (14695981039346656037ULL)

uint64_t hash_function(const char* bytes) {
    uint64_t h = FNV_OFFSET_BASIS_64;
    size_t i;
    for (i = 0; bytes[i] != '\0'; i++) {
        h = h ^ bytes[i];
        h *= FNV_PRIME_64;
    }

    return h;
}

static void grow(HashTable d) {
    HashTable d2;            /* new dictionary we'll create */
    struct hashtable swap;   /* temporary structure for brain transplant */
    int i;
    struct elt* e;

    d2 = internalHashTableCreate(d->size * GROWTH_FACTOR);

    for (i = 0; i < d->size; i++) {
        for (e = d->table[i]; e != 0; e = e->next) {
            /* note: this recopies everything */
            /* a more efficient implementation would
             * patch out the strdups inside DictInsert
             * to avoid this problem */
            HashTableInsert(d2, e->key, e->value);
        }
    }

    /* the hideous part */
    /* We'll swap the guts of d and d2 */
    /* then call DictDestroy on d2 */
    swap = *d;
    *d = *d2;
    *d2 = swap;

    HashTableDestroy(d2);
}

/* insert a new key-value pair into an existing dictionary */
void HashTableInsert(HashTable d, const char* key, const char* value) {
    struct elt* e;
    unsigned long h;

    assert(key);
    assert(value);

    e = malloc(sizeof(*e));

    assert(e);

    e->key = strdup(key);
    e->value = strdup(value);

    h = hash_function(key) % d->size;

    e->next = d->table[h];
    d->table[h] = e;

    d->n++;

    /* grow table if there is not enough room */
    if (d->n >= d->size * MAX_LOAD_FACTOR) {
        grow(d);
    }
}

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
const char* HashTableSearch(HashTable d, const char* key) {
    struct elt* e;

    for (e = d->table[hash_function(key) % d->size]; e != 0; e = e->next) {
        if (!strcmp(e->key, key)) {
            /* got it */
            return e->value;
        }
    }

    return 0;
}

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void HashTableDelete(HashTable d, const char* key) {
    struct elt** prev;          /* what to change when elt is deleted */
    struct elt* e;              /* what to delete */

    for (prev = &(d->table[hash_function(key) % d->size]);
        *prev != 0;
        prev = &((*prev)->next)) {
        if (!strcmp((*prev)->key, key)) {
            /* got it */
            e = *prev;
            *prev = e->next;

            free(e->key);
            free(e->value);
            free(e);

            return;
        }
    }
}