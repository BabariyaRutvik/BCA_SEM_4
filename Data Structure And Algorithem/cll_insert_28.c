/*
28. To implement insertion operations (at beginning, at end, and at a specific position) in a circular linked list.

Explanation:
- Maintaining a tail pointer (where tail->next == head) makes both beginning and
  end insertions O(1):
  - Beginning: newNode->next = tail->next; tail->next = newNode.
  - End: same link, plus tail = newNode.
  - Specific position (1-based): traverse to (pos - 1) and insert after it.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int val) {
    struct Node *newNode = createNode(val);
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtEnd(int val) {
    insertAtBeginning(val);
    tail = tail->next;
}

void insertAtPosition(int val, int pos) {
    struct Node *newNode, *temp;
    int i;
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1 || tail == NULL) {
        if (pos == 1) {
            insertAtBeginning(val);
        } else {
            printf("List is empty, position out of range.\n");
        }
        return;
    }
    temp = tail->next;
    for (i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == tail->next) {
            printf("Position out of range.\n");
            return;
        }
    }
    newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == tail) {
        tail = newNode;
    }
}

void display() {
    struct Node *temp;
    if (tail == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    temp = tail->next;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("(head)\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &val);
            insertAtBeginning(val);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &val);
            insertAtEnd(val);
        } else if (choice == 3) {
            printf("Enter value and 1-based position: ");
            scanf("%d %d", &val, &pos);
            insertAtPosition(val, pos);
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
20
1
10
2
40
3
30 3
4
5

Sample Output:

1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice: Enter value and 1-based position: 
1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice: Circular Linked List: 10 -> 20 -> 30 -> 40 -> (head)

1. Insert Beginning  2. Insert End  3. Insert Position  4. Display  5. Exit
Choice:
*/
