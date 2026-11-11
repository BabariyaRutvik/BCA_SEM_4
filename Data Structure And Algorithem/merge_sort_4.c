
/*
4. Implement the mergesort algorithm.

Explanation:
- Merge Sort uses Divide and Conquer: it recursively splits the array into two halves
  until single elements remain, then merges the sorted halves in linear time.
*/

#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Enter between 1 and 100 elements.");
        return 1;
    }

    printf("Enter Array Elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Sample Input:
5
38 27 43 3 9

Sample Output:
Enter Number of Elements: Enter Array Elements:
Sorted Array: 3 9 27 38 43
*/
