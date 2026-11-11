/*
42. To compare the running time of Bubble Sort, Selection Sort, Merge Sort and Quick Sort on the same input data set.

Explanation:
- Generates an identical random array of size n and copies it to four arrays.
- Measures CPU execution time of Bubble Sort, Selection Sort, Merge Sort, and
  Quick Sort using clock() from <time.h>.
- Using a sufficiently large n (e.g., 5000 or 10000) clearly shows O(n^2) vs O(n log n).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 20000

void copyArray(int src[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void merge(int arr[], int low, int mid, int high) {
    static int temp[MAXN];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (i = low; i <= high; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1, j, temp;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    static int base[MAXN], work[MAXN];
    int n, i;
    clock_t start, end;

    printf("Enter dataset size n (1 to %d, recommended 5000): ", MAXN);
    scanf("%d", &n);
    if (n < 1 || n > MAXN) {
        printf("Invalid size.\n");
        return 1;
    }

    srand(42);
    for (i = 0; i < n; i++) {
        base[i] = rand() % 100000;
    }

    copyArray(base, work, n);
    start = clock();
    bubbleSort(work, n);
    end = clock();
    printf("Bubble Sort Time    : %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    copyArray(base, work, n);
    start = clock();
    selectionSort(work, n);
    end = clock();
    printf("Selection Sort Time : %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    copyArray(base, work, n);
    start = clock();
    mergeSort(work, 0, n - 1);
    end = clock();
    printf("Merge Sort Time     : %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    copyArray(base, work, n);
    start = clock();
    quickSort(work, 0, n - 1);
    end = clock();
    printf("Quick Sort Time     : %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

/*
Sample Input:
20000

Sample Output:
Enter dataset size n (1 to 20000, recommended 5000): Bubble Sort Time    : 0.621000 seconds
Selection Sort Time : 0.168000 seconds
Merge Sort Time     : 0.001000 seconds
Quick Sort Time     : 0.000000 seconds
*/
