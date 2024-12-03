#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    char usn[20];
    char name[50];
    char program[50];
    int sem;
    char phone[15];
    struct Student *next;
};

struct Student *head = NULL;

void createSLL(int n) {
    struct Student *newStudent;
    for (int i = 0; i < n; i++) {
        newStudent = (struct Student *)malloc(sizeof(struct Student));
        
        printf("\nEnter details for student %d:\n", i+1);
        printf("USN: ");
        scanf("%s", newStudent->usn);
        printf("Name: ");
        scanf(" %[^\n]", newStudent->name);  // Reads the full line with spaces
        printf("Program: ");
        scanf(" %[^\n]", newStudent->program);
        printf("Semester: ");
        scanf("%d", &newStudent->sem);
        printf("Phone Number: ");
        scanf("%s", newStudent->phone);

        newStudent->next = head;  // Insert at the front
        head = newStudent;
    }
}

void displaySLL() {
    struct Student *temp = head;
    int count = 0;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("\nStudent Data in SLL:\n");
    while (temp != NULL) {
        printf("USN: %s\n", temp->usn);
        printf("Name: %s\n", temp->name);
        printf("Program: %s\n", temp->program);
        printf("Semester: %d\n", temp->sem);
        printf("Phone: %s\n\n", temp->phone);
        temp = temp->next;
        count++;
    }
    printf("Total number of students: %d\n", count);
}

void insertEnd() {
    struct Student *newStudent, *temp;
    newStudent = (struct Student *)malloc(sizeof(struct Student));

    printf("\nEnter details for new student at the end:\n");
    printf("USN: ");
    scanf("%s", newStudent->usn);
    printf("Name: ");
    scanf(" %[^\n]", newStudent->name);
    printf("Program: ");
    scanf(" %[^\n]", newStudent->program);
    printf("Semester: ");
    scanf("%d", &newStudent->sem);
    printf("Phone Number: ");
    scanf("%s", newStudent->phone);

    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}

void deleteEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Student *temp = head;
    struct Student *prev = NULL;

    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    free(temp);
    prev->next = NULL;
}

void insertFront() {
    struct Student *newStudent;
    newStudent = (struct Student *)malloc(sizeof(struct Student));

    printf("\nEnter details for new student at the front:\n");
    printf("USN: ");
    scanf("%s", newStudent->usn);
    printf("Name: ");
    scanf(" %[^\n]", newStudent->name);
    printf("Program: ");
    scanf(" %[^\n]", newStudent->program);
    printf("Semester: ");
    scanf("%d", &newStudent->sem);
    printf("Phone Number: ");
    scanf("%s", newStudent->phone);

    newStudent->next = head;
    head = newStudent;
}

void deleteFront() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Student *temp = head;
    head = head->next;
    free(temp);
}

int main() {
    int choice, n;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create SLL of n students (Front Insertion)\n");
        printf("2. Display SLL and count the number of nodes\n");
        printf("3. Insert at the End\n");
        printf("4. Delete from the End\n");
        printf("5. Insert at the Front\n");
        printf("6. Delete from the Front\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of students: ");
                scanf("%d", &n);
                createSLL(n);
                break;
            case 2:
                displaySLL();
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
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
