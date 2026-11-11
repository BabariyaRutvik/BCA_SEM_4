/*
47. To implement a program to evaluate a postfix expression using a stack.

Explanation:
- Scan the postfix expression (single-digit operands, e.g., 53+82-*) from left to right:
  - If the character is a digit, push its integer value (ch - '0') onto the stack.
  - If it is an operator (+, -, *, /, ^), pop op2 then op1, compute (op1 op op2),
    and push the result back onto the stack.
  - The final remaining item on the stack is the evaluated result.
*/
#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int intPow(int base, int exp) {
    int res = 1, i;
    for (i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

int main() {
    char postfix[MAX], ch;
    int i = 0, op1, op2;

    printf("Enter postfix expression (single-digit operands, e.g. 53+82-*): ");
    scanf("%s", postfix);

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit((unsigned char)ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '^': push(intPow(op1, op2)); break;
                default:
                    printf("Unknown operator: %c\n", ch);
                    return 1;
            }
        }
    }

    printf("Evaluated Result = %d\n", pop());
    return 0;
}

/*
Sample Input:
53+82-*

Sample Output:
Enter postfix expression (single-digit operands, e.g. 53+82-*): Evaluated Result = 48
*/
