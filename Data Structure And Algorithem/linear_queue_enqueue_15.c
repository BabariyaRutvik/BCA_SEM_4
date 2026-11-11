/*
15. To implement a linear queue using an array and perform enqueue operations.

Explanation:
- A Queue follows FIFO (First-In, First-Out).
- Using an array of size MAX, front = -1 and rear = -1 initially:
  - Enqueue checks Overflow (rear == MAX - 1).
  - If queue is empty (front == -1), set front = 0.
  - Increment rear and store value at queue[rear].
*/
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d into linear queue.\n", value);
    }
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Linear Queue (front to rear): ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, i, val;

    printf("How many elements to enqueue (MAX = %d)? ", MAX);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        enqueue(val);
    }

    display();
    return 0;
}

/*
Sample Input:
4
10 20 30 40

Sample Output:
How many elements to enqueue (MAX = 5)? Enter value 1: Enqueued 10 into linear queue.
Enter value 2: Enqueued 20 into linear queue.
Enter value 3: Enqueued 30 into linear queue.
Enter value 4: Enqueued 40 into linear queue.
Linear Queue (front to rear): 10 20 30 40
*/
