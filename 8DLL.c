#include <stdio.h>
#include <stdlib.h>

struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink, *rlink;
};

typedef struct node* NODE;

NODE first = NULL;
int count = 0;

/* ----------------------------------------------------
   Create a new employee node
---------------------------------------------------- */
NODE create() {
    NODE temp = (NODE)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("\nMemory allocation failed!");
        exit(0);
    }

    printf("\nEnter SSN, Name, Department, Designation, Salary, Phone:\n");
    scanf("%s %s %s %s %d %ld",
          temp->ssn, temp->name, temp->dept, temp->designation,
          &temp->sal, &temp->phone);

    temp->llink = temp->rlink = NULL;
    count++;

    return temp;
}

/* ----------------------------------------------------
   Insert at front
---------------------------------------------------- */
NODE insertFront() {
    NODE newNode = create();

    if (first == NULL)
        return newNode;

    newNode->rlink = first;
    first->llink = newNode;

    return newNode;
}

/* ----------------------------------------------------
   Insert at end (Uses for-loop instead of while)
---------------------------------------------------- */
NODE insertEnd() {
    NODE newNode = create();

    if (first == NULL)
        return newNode;

    NODE cur;
    for (cur = first; cur->rlink != NULL; cur = cur->rlink);

    cur->rlink = newNode;
    newNode->llink = cur;

    return first;
}

/* ----------------------------------------------------
   Delete from front
---------------------------------------------------- */
NODE deleteFront() {
    if (first == NULL) {
        printf("\nList is empty!");
        return NULL;
    }

    if (first->rlink == NULL) {
        printf("\nDeleted: %s", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    NODE temp = first;
    first = first->rlink;
    first->llink = NULL;

    printf("\nDeleted: %s", temp->ssn);
    free(temp);
    count--;

    return first;
}

/* ----------------------------------------------------
   Delete from end (Uses for-loop)
---------------------------------------------------- */
NODE deleteEnd() {
    if (first == NULL) {
        printf("\nList is empty!");
        return NULL;
    }

    if (first->rlink == NULL) {
        printf("\nDeleted: %s", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    NODE cur, prev = NULL;
    for (cur = first; cur->rlink != NULL; cur = cur->rlink)
        prev = cur;

    printf("\nDeleted: %s", cur->ssn);
    free(cur);
    prev->rlink = NULL;
    count--;

    return first;
}

/* ----------------------------------------------------
   Display List (Uses for-loop)
---------------------------------------------------- */
void display() {
    if (first == NULL) {
        printf("\nList is empty!");
        return;
    }

    int nodeNo = 1;
    NODE cur;

    for (cur = first; cur != NULL; cur = cur->rlink) {
        printf("\nNode %d | SSN: %s | Name: %s | Dept: %s | Desg: %s | Salary: %d | Phone: %ld",
               nodeNo, cur->ssn, cur->name, cur->dept,
               cur->designation, cur->sal, cur->phone);
        nodeNo++;
    }

    printf("\nTotal Nodes: %d", count);
}

/* ----------------------------------------------------
   DEQueue operations using DLL
---------------------------------------------------- */
void deqDemo() {
    int ch;
    while (1) {
        printf("\n\n------ DEQueue Menu ------");
        printf("\n1. Insert Front");
        printf("\n2. Delete Front");
        printf("\n3. Insert Rear");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit DEQueue");
        printf("\nEnter choice: ");

        scanf("%d", &ch);

        switch (ch) {
            case 1: first = insertFront(); break;
            case 2: first = deleteFront(); break;
            case 3: first = insertEnd(); break;
            case 4: first = deleteEnd(); break;
            case 5: display(); break;
            default: return;
        }
    }
}

/* ----------------------------------------------------
   MAIN MENU
---------------------------------------------------- */
int main() {
    int ch, n;

    while (1) {
        printf("\n\n--------- MAIN MENU ---------");
        printf("\n1. Create DLL");
        printf("\n2. Display List");
        printf("\n3. Insert at End");
        printf("\n4. Delete at End");
        printf("\n5. Insert at Front");
        printf("\n6. Delete at Front");
        printf("\n7. DEQueue Demo");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nHow many employees? ");
                scanf("%d", &n);

                for (int i = 0; i < n; i++)
                    first = insertEnd();
                break;

            case 2: display(); break;
            case 3: first = insertEnd(); break;
            case 4: first = deleteEnd(); break; 
            case 5: first = insertFront(); break;
            case 6: first = deleteFront(); break;
            case 7: deqDemo(); break;

            case 8: exit(0);

            default: printf("\nInvalid Choice!");
        }
    }

    return 0;
}
