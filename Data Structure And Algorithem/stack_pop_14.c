/*
14. To implement a stack using an array and perform pop operations.

Explanation:
- Pop removes and returns the topmost element from the stack.
- Before popping, check for Stack Underflow (top == -1).
- Otherwise print/return stack[top] and decrement top by 1.
*/
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        stack[++top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top--;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Remaining Stack (top to bottom): ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, i, val, pops;

    printf("Enter number of elements to initialize stack (1 to %d): ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        push(val);
    }

    printf("How many pop operations to perform? ");
    scanf("%d", &pops);

    for (i = 0; i < pops; i++) {
        pop();
    }

    display();
    return 0;
}

/*
Sample Input:
4
10 20 30 40
2

Sample Output:
Enter number of elements to initialize stack (1 to 5): Enter element 1: Enter element 2: Enter element 3: Enter element 4: How many pop operations to perform? Popped element: 40
Popped element: 30
Remaining Stack (top to bottom): 20 10
*/
