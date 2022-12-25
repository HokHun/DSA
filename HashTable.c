#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
// Bảng băm(HashTable)
typedef struct {
  char* key;
  int value;
} Entry;
typedef struct {
  Entry* entries;
} HashTable;
//  Hash function that maps a string to an integer between 0 and TABLE_SIZE-1
int hash(char* key) {
  int sum = 0;
  for (int i = 0; i < strlen(key); i++) {
   sum += key[i];
  }
  return sum % TABLE_SIZE;
}
//  Initialize a new hash table
void init(HashTable* ht) {
  ht->entries = malloc(TABLE_SIZE * sizeof(Entry));
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->entries[i].key = NULL;
    ht->entries[i].value = 0;
  }
}
// Insert a new key/value pair into the hash table
void put(HashTable* ht, char* key, int value) {
  int index = hash(key);
  ht->entries[index].key = key;
  ht->entries[index].value = value;
}
//  Retrieve the value for a given key from the hash table
int get(HashTable* ht, char* key) {
  int index = hash(key);
  return ht->entries[index].value;
}
//  cách 1
int main() {
  HashTable ht;
  init(&ht);
  int n;
  printf("Nhap so luong phan tu: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
        char* key = malloc(sizeof(char) * 100);
        int value;
        printf("Nhap key va gia tri: \n");
        scanf("%s\t%d", key, &value);
        put(&ht, key, value);
   }
  char* key;
  printf("Nhap key muon tim: ");
  scanf("%s", key);
  int value = get(&ht, key);
  printf("Gia tri cua key '%s' la: %d\n", key, value);
  return 0;
}
// cách 2
// int main() {
//   HashTable ht;
//   init(&ht);
//   put(&ht, "apple", 5);
//   put(&ht, "banana", 3);
//   put(&ht, "cherry", 7);
//   printf("apple: %d\n", get(&ht, "apple"));
//   printf("banana: %d\n", get(&ht, "banana"));
//   printf("cherry: %d\n", get(&ht, "cherry"));
//   return 0;
// }