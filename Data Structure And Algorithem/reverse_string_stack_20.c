/*
20. To use stack operations (push & pop) to reverse a string.

Explanation:
- Because a stack is LIFO (Last-In, First-Out), pushing every character of a string
  onto a character stack and then popping them one by one yields the string in
  exact reverse order.
*/
#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    char str[MAX];
    int i, len;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    len = (int)strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    for (i = 0; i < len; i++) {
        str[i] = pop();
    }

    printf("Reversed String: %s\n", str);
    return 0;
}

/*
Sample Input:
DATASTRUCTURES

Sample Output:
Enter a string: Reversed String: SERUTCURTSATAD
*/
