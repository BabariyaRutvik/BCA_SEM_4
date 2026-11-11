/*
16. To implement a linear queue using an array and perform dequeue operations.

Explanation:
- Dequeue removes the element at the front of the linear queue.
- Check Underflow when front == -1 or front > rear.
- Otherwise print queue[front] and increment front. Reset front and rear to -1
  if the last element was removed.
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
        queue[++rear] = value;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    int i;
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Remaining Queue (front to rear): ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
Remaining Queue (front to rear): 30 40
*/
