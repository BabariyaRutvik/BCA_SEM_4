/*
39. To design a ticket booking system using a queue for handling customer requests in order.

Explanation:
- Customers arrive and join the booking queue at rear (FIFO order).
- When a counter serves a request, the customer at front is issued a ticket and removed.
- Circular queue indexing keeps the buffer reusable.
*/
#include <stdio.h>
#include <string.h>
#define MAX 10

struct Request {
    int ticketId;
    char customerName[30];
};

struct Request queue[MAX];
int front = -1, rear = -1, nextTicketId = 101;

void addRequest(char name[]) {
    if ((rear + 1) % MAX == front) {
        printf("Booking queue is full! Please wait.\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear].ticketId = nextTicketId++;
    strcpy(queue[rear].customerName, name);
    printf("Request added: Ticket #%d for %s\n", queue[rear].ticketId, queue[rear].customerName);
}

void processBooking() {
    if (front == -1) {
        printf("No pending ticket requests.\n");
        return;
    }
    printf("Ticket Issued -> #%d to %s\n", queue[front].ticketId, queue[front].customerName);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void displayPending() {
    int i;
    if (front == -1) {
        printf("Pending Queue: Empty\n");
        return;
    }
    printf("Pending Requests: ");
    i = front;
    while (1) {
        printf("[#%d: %s] ", queue[i].ticketId, queue[i].customerName);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    char name[30];

    while (1) {
        printf("\n1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter customer name: ");
            scanf("%s", name);
            addRequest(name);
        } else if (choice == 2) {
            processBooking();
        } else if (choice == 3) {
            displayPending();
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
Alice
1
Bob
3
2
3
4

Sample Output:

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice: Enter customer name: Request added: Ticket #101 for Alice

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice: Enter customer name: Request added: Ticket #102 for Bob

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice: Pending Requests: [#101: Alice] [#102: Bob] 

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice: Ticket Issued -> #101 to Alice

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice: Pending Requests: [#102: Bob] 

1. Book Ticket Request  2. Serve Next Customer  3. View Queue  4. Exit
Choice:
*/
