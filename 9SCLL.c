#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COMPARE(x, y) ((x == y) ? 0 : (x > y ? 1 : -1))

// Node for storing one polynomial term
typedef struct node {
    int coef;
    int xexp, yexp, zexp;
    struct node *next;
} *NODE;

/* ------------------------ GET NEW NODE ------------------------ */
NODE getnode() {
    NODE n = (NODE)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    return n;
}

/* ------------------------ ATTACH TERM ------------------------- */
NODE attach(int c, int x, int y, int z, NODE head) {
    NODE temp = getnode();
    temp->coef = c;
    temp->xexp = x;
    temp->yexp = y;
    temp->zexp = z;

    NODE cur = head;
    while (cur->next != head)
        cur = cur->next;

    cur->next = temp;
    temp->next = head;

    return head;
}

/* ------------------------ READ POLYNOMIAL ------------------------- */
NODE read_poly(NODE head) {
    int n, coef, x, y, z;

    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nTerm %d:", i);

        printf("\n  Coef: ");
        scanf("%d", &coef);

        printf("  Powers of x y z: ");
        scanf("%d %d %d", &x, &y, &z);

        head = attach(coef, x, y, z, head);
    }
    return head;
}

/* ------------------------ DISPLAY POLYNOMIAL ---------------------- */
void display(NODE head) {
    if (head->next == head) {
        printf("\nPolynomial is empty.\n");
        return;
    }

    NODE cur = head->next;
    while (cur != head) {
        printf("%d x^%d y^%d z^%d", cur->coef, cur->xexp, cur->yexp, cur->zexp);
        cur = cur->next;

        if (cur != head) printf(" + ");
    }
}

/* ------------------------ EVALUATE POLYNOMIAL ---------------------- */
int poly_evaluate(NODE head) {
    int x, y, z, sum = 0;

    printf("\nEnter values of x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);

    NODE cur = head->next;

    while (cur != head) {
        sum += cur->coef *
               pow(x, cur->xexp) *
               pow(y, cur->yexp) *
               pow(z, cur->zexp);

        cur = cur->next;
    }

    return sum;
}

/* ------------------------ ADD TWO POLYNOMIALS ---------------------- */
NODE poly_sum(NODE h1, NODE h2, NODE h3) {
    NODE a = h1->next;
    NODE b = h2->next;

    while (a != h1 && b != h2) {
        if (a->xexp == b->xexp &&
            a->yexp == b->yexp &&
            a->zexp == b->zexp)
        {
            int c = a->coef + b->coef;
            h3 = attach(c, a->xexp, a->yexp, a->zexp, h3);

            a = a->next;
            b = b->next;
        }
        else if (a->xexp > b->xexp ||
                 (a->xexp == b->xexp && a->yexp > b->yexp) ||
                 (a->xexp == b->xexp && a->yexp == b->yexp && a->zexp > b->zexp))
        {
            h3 = attach(a->coef, a->xexp, a->yexp, a->zexp, h3);
            a = a->next;
        }
        else {
            h3 = attach(b->coef, b->xexp, b->yexp, b->zexp, h3);
            b = b->next;
        }
    }

    while (a != h1) {
        h3 = attach(a->coef, a->xexp, a->yexp, a->zexp, h3);
        a = a->next;
    }

    while (b != h2) {
        h3 = attach(b->coef, b->xexp, b->yexp, b->zexp, h3);
        b = b->next;
    }

    return h3;
}

/* --------------------------- MAIN --------------------------- */
int main() {
    NODE head, head1, head2, head3;
    int choice;

    head = getnode();   head->next = head;
    head1 = getnode();  head1->next = head1;
    head2 = getnode();  head2->next = head2;
    head3 = getnode();  head3->next = head3;

    while (1) {
        printf("\n--------- MENU ---------");
        printf("\n1. Represent & Evaluate P(x,y,z)");
        printf("\n2. Add Two Polynomials");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = read_poly(head);

                printf("\nPolynomial:\n");
                display(head);

                printf("\nResult = %d\n", poly_evaluate(head));
                break;

            case 2:
                printf("\nEnter Polynomial 1:");
                head1 = read_poly(head1);

                printf("\nPolynomial 1:\n");
                display(head1);

                printf("\n\nEnter Polynomial 2:");
                head2 = read_poly(head2);

                printf("\nPolynomial 2:\n");
                display(head2);

                head3 = poly_sum(head1, head2, head3);

                printf("\n\nResultant Polynomial:\n");
                display(head3);
                break;

            case 3:
                exit(0);
        }
    }

    return 0;
}
