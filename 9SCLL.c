#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COMPARE(x, y) ((x == y) ? 0 : (x > y ? 1 : -1))

typedef struct node {
    int coef;
    int xexp, yexp, zexp;
    struct node *next;
} *NODE;

/* -------------------------------------- */
NODE getnode() {
    NODE n = (NODE)malloc(sizeof(struct node));
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(0);
    }
    return n;
}

/* -------------------------------------- */
NODE attach(int c, int x, int y, int z, NODE head) {
    NODE temp = getnode();
    temp->coef = c;
    temp->xexp = x;
    temp->yexp = y;
    temp->zexp = z;

    NODE cur;
    for (cur = head; cur->next != head; cur = cur->next);

    cur->next = temp;
    temp->next = head;

    return head;
}

/* -------------------------------------- */
NODE read_poly(NODE head) {
    int n, c, x, y, z;

    printf("\nEnter number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("\nTerm %d:", i);

        printf("\n  Coef: ");
        scanf("%d", &c);

        printf("  Powers of x y z: ");
        scanf("%d %d %d", &x, &y, &z);

        head = attach(c, x, y, z, head);
    }

    return head;
}

/* -------------------------------------- */
void display(NODE head) {
    if (head->next == head) {
        printf("\nPolynomial is empty.");
        return;
    }

    NODE cur;
    for (cur = head->next; cur != head; cur = cur->next) {
        printf("%d x^%d y^%d z^%d",
               cur->coef, cur->xexp, cur->yexp, cur->zexp);

        if (cur->next != head) printf(" + ");
    }
}

/* -------------------------------------- */
int poly_evaluate(NODE head) {
    int x, y, z, result = 0;

    printf("\nEnter x y z values: ");
    scanf("%d %d %d", &x, &y, &z);

    NODE cur;
    for (cur = head->next; cur != head; cur = cur->next) {
        result += cur->coef *
                  pow(x, cur->xexp) *
                  pow(y, cur->yexp) *
                  pow(z, cur->zexp);
    }

    return result;
}

/* -------------------------------------- */
NODE poly_sum(NODE h1, NODE h2, NODE h3) {
    NODE a = h1->next;
    NODE b = h2->next;

    while (1) {
        if (a == h1 || b == h2) break;

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

    for (; a != h1; a = a->next)
        h3 = attach(a->coef, a->xexp, a->yexp, a->zexp, h3);

    for (; b != h2; b = b->next)
        h3 = attach(b->coef, b->xexp, b->yexp, b->zexp, h3);

    return h3;
}

/* -------------------------------------- */
int main() {
    NODE head  = getnode(); head->next  = head;
    NODE head1 = getnode(); head1->next = head1;
    NODE head2 = getnode(); head2->next = head2;
    NODE head3 = getnode(); head3->next = head3;

    int ch;

    while (1) {
        printf("\n------ MENU ------");
        printf("\n1. Evaluate Polynomial");
        printf("\n2. Add Two Polynomials");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                head = read_poly(head);
                printf("\nPolynomial: ");
                display(head);
                printf("\nResult = %d\n", poly_evaluate(head));
                break;

            case 2:
                printf("\nEnter POLY1:");
                head1 = read_poly(head1);

                printf("\nEnter POLY2:");
                head2 = read_poly(head2);

                head3 = poly_sum(head1, head2, head3);

                printf("\nSum = ");
                display(head3);
                break;

            case 3:
                exit(0);
        }
    }
}
