#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int s[MAX];
int top = -1;

// Function prototypes
void push(int item);
int pop();
void palindrome();
void display();

void main()
{
    int choice, item;

    while (1)
    {
        printf("\n\n-----------Menu-------------");
        printf("\n1. Push an Element to Stack and Overflow demo");
        printf("\n2. Pop an Element from Stack and Underflow demo");
        printf("\n3. Palindrome demo");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter an element to be pushed: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            item = pop();
            if (item != -1)
                printf("\nElement popped is: %d", item);
            break;

        case 3:
            palindrome();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("\nPlease enter a valid choice");
        }
    }
}

// Push operation
void push(int item)
{
    if (top == MAX - 1)
    {
        printf("\n-----------Stack overflow-----------");
        return;
    }
    top +=1;
    s[top] = item;
    printf("\nElement %d pushed into stack", item);
}

// Pop operation
int pop()
{
    if (top == -1)
    {
        printf("\n-----------Stack underflow----------");
        return -1;
    }
    return s[top--];
}

// Display stack
void display()
{
    if (top == -1)
    {
        printf("\n-----------Stack is empty-----------");
        return;
    }
    printf("\nStack elements are:\n");
    for (int i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);
}

// Palindrome check
void palindrome()
{
    if (top == -1)
    {
        printf("\nStack is empty. Cannot check palindrome.");
        return;
    }

    int flag = 1;
    printf("\nStack content are:\n");
    for (int i = top; i >= 0; i--)
        printf("| %d |\n", s[i]);

    printf("\nReverse of stack content are:\n");
    for (int i = 0; i <= top; i++)
        printf("| %d |\n", s[i]);

    for (int i = 0; i <= top / 2; i++)
    {
        if (s[i] != s[top - i])
        {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("\nIt is a palindrome number");
    else
        printf("\nIt is not a palindrome number");
}
