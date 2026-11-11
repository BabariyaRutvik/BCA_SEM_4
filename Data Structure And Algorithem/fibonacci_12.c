/*
12. To implement a recursive function to generate the Fibonacci series up to 'n' terms.

Explanation:
- The Fibonacci sequence starts with F(0) = 0 and F(1) = 1.
- Each subsequent term is F(k) = F(k - 1) + F(k - 2).
- The program prints the first n terms by calling fibonacci(i) for i = 0 to n - 1.
*/
#include <stdio.h>

int fibonacci(int k) {
    if (k == 0) {
        return 0;
    }
    if (k == 1) {
        return 1;
    }
    return fibonacci(k - 1) + fibonacci(k - 2);
}

int main() {
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series (%d terms): ", n);
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");

    return 0;
}

/*
Sample Input:
7

Sample Output:
Enter number of terms: Fibonacci Series (7 terms): 0 1 1 2 3 5 8
*/
