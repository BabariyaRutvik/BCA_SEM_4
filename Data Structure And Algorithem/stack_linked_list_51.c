/*
51. To implement a stack using a singly linked list and perform push and pop operations.

Explanation:
- The head of the singly linked list acts as the 'top' of the stack so both push
  and pop run in O(1) time without shifting elements or fixed capacity limits.
- Push: insert new node at head (newNode->next = top; top = newNode).
- Pop: remove node at head (temp = top; top = top->next; free(temp)).
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto linked stack.\n", val);
}

void pop() {
    struct Node *temp;
    if (top == NULL) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Push  2. Pop  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
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
3
2
3
4

Sample Output:

1. Push  2. Pop  3. Display  4. Exit
Choice: Enter value: Pushed 10 onto linked stack.

1. Push  2. Pop  3. Display  4. Exit
Choice: Enter value: Pushed 20 onto linked stack.

1. Push  2. Pop  3. Display  4. Exit
Choice: Enter value: Pushed 30 onto linked stack.

1. Push  2. Pop  3. Display  4. Exit
Choice: Stack (top to bottom): 30 -> 20 -> 10 -> NULL

1. Push  2. Pop  3. Display  4. Exit
Choice: Popped element: 30

1. Push  2. Pop  3. Display  4. Exit
Choice: Stack (top to bottom): 20 -> 10 -> NULL

1. Push  2. Pop  3. Display  4. Exit
Choice:
*/
