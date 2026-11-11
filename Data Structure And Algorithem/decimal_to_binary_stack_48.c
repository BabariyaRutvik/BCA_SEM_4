/*
48. To implement a program to convert a decimal number to binary using a stack.

Explanation:
- Repeatedly divide the decimal number by 2 and push each remainder (0 or 1)
  onto the stack until the number becomes 0.
- Popping all elements from the stack outputs the remainders in reverse order,
  which is the binary representation.
*/
#include <stdio.h>
#define MAX 64

int stack[MAX];
int top = -1;

void push(int bit) {
    if (top < MAX - 1) {
        stack[++top] = bit;
    }
}

int pop() {
    return stack[top--];
}

int main() {
    int num, temp;

    printf("Enter a non-negative decimal integer: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }
    if (num == 0) {
        printf("Binary representation: 0\n");
        return 0;
    }

    temp = num;
    while (temp > 0) {
        push(temp % 2);
        temp /= 2;
    }

    printf("Binary representation of %d: ", num);
    while (top != -1) {
        printf("%d", pop());
    }
    printf("\n");

    return 0;
}

/*
Sample Input:
25

Sample Output:
Enter a non-negative decimal integer: Binary representation of 25: 11001
*/
