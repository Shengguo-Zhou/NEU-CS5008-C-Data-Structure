// Simple hash table implemented in C.


#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "ht.h"
#include "ll.h"

// Hash table entry (slot may be filled or empty).
typedef struct {
    char* key;  // key is NULL if this slot is empty
    LinkedListPtr value;
} ht_entry;

// Hash table structure: create with ht_create, free with ht_destroy.
struct ht {
    ht_entry* entries;  // hash slots
    size_t capacity;    // size of _entries array
    // size_t length;      // number of items in hash table
};

#define INITIAL_CAPACITY 200  // must not be zero

ht* ht_create(void) {
    // Allocate space for hash table struct.
    ht* table = malloc(sizeof(ht));
    if (table == NULL) {
        return NULL;
    }
    // table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    // Allocate (zero'd) space for entry buckets.
    // table->entries = calloc(INITIAL_CAPACITY, sizeof(ht_entry));
    
    LinkedListPtr link[INITIAL_CAPACITY];
    for(int q = 0; q < INITIAL_CAPACITY; q++) {
        link[q] = malloc(sizeof(ht_entry));
        // link[q] = NULL;
    }
    // table->entries = &link;
    // if (table->entries == NULL) {
    //     free(table); // error, free table before we return!
    //     return NULL;
    // }
    return table;
}

void ht_destroy(ht* table) {
    // First free allocated keys.
    for (size_t i = 0; i < table->capacity; i++) {
        if (table->entries[i].key != NULL) {
            free((void*)table->entries[i].key);
        }
    }

    // Then free entries array and table itself.
    free(table->entries);
    free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
uint64_t hash_key(char* key) {
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

void* ht_get(ht* table, int index) {
    // AND hash with capacity-1 to ensure it's within entries array.
    // uint64_t hash = hash_key(key);
    // size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));


    if (table->entries[index].key != NULL) {
        printf("key is %s, and elements are: ", table->entries[index].key);
        PrintAllLinkedList(link[index].value);
    }

    return NULL;
}

ht* ht_set(ht* table, char* key, char* cvalue) {
    // AND hash with capacity-1 to ensure it's within entries array.
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

    // printf("index is %zu\n", index);
    // char* real_value;
    // strcpy(real_value, cvalue);
    // 
    if (table->entries[index].value != NULL) {
        // strcpy(real_value, cvalue);
        
        // printf("123");
        // return NULL;
    }
    else {
        // table->entries[index] = (ht_entry)malloc(sizeof(ht_entry));
        table->entries[index].key = malloc(sizeof(key));
        strcpy(table->entries[index].key, key);
        // table->entries[index] = *(void)malloc(sizeof(ht_entry));
        table->entries[index].value = CreateLinkedList();
        // char *realvalue;
        // strcpy(real_value, cvalue);
        // table->entries[index].value = AppendLinkedList(table->entries[index].value, cvalue);
        // printf("append is %s", cvalue);
        // printf("this table index now");
        // PrintAllLinkedList(table->entries[index].value);
    }

    table->entries[index].value = AppendLinkedList(table->entries[index].value, cvalue);
    return table;
}

// Internal function to set an entry (without expanding table).
// char* ht_set_entry(ht_entry* entries, size_t capacity,
//         const char* key, char *string, size_t* plength) {
//     // AND hash with capacity-1 to ensure it's within entries array.
//     uint64_t hash = hash_key(key);
//     size_t index = (size_t)(hash & (uint64_t)(capacity - 1));

//     // Loop till we find an empty entry.
//     while (entries[index].key != NULL) {
//         if (strcmp(key, entries[index].key) == 0) {
//             // Found key (it already exists), update value.
//             AppendLinkedList(entries[index].value, string) ;
//             return entries[index].key;
//         }
//         // Key wasn't in this slot, move to next (linear probing).
//         index++;
//         if (index >= capacity) {
//             // At end of entries array, wrap around.
//             index = 0;
//         }
//     }

//     // Didn't find key, allocate+copy if needed, then insert it.
//     if (plength != NULL) {
//         key = strdup(key);
//         if (key == NULL) {
//             return NULL;
//         }
//         (*plength)++;
//     }
//     entries[index].key = (char*)key;
//     entries[index].value = CreateLinkedList();
//     AppendLinkedList(entries[index].value, string) ;
//     return key;
// }

// Expand hash table to twice its current size. Return true on success,
// false if out of memory.
// static bool ht_expand(ht* table) {
//     // Allocate new entries array.
//     size_t new_capacity = table->capacity * 2;
//     if (new_capacity < table->capacity) {
//         return false;  // overflow (capacity would be too big)
//     }
//     ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));
//     if (new_entries == NULL) {
//         return false;
//     }

//     // Iterate entries, move all non-empty ones to new table's entries.
//     for (size_t i = 0; i < table->capacity; i++) {
//         ht_entry entry = table->entries[i];
//         if (entry.key != NULL) {
//             LinkedListNodePtr temp = entry.value->head;
//             while(temp->next->next != NULL){
//                 ht_set_entry(new_entries, new_capacity, entry.key,
//                          temp->data, NULL);
//                 temp = temp->next;
//             }

//         }
//     }

//     // Free old entries array and update this table's details.
//     free(table->entries);
//     table->entries = new_entries;
//     table->capacity = new_capacity;
//     return true;
// }

// const char* ht_set(ht* table, const char* key, char* value) {
//     assert(value != NULL);
//     if (value == NULL) {
//         return NULL;
//     }

//     // If length will exceed half of current capacity, expand it.
//     if (table->length >= table->capacity * 3 / 4) {
//         if (!ht_expand(table)) {
//             return NULL;
//         }
//     }

//     // Set entry and update length.
//     return ht_set_entry(table->entries, table->capacity, key, value,
//                         &table->length);
// }

size_t ht_length(ht* table) {
    return table->capacity;
}

// hti ht_iterator(ht* table) {
//     hti it;
//     it._table = table;
//     it._index = 0;
//     return it;
// }

// bool ht_next(hti* it) {
//     // Loop till we've hit end of entries array.
//     ht* table = it->_table;
//     while (it->_index < table->capacity) {
//         size_t i = it->_index;
//         it->_index++;
//         if (table->entries[i].key != NULL) {
//             // Found next non-empty item, update iterator key and value.
//             ht_entry entry = table->entries[i];
//             it->key = entry.key;
//             it->value = entry.value;
//             return true;
//         }
//     }
//     return false;
// }
