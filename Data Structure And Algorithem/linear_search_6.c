/*
6. Write a program to search an element in the array using Linear Search.

Explanation:
- Linear Search checks each element of the array sequentially from index 0 to n - 1.
- If a match is found, it reports the 1-based position (and 0-based index) and stops.
- Works on both sorted and unsorted arrays. Time complexity: O(n).
*/
#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, i, key, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    pos = linearSearch(arr, n, key);
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
12 45 23 78 34
23

Sample Output:
Enter number of elements: Enter 5 elements:
Enter element to search: Element 23 found at index 2 (position 3).
*/
