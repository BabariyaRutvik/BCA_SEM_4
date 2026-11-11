/*
44. To implement Binary Search using a recursive function.

Explanation:
- Base case: if low > high, return -1 (not found).
- Compute mid = low + (high - low) / 2.
- If arr[mid] == key return mid; else recursively search left half [low, mid - 1]
  or right half [mid + 1, high].
*/
#include <stdio.h>

int binarySearchRecursive(int arr[], int low, int high, int key) {
    int mid;
    if (low > high) {
        return -1;
    }
    mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if (key < arr[mid]) {
        return binarySearchRecursive(arr, low, mid - 1, key);
    } else {
        return binarySearchRecursive(arr, mid + 1, high, key);
    }
}

int main() {
    int arr[100], n, i, key, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = binarySearchRecursive(arr, 0, n - 1, key);
    if (pos != -1) {
        printf("Element %d found at index %d (position %d).\n", key, pos, pos + 1);
    } else {
        printf("Element %d not found.\n", key);
    }

    return 0;
}

/*
Sample Input:
6
5 12 19 27 35 48
27

Sample Output:
Enter number of elements: Enter 6 sorted elements:
Enter element to search: Element 27 found at index 3 (position 4).
*/
