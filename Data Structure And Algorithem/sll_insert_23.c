/*
23. To implement insertion operations (at beginning, at end, and at a specific position) in a singly linked list.

Explanation:
- Beginning: newNode->next = head; head = newNode.
- End: traverse to last node (where temp->next == NULL) and set temp->next = newNode.
- Specific position (1-based): traverse to node (pos - 1), then link
  newNode->next = temp->next and temp->next = newNode.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int val) {
    struct Node *newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int val) {
    struct Node *newNode = createNode(val);
    struct Node *temp;
    if (head == NULL) {
        head = newNode;
        return;
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(int val, int pos) {
    struct Node *newNode, *temp;
    int i;
    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit\nChoice: ");
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

1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice: Enter value: 
1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice: Enter value and 1-based position: 
1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice: Linked List: 10 -> 20 -> 30 -> 40 -> NULL

1. Insert Beginning  2. Insert End  3. Insert at Position  4. Display  5. Exit
Choice:
*/
