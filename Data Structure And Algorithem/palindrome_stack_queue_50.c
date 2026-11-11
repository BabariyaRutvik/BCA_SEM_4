/*
50. To implement a program to check whether a string is a palindrome using a stack and a queue.

Explanation:
- Insert each character of the string into both a stack (LIFO) and a queue (FIFO).
- Popping from the stack yields characters from end to start, while dequeuing from
  the queue yields characters from start to end.
- If all popped and dequeued characters match, the string is a palindrome.
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX], queue[MAX];
int top = -1, front = 0, rear = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

void enqueue(char ch) {
    queue[++rear] = ch;
}

char dequeue() {
    return queue[front++];
}

int main() {
    char str[MAX];
    int i, len, isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = (int)strlen(str);
    for (i = 0; i < len; i++) {
        push(str[i]);
        enqueue(str[i]);
    }

    for (i = 0; i < len; i++) {
        if (pop() != dequeue()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("'%s' is a Palindrome.\n", str);
    } else {
        printf("'%s' is NOT a Palindrome.\n", str);
    }

    return 0;
}

/*
Sample Input:
madam

Sample Output:
Enter a string: 'madam' is a Palindrome.
*/
