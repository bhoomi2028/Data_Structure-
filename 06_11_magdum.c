#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluate(char operator, int a, int b) {
    if (operator == '+') return a + b;
    if (operator == '-') return a - b;
    if (operator == '*') return a * b;
    if (operator == '/') return a / b;
    return 0;
}

int main() {
    char expr[SIZE];
    int i, a, b;

    printf("Enter a postfix expression (like 34+5*): ");
    scanf("%s", expr);

    for (i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (isdigit(ch)) {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            b = pop();
            a = pop();
            push(evaluate(ch, a, b));
        }
    }

    printf("Result: %d\n", pop());

    return 0;
}
