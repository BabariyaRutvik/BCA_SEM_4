/*
24. To implement deletion operations (from beginning, from end, and from a specific position) in a singly linked list.

Explanation:
- Beginning: save head in temp, move head = head->next, free(temp).
- End: traverse with prev and temp until temp->next == NULL, set prev->next = NULL, free(temp).
- Specific position (1-based): traverse to (pos - 1) node, bypass target node, and free it.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    newNode->data = val;
    newNode->next = NULL;
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

void deleteBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    prev = NULL;
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

void deleteAtPosition(int pos) {
    struct Node *temp, *target;
    int i;
    if (head == NULL || pos < 1) {
        printf("List empty or invalid position.\n");
        return;
    }
    if (pos == 1) {
        deleteBeginning();
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    target = temp->next;
    temp->next = target->next;
    printf("Deleted %d from position %d.\n", target->data, pos);
    free(target);
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
Choice: Linked List: 30 -> NULL

1. Delete Beginning  2. Delete End  3. Delete Position  4. Display  5. Exit
Choice:
*/
