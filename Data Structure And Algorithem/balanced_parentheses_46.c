/*
46. To implement a program to check whether an expression has balanced parentheses using a stack.

Explanation:
- Scan the expression left to right:
  - Push opening brackets '(', '{', '[' onto the stack.
  - On encountering closing brackets ')', '}', ']', pop from the stack and verify
    that the popped bracket matches the closing type.
  - Expression is balanced only if no mismatch occurs and the stack is empty at the end.
*/
#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char expr[MAX], ch, popped;
    int i = 0, balanced = 1;

    printf("Enter expression: ");
    scanf("%s", expr);

    while ((ch = expr[i++]) != '\0') {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            popped = pop();
            if (!isMatchingPair(popped, ch)) {
                balanced = 0;
                break;
            }
        }
    }

    if (top != -1) {
        balanced = 0;
    }

    if (balanced) {
        printf("Expression has BALANCED parentheses.\n");
    } else {
        printf("Expression does NOT have balanced parentheses.\n");
    }

    return 0;
}

/*
Sample Input:
{[a+(b*c)]-d}

Sample Output:
Enter expression: Expression has BALANCED parentheses.
*/
