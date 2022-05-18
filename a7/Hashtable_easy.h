// /*
//  *  This is free software: you can redistribute it and/or modify
//  *  it under the terms of the GNU General Public License as published by
//  *  the Free Software Foundation, either version 3 of the License, or
//  *  (at your option) any later version.
//  *
//  *  It is distributed in the hope that it will be useful,
//  *  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  *  GNU General Public License for more details.
//  *
//  *  See <http://www.gnu.org/licenses/>.
//  */

// #include <stdint.h>

// #include "LinkedList.h"


// #ifndef HASHTABLE_H
// #define HASHTABLE_H


// // struct hashtableInfo {
// // 	int num_buckets;
// // 	int num_elements;
// // 	LinkedList* buckets;
// // };

// // typedef struct hashtableInfo* Hashtable;


// // // Hashtables store key/value pairs.  We'll define a key to be an
// // // unsigned 64-bit integer; it's up to the customer to figure out how
// // // to produce an appropriate hash key, but below we provide an
// // // implementation of FNV hashing to help them out.  We'll define
// // // a value to be a (void *), so that customers can pass in pointers to
// // // arbitrary structs as values, but of course we have to worry about
// // // memory management as a side-effect.
// // typedef struct {
// //   uint64_t   key;    // the key in the key/value pair
// //   char      *value;  // the value in the key/value pair
// // } HTKeyValue, *HTKeyValuePtr;

// // typedef struct {
// //     const char* key;  // key is NULL if this slot is empty
// //     void* value;
// // } ht_entry;

// // // Hash table structure: create with ht_create, free with ht_destroy.
// // struct ht {
// //     ht_entry* entries;  // hash slots
// //     int capacity;    // size of _entries array
// //     int length;      // number of items in hash table
// // };

// // typedef struct ht ht;

// // Allocates and returns a new Hashtable.
// //
// // INPUT:
// //   numBuckets: The number of buckets this hashtable will start with.
// //
// // Returns NULL if the hashtable was unable to be malloc'd, or
// // the hashtable.
// // Hashtable CreateHashtable(int num_buckets);
// // ht* CreateHashtable(int capacity);

// // Destroys and Frees the hashtable.
// //
// // Input:
// //   ht: the table to be free'd. It is unsafe to use the
// //    hashtable after this is called.
// // void DestroyHashtable(Hashtable ht);

// // Puts the given key value pair int the hashtable.
// //
// // INPUT:
// //   ht: the hashtable to insert into
// //   kvp: the key-value pair to put into the hashtable.
// //   old_kvp: if there is a collision, sets the old_kvp to point at the previous value. 
// //
// // Returns 0 if put is successful.
// // Returns 1 on failure (e.g., no more memory)
// // Returns 2 if the key is already in the hashtable
// // int PutInHashtable(Hashtable ht, HTKeyValue kvp, HTKeyValue *old_kvp);

// // Looks up the given key in the hashtable.
// // Returns the Key-Value pair in the provided result pointer.
// //
// // INPUT: 
// //   ht: the hashtable to lookup in
// //   key: the key to lookup
// //   result: If the key is in the hashtable, this is used
// //      to return a pointer to a HTKeyValue to the caller.
// //      Note, this HTKeyValue is still in the hashtable, so can't
// //      be used to free the value.
// //
// // Returns 0 if the lookup was successful (and the result is valid).
// // Returns -1 if the key was not found.
// // int LookupInHashtable(Hashtable ht, uint64_t key, HTKeyValue *result);

// // Replaces the value of a given key in the hashtable.
// //
// // INPUT:
// //   ht: Hashtable to replace value
// //   key: key of item to be replaced
// //   new_val: new item to put in HT
// //   old_val: the HTKeyValue that was removed from the hashtable,
// //      which allows the caller to free it as necessary.
// //
// // Returns 0 if successful (and oldVal is valid)
// // Returns -1 if the key was not found in the hashtable (and oldval is invalic)
// // int ReplaceInHashtable(Hashtable ht, HTKeyValue new_val, HTKeyValue *old_val);

// // Gets the number of elements in the hashtable.
// //
// // INPUT:
// //   ht: the Hashtable
// //
// // Returns the number of elements in the hashtable.
// // int NumElemsInHashtable(Hashtable ht);

// // Removes the HTKeyValue with the given key from the
// //  hashtable.
// //
// // INPUT:
// //   ht: the hashtable
// //   key: the key to remove
// //   junkKVP: a pointer to the removed HTKeyValue, to
// //     allow the value to be freed by the caller.
// //
// // Returns 0 if the key was found successfully (and junkKVP is valid)
// // Returns -1 if the key was not found in the hashtable.
// // int RemoveFromHashtable(Hashtable ht, uint64_t key, HTKeyValue *junk_kvp);

// // Computes an int from a string, to be used for a key in a HTKeyValue.
// //
// // INPUT:
// //   buffer: a pointer to the array holding the string
// //   len: the length of the string
// //
// // Returns an int to be used as an input to FNVHashInt64 for the hash value.
// // uint64_t FNVHash64(unsigned char *buffer, unsigned int len);

// // Creates a hashed value from a given key.
// //
// // INPUT:
// //   makehash: an int to be hashed for the key of a HTKeyValue pair
// //
// // Returns the int to be used as a key.
// // uint64_t FNVHashInt64(uint64_t makehash);

// #include <stdbool.h>
// #include <stddef.h>

// // Hash table structure: create with ht_create, free with ht_destroy.
// typedef struct ht ht;

// // Create hash table and return pointer to it, or NULL if out of memory.
// ht* ht_create();

// // Free memory allocated for hash table, including allocated keys.
// void ht_destroy(ht* table);

// // Get item with given key (NUL-terminated) from hash table. Return
// // value (which was set with ht_set), or NULL if key not found.
// void* ht_get(ht* table, const char* key);

// // Set item with given key (NUL-terminated) to value (which must not
// // be NULL). If not already present in table, key is copied to newly
// // allocated memory (keys are freed automatically when ht_destroy is
// // called). Return address of copied key, or NULL if out of memory.
// const char* ht_set(ht* table, const char* key, void* value);

// // Return number of items in hash table.
// size_t ht_length(ht* table);

// // Hash table iterator: create with ht_iterator, iterate with ht_next.
// typedef struct {
//     const char* key;  // current key
//     void* value;      // current value

//     // Don't use these fields directly.
//     ht* _table;       // reference to hash table being iterated
//     size_t _index;    // current index into ht._entries
// } hti;

// // Return new hash table iterator (for use with ht_next).
// hti ht_iterator(ht* table);

// // Move iterator to next item in hash table, update iterator's key
// // and value to current item, and return true. If there are no more
// // items, return false. Don't call ht_set during iteration.
// bool ht_next(hti* it);


// #endif  // HASHTABLE_H

