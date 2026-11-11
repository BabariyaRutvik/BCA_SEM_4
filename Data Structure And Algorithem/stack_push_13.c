/*
13. To implement a stack using an array and perform push operations.

Explanation:
- A stack follows LIFO (Last-In, First-Out).
- Using an array of fixed size MAX and index top initialized to -1:
  - Push checks for Stack Overflow (top == MAX - 1).
  - Otherwise increments top and stores the value at stack[top].
*/
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto stack.\n", value);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, i, val;

    printf("How many elements to push (MAX = %d)? ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        push(val);
    }

    display();
    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
How many elements to push (MAX = 5)? Enter value 1: Pushed 10 onto stack.
Enter value 2: Pushed 20 onto stack.
Enter value 3: Pushed 30 onto stack.
Enter value 4: Pushed 40 onto stack.
Stack elements (top to bottom): 40 30 20 10
*/
