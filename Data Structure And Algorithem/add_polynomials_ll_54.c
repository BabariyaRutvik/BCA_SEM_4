/*
54. To implement a program to add two polynomials using linked lists.

Explanation:
- Each node stores a term: coefficient, exponent, and next pointer, ordered
  from highest exponent to lowest.
- Two pointers p1 and p2 traverse both polynomials simultaneously:
  - If p1->exp == p2->exp, add coefficients and append if non-zero.
  - If p1->exp > p2->exp, copy p1's term; else copy p2's term.
  - Append any remaining terms from either list.
*/
#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term *next;
};

struct Term *insertTerm(struct Term *head, int coeff, int exp) {
    struct Term *newNode = (struct Term *)malloc(sizeof(struct Term));
    struct Term *temp;
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Term *addPolynomials(struct Term *p1, struct Term *p2) {
    struct Term *result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp == p2->exp) {
            int sum = p1->coeff + p2->coeff;
            if (sum != 0) {
                result = insertTerm(result, sum, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }
    return result;
}

void displayPoly(struct Term *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next != NULL) {
            printf(" + ");
        }
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct Term *poly1 = NULL, *poly2 = NULL, *sum = NULL;
    int n1, n2, i, c, e;

    printf("Enter number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter terms (coeff exp) in descending order of exponent:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d %d", &c, &e);
        poly1 = insertTerm(poly1, c, e);
    }

    printf("Enter number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter terms (coeff exp) in descending order of exponent:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d %d", &c, &e);
        poly2 = insertTerm(poly2, c, e);
    }

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    sum = addPolynomials(poly1, poly2);
    printf("Sum         : ");
    displayPoly(sum);

    return 0;
}

/*
Sample Input:
3
5 2
4 1
2 0
2
3 1
5 0

Sample Output:
Enter number of terms in Polynomial 1: Enter terms (coeff exp) in descending order of exponent:
Enter number of terms in Polynomial 2: Enter terms (coeff exp) in descending order of exponent:
Polynomial 1: 5x^2 + 4x^1 + 2x^0
Polynomial 2: 3x^1 + 5x^0
Sum         : 5x^2 + 7x^1 + 7x^0
*/
