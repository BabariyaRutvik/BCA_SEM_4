/*
45. To implement a stack using an array and perform the peep (peek) and change operations.

Explanation:
- Standard stack uses top (0-based index) and MAX capacity.
- Peep(pos) returns the element at 1-based position 'pos' from the top
  (index = top - pos + 1). When pos = 1, it acts as Peek (top element).
- Change(pos, newVal) replaces the element at 'pos' from the top with newVal.
*/
#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = val;
        printf("Pushed %d.\n", val);
    }
}

void peep(int pos) {
    int idx = top - pos + 1;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else if (pos < 1 || idx < 0) {
        printf("Position %d out of range.\n", pos);
    } else {
        printf("Element at position %d from top is %d.\n", pos, stack[idx]);
    }
}

void change(int pos, int newVal) {
    int idx = top - pos + 1;
    if (top == -1) {
        printf("Stack is empty.\n");
    } else if (pos < 1 || idx < 0) {
        printf("Position %d out of range.\n", pos);
    } else {
        printf("Changed element at position %d from %d to %d.\n", pos, stack[idx], newVal);
        stack[idx] = newVal;
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            printf("Enter position from top (1 for top/peek): ");
            scanf("%d", &pos);
            peep(pos);
        } else if (choice == 3) {
            printf("Enter position from top and new value: ");
            scanf("%d %d", &pos, &val);
            change(pos, val);
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

/*
Sample Input:
1
10
1
20
1
30
2
2
3
2 99
4
5

Sample Output:

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Enter value: Pushed 10.

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Enter value: Pushed 20.

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Enter value: Pushed 30.

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Enter position from top (1 for top/peek): Element at position 2 from top is 20.

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Enter position from top and new value: Changed element at position 2 from 20 to 99.

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice: Stack (top to bottom): 30 99 10 

1. Push  2. Peep (Peek)  3. Change  4. Display  5. Exit
Choice:
*/
