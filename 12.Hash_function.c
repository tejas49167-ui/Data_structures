#include <stdio.h>
#include <stdlib.h>

int *hashTable;
int size;          // m
int recordCount = 0;

// Insert key into hash table using linear probing
void insertKey(int key) {
    int index = key % size;

    // Find next empty slot
    while (hashTable[index] != -1) {
        index = (index + 1) % size;
    }

    hashTable[index] = key;
    recordCount++;
}

// Display the hash table
void displayTable() {
    if (recordCount == 0) {
        printf("\nHash Table is empty\n");
        return;
    }

    printf("\nHash Table contents:\n");
    for (int i = 0; i < size; i++) {
        printf("T[%d] --> %d\n", i, hashTable[i]);
    }
}

int main() {
    int n;

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter the number of hash table slots (m): ");
    scanf("%d", &size);

    // Allocate memory for hash table
    hashTable = (int *)malloc(size * sizeof(int));

    // Initialize all slots as empty
    for (int i = 0; i < size; i++)
        hashTable[i] = -1;

    int key;
    printf("\nEnter %d employee key values (4-digit):\n", n);

    for (int i = 0; i < n; i++) {

        if (recordCount == size) {
            printf("\nHash table FULL. Cannot insert key %d.\n", i + 1);
            break;
        }

        scanf("%d", &key);
        insertKey(key);
    }

    displayTable();

    return 0;
}
