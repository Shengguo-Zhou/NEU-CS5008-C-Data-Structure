typedef struct hashtable *HashTable;

/* create a new empty HashTable */
HashTable HashTableCreate(void);

/* destroy a HashTable */
void HashTableDestroy(HashTable);

/* insert a new key-value pair into an existing HashTable */
void HashTableInsert(HashTable, const char *key, const char *value);

/* return the most recently inserted value associated with a key */
/* or 0 if no matching key is present */
const char *HashTableSearch(HashTable, const char *key);

/* delete the most recently inserted record with the given key */
/* if there is no such record, has no effect */
void HashTableDelete(HashTable, const char *key);