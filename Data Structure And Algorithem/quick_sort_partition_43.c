/*
43. To implement Quick Sort using the first element as pivot and display the array after each partition.

Explanation:
- Selects arr[low] as the pivot.
- Uses two pointers i (moving right) and j (moving left) to place elements <= pivot
  on the left and > pivot on the right, then swaps pivot with arr[j].
- Prints the full array after every partition step so each stage is visible.
*/
#include <stdio.h>

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    printf("After partition (pivot = %d at index %d): ", pivot, j);
    printArray(arr, n);
    return j;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int p = partition(arr, low, high, n);
        quickSort(arr, low, p - 1, n);
        quickSort(arr, p + 1, high, n);
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

    quickSort(arr, 0, n - 1, n);

    printf("Final Sorted Array: ");
    printArray(arr, n);

    return 0;
}

/*
Sample Input:
6
35 12 48 19 5 27

Sample Output:
Enter number of elements: Enter 6 elements:
After partition (pivot = 35 at index 4): 5 12 27 19 35 48 
After partition (pivot = 5 at index 0): 5 12 27 19 35 48 
After partition (pivot = 12 at index 1): 5 12 27 19 35 48 
After partition (pivot = 27 at index 3): 5 12 19 27 35 48 
Final Sorted Array: 5 12 19 27 35 48
*/
