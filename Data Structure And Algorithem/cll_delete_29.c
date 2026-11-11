/*
29. To implement deletion operations (from beginning, from end, and from a specific position) in a circular linked list.

Explanation:
- Using tail pointer where head = tail->next:
  - Beginning: remove head = tail->next; update tail->next = head->next (or tail = NULL if single node).
  - End: traverse from head to the node just before tail, point it to head, update tail.
  - Specific position: traverse to (pos - 1) and unlink its next node, updating tail if needed.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *tail = NULL;

void insertEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (tail == NULL) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteBeginning() {
    struct Node *head;
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    head = tail->next;
    if (head == tail) {
        printf("Deleted %d from beginning.\n", head->data);
        free(head);
        tail = NULL;
    } else {
        tail->next = head->next;
        printf("Deleted %d from beginning.\n", head->data);
        free(head);
    }
}

void deleteEnd() {
    struct Node *temp;
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (tail->next == tail) {
        printf("Deleted %d from end.\n", tail->data);
        free(tail);
        tail = NULL;
        return;
    }
    temp = tail->next;
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail->next;
    printf("Deleted %d from end.\n", tail->data);
    free(tail);
    tail = temp;
}

void deleteAtPosition(int pos) {
    struct Node *temp, *target;
    int i;
    if (tail == NULL || pos < 1) {
        printf("List empty or invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
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
    if (temp == tail) {
        printf("Position out of range.\n");
        return;
    }
    target = temp->next;
    temp->next = target->next;
    if (target == tail) {
        tail = temp;
    }
    printf("Deleted %d from position %d.\n", target->data, pos);
    free(target);
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
    int n, i, val, choice, pos;

    printf("Enter initial number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        insertEnd(val);
    }

    while (1) {
        printf("\n1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            deleteBeginning();
        } else if (choice == 2) {
            deleteEnd();
        } else if (choice == 3) {
            printf("Enter 1-based position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
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
4
10 20 30 40
1
2
3
1
4
5

Sample Output:
Enter initial number of nodes: Enter value 1: Enter value 2: Enter value 3: Enter value 4: 
1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice: Deleted 10 from beginning.

1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice: Deleted 40 from end.

1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice: Enter 1-based position: Deleted 20 from beginning.

1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice: Circular Linked List: 30 -> (head)

1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice:
*/
