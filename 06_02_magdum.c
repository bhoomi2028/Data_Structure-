#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is full. Can't add %d\n", value);
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("%d added to the queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Nothing to remove\n");
    } else {
        printf("%d removed from the queue\n", queue[front++]);
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Front of the queue: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    printf("Welcome to Queue Manager!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add to queue\n");
        printf("2. Remove from queue\n");
        printf("3. See front item\n");
        printf("4. Show entire queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to add: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            peek();
        } else if (choice == 4) {
            display();
        } else if (choice == 5) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
