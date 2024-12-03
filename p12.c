#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Size of the hash table, you can adjust as needed

// Employee record structure
struct Employee {
    int key;            // Unique 4-digit key
    char name[50];      // Name of the employee
    char dept[50];      // Department
    double salary;      // Salary of the employee
};

// Hash table to store employees
struct Employee hashTable[TABLE_SIZE];

// Function to initialize the hash table
void initTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].key = -1;  // Indicating empty slot
    }
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to insert an employee record using linear probing for collision resolution
void insertEmployee(int key, char *name, char *dept, double salary) {
    int index = hash(key);
    
    // Linear probing to find the next available slot
    while (hashTable[index].key != -1) {
        index = (index + 1) % TABLE_SIZE;  // Move to the next index (wrap around if needed)
    }

    // Insert employee record into the hash table
    hashTable[index].key = key;
    strcpy(hashTable[index].name, name);
    strcpy(hashTable[index].dept, dept);
    hashTable[index].salary = salary;
}

// Function to search for an employee by key
struct Employee* searchEmployee(int key) {
    int index = hash(key);
    int startIndex = index;

    // Linear probing to search the employee
    while (hashTable[index].key != -1) {
        if (hashTable[index].key == key) {
            return &hashTable[index];  // Employee found
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break;  // If we've looped back to the start, stop
    }
    return NULL;  // Employee not found
}

// Function to display all employee records
void displayEmployees() {
    printf("\nEmployee Records:\n");
    printf("Key\tName\tDepartment\tSalary\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].key != -1) {
            printf("%d\t%s\t%s\t%.2f\n", hashTable[i].key, hashTable[i].name, hashTable[i].dept, hashTable[i].salary);
        }
    }
}

int main() {
    initTable();  // Initialize the hash table

    // Sample employee records
    insertEmployee(1234, "Alice", "HR", 50000);
    insertEmployee(5678, "Bob", "IT", 60000);
    insertEmployee(9101, "Charlie", "Finance", 70000);
    insertEmployee(1122, "David", "Marketing", 45000);
    insertEmployee(2233, "Eva", "Sales", 55000);
    
    // Display the records in the hash table
    displayEmployees();

    // Search for an employee by key
    int searchKey = 1234;
    struct Employee* emp = searchEmployee(searchKey);
    if (emp != NULL) {
        printf("\nEmployee with key %d found: %s, Department: %s, Salary: %.2f\n", emp->key, emp->name, emp->dept, emp->salary);
    } else {
        printf("\nEmployee with key %d not found.\n", searchKey);
    }

    return 0;
}
