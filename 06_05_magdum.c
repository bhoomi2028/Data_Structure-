#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top == SIZE - 1) {
        printf("Stack is full. Can't push '%c'\n", ch);
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int checkParentheses(char *expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();
            if (!isMatching(open, ch)) {
                return 0;
            }
        }
    }

    return top == -1;
}

int main() {
    char expr[SIZE];

    printf("Enter an expression with brackets: ");
    scanf("%s", expr);

    if (checkParentheses(expr)) {
        printf("All brackets are matched correctly!\n");
    } else {
        printf("Brackets are NOT matched properly.\n");
    }

    return 0;
}
