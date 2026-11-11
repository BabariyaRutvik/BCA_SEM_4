/*
40. To implement a hospital emergency room system using a priority queue (patients treated by priority).

Explanation:
- Patients are assigned a priority level (1 = Critical, 2 = Serious, 3 = General).
- On admission, the patient is inserted in sorted order by priority number so the
  most critical patient is always at index 0 for immediate treatment.
*/
#include <stdio.h>
#include <string.h>
#define MAX 20

struct Patient {
    char name[30];
    int priority; /* 1 = Critical, 2 = Serious, 3 = Normal */
};

struct Patient er[MAX];
int count = 0;

void admitPatient(char name[], int priority) {
    int i;
    if (count == MAX) {
        printf("Emergency Room is full!\n");
        return;
    }
    i = count - 1;
    while (i >= 0 && er[i].priority > priority) {
        er[i + 1] = er[i];
        i--;
    }
    strcpy(er[i + 1].name, name);
    er[i + 1].priority = priority;
    count++;
    printf("Admitted %s (Priority %d).\n", name, priority);
}

void treatPatient() {
    int i;
    if (count == 0) {
        printf("No patients waiting.\n");
        return;
    }
    printf("Treating Patient: %s (Priority %d)\n", er[0].name, er[0].priority);
    for (i = 0; i < count - 1; i++) {
        er[i] = er[i + 1];
    }
    count--;
}

void displayWaiting() {
    int i;
    if (count == 0) {
        printf("Waiting List: Empty\n");
        return;
    }
    printf("Waiting Patients (in treatment order):\n");
    for (i = 0; i < count; i++) {
        printf("  %d. %s (Priority %d)\n", i + 1, er[i].name, er[i].priority);
    }
}

int main() {
    int choice, priority;
    char name[30];

    while (1) {
        printf("\n1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter patient name: ");
            scanf("%s", name);
            printf("Enter priority (1=Critical, 2=Serious, 3=Normal): ");
            scanf("%d", &priority);
            admitPatient(name, priority);
        } else if (choice == 2) {
            treatPatient();
        } else if (choice == 3) {
            displayWaiting();
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
Riya 3
1
Aman 1
1
Kiran 2
3
2
3
4

Sample Output:

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Enter patient name: Enter priority (1=Critical, 2=Serious, 3=Normal): Admitted Riya (Priority 3).

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Enter patient name: Enter priority (1=Critical, 2=Serious, 3=Normal): Admitted Aman (Priority 1).

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Enter patient name: Enter priority (1=Critical, 2=Serious, 3=Normal): Admitted Kiran (Priority 2).

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Waiting Patients (in treatment order):
  1. Aman (Priority 1)
  2. Kiran (Priority 2)
  3. Riya (Priority 3)

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Treating Patient: Aman (Priority 1)

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice: Waiting Patients (in treatment order):
  1. Kiran (Priority 2)
  2. Riya (Priority 3)

1. Admit Patient  2. Treat Next Patient  3. Show Waiting List  4. Exit
Choice:
*/
