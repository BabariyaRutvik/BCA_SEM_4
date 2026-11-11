/*
21. To apply stack operations (push & pop) in converting infix expression to postfix.

Explanation:
- Scan the infix expression left to right:
  - Operands (letters/digits) go directly to the postfix output.
  - '(' is pushed onto the operator stack.
  - ')' pops and outputs operators until '(' is found.
  - For an operator, pop operators with higher or equal precedence (for left-
    associative operators) from the stack, then push the current operator.
  - After scanning, pop all remaining operators from the stack.
*/
#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX], ch, temp;
    int i = 0, j = 0;

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {
        if (isalnum((unsigned char)ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && (temp = pop()) != '(') {
                postfix[j++] = temp;
            }
        } else {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

/*
Sample Input:
A+B*(C^D-E)

Sample Output:
Enter infix expression (no spaces): Postfix Expression: ABCD^E-*+
*/
