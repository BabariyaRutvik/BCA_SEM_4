/*
19. To implement a priority queue using an array.

Explanation:
- Each element in the priority queue stores a value and a priority number
  (smaller number = higher priority, e.g., 1 is highest).
- Enqueue inserts the new item in sorted order by priority (shifting lower-priority
  items right), so Dequeue simply removes from index 0 in O(1).
*/
#include <stdio.h>
#define MAX 20

struct Item {
    int data;
    int priority;
};

struct Item pq[MAX];
int size = 0;

void enqueue(int data, int priority) {
    int i;
    if (size == MAX) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    i = size - 1;
    while (i >= 0 && pq[i].priority > priority) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1].data = data;
    pq[i + 1].priority = priority;
    size++;
    printf("Inserted %d with priority %d.\n", data, priority);
}

void dequeue() {
    int i;
    if (size == 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    printf("Dequeued: %d (Priority: %d)\n", pq[0].data, pq[0].priority);
    for (i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    int i;
    if (size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue [Data(Priority)]: ");
    for (i = 0; i < size; i++) {
        printf("%d(%d) ", pq[i].data, pq[i].priority);
    }
    printf("\n");
}

int main() {
    int choice, data, priority;

    while (1) {
        printf("\n1. Enqueue  2. Dequeue  3. Display  4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value and priority (lower number = higher priority): ");
            scanf("%d %d", &data, &priority);
            enqueue(data, priority);
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
100 3
1
200 1
1
300 2
3
2
3
4

Sample Output:

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Enter value and priority (lower number = higher priority): Inserted 100 with priority 3.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Enter value and priority (lower number = higher priority): Inserted 200 with priority 1.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Enter value and priority (lower number = higher priority): Inserted 300 with priority 2.

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Priority Queue [Data(Priority)]: 200(1) 300(2) 100(3) 

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Dequeued: 200 (Priority: 1)

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice: Priority Queue [Data(Priority)]: 300(2) 100(3) 

1. Enqueue  2. Dequeue  3. Display  4. Exit
Enter choice:
*/
