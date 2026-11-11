/*
7. Write a program to perform Bubble Sort.

Explanation:
- Bubble Sort repeatedly compares adjacent elements and swaps them if they are
  in the wrong order.
- After each pass i, the largest remaining unsorted element settles at index n - 1 - i.
- A swapped flag stops the algorithm early if the array is already sorted.
*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp, swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

/*
Sample Input:
5
64 34 25 12 22

Sample Output:
Enter number of elements: Enter 5 elements:
Sorted Array: 12 22 25 34 64
*/
