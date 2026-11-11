/*
17. To implement a Circular queue using an array and perform enqueue operations.

Explanation:
- A Circular Queue wraps rear and front around the array using modulo (% MAX),
  avoiding wasted space after dequeues in a linear queue.
- Queue is full when (rear + 1) % MAX == front.
- Enqueue sets front = 0 if empty, else advances rear = (rear + 1) % MAX.
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
    printf("Enqueued %d at index %d.\n", value, rear);
}

void display() {
    int i;
    if (front == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue (front to rear): ");
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
How many elements to enqueue (MAX = 5)? Enter value 1: Enqueued 10 at index 0.
Enter value 2: Enqueued 20 at index 1.
Enter value 3: Enqueued 30 at index 2.
Enter value 4: Enqueued 40 at index 3.
Circular Queue (front to rear): 10 20 30 40
*/
