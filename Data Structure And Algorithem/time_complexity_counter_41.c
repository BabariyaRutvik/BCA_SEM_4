/*
41. To implement a program to find the time complexity of an algorithm by counting the number of basic operations (loop-based examples).

Explanation:
- By incrementing a counter variable inside loops, we empirically count basic
  operations for a given input size n across four common complexity classes:
  1. Constant time O(1)
  2. Linear single loop O(n)
  3. Logarithmic halving loop O(log n)
  4. Quadratic nested loop O(n^2)
*/
#include <stdio.h>

int main() {
    int n, i, j, temp;
    long opsConstant = 0, opsLinear = 0, opsLog = 0, opsQuad = 0;

    printf("Enter input size n: ");
    scanf("%d", &n);

    /* 1. O(1) Constant */
    opsConstant++;

    /* 2. O(n) Linear Loop */
    for (i = 0; i < n; i++) {
        opsLinear++;
    }

    /* 3. O(log n) Logarithmic Loop */
    temp = n;
    while (temp > 0) {
        opsLog++;
        temp = temp / 2;
    }

    /* 4. O(n^2) Nested Loop */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            opsQuad++;
        }
    }

    printf("\nBasic Operation Counts for n = %d:\n", n);
    printf("1. Constant O(1)       : %ld operations\n", opsConstant);
    printf("2. Linear O(n)         : %ld operations\n", opsLinear);
    printf("3. Logarithmic O(log n): %ld operations\n", opsLog);
    printf("4. Quadratic O(n^2)    : %ld operations\n", opsQuad);

    return 0;
}

/*
Sample Input:
16

Sample Output:
Enter input size n: 
Basic Operation Counts for n = 16:
1. Constant O(1)       : 1 operations
2. Linear O(n)         : 16 operations
3. Logarithmic O(log n): 5 operations
4. Quadratic O(n^2)    : 256 operations
*/
