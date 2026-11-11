/*
38. To analyze the real-life applications of searching techniques (e.g., searching a name in contacts, dictionary lookup).

Explanation:
- Linear Search works on unsorted data (e.g., recently added phone contacts),
  taking O(n) comparisons in the worst case.
- Binary Search requires sorted data (e.g., alphabetical dictionary lookup),
  taking O(log n) comparisons by halving the search space each step.
- This program runs both real-life scenarios and prints comparison counts to
  compare their practical efficiency.
*/
#include <stdio.h>
#include <string.h>

struct Contact {
    char name[30];
    char phone[15];
};

int searchContactLinear(struct Contact list[], int n, char target[], int *comparisons) {
    int i;
    *comparisons = 0;
    for (i = 0; i < n; i++) {
        (*comparisons)++;
        if (strcmp(list[i].name, target) == 0) {
            return i;
        }
    }
    return -1;
}

int searchDictionaryBinary(char dict[][30], int n, char target[], int *comparisons) {
    int low = 0, high = n - 1, mid, cmp;
    *comparisons = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        (*comparisons)++;
        cmp = strcmp(dict[mid], target);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    struct Contact contacts[6] = {
        {"Rohan", "9876543210"},
        {"Asha", "9123456780"},
        {"Vikram", "9988776655"},
        {"Neha", "9012345678"},
        {"Karan", "9765432109"},
        {"Priya", "9811223344"}
    };
    char dictionary[8][30] = {
        "algorithm", "binary", "compiler", "database",
        "graph", "pointer", "queue", "stack"
    };
    char contactQuery[30], wordQuery[30];
    int idx, comps;

    printf("--- Real-Life Application 1: Unsorted Contacts (Linear Search) ---\n");
    printf("Available contacts: Rohan, Asha, Vikram, Neha, Karan, Priya\n");
    printf("Enter contact name to search: ");
    scanf("%s", contactQuery);

    idx = searchContactLinear(contacts, 6, contactQuery, &comps);
    if (idx != -1) {
        printf("Found %s -> Phone: %s (Comparisons: %d)\n", contacts[idx].name, contacts[idx].phone, comps);
    } else {
        printf("Contact not found (Comparisons: %d)\n", comps);
    }

    printf("\n--- Real-Life Application 2: Sorted Dictionary (Binary Search) ---\n");
    printf("Dictionary words: algorithm, binary, compiler, database, graph, pointer, queue, stack\n");
    printf("Enter word to look up: ");
    scanf("%s", wordQuery);

    idx = searchDictionaryBinary(dictionary, 8, wordQuery, &comps);
    if (idx != -1) {
        printf("Word '%s' found at index %d (Comparisons: %d)\n", dictionary[idx], idx, comps);
    } else {
        printf("Word '%s' not found (Comparisons: %d)\n", wordQuery, comps);
    }

    return 0;
}

/*
Sample Input:
Vikram
pointer

Sample Output:
--- Real-Life Application 1: Unsorted Contacts (Linear Search) ---
Available contacts: Rohan, Asha, Vikram, Neha, Karan, Priya
Enter contact name to search: Found Vikram -> Phone: 9988776655 (Comparisons: 3)

--- Real-Life Application 2: Sorted Dictionary (Binary Search) ---
Dictionary words: algorithm, binary, compiler, database, graph, pointer, queue, stack
Enter word to look up: Word 'pointer' found at index 5 (Comparisons: 2)
*/
