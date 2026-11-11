/*
52. To implement a queue using a singly linked list and perform enqueue and dequeue operations.

Explanation:
- Maintains two pointers: front (first node) and rear (last node).
- Enqueue inserts a new node after rear (or sets both front and rear if empty) in O(1).
- Dequeue removes the node at front and advances front = front->next in O(1).
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d into linked queue.\n", val);
}

void dequeue() {
    struct Node *temp;
    if (front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    printf("Dequeued element: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue (front to rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
        } else if (choice == 2) {
            dequeue();
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

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Enter value: Enqueued 10 into linked queue.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Enter value: Enqueued 20 into linked queue.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Enter value: Enqueued 30 into linked queue.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Queue (front to rear): 10 -> 20 -> 30 -> NULL

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Dequeued element: 10

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice: Queue (front to rear): 20 -> 30 -> NULL

1. Enqueue  2. Dequeue  3. Display  4. Exit
Choice:
*/
