/*
18. To implement a Circular queue using an array and perform dequeue operations.

Explanation:
- Dequeue from a Circular Queue checks Underflow (front == -1).
- If front == rear (only one element), reset front = -1 and rear = -1.
- Otherwise advance front = (front + 1) % MAX.
*/
#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = value;
}

void dequeue() {
    if (front == -1) {
        printf("Circular Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("Dequeued element: %d\n", cqueue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Remaining Circular Queue: ");
    i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, i, val, deqs;

    printf("Enter number of elements to initialize queue (1 to %d): ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &val);
        enqueue(val);
    }

    printf("How many dequeue operations to perform? ");
    scanf("%d", &deqs);

    for (i = 0; i < deqs; i++) {
        dequeue();
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
Enter number of elements to initialize queue (1 to 5): Enter element 1: Enter element 2: Enter element 3: Enter element 4: How many dequeue operations to perform? Dequeued element: 10
Dequeued element: 20
Remaining Circular Queue: 30 40
*/
