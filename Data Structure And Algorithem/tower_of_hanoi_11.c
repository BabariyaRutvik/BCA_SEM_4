/*
11. To implement a recursive solution for the Tower of Hanoi problem.

Explanation:
- Move n disks from Source (S) to Destination (D) using Auxiliary (A):
  1. Recursively move n - 1 disks from S to A using D.
  2. Move the largest disk (disk n) directly from S to D.
  3. Recursively move n - 1 disks from A to D using S.
- Total moves required for n disks = (2^n) - 1.
*/
#include <stdio.h>

int moveCount = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveCount++;
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    moveCount++;
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be positive.\n");
        return 1;
    }

    towerOfHanoi(n, 'A', 'B', 'C');
    printf("Total moves: %d\n", moveCount);

    return 0;
}

/*
Sample Input:
3

Sample Output:
Enter number of disks: Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
Total moves: 7
*/
