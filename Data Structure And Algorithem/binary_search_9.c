/*
9. Write a program to search an element in the array using Binary Search.

Explanation:
- Binary Search requires a sorted array.
- It maintains low and high bounds, checks the middle element mid, and halves the
  search space each iteration based on whether key < arr[mid] or key > arr[mid].
- Time complexity: O(log n).
*/
#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, i, key, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements (ascending):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binarySearch(arr, n, key);
    if (pos != -1) {
        printf("Element %d found at index %d (position %d).\n", key, pos, pos + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

/*
Sample Input:
5
10 20 30 40 50
40

Sample Output:
Enter number of elements: Enter 5 sorted elements (ascending):
Enter element to search: Element 40 found at index 3 (position 4).
*/
