
/*
3. Write a program to perform Selection Sort.

Explanation:
- Selection Sort divides the array into a sorted prefix and an unsorted suffix.
- In each pass i, it finds the minimum element in arr[i..n-1] and swaps it with arr[i].
*/

#include <stdio.h>

int main()
{
    int arr[100], n, i, j, min, temp;

    printf("Enter Number of Elements: ");
    scanf("%d", &n);

    printf("Enter Array Elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted Array: ");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

/*
Sample Input:
5
64 25 12 22 11

Sample Output:
Enter Number of Elements: Enter Array Elements:
Sorted Array: 11 12 22 25 64
*/
