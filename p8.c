#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char ssn[20];
    char name[50];
    char dept[50];
    char designation[50];
    float salary;
    char phone[15];
    struct Employee *prev, *next;
};

struct Employee *head = NULL;

void createDLL(int n) {
    struct Employee *newEmployee, *temp;
    
    for (int i = 0; i < n; i++) {
        newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
        
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("SSN: ");
        scanf("%s", newEmployee->ssn);
        printf("Name: ");
        scanf(" %[^\n]", newEmployee->name);  // Reads full name with spaces
        printf("Department: ");
        scanf(" %[^\n]", newEmployee->dept);
        printf("Designation: ");
        scanf(" %[^\n]", newEmployee->designation);
        printf("Salary: ");
        scanf("%f", &newEmployee->salary);
        printf("Phone Number: ");
        scanf("%s", newEmployee->phone);
        
        newEmployee->next = NULL;
        newEmployee->prev = NULL;
        
        if (head == NULL) {
            head = newEmployee;  // If the DLL is empty, make this the head.
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;  // Traverse to the end of the DLL.
            }
            temp->next = newEmployee;  // Insert the new employee at the end.
            newEmployee->prev = temp;  // Set the prev pointer of new node to last node.
        }
    }
}

void displayDLL() {
    struct Employee *temp = head;
    int count = 0;
    
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nEmployee Data in DLL:\n");
    while (temp != NULL) {
        printf("SSN: %s\n", temp->ssn);
        printf("Name: %s\n", temp->name);
        printf("Department: %s\n", temp->dept);
        printf("Designation: %s\n", temp->designation);
        printf("Salary: %.2f\n", temp->salary);
        printf("Phone: %s\n\n", temp->phone);
        temp = temp->next;
        count++;
    }
    printf("Total number of employees: %d\n", count);
}

void insertEnd() {
    struct Employee *newEmployee, *temp;
    
    newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    printf("\nEnter details for new employee at the end:\n");
    printf("SSN: ");
    scanf("%s", newEmployee->ssn);
    printf("Name: ");
    scanf(" %[^\n]", newEmployee->name);
    printf("Department: ");
    scanf(" %[^\n]", newEmployee->dept);
    printf("Designation: ");
    scanf(" %[^\n]", newEmployee->designation);
    printf("Salary: ");
    scanf("%f", &newEmployee->salary);
    printf("Phone Number: ");
    scanf("%s", newEmployee->phone);

    newEmployee->next = NULL;

    if (head == NULL) {
        head = newEmployee;
        newEmployee->prev = NULL;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->prev = temp;
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Employee *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;  // The list has only one element.
    }
    
    free(temp);
}

void insertFront() {
    struct Employee *newEmployee;
    
    newEmployee = (struct Employee *)malloc(sizeof(struct Employee));
    printf("\nEnter details for new employee at the front:\n");
    printf("SSN: ");
    scanf("%s", newEmployee->ssn);
    printf("Name: ");
    scanf(" %[^\n]", newEmployee->name);
    printf("Department: ");
    scanf(" %[^\n]", newEmployee->dept);
    printf("Designation: ");
    scanf(" %[^\n]", newEmployee->designation);
    printf("Salary: ");
    scanf("%f", &newEmployee->salary);
    printf("Phone Number: ");
    scanf("%s", newEmployee->phone);

    newEmployee->prev = NULL;
    newEmployee->next = head;

    if (head != NULL) {
        head->prev = newEmployee;
    }
    head = newEmployee;
}

void deleteFront() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Employee *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}

void demonstrateQueue() {
    int choice;

    while (1) {
        printf("\nQueue Operations on DLL:\n");
        printf("1. Insert at the Front (Enqueue Front)\n");
        printf("2. Insert at the End (Enqueue End)\n");
        printf("3. Delete from the Front (Dequeue Front)\n");
        printf("4. Delete from the End (Dequeue End)\n");
        printf("5. Exit Queue Operations\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                return;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    int choice, n;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create DLL of n employees (End Insertion)\n");
        printf("2. Display DLL and count the number of nodes\n");
        printf("3. Insert at the End\n");
        printf("4. Delete from the End\n");
        printf("5. Insert at the Front\n");
        printf("6. Delete from the Front\n");
        printf("7. Demonstrate how DLL can be used as Double Ended Queue\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of employees: ");
                scanf("%d", &n);
                createDLL(n);
                break;
            case 2:
                displayDLL();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                demonstrateQueue();
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
