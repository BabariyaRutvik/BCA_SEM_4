/*
49. To implement a double-ended queue (deque) using an array and perform insertion and deletion at both ends.

Explanation:
- A Deque supports insertFront, insertRear, deleteFront, and deleteRear.
- Implemented using a circular array of size MAX:
  - isFull(): (front == 0 && rear == MAX - 1) || (front == rear + 1)
  - insertFront moves front backward circularly: front = (front - 1 + MAX) % MAX.
  - deleteRear moves rear backward circularly: rear = (rear - 1 + MAX) % MAX.
*/
#include <stdio.h>
#define MAX 6

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int val) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

void insertRear(int val) {
    if (isFull()) {
        printf("Deque Overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque Underflow!\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque (front to rear): ");
    i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            insertFront(val);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            insertRear(val);
        } else if (choice == 3) {
            deleteFront();
        } else if (choice == 4) {
            deleteRear();
        } else if (choice == 5) {
            display();
        } else if (choice == 6) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}

/*
Sample Input:
2
10
2
20
1
5
5
3
4
5
6

Sample Output:

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Enter value: Inserted 10 at rear.

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Enter value: Inserted 20 at rear.

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Enter value: Inserted 5 at front.

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Deque (front to rear): 5 10 20 

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Deleted 5 from front.

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Deleted 20 from rear.

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice: Deque (front to rear): 10 

1. Insert Front  2. Insert Rear  3. Delete Front  4. Delete Rear  5. Display  6. Exit
Choice:
*/
