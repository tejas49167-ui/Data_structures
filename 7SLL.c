#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char usn[20], name[20], course[20];
    int sem;
    long int phno;
    struct node *next;
};
typedef struct node *NODE;

NODE first = NULL;

// Function to create a new node
NODE getnode() {
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    return x;
}

// Function to insert at front
NODE insert_front(NODE first) {
    NODE temp;
    temp = getnode();
    printf("Enter USN, Name, Course, Sem, Phone number:\n");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->course, &temp->sem, &temp->phno);
    temp->next = first;
    first = temp;
    return first;
}

// Function to insert at end
NODE insert_end(NODE first) {
    NODE temp, cur;
    temp = getnode();
    printf("Enter USN, Name, Course, Sem, Phone number:\n");
    scanf("%s %s %s %d %ld", temp->usn, temp->name, temp->course, &temp->sem, &temp->phno);
    temp->next = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->next != NULL)
        cur = cur->next;
    cur->next = temp;
    return first;
}

// Function to delete at front
NODE delete_front(NODE first) {
    NODE temp;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    temp = first;
    printf("Deleted record: %s %s %s %d %ld\n", temp->usn, temp->name, temp->course, temp->sem, temp->phno);
    first = first->next;
    free(temp);
    return first;
}

// Function to delete at end
NODE delete_end(NODE first) {
    NODE cur, prev;
    if (first == NULL) {
        printf("List is empty\n");
        return first;
    }
    if (first->next == NULL) {
        printf("Deleted record: %s %s %s %d %ld\n", first->usn, first->name, first->course, first->sem, first->phno);
        free(first);
        return NULL;
    }
    cur = first;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted record: %s %s %s %d %ld\n", cur->usn, cur->name, cur->course, cur->sem, cur->phno);
    free(cur);
    prev->next = NULL;
    return first;
}

// Function to display list
void display(NODE first) {
    NODE temp;
    int count = 0;
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("\nStudent Details are:\n");
    printf("USN\tName\tCourse\tSem\tPhone\n");
    printf("---------------------------------------------\n");
    temp = first;
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%d\t%ld\n", temp->usn, temp->name, temp->course, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("---------------------------------------------\n");
    printf("Total number of students = %d\n", count);
}

// Function to create list with N students (front insertion)
NODE create(NODE first) {
    int n, i;
    printf("Enter number of students:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter details of student %d\n", i + 1);
        first = insert_front(first);
    }
    return first;
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create SLL using front insertion\n");
        printf("2. Display and count nodes\n");
        printf("3. Insert at end\n");
        printf("4. Delete at end\n");
        printf("5. Insert at front (Stack Push)\n");
        printf("6. Delete at front (Stack Pop)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: first = create(first); break;
            case 2: display(first); break;
            case 3: first = insert_end(first); break;
            case 4: first = delete_end(first); break;
            case 5: first = insert_front(first); break;
            case 6: first = delete_front(first); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
