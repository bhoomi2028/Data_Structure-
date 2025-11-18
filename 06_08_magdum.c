#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char ch) {
    if (ch == '^') return 3;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '+' || ch == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

void reverse(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void swapBrackets(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void convertToPrefix(char *infix, char *prefix) {
    reverse(infix);
    swapBrackets(infix);

    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            prefix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                prefix[j++] = pop();
            }
            if (!isEmpty()) pop();
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) > precedence(ch)) {
                prefix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';
    reverse(prefix);
}

int main() {
    char infix[SIZE], prefix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    convertToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
