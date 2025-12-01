#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student node
typedef struct Node {
    char usn[20];
    char name[20];
    char course[20];
    int sem;
    long int phone;
    struct Node *next;
} *NODE;

NODE head = NULL;   // Global head pointer

/* -------------------------------------------------------
   Allocate memory for a new student node
------------------------------------------------------- */
NODE createNode() {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    return newNode;
}

/* -------------------------------------------------------
   Insert at the FRONT of the list
------------------------------------------------------- */
NODE insertAtFront(NODE head) {
    NODE newNode = createNode();

    printf("Enter USN, Name, Course, Semester, Phone Number:\n");
    scanf("%s %s %s %d %ld",
          newNode->usn, newNode->name, newNode->course,
          &newNode->sem, &newNode->phone);

    newNode->next = head;
    return newNode;       // new head
}

/* -------------------------------------------------------
   Insert at the END of the list  (FOR LOOP used)
------------------------------------------------------- */
NODE insertAtEnd(NODE head) {
    NODE newNode = createNode();

    printf("Enter USN, Name, Course, Semester, Phone Number:\n");
    scanf("%s %s %s %d %ld",
          newNode->usn, newNode->name, newNode->course,
          &newNode->sem, &newNode->phone);

    newNode->next = NULL;

    if (head == NULL)     // If list empty
        return newNode;

    NODE temp;
    for (temp = head; temp->next != NULL; temp = temp->next);

    temp->next = newNode;
    return head;
}

/* -------------------------------------------------------
   Delete from FRONT
------------------------------------------------------- */
NODE deleteFromFront(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    NODE temp = head;
    printf("Deleted: %s %s %s %d %ld\n",
           temp->usn, temp->name, temp->course, temp->sem, temp->phone);

    head = head->next;
    free(temp);

    return head;
}

/* -------------------------------------------------------
   Delete from END (FOR LOOP used)
------------------------------------------------------- */
NODE deleteFromEnd(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) { // Only one node
        printf("Deleted: %s %s %s %d %ld\n",
               head->usn, head->name, head->course, head->sem, head->phone);
        free(head);
        return NULL;
    }

    NODE temp, prev = NULL;

    for (temp = head; temp->next != NULL; temp = temp->next)
        prev = temp;

    printf("Deleted: %s %s %s %d %ld\n",
           temp->usn, temp->name, temp->course, temp->sem, temp->phone);

    free(temp);
    prev->next = NULL;
    return head;
}

/* -------------------------------------------------------
   Display List (FOR LOOP used)
------------------------------------------------------- */
void displayList(NODE head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-10s %-10s %-10s %-5s %-12s\n",
           "USN", "Name", "Course", "Sem", "Phone");
    printf("-------------------------------------------------------------\n");

    int count = 0;
    NODE temp;

    for (temp = head; temp != NULL; temp = temp->next) {
        printf("%-10s %-10s %-10s %-5d %-12ld\n",
               temp->usn, temp->name, temp->course, temp->sem, temp->phone);
        count++;
    }

    printf("-------------------------------------------------------------\n");
    printf("Total Students: %d\n", count);
}

/* -------------------------------------------------------
   Create list using FRONT insertion (FOR LOOP)
------------------------------------------------------- */
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

/* -------------------------------------------------------
   MAIN MENU
------------------------------------------------------- */
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
