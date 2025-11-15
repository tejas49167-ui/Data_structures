#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure representing a student node
typedef struct Node {
    char usn[20]    ;
    char name[20]   ;
    char course[20] ;
    int sem;
    long int phone;
    struct Node *next;
}* NODE;

NODE head = NULL;  //Pointer to the first node (head of list)

// Function to allocate memory for a new node
NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    return newNode;
}

// Function to insert a new node at the front
NODE insertAtFront(NODE head) {
    NODE newNode = createNode();
    printf("Enter USN, Name, Course, Semester, Phone Number:\n");
    scanf("%s %s %s %d %ld", newNode->usn, newNode->name, newNode->course, &newNode->sem, &newNode->phone);
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert a new node at the end
NODE insertAtEnd(NODE head) {
    NODE newNode = createNode();
    printf("Enter USN, Name, Course, Semester, Phone Number:\n");
    scanf("%s %s %s %d %ld", newNode->usn, newNode->name, newNode->course, &newNode->sem, &newNode->phone);
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    NODE temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete a node from the front
NODE deleteFromFront(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    NODE temp = head;
    printf("Deleted: %s %s %s %d %ld\n", temp->usn, temp->name, temp->course, temp->sem, temp->phone);
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
NODE deleteFromEnd(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    if (head->next == NULL) {
        printf("Deleted: %s %s %s %d %ld\n", head->usn, head->name, head->course, head->sem, head->phone);
        free(head);
        return NULL;
    }
    NODE temp = head, prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Deleted: %s %s %s %d %ld\n", temp->usn, temp->name, temp->course, temp->sem, temp->phone);
    free(temp);
    prev->next = NULL;
    return head;
}

// Function to display all nodes
void displayList(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("\n%s %s %s %s %s\n", "USN", "Name", "Course", "Sem", "Phone");
    printf("-------------------------------------------------------------\n");
    NODE temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("%s %s %s %d %ld\n", temp->usn, temp->name, temp->course, temp->sem, temp->phone);
        temp = temp->next;
        count++;
    }
    printf("-------------------------------------------------------------\n");
    printf("Total Students: %d\n", count);
}

// Function to create a list using front insertion
NODE createList(NODE head) {
    int n;
    printf("Enter number of students to add: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        head = insertAtFront(head);
    }
    return head;
}

// Main function (menu-driven)
int main() {
    int choice;
    while (1) {
        printf("\n========== STUDENT MANAGEMENT MENU ==========\n");
        printf("1. Create List (Front Insertion)\n");
        printf("2. Display All Students\n");
        printf("3. Insert Student at End\n");
        printf("4. Delete Student from End\n");
        printf("5. Insert Student at Front (Push)\n");
        printf("6. Delete Student from Front (Pop)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head = createList(head); break;
            case 2: displayList(head); break;
            case 3: head = insertAtEnd(head); break;
            case 4: head = deleteFromEnd(head); break;
            case 5: head = insertAtFront(head); break;
            case 6: head = deleteFromFront(head); break;
            case 7: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
