#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory full. Can't add %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d added to the queue\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to remove\n");
        return;
    }

    struct Node *temp = front;
    printf("%d removed from the queue\n", front->data);
    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front of the queue: %d\n", front->data);
    }
}

void show() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    struct Node *current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("Welcome! Let's work with a queue using linked list.\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add to queue\n");
        printf("2. Remove from queue\n");
        printf("3. See front item\n");
        printf("4. Show queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Thanks for using the queue. See you next time!\n");
            break;
        }

        if (choice == 1) {
            printf("Enter number to add: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
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
