#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory full. Can't add %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d added to the stack\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty. Nothing to remove\n");
        return;
    }
    struct Node *temp = top;
    printf("%d removed from the stack\n", top->data);
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top of the stack: %d\n", top->data);
    }
}

void show() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    struct Node *current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("Welcome! Let's work with a stack using linked list.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add to stack\n");
        printf("2. Remove from stack\n");
        printf("3. See top item\n");
        printf("4. Show stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thanks for using the stack. See you next time!\n");
            break;
        }

        if (choice == 1) {
            printf("Enter number to add: ");
            scanf("%d", &value);
            push(value);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            show();
        } else {
            printf("That's not a valid option. Try again.\n");
        }
    }

    return 0;
}
